#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    double x,y;
    Point() {}
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
    friend double xmult(Point a,Point b)
    {
        return a.x*b.y-a.y*b.x;
    }
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};
struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
    }
};
int n,m;
double ta[10000],tb[10000];
Point A,B,C,D;
Point pa[10000],pb[10000];

double CalcDis(Point a,Point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

struct Edge
{
    int u,v;
    double dis;
    friend bool operator < (const Edge& a,const Edge& b)
    {
        return a.dis < b.dis;
    }
    Edge() {}
    Edge(int _u,int _v,double _dis)
    {
        u = _u;
        v = _v;
        dis = _dis;
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

Edge edge[400000];
int totedge,f[10000],fa,fb;

int findf(int x)
{
    if (x != f[x])  f[x] = findf(f[x]);
    return f[x];
}

double get_sit(Point p1,Point p2,Point p3)
{
    return xmult(Point(p1,p2),Point(p1,p3));
}

Line getmidline(Point s,Point e)
{
    Point _s,_e;
    _s = Point((s.x+e.x)/2,(s.y+e.y)/2);
    _e = Point(_s.x+(s.y-e.y),_s.y-(s.x-e.x));
    return Line(_s,_e);
}

const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)  return 0;
    if (a < b)  return -1;
    return 1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
        scanf("%lf%lf%lf%lf",&C.x,&C.y,&D.x,&D.y);
        for (int i = 0; i < n; i++)
            scanf("%lf",&ta[i]);
        sort(ta,ta+n);
        for (int i = 0; i < m; i++)
            scanf("%lf",&tb[i]);
        sort(tb,tb+m);
        for (int i = 0; i < n; i++)
            pa[i] = Point(A.x*ta[i]+B.x*(1-ta[i]),A.y*ta[i]+B.y*(1-ta[i]));
        for (int i = 0; i < m; i++)
            pb[i] = Point(C.x*tb[i]+D.x*(1-tb[i]),C.y*tb[i]+D.y*(1-tb[i]));
////////////////////////////////////////
        totedge = 0;

        for (int i = 1; i < n; i++)
            edge[totedge++] = Edge(i-1,i,CalcDis(pa[i-1],pa[i]));
        for (int i = 1; i < m; i++)
            edge[totedge++] = Edge(n+i-1,n+i,CalcDis(pb[i-1],pb[i]));

        int cur;
        Line l1,l2;
        Point xp;
        double dis1,dis2;

        cur = 0;
        for (int i = 0; i < n; i++)
            while (true)
            {
                edge[totedge++] = Edge(i,n+cur,CalcDis(pa[i],pb[cur]));
                if (i+1 == n && cur+1 == m)
                    break;
                if (i+1 == n)
                {
                    cur++;
                    continue;
                }
                else if (cur+1 == m)
                    break;
                else
                {
                    if (cmp(get_sit(pa[i],pb[cur],pa[i+1]),0) <= 0)
                        break;
                    if (cmp(get_sit(pa[i],pb[cur],pb[cur+1]),0) <= 0)
                    {
                        cur++;
                        continue;
                    }

                    l2 = getmidline(pa[i],pa[i+1]);
                    xp = LineToLine(l1,l2);
                    dis1 = Point(xp,l1.s).Length();


                    l2 = getmidline(pb[cur],pb[cur+1]);
                    xp = LineToLine(l1,l2);
                    dis2 = Point(xp,l1.s).Length();

                    if (cmp(dis1,dis2) < 0)
                        break;
                    else
                    {
                        cur++;
                        continue;
                    }
                }
            }

        cur = m-1;
        for (int i = 0; i < n; i++)
            while (true)
            {
                edge[totedge++] = Edge(i,n+cur,CalcDis(pa[i],pb[cur]));
                if (i+1 == n && cur == 0)
                    break;
                if (i+1 == n)
                {
                    cur--;
                    continue;
                }
                else if (cur == 0)
                    break;
                else
                {
                    if (cmp(get_sit(pa[i],pb[cur],pa[i+1]),0) <= 0)
                        break;
                    if (cmp(get_sit(pa[i],pb[cur],pb[cur-1]),0) <= 0)
                    {
                        cur--;
                        continue;
                    }

                    l2 = getmidline(pa[i],pa[i+1]);
                    xp = LineToLine(l1,l2);
                    dis1 = Point(xp,l1.s).Length();


                    l2 = getmidline(pb[cur],pb[cur-1]);
                    xp = LineToLine(l1,l2);
                    dis2 = Point(xp,l1.s).Length();

                    if (cmp(dis1,dis2) < 0)
                        break;
                    else
                    {
                        cur--;
                        continue;
                    }
                }
            }

        cur = 0;
        for (int i = n-1; i >= 0; i--)
            while (true)
            {
                edge[totedge++] = Edge(i,n+cur,CalcDis(pa[i],pb[cur]));
                if (i == 0 && cur+1 == m)
                    break;
                if (i == 0)
                {
                    cur++;
                    continue;
                }
                else if (cur+1 == m)
                    break;
                else
                {
                    if (cmp(get_sit(pa[i],pb[cur],pa[i-1]),0) <= 0)
                        break;
                    if (cmp(get_sit(pa[i],pb[cur],pb[cur+1]),0) <= 0)
                    {
                        cur++;
                        continue;
                    }

                    l2 = getmidline(pa[i],pa[i-1]);
                    xp = LineToLine(l1,l2);
                    dis1 = Point(xp,l1.s).Length();


                    l2 = getmidline(pb[cur],pb[cur+1]);
                    xp = LineToLine(l1,l2);
                    dis2 = Point(xp,l1.s).Length();

                    if (cmp(dis1,dis2) < 0)
                        break;
                    else
                    {
                        cur++;
                        continue;
                    }
                }
            }

        cur = m-1;
        for (int i = n-1; i >= 0; i--)
            while (true)
            {
                edge[totedge++] = Edge(i,n+cur,CalcDis(pa[i],pb[cur]));
                if (i == 0 && cur == 0)
                    break;
                if (i == 0)
                {
                    cur--;
                    continue;
                }
                else if (cur == 0)
                    break;
                else
                {
                    if (cmp(get_sit(pa[i],pb[cur],pa[i-1]),0) <= 0)
                        break;
                    if (cmp(get_sit(pa[i],pb[cur],pb[cur-1]),0) <= 0)
                    {
                        cur--;
                        continue;
                    }

                    l2 = getmidline(pa[i],pa[i-1]);
                    xp = LineToLine(l1,l2);
                    dis1 = Point(xp,l1.s).Length();


                    l2 = getmidline(pb[cur],pb[cur-1]);
                    xp = LineToLine(l1,l2);
                    dis2 = Point(xp,l1.s).Length();

                    if (cmp(dis1,dis2) < 0)
                        break;
                    else
                    {
                        cur--;
                        continue;
                    }
                }
            }

        for (int i = 0;i < totedge;i++)
            cout << edge[i].u << ' ' << edge[i].v << ' ' << edge[i].dis << endl;
////////////////////////////////////////
        for (int i = 0; i < n+m; i++)
            f[i] = i;
        sort(edge,edge+totedge);
        double res = 0;
        for (int i = 0; i < totedge; i++)
        {
            fa = findf(edge[i].u);
            fb = findf(edge[i].v);
            if (fa != fb)
            {
                f[fa] = fb;
                res += edge[i].dis;
            }
        }
        printf("Case #%d: %.3f\n",ft,res);
    }
    return 0;
}
