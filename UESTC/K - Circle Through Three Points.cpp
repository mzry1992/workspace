#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Point
{
    double x,y;
    Point(){}
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
    double len()
        {
            return sqrt(x*x+y*y);
        }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
        {
            s = _s;
            e = _e;
        }
};

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t
            = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/
                ((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

Point p0,p1,p2,cc,ts,te;
Line l0,l1;
double h,k,r,c,d,e;

int main()
{
    while (scanf("%lf%lf%lf%lf%lf%lf",&p0.x,&p0.y,&p1.x,&p1.y,&p2.x,&p2.y) != EOF)
    {
        ts = Point(p0.x+(p1.x-p0.x)/2.0,p0.y+(p1.y-p0.y)/2.0);
        te = Point(ts.x+(p1.y-p0.y),ts.y-(p1.x-p0.x));
        l0 = Line(ts,te);
        ts = Point(p0.x+(p2.x-p0.x)/2.0,p0.y+(p2.y-p0.y)/2.0);
        te = Point(ts.x+(p2.y-p0.y),ts.y-(p2.x-p0.x));
        l1 = Line(ts,te);
        cc = LineToLine(l0,l1);
        h = cc.x;
        k = cc.y;
        r = Point(cc,p0).len();
        c = -2*h;
        d = -2*k;
        e = -(h*h+k*k-r*r);
        printf("(x %c %.3f)^2 + (y %c %.3f)^2 = %.3f^2\n",(h > 0.0)?'-':'+',fabs(h),(k > 0.0)?'-':'+',fabs(k),r);
        printf("x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n",(c < 0.0)?'-':'+',fabs(c),(d < 0.0)?'-':'+',fabs(d),(e > 0.0)?'-':'+',fabs(e));
        printf("\n");
    }
    return 0;
}
