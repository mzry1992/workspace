#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

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
    friend bool operator < (const Point& a,const Point& b)
    {
        if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
        return cmp(a.x,b.x) < 0;
    }
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
};

struct Line
{
    Point s,e;
    double k;
    Line(){}
    Line(Point _s,Point _e)
        {
            s = _s;
            e = _e;
            k = atan2(e.y-s.y,e.x-s.x);
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

Point p[100];
int n;

struct Edge
{
    int to,next;
};
Edge g[400];
int mem[400],top;

void addedge(int u,int v)
{
    int L = mem[--top];
    g[L].to = v;
    g[L].next = g[u].next;
    g[u].next = L;
    L = mem[--top];
    g[L].to = u;
    g[L].next = g[v].next;
    g[v].next = L;
}

void deledge(int u,int v)
{
    int pre = u;
    for (int i = pre;i != -1;i = g[i].next)
    {
        if (g[i].to == v)
        {
            g[pre].next = g[i].next;
            mem[top++] = i;
            break;
        }
        pre = i;
    }
    pre = v;
    for (int i = pre;i != -1;i = g[i].next)
    {
        if (g[i].to == u)
        {
            g[pre].next = g[i].next;
            mem[top++] = i;
            break;
        }
        pre = i;
    }
}

void Delaunay(int l,int r)
{
    if (r-l+1 <= 3)
    {
        addedge(l,r);
        if (r-l+1 == 3)
        {
            addedge(l,l+1);
            addedge(l+1,r);
        }
    }
    else
    {
        int mid = (l+r)>>1;
        Delaunay(l,mid);
        Delaunay(mid+1,r);
        int pl,pr;
        pl = l;
        pr = r;
        for (int i = l;i <= mid;i++)
            if (cmp(p[i].y,p[pl].y) < 0)
                pl = i;
        for (int i = mid+1;i <= r;i++)
            if (cmp(p[i].y,p[pr].y) < 0)
                pr = i;
        double miny;
        int minid,toid,typ;
        Point xp,midp,midp2;
        midp = Point((p[pl].x+p[pr].x)/2.0,(p[pl].y+p[pr].y)/2.0);
        midp2 = Point(midp.x+(p[pr].y-p[pl].y),midp.y-(p[pr].x-p[pl].x));
        Line midline = Line(midp,midp2);
        miny = 1e100;
        while (true)
        {
            for (int i = g[pl].next;i != -1;i = g[i].next)
            {
                toid = g[i].to;
                midp = Point((p[pl].x+p[toid].x)/2.0,(p[pl].y+p[toid].y)/2.0);
                midp2 = Point(midp.x+(p[toid].y-p[pl].y),midp.y-(p[toid].x-p[pl].x));
                xp = LineToLine(midline,Line(midp,midp2));
                if (cmp(xp.y,miny) < 0)
                {
                    miny = xp.y;
                    minid = toid;
                    typ = 0;
                }
            }
            for (int i = g[pr].next;i != -1;i = g[i].next)
            {
                toid = g[i].to;
                midp = Point((p[pr].x+p[toid].x)/2.0,(p[pr].y+p[toid].y)/2.0);
                midp2 = Point(midp.x+(p[toid].y-p[pr].y),midp.y-(p[toid].x-p[pr].x));
                xp = LineToLine(midline,Line(midp,midp2));
                if (cmp(xp.y,miny) < 0)
                {
                    miny = xp.y;
                    minid = toid;
                    typ = 1;
                }
            }

        }
    }
}

void Voronoi()
{
    for (int i = 0;i < n;i++)
        g[i].next = -1;
    top = 0;
    for (int i = n;i < 400;i++)
        mem[top++] = i;
    sort(p,p+n);
    Delaunay(0,n-1);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        Voronoi();
    }
    return 0;
}
