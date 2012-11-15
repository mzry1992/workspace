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

bool OnSeg(Point a,Line b)
{
    if (cmp(xmult(Point(a,b.s),Point(a,b.e)),0.0) != 0)  return false;
    return (cmp(a.x,min(b.s.x,b.e.x)) >= 0 && cmp(max(b.s.x,b.e.x),a.x) >= 0 &&
            cmp(a.y,min(b.s.y,b.e.y)) >= 0 && cmp(max(b.s.y,b.e.y),a.y) >= 0);
}

bool Cross(Line a,Line b)
{
    if (OnSeg(a.s,b) || OnSeg(a.e,b) || OnSeg(b.s,a) || OnSeg(b.e,a))   return true;
    if (cmp(xmult(Point(a.s,a.e),Point(b.s,b.e)),0.0) == 0)   return false;
    if (cmp(min(b.s.x,b.e.x),max(a.s.x,a.e.x)) > 0 || cmp(min(a.s.x,a.e.x),max(b.s.x,b.e.x)) > 0) return false;
    if (cmp(min(b.s.y,b.e.y),max(a.s.y,a.e.y)) > 0 || cmp(min(a.s.y,a.e.y),max(b.s.y,b.e.y)) > 0) return false;
    if (cmp(xmult(Point(a.s,a.e),Point(a.s,b.e))*xmult(Point(a.s,a.e),Point(a.s,b.s)),0.0) > 0 ||
        cmp(xmult(Point(b.s,b.e),Point(b.s,a.e))*xmult(Point(b.s,b.e),Point(b.s,a.s)),0.0) > 0) return false;
    return true;
}

Line l[20];
int n,x,y;
bool mp[20][20];

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 1;i <= n;i++)
            scanf("%lf%lf%lf%lf",&l[i].s.x,&l[i].s.y,&l[i].e.x,&l[i].e.y);
        memset(mp,false,sizeof(mp));
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                mp[i][j] = Cross(l[i],l[j]);
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                    if (mp[i][k] && mp[k][j])
                        mp[i][j] = true;
        while (true)
        {
            scanf("%d%d",&x,&y);
            if (x == 0 && y == 0)   break;
            if (mp[x][y] == true)
                printf("CONNECTED\n");
            else
                printf("NOT CONNECTED\n");
        }
    }
    return 0;
}
