#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    double x,y;
    Point(){}
    Point(Point _s,Point _e)
        {
            x = _e.x-_s.x;
            y = _e.y-_s.y;
        }
};
struct Line
{
    Point s,e;
};

Point p[4];
int a[4];

double CalcDis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double CalcDis(Point a)
{
    double res = 0;
    for (int i = 0;i < 4;i++)
        res += CalcDis(a,p[i]);
    return res;
}

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

int main()
{
    while (true)
    {
        for (int i = 0;i < 4;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            a[i] = i;
        }
        if (p[0].x < -1e-5) break;
        double res = 1e100,tres;
        Line l1,l2;
        for (int i = 0;i < 4;i++)
            res = min(res,CalcDis(p[i]));
        do
        {
            tres = 1e100;
            l1.s = p[a[0]];
            l1.e = p[a[1]];
            l2.s = p[a[2]];
            l2.e = p[a[3]];
            if (fabs(xmult(Point(l1.s,l2.s),Point(l1.s,l1.e))) > 1e-12)
                tres = CalcDis(LineToLine(l1,l2));
            res = min(res,tres);
        }
        while (next_permutation(a,a+4));
        printf("%.4f\n",res);
    }
    return 0;
}
