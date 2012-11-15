#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
const double pi = acos(-1.0);

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

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
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};
struct Line
{
    Point s,e;
    double k;
    Line() {}
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

bool HPCmp(Line a,Line b)
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
Line Q[4000];

void HPI(Line line[],int n,Point res[],int& resn)
{
    int tot = n;
    sort(line,line+n,HPCmp);
    tot = 1;
    for (int i = 1; i < n; i++)
        if (fabs(line[i].k-line[i-1].k) > eps)
            line[tot++] = line[i];
    int head,tail;
    head = 0;
    tail = 1;
    Q[0] = line[0];
    Q[1] = line[1];
    resn = 0;
    for (int i = 2; i < tot; i++)
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
    for (int i = head; i < tail; i++)
        res[resn++] = LineToLine(Q[i],Q[i+1]);
    if (head < tail+1)
        res[resn++] = LineToLine(Q[head],Q[tail]);
}

bool OnSeg(Line a,Point b)
{
    return (cmp(xmult(Point(b,a.s),Point(b,a.e)),0.0) == 0 &&
           cmp((b.x-a.s.x)*(b.x-a.e.x),0.0) <= 0 &&
           cmp((b.y-a.s.y)*(b.y-a.e.y),0.0) <= 0);
}

bool InCircle(Point a,double r)
{
    return cmp(a.x*a.x+a.y*a.y,r*r) <= 0; //这里判断的时候EPS一定不要太小！！
}

double CalcArea(Point a,Point b,double r)
{
    Point p[4];
    int tot = 0;
    p[tot++] = a;

    Point tv = Point(a,b);
    Line tmp = Line(Point(0,0),Point(tv.y,-tv.x));
    Point near = LineToLine(Line(a,b),tmp);
    if (cmp(near.x*near.x+near.y*near.y,r*r) <= 0)
    {
        double A,B,C;
        A = near.x*near.x+near.y*near.y;
        C = r;
        B = C*C-A;
        double tvl = tv.x*tv.x+tv.y*tv.y;
        double tmp = sqrt(B/tvl); //这样做只用一次开根
        p[tot] = Point(near.x+tmp*tv.x,near.y+tmp*tv.y);
        if (OnSeg(Line(a,b),p[tot]) == true)    tot++;
        p[tot] = Point(near.x-tmp*tv.x,near.y-tmp*tv.y);
        if (OnSeg(Line(a,b),p[tot]) == true)    tot++;
    }
    if (tot == 3)
    {
        if (cmp(Point(p[0],p[1]).Length(),Point(p[0],p[2]).Length()) > 0)
            swap(p[1],p[2]);
    }
    p[tot++] = b;

    double res = 0.0,theta,a0,a1,sgn;
    for (int i = 0;i < tot-1;i++)
    {
        if (InCircle(p[i],r) == true && InCircle(p[i+1],r) == true)
        {
            res += 0.5*xmult(p[i],p[i+1]);
        }
        else
        {
            a0 = atan2(p[i+1].y,p[i+1].x);
            a1 = atan2(p[i].y,p[i].x);
            if (a0 < a1)    a0 += 2*pi;
            theta = a0-a1;
            if (cmp(theta,pi) >= 0) theta = 2*pi-theta;
            sgn = xmult(p[i],p[i+1])/2.0;
            if (cmp(sgn,0) < 0) theta = -theta;
            res += 0.5*r*r*theta;
        }
    }
    return res;
}

int n,resn;
Point p[4000],tp[2000][2];
Line line[4000];
double r,x,y,area,area2,res;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%lf%d",&r,&n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf",&tp[i][0].x,&tp[i][0].y,&tp[i][1].x,&tp[i][1].y);
        scanf("%lf%lf",&x,&y);
        for (int i = 0; i < n; i++)
            if (cmp(xmult(Point(tp[i][0],tp[i][1]),Point(tp[i][0],Point(x,y))),0.0) > 0)
                line[i] = Line(tp[i][0],tp[i][1]);
            else
                line[i] = Line(tp[i][1],tp[i][0]);
        line[n++] = Line(Point(-r,-r),Point(r,-r));
        line[n++] = Line(Point(r,-r),Point(r,r));
        line[n++] = Line(Point(r,r),Point(-r,r));
        line[n++] = Line(Point(-r,r),Point(-r,-r));
        HPI(line,n,p,resn);
        area2 = 0.0;
        for (int i = 0;i < resn;i++)
            area2 += CalcArea(p[i],p[(i+1)%resn],r);
        area = pi*r*r;
        res = 100*area2/area;
        printf("Case %d: %.5f%%\n",ft,res);
    }
    return 0;
}
