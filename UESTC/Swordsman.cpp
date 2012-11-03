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

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

int n,p0,p1;
Point p[20000],pre,now,ts,te;
Line sym;
bool visit[20000];

double xmult(Point a,Point b)
{
    return a.x*b.y-b.x*a.y;
}

double pmult(Point a,Point b)
{
    return a.x*b.x+a.y*b.y;
}

bool PointOnLine(Point a,Line b)
{
    if (cmp(xmult(Point(b.s,a),Point(b.s,b.e)),0.0) == 0)   return true;
    return false;
}
int wg;
char ch;
bool ng;

inline int readint()
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))    ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
        {
            p[i].x = 1.0*readint();
            p[i].y = 1.0*readint();
        }
        bool res = false;
        for (int i = 0;i < n;i++)
        {
            //case 1
            p0 = (i-1+n)%n;
            p1 = (i+1)%n;
            sym.s = p[i];
            if (n%2 == 0)
                sym.e = p[(i+n/2)%n];
            else
            {
                pre = p[(i+n/2)%n];
                now = p[(i+n/2+1)%n];
                sym.e = Point((pre.x+now.x)/2.0,(pre.y+now.y)/2.0);
            }
            if (true)
            {
                bool tres = true;
                memset(visit,false,sizeof(visit));
                int tim = n;
                if (n%2 == 1 && cmp(pmult(Point(pre,now),Point(sym.s,sym.e)),0.0) != 0)
                    tres = false;
                while (tim--)
                {
                    if (tres == false)  break;
                    if (cmp(pmult(Point(p[p0],p[p1]),Point(sym.s,sym.e)),0.0) != 0)
                        tres = false;
                    if (PointOnLine(Point((p[p0].x+p[p1].x)/2.0,(p[p0].y+p[p1].y)/2.0),sym) == false)
                        tres = false;
                    p0 = (p0-1+n)%n;
                    p1 = (p1+1)%n;
                }
                if (tres == true)
                {
                    res = true;
                    break;
                }
            }
            //case 2
            p0 = i;
            p1 = (i+1)%n;
            pre = p[p0];
            now = p[p1];
            sym.s = Point((pre.x+now.x)/2.0,(pre.y+now.y)/2.0);
            if (n%2 == 0)
            {
                pre = p[(i+n/2)%n];
                now = p[(i+1+n/2)%n];
                sym.e = Point((pre.x+now.x)/2.0,(pre.y+now.y)/2.0);
            }
            else
                sym.e = p[(i+n/2)%n];
            if (true)
            {
                bool tres = true;
                int tim = n;
                if (n%2 == 0 && cmp(pmult(Point(pre,now),Point(sym.s,sym.e)),0.0) != 0)
                    tres = false;
                while (tim--)
                {
                    if (tres == false)  break;
                    if (cmp(pmult(Point(p[p0],p[p1]),Point(sym.s,sym.e)),0.0) != 0)
                        tres = false;
                    if (PointOnLine(Point((p[p0].x+p[p1].x)/2.0,(p[p0].y+p[p1].y)/2.0),sym) == false)
                        tres = false;
                    p0 = (p0-1+n)%n;
                    p1 = (p1+1)%n;
                }
                if (tres == true)
                {
                    res = true;
                    break;
                }
            }
        }
        if (res == true)    printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
