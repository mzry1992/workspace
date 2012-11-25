#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
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

struct Point
{
    double x,y;
    Point() {}
    Point (double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point (Point _s,Point _e)
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
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
};

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/
               ((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool OnSeg(Line a,Point b)
{
    return (cmp(xmult(Point(b,a.s),Point(b,a.e)),0) == 0 &&
            cmp((b.x-a.s.x)*(b.x-a.e.x),0) <= 0 &&
            cmp((b.y-a.s.y)*(b.y-a.e.y),0) <= 0);
}

bool InCircle(Point a,double r)
{
    return cmp(a.x*a.x+a.y*a.y,r*r) <= 0;
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
        double tmp = sqrt(B/tvl);
        p[tot] = Point(near.x+tmp*tv.x,near.y+tmp*tv.y);
        if (OnSeg(Line(a,b),p[tot]) == true)
            tot++;
        p[tot] = Point(near.x-tmp*tv.x,near.y-tmp*tv.y);
        if (OnSeg(Line(a,b),p[tot]) == true)
            tot++;
    }
    if (tot == 3)
    {
        if (cmp(Point(p[0],p[1]).Length(),Point(p[0],p[2]).Length()) > 0)
            swap(p[1],p[2]);
    }
    p[tot++] = b;

    double res = 0.0,theta,a0,a1,sgn;
    for (int i = 0; i < tot-1; i++)
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

    //printf("%d %.4f\n",tot,res);
    return res;
}

Point p0,p1,p[100];
double v0,theta,t,g,R;
int n;

int main()
{
    while (true)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf",&p0.x,&p0.y,&v0,&theta,&t,&g,&R);
        if (p0.x == 0 && p0.y == 0 && v0 == 0 && theta == 0 && t == 0 && g == 0 && R == 0)  break;

        theta = theta/180*pi;
        p1.x = p0.x+v0*cos(theta)*t;
        p1.y = p0.y+v0*sin(theta)*t-0.5*g*t*t;

        //printf("%.4f %.4f\n",p1.x,p1.y);

        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].x -= p1.x;
            p[i].y -= p1.y;

            //printf("(%.3f %.3f) ",p[i].x,p[i].y);
        }
        //printf("\n");

        double area = 0;
        for (int i = 0;i < n;i++)
            area += xmult(p[i],p[(i+1)%n]);
        if (cmp(area,0) < 0)
            reverse(p,p+n);
        double ans = 0;
        for (int i = 0; i < n; i++)
            ans += CalcArea(p[i],p[(i+1)%n],R);

        printf("%.2f\n",ans);
    }
    return 0;
}
