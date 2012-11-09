#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x,y;
    Point(){}
    Point (int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    int operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
    int operator &(const Point& b)const
    {
        return x*b.x+y*b.y;
    }
};

int sgn(int x)
{
    if (x > 0)  return 1;
    if (x == 0) return 0;
    return -1;
}

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

bool inter(Line l1,Line l2)
{
    return
    max(l1.s.x,l1.e.x) > min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) > min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l2.e.y) > min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) > min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.s)*(l1.e-l1.s))*sgn((l2.e-l1.s)*(l1.e-l1.s)) < 0 &&
    sgn((l1.s-l2.s)*(l2.e-l2.s))*sgn((l1.e-l2.s)*(l2.e-l2.s)) < 0;
}
bool OnSeg(Line a,Point b)
{
    return ((a.s-b)*(a.e-b) == 0 && (b.x-a.s.x)*(b.x-a.e.x) <= 0 && (b.y-a.s.y)*(b.y-a.e.y) <= 0);
}

double dist(Point a,Point b)
{
    return sqrt(1.0*((a-b)&(a-b)));
}

struct Edge
{
    int u,v;
    double w;
    Edge(){}
    Edge(int _u,int _v,double _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator <(const Edge& b)const
    {
        return w < b.w;
    }
};
Edge edge[2500];
int tote;
int n;
Point p[50];
int f[50];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        int ida,idb;
        scanf("%d%d",&ida,&idb);
        ida--;
        idb--;

        for (int i = 0;i < n;i++)
        {
            f[i] = i;
            scanf("%d%d",&p[i].x,&p[i].y);
        }

        double ans = dist(p[ida],p[idb]);
        f[findf(ida)] = findf(idb);
        for (int i = 0;i < n;i++)
            if (OnSeg(Line(p[ida],p[idb]),p[i]))
                f[findf(i)] = findf(ida);

        tote = 0;
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                if (inter(Line(p[ida],p[idb]),Line(p[i],p[j])) == false)
                    edge[tote++] = Edge(i,j,dist(p[i],p[j]));
        sort(edge,edge+tote);

        for (int i = 0;i < tote;i++)
        {
            int u = edge[i].u;
            int v = edge[i].v;
            double w = edge[i].w;

            if (findf(u) != findf(v))
            {
                ans += w;
                f[findf(u)] = findf(v);
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}

