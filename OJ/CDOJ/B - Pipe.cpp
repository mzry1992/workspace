#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double eps = 1e-8;
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

double CalcY(Line l,double x,double y)
{
    return (x-l.s.x)*(l.e.y-l.s.y)/(l.e.x-l.s.x)+l.s.y;
}

bool CheckIn(Line l,double x,double y)
{
    double ty = CalcY(l,x,y);
    return cmp(ty,y) <= 0 && cmp(y-1,ty) <= 0;
}

int n;
Point p[25],tp;
Line l;
double res;

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        res = p[0].x;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (i != j)
                {
                    l = Line(p[i],Point(p[j].x,p[j].y-1.0));
                    bool hascross = false;
                    for (int k = 0;k < n;k++)
                        if (CheckIn(l,p[k].x,p[k].y) == false)
                        {
                            hascross = true;
                            if (k == 0) break;
                            double ty = CalcY(l,p[k].x,p[k].y);
                            if (cmp(ty,p[k].y) > 0)
                                tp = LineToLine(l,Line(p[k-1],p[k]));
                            else
                                tp = LineToLine(l,Line(Point(p[k-1].x,p[k-1].y-1),Point(p[k].x,p[k].y-1)));
                            res = max(res,tp.x);
                            break;
                        }
                    if (hascross == false)
                        res = p[n-1].x+1.0;
                }
        if (cmp(res,p[n-1].x) >= 0)
            puts("Through all the pipe.");
        else
            printf("%.2f\n",res);
    }
    return 0;
}
