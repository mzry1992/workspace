#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y,r;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point(Point _s,Point _e)
    {
        x = _e.x-_s.x;
        y = _e.y-_s.y;
    }
    double Length()
    {
        return sqrt(x*x+y*y);
    }
    double theta()
    {
        return atan2(y,x);
    }
};

Point NPT(Point P, Point s,Point e)
{
    Point result;
    double a, b, t;
    a = e.x - s.x;
    b = e.y - s.y;
    t = ( (P.x - s.x) * a + (P.y - s.y) * b ) / (a * a + b * b);
    result.x = s.x + a * t;
    result.y = s.y + b * t;
    return result;
}

double pmult(Point a,Point b)
{
    return a.x*b.x+a.y*b.y;
}

Point p[25],xp[25*25*2+25];
double d[25*25*2+25][25*25*2+25];
bool g[25*25*2+25][25*25*2+25];
int n,tn;

struct Event
{
    double l,r;
    Event() {}
    Event(double _l,double _r)
    {
        l = _l;
        r = _r;
    }
    friend bool operator < (const Event& a,const Event& b)
    {
        if (cmp(a.l,b.l) == 0)  return cmp(a.r,b.r) < 0;
        return cmp(a.l,b.l) < 0;
    }
};

Event e[500];
int tote;
double dis[25*25*2+25];
bool flag[25*25*2+25];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d",&n);
        tn = 0;
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].r);
        xp[tn++] = p[0];
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
            {
                double disc = Point(p[i],p[j]).Length();
                if (cmp(disc,p[i].r+p[j].r) > 0)    continue;
                if (cmp(disc,fabs(p[i].r-p[j].r)) < 0)    continue;
                double theta0 = Point(p[i],p[j]).theta();
                double theta1 = acos((p[i].r*p[i].r+disc*disc-p[j].r*p[j].r)/(2*p[i].r*disc));
                double theta2 = theta0-theta1;
                double theta3 = theta0+theta1;
                xp[tn++] = Point(p[i].x+p[i].r*cos(theta2),p[i].y+p[i].r*sin(theta2));
                xp[tn++] = Point(p[i].x+p[i].r*cos(theta3),p[i].y+p[i].r*sin(theta3));
            }
        xp[tn++] = p[n-1];
        memset(g,false,sizeof(g));
        for (int i = 0; i < tn; i++)
            for (int j = i+1; j < tn; j++)
            {
                tote = 0;
                for (int k = 0; k < n; k++)
                {
                    Point npt = NPT(p[k],xp[i],xp[j]);
                    double A = Point(p[k],npt).Length();
                    if (cmp(A,p[k].r) > 0)  continue;
                    double C = p[k].r;
                    double B = sqrt(C*C-A*A);
                    double dis0,dis1;
                    if (cmp(Point(p[k],npt).x,0) == 0 && cmp(Point(p[k],npt).y,0) == 0)
                    {
                        double dis2 = Point(xp[i],npt).Length();
                        if (cmp(pmult(Point(xp[i],npt),Point(xp[i],xp[j])),0) < 0)
                            dis2 = -dis2;
                        dis0 = dis2-B;
                        dis1 = dis2+B;
                    }
                    else
                    {
                        double theta0 = Point(p[k],npt).theta();
                        double theta1 = atan2(B,A);
                        double theta2 = theta0-theta1;
                        double theta3 = theta0+theta1;
                        Point np0,np1;
                        np0 = Point(p[k].x+p[k].r*cos(theta2),p[k].y+p[k].r*sin(theta2));
                        dis0 = Point(xp[i],np0).Length();
                        if (cmp(pmult(Point(xp[i],np0),Point(xp[i],xp[j])),0) < 0)  dis0 = -dis0;
                        np1 = Point(p[k].x+p[k].r*cos(theta3),p[k].y+p[k].r*sin(theta3));
                        dis1 = Point(xp[i],np1).Length();
                        if (cmp(pmult(Point(xp[i],np1),Point(xp[i],xp[j])),0) < 0)  dis1 = -dis1;
                    }
                    if (cmp(dis0,dis1) > 0) swap(dis0,dis1);

                    A = Point(xp[i],xp[j]).Length();
                    if (cmp(dis1,0) < 0)    continue;
                    if (cmp(dis0,A) > 0)    continue;
                    if (cmp(dis0,0) < 0)    dis0 = 0;
                    if (cmp(dis1,A) > 0)    dis1 = A;
                    e[tote++] = Event(dis0,dis1);
                }
                sort(e,e+tote);
                bool flg = true;
                for (int k = 1;k < tote;k++)
                    if (cmp(e[k].l,e[0].r) > 0)
                    {
                        flg = false;
                        break;
                    }
                    else
                        e[0].r = max(e[0].r,e[k].r);
                if (cmp(e[0].r,Point(xp[i],xp[j]).Length()) < 0)
                    flg = false;
                if (flg == true)
                {
                    g[i][j] = g[j][i] = true;
                    d[i][j] = d[j][i] = Point(xp[i],xp[j]).Length();
                }
            }
        for (int i = 0;i < tn;i++)
            dis[i] = 1e100;
        dis[0] = 0;
        memset(flag,false,sizeof(flag));
        for (int i=0;i<tn;i++)
        {
            int idx=-1;
            for (int j=0;j<tn;j++)
                if (!flag[j] && (idx==-1 || dis[idx]>dis[j]))
                    idx=j;
            if (idx==tn-1)
                break;
            flag[idx]=1;
            for (int j=0;j<tn;j++)
                if (g[idx][j]  && dis[j]>dis[idx]+d[idx][j])
                    dis[j]=dis[idx]+d[idx][j];
        }
        if (cmp(dis[tn-1],1e50) < 0)
            printf("Case %d: %.4f\n",ft,dis[tn-1]);
        else
            printf("Case %d: No such path.\n",ft);
    }
    return 0;
}
