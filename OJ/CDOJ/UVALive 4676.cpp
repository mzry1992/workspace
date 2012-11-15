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
    double Length()
        {
            return sqrt(x*x+y*y);
        }
};

Point r1[3],r2[3],v1,v2;
double res;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double pmult(Point a,Point b)
{
    return a.x*b.x+a.y*b.y;
}

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
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

void Gao(Point r1[3],Point r2[3],Point v1,Point v2)
{
    Point v,xp;
    double len;
    v.x = v1.x-v2.x;
    v.y = v1.y-v2.y;
    if (cmp(v.Length(),0.0) == 0)   return;
    for (int i = 0;i < 3;i++)
        for (int j = 0;j < 3;j++)
            if (cmp(xmult(v,Point(r1[i],r2[j])),0.0)*cmp(xmult(v,Point(r1[i],r2[(j+1)%3])),0.0) <= 0)
                if (cmp(pmult(v,Point(r1[i],r2[j])),0.0) >= 0 || cmp(pmult(v,Point(r1[i],r2[(j+1)%3])),0.0) >= 0)
                    if (cmp(xmult(Point(r1[i],r2[j]),Point(r1[i],r2[(j+1)%3])),xmult(Point(v,Point(r1[i],r2[j])),Point(v,Point(r1[i],r2[(j+1)%3])))) != 0)
                    {
                        xp = LineToLine(Line(r1[i],Point(r1[i].x+v.x,r1[i].y+v.y)),
                                        Line(r2[j],r2[(j+1)%3]));
                        len = Point(r1[i],xp).Length();
                        res = min(res,len/v.Length());
                    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        for (int i = 0;i < 3;i++)   scanf("%lf%lf",&r1[i].x,&r1[i].y);
        scanf("%lf%lf",&v1.x,&v1.y);
        for (int i = 0;i < 3;i++)   scanf("%lf%lf",&r2[i].x,&r2[i].y);
        scanf("%lf%lf",&v2.x,&v2.y);
        res = 1e20;
        Gao(r1,r2,v1,v2);
        Gao(r2,r1,v2,v1);
        if (cmp(res,1e20) == 0)  puts("NO COLLISION");
        else    printf("%.12f\n",res);
    }
    return 0;
}
