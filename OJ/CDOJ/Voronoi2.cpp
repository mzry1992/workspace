#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int MaxN = 10000;

const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    friend bool operator < (const Point& a,const Point& b)
    {
        if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
        return cmp(a.x,b.x) < 0;
    }
    friend double xmult(const Point& a,const Point& b)
    {
        return a.x*b.y-a.y*b.x;
    }
    double x,y;
    int id;
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

struct Edge
{
    int to,next;
};

Point p[MaxN];
int n,mem[MaxN+MaxN*MaxN],top;
Edge g[MaxN+MaxN*MaxN];

void Addedge(int u,int v)
{
    int L = mem[--top];
    g[L].to = v;
    g[L].next = g[u].next;
    g[u].next = L;
}

void Deledge(int u,int v)
{
    for (int pre,cur = u;cur != -1;cur = g[cur].next)
    {
        if (g[cur].to == v)
        {
            g[pre].next = g[cur].next;
            break;
        }
        pre = cur;
    }
}

bool Conline(Point a,Point b,Point c)
{
    return cmp(xmult(Point(a,b),Point(a,c)),0.0) == 0;
}

int used[MaxN],a[MaxN];
bool check[MaxN];

void Voronoi(int l,int r)
{
    if (l == r) return;
    else if (l == r-1)
    {
        Addedge(l,r);
        Addedge(r,l);
    }
    else if (l == r-2)
    {
        Addedge(l,l+1); Addedge(l+1,l);
        Addedge(l+1,r); Addedge(r,l+1);
        if (Conline(p[l],p[l+1],p[r]) == false)
        {
            Addedge(r,l);
            Addedge(l,r);
        }
    }
    else
    {
        int mid = (l+r)>>1;
        Voronoi(l,mid);
        Voronoi(mid+1,r);
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            p[i].id = i;
            g[i].next = g[i].to = -1;
        }
        sort(p,p+n);
        top = 0;
        for (int i = n;i < n+n*n;i++)
            mem[top++] = i;
        Voronoi(0,n-1);
    }
    return 0;
}
