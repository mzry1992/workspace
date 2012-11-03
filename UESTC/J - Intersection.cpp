#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-8;
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

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool EQ(double a,double b)
{
    return fabs(a-b) < eps;
}

bool BT(double a,double b)
{
    return a-b > eps;
}

bool EBT(double a,double b)
{
    return EQ(a,b) || BT(a,b);
}

bool OnSeg(Point a,Line b)
{
    if (EQ(xmult(Point(a,b.s),Point(a,b.e)),0.0) == false)  return false;
    return (EBT(a.x,min(b.s.x,b.e.x)) && EBT(max(b.s.x,b.e.x),a.x) &&
            EBT(a.y,min(b.s.y,b.e.y)) && EBT(max(b.s.y,b.e.y),a.y));
}

bool Cross(Line a,Line b)
{
    if (OnSeg(a.s,b) || OnSeg(a.e,b) || OnSeg(b.s,a) || OnSeg(b.e,a))   return true;
    if (EQ(xmult(Point(a.s,a.e),Point(b.s,b.e)),0.0) == true)   return false;
    if (BT(min(b.s.x,b.e.x),max(a.s.x,a.e.x)) || BT(min(a.s.x,a.e.x),max(b.s.x,b.e.x))) return false;
    if (BT(min(b.s.y,b.e.y),max(a.s.y,a.e.y)) || BT(min(a.s.y,a.e.y),max(b.s.y,b.e.y))) return false;
    if (BT(xmult(Point(a.s,a.e),Point(a.s,b.e))*xmult(Point(a.s,a.e),Point(a.s,b.s)),0.0)||
        BT(xmult(Point(b.s,b.e),Point(b.s,a.e))*xmult(Point(b.s,b.e),Point(b.s,a.s)),0.0)) return false;
    return true;
}

bool CheckIn(Point a,Point lb,Point rt)
{
    return (EBT(a.x,lb.x) && EBT(rt.x,a.x) && EBT(a.y,lb.y) && EBT(rt.y,a.y));
}

Point p1,p2;
Line seg,ret[4];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
        seg = Line(p1,p2);
        scanf("%lf%lf%lf%lf",&p1.x,&p1.y,&p2.x,&p2.y);
        ret[0] = Line(Point(min(p1.x,p2.x),min(p1.y,p2.y)),Point(max(p1.x,p2.x),min(p1.y,p2.y)));
        ret[1] = Line(Point(max(p1.x,p2.x),min(p1.y,p2.y)),Point(max(p1.x,p2.x),max(p1.y,p2.y)));
        ret[2] = Line(Point(max(p1.x,p2.x),max(p1.y,p2.y)),Point(min(p1.x,p2.x),max(p1.y,p2.y)));
        ret[3] = Line(Point(min(p1.x,p2.x),max(p1.y,p2.y)),Point(min(p1.x,p2.x),min(p1.y,p2.y)));
        bool flag = false;
        for (int i = 0;i < 4;i++)
            if (Cross(seg,ret[i]) == true)
               flag = true;
        if (CheckIn(seg.s,ret[0].s,ret[1].e) == true && CheckIn(seg.e,ret[0].s,ret[1].e) == true)   flag = true;
        if (flag == true)   printf("T\n");
        else printf("F\n");
    }
}
