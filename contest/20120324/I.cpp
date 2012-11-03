#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct point
{
    double x,y;
    point() {}
    point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    double operator *(const point& b)
    {
        return x*b.y-y*b.x;
    }
    double operator &(const point& b)
    {
        return x*b.x+y*b.y;
    }
    point operator -(const point& b)
    {
        return point(x-b.x,y-b.y);
    }
    point operator +(const point& b)
    {
        return point(x+b.x,y+b.y);
    }
    bool operator < (const point& b)const
    {
        if (cmp(x,b.x) == 0)   return  cmp(y,b.y) < 0;
        return cmp(x,b.x) < 0;
    }
    bool operator == (const point& b)const
    {
        return cmp(x,b.x) == 0 && cmp(y,b.y) == 0;
    }
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B) - ty*sin(B);
        y = tx*sin(B) + ty*cos(B);
    }

};

struct line
{
    point s,e;
    line() {}
    line(point _s,point _e)
    {
        s = _s;
        e = _e;
    }
    bool operator < (const line& b)const
    {
        if (s == b.s)   return e < b.e;
        return s < b.s;
    }
};

double xxx(line a,line b)
{
    return (a.e-a.s)*(b.e-b.s);
}

int dx,dy,px,py;
char com;
line a[1100],b[1100];
int tota,totb;
bool del[1100];

bool check(point mid,point s,point e)
{
    double minx = min(s.x,e.x);
    double maxx = max(s.x,e.x);
    double miny = min(s.y,e.y);
    double maxy = max(s.y,e.y);
    return (cmp(minx,mid.x) <= 0 && cmp(mid.x,maxx) <= 0 && cmp(miny,mid.y) <= 0 && cmp(mid.y,maxy) <= 0);
}

void output(line a)
{
    printf("[(%.10f,%.10f) -> (%.10f,%.10f)] ",a.s.x,a.s.y,a.e.x,a.e.y);
}

bool Gao(line a[],int& tot)
{
    px = py = tot = 0;
    while (true)
    {
        scanf(" %c",&com);
        if (com == 'Q') return false;
        if (com == 'E') break;
        scanf("%d%d",&dx,&dy);
        if (com == 'L')
            a[tot++] = line(point(px,py),point(px+dx,py+dy));
        px += dx;
        py += dy;
    }
    memset(del,false,sizeof(del));
    for (int i = 0; i < tot; i++)
        if (del[i] == false)
            for (int j = i+1; j < tot; j++)
                if (del[j] == false)
                    if (cmp(xxx(a[i],a[j]),0) == 0 && cmp((a[i].s-a[j].s)*(a[i].s-a[j].e),0) == 0 && (check(a[i].s,a[j].s,a[j].e) || check(a[i].e,a[j].s,a[j].e)))
                    {
                        int typ = 0;
                        if (cmp(min(a[i].s.x,a[i].e.x),a[i].s.x) == 0 && cmp(max(a[i].s.y,a[i].e.y),a[i].s.y) == 0)   typ = 1;
                        if (cmp(min(a[i].s.x,a[i].e.x),a[i].e.x) == 0 && cmp(max(a[i].s.y,a[i].e.y),a[i].e.y) == 0)   typ = 1;

                        double minx = min(min(a[i].s.x,a[i].e.x),min(a[j].s.x,a[j].e.x));
                        double maxx = max(max(a[i].s.x,a[i].e.x),max(a[j].s.x,a[j].e.x));
                        double miny = min(min(a[i].s.y,a[i].e.y),min(a[j].s.y,a[j].e.x));
                        double maxy = max(max(a[i].s.y,a[i].e.y),max(a[j].s.y,a[j].e.y));
                        del[j] = true;

                        if (typ == 0)
                            a[i] = line(point(minx,miny),point(maxx,maxy));
                        else
                            a[i] = line(point(minx,maxy),point(maxx,miny));
                    }
    int tmp = tot;
    tot = 0;
    for (int i = 0; i < tmp; i++)
        if (del[i] == false)
            a[tot++] = a[i];
    /*for (int i = 0;i < tot;i++)
        output(a[i]);
    printf("\n");*/
    return true;
}

set<line > mp;

bool wa(line la,line lb)
{
    point pa = la.e-la.s;
    point pb = lb.e-lb.s;

    double thetapa = atan2(pa.y,pa.x);
    double thetapb = atan2(pb.y,pb.x);
    double theta = (thetapa-thetapb);
    if (cmp(theta,0) < 0)   theta += 2*pi;
    double fai = sqrt((double)(pb&pb)/(double)(pa&pa));

    //printf("theta = %.4f, fai = %.4f\n",theta/pi*180,fai);

    for (int i = 0; i < tota; i++)
    {
        point ps = a[i].s-la.s,pe = a[i].e-la.s;
        ps.transXY(-theta);
        pe.transXY(-theta);


        ps = point(ps.x*fai,ps.y*fai);
        pe = point(pe.x*fai,pe.y*fai);

        //output(line(ps,pe));
        //printf("\n");

        ps = ps+la.s;
        pe = pe+la.s;

        if (mp.find(line(ps,pe)) == mp.end() &&
            mp.find(line(pe,ps)) == mp.end())
                return false;

    }
    return true;
}

int main()
{
    /*point tmp = point(0,1);
    tmp.transXY(-pi/2);
    printf("%.4f %.4f\n",tmp.x,tmp.y);*/
    while (true)
    {
        if (Gao(a,tota) == false)   break;
        Gao(b,totb);

        if (tota != totb)
            puts("NO");
        else
        {
            mp.clear();
            for (int i = 0; i < totb; i++)
                mp.insert(b[i]);
            bool hasres = false;
            for (int i = 0; i < totb; i++)
            {
                if (wa(a[0],line(b[i].s,b[i].e)) ||
                        wa(a[0],line(b[i].e,b[i].s)))
                {
                    hasres = true;
                    break;
                }
            }
            if (hasres == true)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}
