#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int MaxN = 1000;
const double eps = 1e-8;
struct Point
{
    double x,y,z;
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

bool HPICmp(Line a,Line b)
{
    if (fabs(a.k-b.k) > eps)    return a.k < b.k;
    return xmult(Point(b.s,a.s),Point(b.s,b.e)) < 0;
}

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/
               ((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

void HPI(Line line[],int n,Point res[],int& resn)
{
    Line Q[MaxN];
    int tot = n;
    sort(line,line+n,HPICmp);
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
        if ((fabs(xmult(Q[tail],Q[tail-1])) < eps) ||
                (fabs(xmult(Q[head],Q[head+1])) < eps)) return;
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

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)
        return 0;
    if (a < b)  return -1;
    return 1;
}

bool GSCmp(Point a,Point b)
{
    if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void GS(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,GSCmp);
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

double CalcArea(Point a,Point b,Point c)
{
    return xmult(Point(a,b),Point(a,c))/2.0;
}

double CalcArea(Point l[],int n)
{
    if (n < 3)  return 0;
    double res = 0;
    for (int i = 2; i < n; i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

Line hp[MaxN];
int hpcnt;

Point v[MaxN],c,tp[MaxN],p[MaxN],res[MaxN];
int n,pn,tpn,resn;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf",&v[i].x,&v[i].y,&v[i].z);
        bool can = true;
        hpcnt = 0;
        for (int i = 0; i < 3; i++)
        {
            scanf("%lf%lf",&c.x,&c.y);
            c.z = 100;

            tpn = 0;
            for (int j = 0; j < n; j++)
                if (v[j].z >= 0 && v[j].z < c.z)
                {
                    double dz = c.z-v[j].z;
                    double dx = c.x-v[j].x;
                    double dy = c.y-v[j].y;
                    double tt = 100.0/dz;
                    tp[tpn++] = Point(c.x-dx*tt,c.y-dy*tt);
                }
            GS(tp,tpn,p,pn);
//            for (int j = 0;j < pn;j++)
//                printf("(%.2f %.2f) ",p[j].x,p[j].y);
//            printf("\n");
            for (int j = 0; j < pn; j++)
                hp[hpcnt++] = Line(p[j],p[(j+1)%pn]);
        }
//            for (int j = 0;j < hpcnt;j++)
//                printf("((%.2f %.2f)(%.2f %.2f) ) ",hp[j].s.x,hp[j].s.y,hp[j].e.x,hp[j].e.y);
//            printf("\n");
        HPI(hp,hpcnt,res,resn);
//        for (int i = 0;i < resn;i++)
//            printf("(%.2f %.2f) ",res[i].x,res[i].y);
//        printf("\n");
        double ans = 0;
        ans = CalcArea(res,resn);
        printf("%.2f\n",ans);
    }
    return 0;
}
