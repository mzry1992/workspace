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
}p[12][12];
int m,n[12];

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

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool OnSeg(Point a,Line b)
{
    if (cmp(xmult(Point(a,b.s),Point(a,b.e)),0.0) != 0)  return false;
    return (cmp(a.x,min(b.s.x,b.e.x)) >= 0 && cmp(max(b.s.x,b.e.x),a.x) >= 0 &&
            cmp(a.y,min(b.s.y,b.e.y)) >= 0 && cmp(max(b.s.y,b.e.y),a.y) >= 0);
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

bool Cross(Line a,Line b)
{
    Point xp = LineToLine(a,b);
    return OnSeg(xp,b);
}

int check(Point s,Point e)
{
    int res = 0;
    for (int i = 0;i < m;i++)
    {
        bool cut = false;
        for (int j = 0;j < n[i];j++)
            if (Cross(Line(s,e),Line(p[i][j],p[i][(j+1)%n[i]])) == true)
            {
                cut = true;
                break;
            }
        if (cut == true)    res++;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&m);
        for (int i = 0;i < m;i++)
        {
            scanf("%d",&n[i]);
            for (int j = 0;j < n[i];j++)
                scanf("%lf%lf",&p[i][j].x,&p[i][j].y);
        }
        int res = 0;
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n[i];j++)
                for (int k = 0;k < m;k++)
                    for (int q = 0;q < n[k];q++)
                        if (p[i][j].x != p[k][q].x || p[i][j].y != p[k][q].y)
                            res = max(res,check(p[i][j],p[k][q]));
        printf("Case %d: %d\n",ft,res);
    }
    return 0;
}
