#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
    point(point s,point e)
    {
        x = e.x-s.x;
        y = e.y-s.y;
    }
    double Length()
    {
        return sqrt(x*x+y*y);
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
};

double xmult(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}

point LineToLine(line a,line b)
{
    point res = a.s;
    double t =
        xmult(point(b.s,a.s),point(b.e,b.s))/xmult(point(a.e,a.s),point(b.e,b.s));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

point p[3],tp,mid;
line l[2];
char tmp[1000];
double r,theta[3];

double fixit(double a)
{
    if (cmp(a,0) < 0)   a += 2*pi;
    if (cmp(a,2*pi) > 0)    a -= 2*pi;
    return a;
}

int main()
{
    while (true)
    {
        scanf("%s",tmp);
        if (strcmp(tmp,"END") == 0)  break;
        sscanf(tmp,"%lf",&p[0].x);
        scanf("%lf",&p[0].y);
        for (int i = 1; i < 3; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        tp = point((p[0].x+p[1].x)/2,(p[0].y+p[1].y)/2);
        l[0] = line(tp,point(tp.x-(p[1].y-p[0].y),tp.y+(p[1].x-p[0].x)));
        tp = point((p[0].x+p[2].x)/2,(p[0].y+p[2].y)/2);
        l[1] = line(tp,point(tp.x-(p[2].y-p[0].y),tp.y+(p[2].x-p[0].x)));
        tp = LineToLine(l[0],l[1]);
        r = point(tp,p[0]).Length();
        mid = tp;
        for (int i = 0;i < 3;i++)
        {
            tp = point(mid,p[i]);
            theta[i] = atan2(tp.y,tp.x);
        }
        double ta = fixit(theta[1]-theta[0]);
        double tb = fixit(theta[2]-theta[1]);
        for (int i = 3;i <= 1000;i++)
        {
            double x = (ta*i)/(2*pi);
            double y = (tb*i)/(2*pi);
            if (cmp(x,floor(x+0.5)) == 0 && cmp(y,floor(y+0.5)) == 0)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
