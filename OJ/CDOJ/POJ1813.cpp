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

Line line[POLYSIZE],Q[POLYSIZE];
Poly res;

Poly HalfPlaneIntersection()
{
    res.size = 0;
    int tot = n;
    for (int i = 0;i < tot;i++)
        line[i].k = CalcK(line[i].s,line[i].e);
    int ttot = n;
    sort(line,line+tot,HalfPlaneIntersectionCmp);
    tot = 1;
    for (int i = 1;i < ttot;i++)
        if (fabs(line[i].k-line[i-1].k) > eps)
            line[tot++] = line[i];
    //cout << tot << endl;
    //for (int i = 0;i < tot;i++)
    //    cout << line[i].k << ' ' << line[i].s.x << ' ' << line[i].s.y << ' ' << line[i].e.x << ' ' << line[i].e.y << endl;
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

char typ[10],typ1[10],typ2[10];
double a,b,c,d;
double a1,b1,c1,a2,b2,c2;

double dis(int x,int y)
{
    return sqrt((double)(x*x+y*y));
}

double area(int x1,int y1,int x2,int y2,double r1,double r2)
{
    double s = dis(x2-x1,y2-y1);
    if (r1+r2<=s)    return 0;
    else if (r2-r1>=s)   return pi*r1*r1;
    else if (r1-r2>=s)   return pi*r2*r2;
    double q1 = acos((r1*r1+s*s-r2*r2)/(2*r1*s));
    double q2 = acos((r2*r2+s*s-r1*r1)/(2*r2*s));
    return (r1*r1*q1+r2*r2*q2-r1*s*sin(q1));
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        n = 0;
        scanf("%s",typ);
        typ1[0] = typ[0];
        if (strcmp(typ,"R") == 0)
        {
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            line[n].s.x = a; line[n].s.y = b;
            line[n].e.x = c; line[n].e.y = b;
            n++;
            line[n].s.x = c; line[n].s.y = b;
            line[n].e.x = c; line[n].e.y = d;
            n++;
            line[n].s.x = c; line[n].s.y = d;
            line[n].e.x = a; line[n].e.y = d;
            n++;
            line[n].s.x = a; line[n].s.y = d;
            line[n].e.x = a; line[n].e.y = b;
            n++;
        }
        else
        {
            scanf("%lf%lf%lf",&a,&b,&c);
            a1 = a;
            b1 = b;
            c1 = c;
            for (int i = 0;i < 3600;i++)
            {
                line[n].s.x = (a+c*cos(2*pi*(double)i/3600.0));
                line[n].s.y = (b+c*sin(2*pi*(double)i/3600.0));
                line[n].e.x = (a+c*cos(2*pi*(double)((i+1)%3600)/3600.0));
                line[n].e.y = (b+c*sin(2*pi*(double)((i+1)%3600)/3600.0));
                n++;
            }
        }
        scanf("%s",typ);
        typ2[0] = typ[0];
        if (strcmp(typ,"R") == 0)
        {
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            line[n].s.x = a; line[n].s.y = b;
            line[n].e.x = c; line[n].e.y = b;
            n++;
            line[n].s.x = c; line[n].s.y = b;
            line[n].e.x = c; line[n].e.y = d;
            n++;
            line[n].s.x = c; line[n].s.y = d;
            line[n].e.x = a; line[n].e.y = d;
            n++;
            line[n].s.x = a; line[n].s.y = d;
            line[n].e.x = a; line[n].e.y = b;
            n++;
        }
        else
        {
            scanf("%lf%lf%lf",&a,&b,&c);
            a2 = a;
            b2 = b;
            c2 = c;
            for (int i = 0;i < 3600;i++)
            {
                line[n].s.x = (a+c*cos(2*pi*(double)i/3600.0));
                line[n].s.y = (b+c*sin(2*pi*(double)i/3600.0));
                line[n].e.x = (a+c*cos(2*pi*(double)((i+1)%3600)/3600.0));
                line[n].e.y = (b+c*sin(2*pi*(double)((i+1)%3600)/3600.0));
                n++;
            }
        }
        if (typ1[0] == typ2[0] && typ1[0] == 'C')
        {
            printf("%d\n",(int)(area(a1,b1,a2,b2,(double)c1,(double)c2)+0.5));
            continue;
        }
        tres = HalfPlaneIntersection();
        printf("%d\n",(int)(CalcArea(tres)+0.5));
    }
}
