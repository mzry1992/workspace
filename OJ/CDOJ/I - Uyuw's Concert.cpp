#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-12;
const double pi = acos(-1.0);

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
    double k;
    Line(){}
    Line(Point _s,Point _e)
        {
            s = _s;
            e = _e;
            k = atan2(e.y-s.y,e.x-s.x);
        }
};

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

double xmult(Line a,Line b)
{
    return xmult(Point(a.s,a.e),Point(b.s,b.e));
}

bool HalfPlaneIntersectionCmp(Line a,Line b)
{
    if (fabs(a.k-b.k) > eps)    return a.k < b.k;
    return xmult(Point(b.s,a.s),Point(b.s,b.e)) < 0.0;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

void HalfPlaneIntersection(Line line[],int n,Point res[],int& resn)
{
    Line Q[30000];
    int tot = n;
    sort(line,line+n,HalfPlaneIntersectionCmp);
    tot = 1;
    for (int i = 1;i < n;i++)
        if (fabs(line[i].k-line[i-1].k) > eps)
            line[tot++] = line[i];
    int head,tail;
    head = 0;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for (int i = 2;i < tot;i++)
    {
        if ((fabs(xmult(Q[tail],Q[tail-1])) < eps) || (fabs(xmult(Q[head],Q[head+1])) < eps))   return;
        while (head < tail && xmult(Point(line[i].s,LineToLine(Q[tail],Q[tail-1])),Point(line[i].s,line[i].e)) > eps)
            tail--;
        while (head < tail && xmult(Point(line[i].s,LineToLine(Q[head],Q[head+1])),Point(line[i].s,line[i].e)) > eps)
            head++;
        tail++;
        Q[tail] = line[i];
    }
    while (head < tail && xmult(Point(Q[head].s,LineToLine(Q[tail],Q[tail-1])),Point(Q[head].s,Q[head].e)) > eps)
        tail--;
    while (head < tail && xmult(Point(Q[tail].s,LineToLine(Q[head],Q[head+1])),Point(Q[tail].s,Q[tail].e)) > eps)
        head++;
    if (tail <= head+1) return;
    for (int i = head;i < tail;i++)
        res[resn++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[resn++] = LineToLine(Q[head],Q[tail]);
}

double CalcArea(Point a,Point b,Point c)    {   return xmult(Point(a,b),Point(a,c))/2.0;}

double CalcArea(Point l[],int n)
{
    if (n < 3) return 0.0;
    double res = 0.0;
    for (int i = 2;i < n;i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

int n,resn,linen;
Line line[30000];
Point res[30000],s,e;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        linen = 0;
        line[linen++] = Line(Point(0,0),Point(10000,0));
        line[linen++] = Line(Point(10000,0),Point(10000,10000));
        line[linen++] = Line(Point(10000,10000),Point(0,10000));
        line[linen++] = Line(Point(0,10000),Point(0,0));
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf%lf%lf",&s.x,&s.y,&e.x,&e.y);
            line[linen++] = Line(s,e);
        }
        HalfPlaneIntersection(line,linen,res,resn);
        printf("%.1f\n",CalcArea(res,resn));
    }
    return 0;
}
