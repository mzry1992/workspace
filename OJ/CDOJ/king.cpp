    #include<stdio.h>
    #include<cmath>
    #include<stdlib.h>
    #include<algorithm>
    #define BOW 1
    #define SOL 2
    using namespace std;
    const int PSIZE = 30000;
    const double eps = 0.000001;
    const double pi = acos(-1.0);
    struct Point
        {
            double x;
            double y;
            double z;
            int type;
            void set(const double &xx,const double &yy,const double &zz){x=xx;y=yy;z=zz;}
            //TPoint Rot(db k){return TPoint(cos(k) * x - sin(k) * y, sin(k) * x + cos(k) * y);}

            void transXY(double B)
                {
                    double tx = x, ty =y;
                    x = tx*cos(B) - ty*sin(B);
                    y = tx*sin(B) + ty*cos(B);
                }
            void transXZ(double B)
                {
                    double tx = x, tz =z;
                    x = tx*cos(B) - tz*sin(B);
                    z = tx*sin(B) + tz*cos(B);
                }
        };
    bool eql(double a,double b){return fabs(a-b)<eps;}
    Point pnt[PSIZE];
    int cnt;
    Point vec;
    void trans()
        {
            double b1 = atan2(vec.y,vec.x);
            vec.transXY(2.0*pi-b1);
            for(int i=1;i<=cnt;i++)
                pnt[i].transXY(2.0*pi-b1);
            double b2 = atan2(vec.z,vec.x);
            vec.transXZ(2.0*pi-b2);
            for(int i=1;i<=cnt;i++)
                pnt[i].transXZ(2.0*pi-b2);
        }
    bool cmp(const Point &p1, const Point &p2)
        {
            if(eql(p1.y,p2.y))
                {
                if(eql(p1.z,p2.z))
                    {
                    if(eql(p1.x,p2.x))
                        return p1.type < p2.type;
                    else
                        return p1.x < p2.x;
                    }
                else
                    return p1.z<p2.z;
                }
                else return p1.y < p2.y;
        }
    int sn;
    int calc()
        {
            sort(pnt+1,pnt+cnt+1,cmp);
            sn = 0;
            double cy = -100000000.0,cz = -1000000000.0;
            int ans = 0;
            for(int i=1;i<=cnt;)
                {
                    double iy = pnt[i].y , iz = pnt[i].z;
                    double ix = pnt[i].x;
                    if(!eql(iy,cy) || !eql(iz,cz))
                        {
                            cy = iy;cz = iz;
                            sn = 0;
                        }
                    if(pnt[i].type == SOL && sn)
                        {
                            ans++;
                            int tp = i+1;
                            while(tp <=cnt && eql(iy,pnt[tp].y) && eql(iz,pnt[tp].z))
                                {
                                    ans+=(pnt[tp].type == SOL);
                                    tp++;
                                }
                            sn--;
                            i = tp;
                            continue;
                        }
                    else if(pnt[i].type == BOW)
                        {
                            sn++;
                        }
                    i++;
                }
            return ans;
        }

    int main()
        {
            freopen("out.txt","r",stdin);
            freopen("out2.txt","w",stdout);
            int ca,cb;
            int cas;
            scanf("%d",&cas);
            for(int ii=1;ii<=cas;ii++)
                {
                    //clr
                    cnt = 0;
                    //clr
                    scanf("%d%d",&ca,&cb);
                    double tx,ty,tz;
                    for(int i=1;i<=ca;i++)
                        {
                            scanf("%lf%lf%lf",&tx,&ty,&tz);
                            cnt++;
                            pnt[cnt].set(tx,ty,tz);
                            pnt[cnt].type = SOL;
                        }

                    for(int i=1;i<=cb;i++)
                        {

                            scanf("%lf%lf%lf",&tx,&ty,&tz);
                            cnt++;
                            pnt[cnt].set(tx,ty,tz);
                            pnt[cnt].type = BOW;
                        }
                    scanf("%lf%lf%lf",&tx,&ty,&tz);
                    vec.set(tx,ty,tz);

                    //cnt = ca + cb;
                    trans();
                    printf("Case %d: %d\n",ii,calc());
                }
            return 0;
        }
