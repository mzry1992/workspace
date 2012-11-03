#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
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

bool conPoint(Point p[],int n)
{
    for (int i = 1; i < n; i++)
        if (cmp(p[i].x,p[0].x) != 0 ||
                cmp(p[i].y,p[0].y) != 0) return false;
    return true;
}

bool conLine(Point p[],int n)
{
    for (int i = 2; i < n; i++)
        if (cmp(xmult(Point(p[0],p[1]),Point(p[0],p[i])),0) != 0)  return false;
    return true;
}

bool grahamScanCmp(Point a,Point b)
{
    if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    if (n == 0) return;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    if (conPoint(p,n) == true)
    {
        res[resn++] = p[0];
        return;
    }
    if (conLine(p,n) == true)
    {
        res[resn++] = p[0];
        res[resn++] = p[n-1];
        return;
    }
    for (int i = 0; i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0) //将等号去掉就是求不保留凸包边上的点
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
Point s,e;
Line v;
double theta[100000];

bool check(Point s,Point e)
{
    int pl,pr;
    double tnow;
    tnow = Line(s,e).k;
    if (cmp(tnow,theta[0]) < 0) tnow += 2*pi;
    pl = lower_bound(theta,theta+n,tnow)-theta;
    tnow = Line(e,s).k;
    if (cmp(tnow,theta[0]) < 0) tnow += 2*pi;
    pr = lower_bound(theta,theta+n,tnow)-theta;
    //交点就在pl到pr这个区间和pr到pl这个区间（如果有交点）
    if (cmp(xmult(Point(s,e),Point(s,p[pl%n])),0)*cmp(xmult(Point(s,e),Point(s,p[pr%n])),0) <= 0)   return true;
    return false;
}

int main()
{
    scanf("%d",&tn);
    for (int i = 0; i < tn; i++)
        scanf("%lf%lf",&tp[i].x,&tp[i].y);
    grahamScan(tp,tn,p,n);
    for (int i = 0;i < n;i++)
        theta[i] = Line(p[i],p[(i+1)%n]).k;
    for (int i = 1;i < n;i++)
        if (cmp(theta[i-1],theta[i]) > 0)
            theta[i] += 2*pi;
    while (scanf("%lf%lf%lf%lf",&s.x,&s.y,&e.x,&e.y) != EOF)
    {
        if (n < 2)
            printf("GOOD\n");
        else
        {
            if (check(s,e) == true)
                printf("BAD\n");
            else
                printf("GOOD\n");
        }
    }
    return 0;
}
