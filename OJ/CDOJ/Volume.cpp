#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
double r,h,res,tmp;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y;
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
};
struct Line
{
    Point s,e;
    double k;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
        k = atan2(e.y-s.y,e.x-s.x);
    }
};

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

bool OnSeg(Line a,Point b)
{
    return (cmp(xmult(Point(b,a.s),Point(b,a.e)),0.0) == 0 &&
           cmp((b.x-a.s.x)*(b.x-a.e.x),0.0) <= 0 &&
           cmp((b.y-a.s.y)*(b.y-a.e.y),0.0) <= 0);
}

bool InCircle(Point a,double r)
{
    return cmp(a.x*a.x+a.y*a.y,r*r) <= 0; //这里判断的时候EPS一定不要太小！！
}

double CalcArea(Point a,Point b,double r)
{
    Point p[4];
    int tot = 0;
    p[tot++] = a;

    Point tv = Point(a,b);
    Line tmp = Line(Point(0,0),Point(tv.y,-tv.x));
    Point near = LineToLine(Line(a,b),tmp);
    if (cmp(near.x*near.x+near.y*near.y,r*r) <= 0)
    {
        double A,B,C;
        A = near.x*near.x+near.y*near.y;
        C = r;
        B = C*C-A;
        double tvl = tv.x*tv.x+tv.y*tv.y;
        double tmp = sqrt(B/tvl); //这样做只用一次开根
        p[tot] = Point(near.x+tmp*tv.x,near.y+tmp*tv.y);
        if (OnSeg(Line(a,b),p[tot]) == true)    tot++;
        p[tot] = Point(near.x-tmp*tv.x,near.y-tmp*tv.y);
        if (OnSeg(Line(a,b),p[tot]) == true)    tot++;
    }
    if (tot == 3)
    {
        if (cmp(Point(p[0],p[1]).Length(),Point(p[0],p[2]).Length()) > 0)
            swap(p[1],p[2]);
    }
    p[tot++] = b;

    double res = 0.0,theta,a0,a1,sgn;
    for (int i = 0;i < tot-1;i++)
    {
        if (InCircle(p[i],r) == true && InCircle(p[i+1],r) == true)
        {
            res += 0.5*xmult(p[i],p[i+1]);
        }
        else
        {
            a0 = atan2(p[i+1].y,p[i+1].x);
            a1 = atan2(p[i].y,p[i].x);
            if (a0 < a1)    a0 += 2*pi;
            theta = a0-a1;
            if (cmp(theta,pi) >= 0) theta = 2*pi-theta;
            sgn = xmult(p[i],p[i+1])/2.0;
            if (cmp(sgn,0) < 0) theta = -theta;
            res += 0.5*r*r*theta;
        }
    }
    return res;
}

double calc(double x)
{
    double a = sqrt(r*r-x*x)*2;
    double b = h;
    if (cmp(a*a+b*b,4*r*r) <= 0)    return a*b;
    double res = 0.0;
    res += CalcArea(Point(-0.5*a,-0.5*b),Point(0.5*a,-0.5*b),r);
    res += CalcArea(Point(0.5*a,-0.5*b),Point(0.5*a,0.5*b),r);
    res += CalcArea(Point(0.5*a,0.5*b),Point(-0.5*a,0.5*b),r);
    res += CalcArea(Point(-0.5*a,0.5*b),Point(-0.5*a,-0.5*b),r);
    return res;
}

double Simp(double l,double r)
{
    double h = (r-l)/2.0;
    return h*(calc(l)+4*calc((l+r)/2.0)+calc(r))/3.0;
}

double rSimp(double l,double r)
{
    double mid = (l+r)/2.0;
    if (abs((Simp(l,r)-Simp(l,mid)-Simp(mid,r)))/15 < eps)
        return Simp(l,r);
    else
        return rSimp(l,mid)+rSimp(mid,r);
}

int main()
{
    while (scanf("%lf%lf",&r,&h) != EOF)
    {
        tmp = min(0.5*h,r);
        res = pi*r*r*h*2.0;
        res -= rSimp(-tmp,tmp);
        printf("%.4f\n",res);
    }
    return 0;
}
