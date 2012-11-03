#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-10;
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

Point r1[3],r2[3],v1,v2,xp;
Line l1,l2;

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double xmult(Line a,Line b)
{
    return xmult(Point(a.s,a.e),Point(b.s,b.e));
}

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

bool OnSeg(Point a,Line b)
{
    if (cmp(xmult(Point(a,b.s),Point(a,b.e)),0.0) != 0)  return false;
    return (cmp(a.x,min(b.s.x,b.e.x)) >= 0 && cmp(max(b.s.x,b.e.x),a.x) >= 0 &&
            cmp(a.y,min(b.s.y,b.e.y)) >= 0 && cmp(max(b.s.y,b.e.y),a.y) >= 0);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        for (int i = 0;i < 3;i++)
            scanf("%lf%lf",&r1[i].x,&r1[i].y);
        scanf("%lf%lf",&v1.x,&v1.y);
        for (int i = 0;i < 3;i++)
            scanf("%lf%lf",&r2[i].x,&r2[i].y);
        scanf("%lf%lf",&v2.x,&v2.y);
        v1.x -= v2.x;
        v1.y -= v2.y;
        double res = 1e100;
        bool flag = false;
        double speed = v1.Length();
        if (cmp(speed,0.0) > 0)
        {
            for (int i = 0;i < 3;i++)
            {
                l1 = Line(r1[i],Point(r1[i].x+v1.x,r1[i].y+v1.y));
                double curmin = 1e100;
                bool tflag = false;
                for (int j = 0;j < 3;j++)
                {
                    l2 = Line(r2[j],r2[(j+1)%3]);
                    if (cmp(xmult(l1,l2),0.0) == 0) continue;
                    xp = LineToLine(l1,l2);
                    if (OnSeg(xp,l2) == false)  continue;
                    if (cmp(v1.x,0.0) != 0)
                        if (cmp(Point(r1[i],xp).x/v1.x,0.0) < 0)    continue;
                    if (cmp(v1.y,0.0) != 0)
                        if (cmp(Point(r1[i],xp).y/v1.y,0.0) < 0)    continue;
                    curmin = min(curmin,Point(r1[i],xp).Length());
                    tflag = true;
                }
                if (tflag == true)
                {
                    res = min(res,curmin/speed);
                    flag = true;
                }
            }
        }
        if (flag == true)
            printf("%.9f\n",res);
        else
            puts("NO COLLISION");
    }
    return 0;
}
