#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y;
    Point(){}
    Point(int _x ,int _y)
        {
            x = _x;
            y = _y;
        }
    Point(Point a,Point b)
        {
            x = b.x-a.x;
            y = b.y-a.y;
        }
    int len()
        {
            return x*x+y*y;
        }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(const Point & a ,const Point &b)
        {
            s = a;
            e = b;
        }
};

int n,res,tpn;
Point p[50001],tp[50001];

void AntiPodal(Point a,Point b)
{
    res = max(res,Point(a,b).len());
}

void AntiPodal(Point a,Line b)
{

}

void AntiPodal(Line a,Line b)
{

}

inline int xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

void RotatingCalipers(Point p[],int n)
{
    int p0,p1,q0,q1,Xmult,tp0,tp1;
    Point now;
    p0 = p1 = 1;
    for (int i = 0;i < n;i++)
    {
        if ((p[p0].y > p[i].y) || ((p[p0].y == p[i].y) && (p[p0].x > p[i].x)))  p0 = i;
        if ((p[p1].y < p[i].y) || ((p[p1].y == p[i].y) && (p[p1].x < p[i].x)))  p1 = i;
    }
    AntiPodal(p[p0],p[p1]);
    tp0 = p0;
    tp1 = p1;
    while (true)
    {
        q0 = (p0+1)%n;
        q1 = (p1+1)%n;
        Xmult = xmult(Point(p[p0],p[q0]),Point(p[p1],p[q1]));
        if (Xmult < 0)
        {
            AntiPodal(p[q0],p[p1]);
            AntiPodal(p[p1],Line(p[p0],p[q0]));
            p0 = q0;
        }
        else if (Xmult == 0)
        {
            AntiPodal(p[p0],p[q1]);
            AntiPodal(p[q0],p[p1]);
            AntiPodal(p[q0],p[q1]);
            AntiPodal(Line(p[p0],p[q0]),Line(p[p1],p[q1]));
            p0 = q0;
            p1 = q1;
        }
        else
        {
            AntiPodal(p[p0],p[q1]);
            AntiPodal(p[p0],Line(p[p1],p[q1]));
            p1 = q1;
        }
        if (p1 == tp0 || p0 == tp1) break;
    }
}

bool EQ(Point a,Point b)
{
    return a.x == b.x && b.y == a.y;
}

bool conPoint(Point p[],int n)
{
    for (int i = 1;i < n;i++)
        if (EQ(p[i],p[0]) == false) return false;
    return true;
}

bool conLine(Point p[],int n)
{
    for (int i = 2;i < n;i++)
        if (xmult(Point(p[0],p[1]),Point(p[0],p[i])) != 0)  return false;
    return true;
}

bool grahamScanCmp(Point a,Point b)
{
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    if (n < 3 || conPoint(p,n) == true || conLine(p,n) == true) return;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    for (int i = 0;i < n;)
        if (resn < 2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) >= 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) >= 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

int main()
{
    while (scanf("%d",&tpn) != EOF)
    {
        for (int i = 0;i < tpn;i++)
            scanf("%d%d",&tp[i].x,&tp[i].y);
        if (conPoint(tp,tpn) == true)
            res = 0;
        else if (conLine(tp,tpn) == true)
        {
            sort(tp,tp+tpn,grahamScanCmp);
            res = Point(tp[0],tp[tpn-1]).len();
        }
        else
        {
            res = 0;
            grahamScan(tp,tpn,p,n);
            RotatingCalipers(p,n);
        }
        printf("%d\n",res);
    }
}
