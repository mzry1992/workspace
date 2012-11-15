#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

struct Point
{
    double x,y;
    Point(){}
    Point(int _x,int _y)
        {
            x = _x;
            y = _y;
        }
};

inline double CalcK(Point a,Point b){return atan2(b.y-a.y,b.x-a.x);}

struct Line
{
    Point s,e;
    double k;
    Line(){}
    Line(Point _s,Point _e)
        {
           s = _s;
           e = _e;
           k = CalcK(_s,_e);
        }
};

Line line[1100],Q[1100];
Point p[110],res[110],sp,ep;
int n,tp,tl,tres;
double L,W,H,ez;

double xmult(Point ps,Point pe,Point po)
{
    return (ps.x-po.x)*(pe.y-po.y)-(pe.x-po.x)*(ps.y-po.y);
}

double xmult(Line a,Line b)
{
    return (a.e.x-a.s.x)*(b.e.y-b.s.y)-(a.e.y-a.s.y)*(b.e.x-b.s.x);
}

bool cmp(Line a,Line b)
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

void HPI()
{
    sort(line,line+tl,cmp);
    int tot = 1;
    for (int i = 1;i < tl;i++)
        if (fabs(line[i].k-line[i-1].k) > eps)
            line[tot++] = line[i];
    int head,tail;
    head = 0;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    tres = 0;
    for (int i = 2;i < tot;i++)
    {
        if ((fabs(xmult(Q[tail],Q[tail-1])) < eps) || (fabs(xmult(Q[head],Q[head+1])) < eps))   return;
        while (head < tail && xmult(LineToLine(Q[tail],Q[tail-1]),line[i].e,line[i].s) > eps)   tail--;
        while (head < tail && xmult(LineToLine(Q[head],Q[head+1]),line[i].e,line[i].s) > eps)   head++;
        tail++;
        Q[tail] = line[i];
    }
    while (head < tail && xmult(LineToLine(Q[tail],Q[tail-1]),Q[head].e,Q[head].s) > eps)   tail--;
    while (head < tail && xmult(LineToLine(Q[head],Q[head+1]),Q[tail].e,Q[tail].s) > eps)   head++;
    if (tail <= head+1) return;
    for (int i = head;i < tail;i++)
        res[tres++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[tres++] = LineToLine(Q[head],Q[tail]);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lf%lf%lf",&L,&W,&H);
        scanf("%d",&n);
        tl = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&tp);
            for (int j = 0;j < tp;j++)
                scanf("%lf%lf",&p[j].x,&p[j].y);
            for (int j = 0;j < tp;j++)
            {
                line[tl] = Line(p[j],p[(j+1)%tp]);
                tl++;
            }
        }
        scanf("%lf%lf%lf",&ep.x,&ep.y,&ez);
        HPI();
        cout << tres << endl;
        for (int i = 0;i < tres;i++)
            cout << res[i].x << ' ' << res[i].y << endl;
    }
}
