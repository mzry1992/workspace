#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

const int POLYSIZE = 160;
const int LINESIZE = 310;
const double eps = 1e-8;
bool equal(double a,double b){return fabs(a-b)<eps;}
struct Point{double x,y;};
struct Line
{
    Point s,e;
    double k;
};
struct Lines
{
    int size;
    Line l[LINESIZE];
    Line& operator [](int k){return l[k];};
};
struct Poly
{
    int size;
    Point p[POLYSIZE];
    Point& operator [](int k){return p[k];};
};
int n;
Poly p,res;

inline double CalcK(Point a,Point b){return atan2(b.y-a.y,b.x-a.x);}
double xmult(Point ps,Point pe,Point po)
{
    return (ps.x-po.x)*(pe.y-po.y)-(pe.x-po.x)*(ps.y-po.y);
}

double xmult(Line a,Line b)
{
    return (a.e.x-a.s.x)*(b.e.y-b.s.y)-(a.e.y-a.s.y)*(b.e.x-b.s.x);
}

bool HalfPlaneIntersectionCmp(Line a,Line b)
{
    if (fabs(a.k-b.k) > eps)    return a.k < b.k;
    return xmult(a.s,b.e,b.s) < 0.0;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

Poly HalfPlaneIntersection(Poly &p)
{
    Line line[POLYSIZE],Q[POLYSIZE];
    Poly res;
    res.size = 0;
    int tot = p.size;
    for (int i = 0;i < p.size;i++)
    {
        line[i].s = p[(i+1)%n];
        line[i].e = p[i];
        line[i].k = CalcK(line[i].s,line[i].e);
    }
    sort(line,line+p.size,HalfPlaneIntersectionCmp);
    tot = 1;
    for (int i = 1;i < p.size;i++)
        if (fabs(line[i].k-line[i-1].k) > eps)
            line[tot++] = line[i];
    int head,tail;
    head = 0;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    for (int i = 2;i < tot;i++)
    {
        if ((fabs(xmult(Q[tail],Q[tail-1])) < eps) || (fabs(xmult(Q[head],Q[head+1])) < eps))   return res;
        if (head < tail && xmult(LineToLine(Q[tail],Q[tail-1]),line[i].e,line[i].s) > eps)  tail--;
        if (head < tail && xmult(LineToLine(Q[head],Q[head+1]),line[i].e,line[i].s) > eps)  head++;
        tail++;
        Q[tail] = line[i];
    }
    if (head < tail && xmult(LineToLine(Q[tail],Q[tail-1]),Q[head].e,Q[head].s) > eps)  tail--;
    if (head < tail && xmult(LineToLine(Q[head],Q[head+1]),Q[tail].e,Q[tail].s) > eps)  head++;
    if (tail <= head+1) return res;
    for (int i = head;i < tail;i++)
        res[res.size++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[res.size++] = LineToLine(Q[head],Q[tail]);
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        p.size = n;
        for (int i = 0;i < n;i++)  scanf("%lf%lf",&p[i].x,&p[i].y);
        res = HalfPlaneIntersection(p);
        if (res.size == 0)  printf("NO\n");
        else printf("YES\n");
    }
}
