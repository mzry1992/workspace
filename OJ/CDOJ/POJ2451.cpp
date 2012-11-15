//半平面求交，边界线按照逆时针顺序
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

const int POLYSIZE = 20010;
const int LINESIZE = 20010;
const double eps = 1e-8;
struct Point
{
    double x,y;
};
struct Line
{
    Point s,e;
    double k;
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

Line line[POLYSIZE],Q[POLYSIZE];
int linesize;

Poly HalfPlaneIntersection()
{
    Poly res;
    res.size = 0;
    int tot = linesize;
    for (int i = 0;i < linesize;i++)
        line[i].k = CalcK(line[i].s,line[i].e);
    sort(line,line+linesize,HalfPlaneIntersectionCmp);
    tot = 1;
    for (int i = 1;i < linesize;i++)
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
        while (head < tail && xmult(LineToLine(Q[tail],Q[tail-1]),line[i].e,line[i].s) > eps)  tail--;
        while (head < tail && xmult(LineToLine(Q[head],Q[head+1]),line[i].e,line[i].s) > eps)  head++;
        tail++;
        Q[tail] = line[i];
    }
    while (head < tail && xmult(LineToLine(Q[tail],Q[tail-1]),Q[head].e,Q[head].s) > eps)  tail--;
    while (head < tail && xmult(LineToLine(Q[head],Q[head+1]),Q[tail].e,Q[tail].s) > eps)  head++;
    if (tail <= head+1) return res;
    for (int i = head;i < tail;i++)
        res[res.size++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[res.size++] = LineToLine(Q[head],Q[tail]);
    return res;
}

double CalcArea(Point a,Point b,Point c)    {   return xmult(a,b,c)/2.0;}

double CalcArea(Poly& l)
{
    if (l.size < 3) return 0.0;
    double res = 0.0;
    for (int i = 2;i < l.size;i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

double l,r,mid,k;

Point getPoint(double x,double y)
{
    Point res;
    res.x = x;
    res.y = y;
    return res;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        linesize = n+4;
        line[0].s = getPoint(0,0);
        line[0].e = getPoint(10000,0);
        line[1].s = getPoint(10000,0);
        line[1].e = getPoint(10000,10000);
        line[2].s = getPoint(10000,10000);
        line[2].e = getPoint(0,10000);
        line[3].s = getPoint(0,10000);
        line[3].e = getPoint(0,0);
        for (int i = 4;i < linesize;i++)
            scanf("%lf%lf%lf%lf",&line[i].s.x,&line[i].s.y,&line[i].e.x,&line[i].e.y);
        res = HalfPlaneIntersection();
        printf("%.1f\n",CalcArea(res));
    }
}

