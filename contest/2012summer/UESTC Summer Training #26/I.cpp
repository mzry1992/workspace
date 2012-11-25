#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Point
{
    double x, y;
    Point () {}
    Point ( double _x , double _y)
    {
        x = _x , y = _y;
    }
    Point operator -( const Point &b) const
    {
        return Point (x - b.x, y - b.y);
    }
    double operator *( const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    double operator &( const Point &b) const
    {
        return x * b.x + y * b.y;
    }
    void transXY(double B)
    {
        double tx = x,ty = y;
        x = tx*cos(B)-ty*sin(B);
        y = tx*sin(B)+ty*cos(B);
    }
};

struct Line
{
    Point s, e;
    double k;
    Line () {}
    Line ( Point _s , Point _e)
    {
        s = _s , e = _e;
        k = atan2 (e.y - s.y, e.x - s.x);
    }
    Point operator &( const Line &b) const
    {
        Point res = s;
        double t = ((s - b.s) * (b.s - b.e)) /
                   ((s - e) * (b.s - b.e));
        res .x += (e.x - s.x) * t;
        res .y += (e.y - s.y) * t;
        return res ;
    }
};

double dist2(Point a,Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int sgn(double x)
{
    if (fabs(x) < 1e-8) x = 0;
    if (x < 0)  return -1;
    return 1;
}

double r,n;
Line l[2];

int main()
{
    while (scanf("%lf%lf",&r,&n) != EOF)
    {
        for (int i = 0; i < 2; i++)
        {
            Point a,tv;
            scanf("%lf%lf%lf%lf",&a.x,&a.y,&tv.x,&tv.y);
            Point b = Point(a.x+tv.x,a.y+tv.y);
            Point near = Line(a,b)&Line(Point(0,0),Point(tv.y,-tv.x));
            double B = r*r-(near&near);
            double tmp = sqrt(B/(tv&tv));
            Point xp = Point(near.x-tmp*tv.x,near.y-tmp*tv.y),
                       txp = Point(near.x+tmp*tv.x,near.y+tmp*tv.y);
            if (dist2(txp,a) < dist2(xp,a))
                xp = txp;
            Point pa = xp,pb = a-xp;
            double stheta = (pa*pb)/sqrt(dist2(pa,Point(0,0))*dist2(pb,Point(0,0)));
            double theta = asin(stheta/n);

            pb = pa = Point(-xp.x,-xp.y);
            pb.transXY(theta);

            l[i] = Line(xp,Point(xp.x+pb.x,xp.y+pb.y));

            //printf("(%.2f %.2f) (%.2f %.2f)\n",l[i].s.x,l[i].s.y,l[i].e.x,l[i].e.y);
            //printf("%.2f %.2f\n",xp.x,xp.y);
        }
        if (fabs((l[0].s-l[0].e)*(l[1].s-l[1].e)) < 1e-8)
        {
            if (fabs((l[0].s-l[0].e)*(l[1].s-l[0].e)) < 1e-8)
                puts("Yes");
            else
                puts("No");
        }
        else
        {
            Point xp = l[0]&l[1];
            //printf("%.2f %.2f\n",xp.x,xp.y);
            if (dist2(xp,Point(0,0)) < r*r)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}
