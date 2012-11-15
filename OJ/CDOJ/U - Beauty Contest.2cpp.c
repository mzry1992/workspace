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

int n,res,h[50001];
Point p[50001],tp[50001];

void AntiPodal(Point a,Point b)
{
    if ((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y) > res)
        res = (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
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

void RotatingCalipers()
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

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        res = 0;
        GrahamScan();
        RotatingCalipers();
        printf("%d\n",res);
    }
}
