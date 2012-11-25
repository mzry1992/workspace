#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-6;

struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x,y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
    double operator &(const Point& b)const
    {
        return x*b.x+y*b.y;
    }
    Point Rotate(double B)
    {
        return Point(x*cos(B)-y*sin(B),x*sin(B)+y*cos(B));
    }
};

Point p[200];
int n,m;

inline double dist2(Point a,Point b)
{
    return (a-b)&(a-b);
}

inline double dist2(Point p1,Point p2,Point p)
{
    Point res;
    double a,b,t;
    a = p2.x-p1.x;
    b = p2.y-p1.y;
    t = ((p.x-p1.x)*a+(p.y-p1.y)*b)/(a*a+b*b);
    res.x = p1.x+a*t;
    res.y = p1.y+b*t;
    return dist2(p,res);
}

inline int calc(Point a,Point b,double r)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        if (dist2(a,b,p[i]) <= r*r+eps)
            res++;
    return res;
}

inline int calc(double r)
{
    r += 0.5;
    int res = 1;
    for (int i = pa; i < n; i++)
        for (int j = pb; j < n; j++)
        {
            Point v = p[j]-p[i],tv,xa,xb;
            tv = Point(v.y,-v.x);
            double tvlen = sqrt(tv&tv);
            double vlen2 = v&v;

            xa = Point(p[i].x+r*tv.x/tvlen,p[i].y+r*tv.y/tvlen);
            xb = Point(p[j].x+r*tv.x/tvlen,p[j].y+r*tv.y/tvlen);
            res = max(res,calc(xa,xb,r));

            xa = Point(p[i].x-r*tv.x/tvlen,p[i].y-r*tv.y/tvlen);
            xb = Point(p[j].x-r*tv.x/tvlen,p[j].y-r*tv.y/tvlen);
            res = max(res,calc(xa,xb,r));

            if (dist2(p[i],p[j]) > 4*r*r)
            {

                double theta = acos(r/sqrt(vlen2));
                tv = v.Rotate(theta);
                tvlen = sqrt(tv&tv);
                xa = Point(p[i].x+r*tv.x/tvlen,p[i].y+r*tv.y/tvlen);
                xb = Point(p[j].x-r*tv.x/tvlen,p[j].y-r*tv.y/tvlen);
                res = max(res,calc(xa,xb,r));

                tv = v.Rotate(-theta);
                tvlen = sqrt(tv&tv);
                xa = Point(p[i].x+r*tv.x/tvlen,p[i].y+r*tv.y/tvlen);
                xb = Point(p[j].x-r*tv.x/tvlen,p[j].y-r*tv.y/tvlen);
                res = max(res,calc(xa,xb,r));
            }
            if (res >= m)
                return res;
        }
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    double l,r,mid;
    l = 0;
    r = 1e6;
    for (int tim = 0; tim < 50; tim++)
    {
        mid = (l+r)/2;
        if (calc(mid) < m)
            l = mid;
        else
            r = mid;
    }
    printf("%.10f\n",l*2+1e-8);
    return 0;
}
