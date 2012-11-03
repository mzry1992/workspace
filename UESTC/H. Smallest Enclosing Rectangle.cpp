#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
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
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};
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

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

bool grahamScanCmp(Point a,Point b)
{
    if (cmp(a.x,b.x) == 0) return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    for (int i = 0; i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

int n,tn;
Point p[100000],tp[100000];
double resa,resb;

void solve()
{
    resa = resb = 1e100;
    double dis1,dis2;
    Point xp[4];
    Line l[4];
    int a,b,c,d;
    int sa,sb,sc,sd;
    a = b = c = d = 0;
    sa = sb = sc = sd = 0;
    Point va,vb,vc,vd;
    for (a = 0;a < n;a++)
    {
        va = Point(p[a],p[(a+1)%n]);
        vc = Point(-va.x,-va.y);
        vb = Point(-va.y,va.x);
        vd = Point(-vb.x,-vb.y);

        if (sb < sa)
        {
            b = a;
            sb = sa;
        }

        while (xmult(vb,Point(p[b],p[(b+1)%n])) < 0)
        {
            b = (b+1)%n;
            sb++;
        }

        if (sc < sb)
        {
            c = b;
            sc = sb;
        }

        while (xmult(vc,Point(p[c],p[(c+1)%n])) < 0)
        {
            c = (c+1)%n;
            sc++;
        }

        if (sd < sc)
        {
            d = c;
            sd = sc;
        }

        while (xmult(vd,Point(p[d],p[(d+1)%n])) < 0)
        {
            d = (d+1)%n;
            sd++;
        }

        l[0] = Line(p[a],Point(p[a].x+va.x,p[a].y+va.y));
        l[1] = Line(p[b],Point(p[b].x+vb.x,p[b].y+vb.y));
        l[2] = Line(p[c],Point(p[c].x+vc.x,p[c].y+vc.y));
        l[3] = Line(p[d],Point(p[d].x+vd.x,p[d].y+vd.y));
        for (int j = 0;j < 4;j++)
            xp[j] = LineToLine(l[j],l[(j+1)%4]);
        dis1 = Point(xp[0],xp[1]).Length();
        dis2 = Point(xp[1],xp[2]).Length();
        resa = min(resa,dis1*dis2);
        resb = min(resb,(dis1+dis2)*2);

        sa++;
    }
}

int main()
{
    while (true)
    {
        scanf("%d",&tn);
        if (tn == 0) break;
        for (int i = 0;i < tn;i++)
            scanf("%lf%lf",&tp[i].x,&tp[i].y);
        grahamScan(tp,tn,p,n);
        solve();
        printf("%.2f %.2f\n",resa,resb);
    }
    return 0;
}
