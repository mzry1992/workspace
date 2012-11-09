#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-6;
const double pi = acos(-1.0);
struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
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
};
int sgn(double x)
{
    if (x > eps)    return 1;
    if (x < -eps)   return -1;
    return 0;
}
double dist(Point a,Point b)
{
    return sqrt((a-b)&(a-b));
}
double dist(Point p,Point ls,Point le)
{
    Point result;
    double a,b,t;

    a = le.x-ls.x;
    b = le.y-ls.y;
    t = ((p.x-ls.x)*a+(p.y-ls.y)*b)/(a*a+b*b);

    if (t >= 0 && t <= 1)
    {
        result.x = ls.x+a*t;
        result.y = ls.y+b*t;
    }
    else
    {
        if (dist(p,ls) < dist(p,le))
            result = ls;
        else
            result = le;
    }
    return dist(result,p);
}

Point s,c,ra,rb,rra,rrb;
double r;

int main()
{
    while (true)
    {
        scanf("%lf%lf",&s.x,&s.y);
        if (s.x == 0 && s.y == 0)   break;

        scanf("%lf%lf%lf",&c.x,&c.y,&r);
        scanf("%lf%lf%lf%lf",&rra.x,&rra.y,&rrb.x,&rrb.y);
        ra = Point(min(rra.x,rrb.x),min(rra.y,rrb.y));
        rb = Point(max(rra.x,rrb.x),max(rra.y,rrb.y));

        double ans = 1e100;

        int times = 1000000;
        double det = 2*pi/times;
        for (int div = 0; div < times; div++)
        {
            Point p = Point(r*cos(det*div)+c.x,r*sin(det*div)+c.y);
            double ret1 = dist(s,p);
            double ret2 = min(
                              min(
                                  dist(p,Point(ra.x,ra.y),Point(ra.x,rb.y)),
                                  dist(p,Point(ra.x,rb.y),Point(rb.x,rb.y))),
                              min(
                                  dist(p,Point(ra.x,rb.y),Point(rb.x,rb.y)),
                                  dist(p,Point(ra.x,ra.y),Point(rb.x,ra.y))));

            ans = min(ans,ret1+ret2);
        }
        printf("%.6f\n",ans);
    }
    return 0;
}


