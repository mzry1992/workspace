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

        tote = 0;
        edge[tote++] = Edge(ida,idb,-1);

        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                edge[tote++] = Edge(i,j,dist(p[i],p[j]));
        sort(edge,edge+tote);

        double ans = 0;
        for (int i = 0;i < tote;i++)
        {
            int u = edge[i].u;
            int v = edge[i].v;
            double w = edge[i].w;

            if (findf(u) != findf(v))
            {
                if (w < 0)
                    w = dist(p[u],p[v]);
                ans += w;
                f[findf(u)] = findf(v);
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}

