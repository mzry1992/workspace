#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

const int POLYSIZE = 10000;
const int LINESIZE = 10000;
const double eps = 1e-15;
const double pi = acos(-1.0);
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
Poly p,tres;

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

Line tline[LINESIZE],line[LINESIZE],Q[POLYSIZE];
Poly res;

Poly HalfPlaneIntersection()
{
    res.size = 0;
    int tot = n;
    for (int i = 0;i < tot;i++) line[i] = tline[i];
    for (int i = 0;i < tot;i++)
        line[i].k = CalcK(line[i].s,line[i].e);
    int ttot = n;
    sort(line,line+tot,HalfPlaneIntersectionCmp);
    tot = 1;
    for (int i = 1;i < ttot;i++)
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

Point now,pre,ts,te;
char s[10];

Point getPoint(double x,double y)
{
    Point res;
    res.x = x;
    res.y = y;
    return res;
}

int main()
{
    n = 4;
    tline[0].s = getPoint(0,0);
    tline[0].e = getPoint(10,0);
    tline[1].s = getPoint(10,0);
    tline[1].e = getPoint(10,10);
    tline[2].s = getPoint(10,10);
    tline[2].e = getPoint(0,10);
    tline[3].s = getPoint(0,10);
    tline[3].e = getPoint(0,0);
    pre = getPoint(0,0);
    while (scanf("%lf%lf%s",&now.x,&now.y,s) != EOF)
    {
        ts = getPoint(pre.x+(now.x-pre.x)/2.0,pre.y+(now.y-pre.y)/2.0);
        te = getPoint(ts.x+(now.y-pre.y),ts.y-(now.x-pre.x));
        //cout << ts.x << ' ' << ts.y << endl;
        //cout << te.x << ' ' << te.y << endl;
        if (strcmp(s,"Colder") == 0)
        {
            tline[n].s = te;
            tline[n].e = ts;
            n++;
        }
        else if (strcmp(s,"Hotter") == 0)
        {
            tline[n].s = ts;
            tline[n].e = te;
            n++;
        }
        else
        {
            tline[n].s = te;
            tline[n].e = ts;
            n++;
            tline[n].s = ts;
            tline[n].e = te;
            n++;
        }
        res = HalfPlaneIntersection();
        //cout << res.size << ' ' << n << endl;
        printf("%.2f\n",CalcArea(res));
        pre = now;
        //for (int i = 0;i < n;i++)
            //cout << tline[i].s.x << ' ' << tline[i].s.y << ' ' << tline[i].e.x << ' ' << tline[i].e.y << endl;
    }
}
