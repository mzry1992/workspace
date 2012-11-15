Á½´ÎÍ¹°ü
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x,y;
    Point(){};
    Point(int _x,int _y)
        {
            x = _x;
            y = _y;
        }
    Point(Point _a,Point _b)
        {
            x = _b.x-_a.x;
            y = _b.y-_a.y;
        }
    int len()
        {
            return x*x+y*y;
        }
};

bool EQ(Point a,Point b)
{
    return a.x == b.x && b.y == a.y;
}

int xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
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
        if (resn < 2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) > 0)
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

double CalcArea(Point a,Point b,Point c)    {   return (double)xmult(Point(a,b),Point(a,c))/2.0;}

double CalcArea(Point l[],int n)
{
    if (n < 3) return 0.0;
    double res = 0.0;
    for (int i = 2;i < n;i++)
        res += CalcArea(l[0],l[i-1],l[i]);
    return res;
}

int n,newn,tpn;
Point p[10000],tp[10000];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)   scanf("%d%d",&p[i].x,&p[i].y);
        grahamScan(p,n,tp,tpn);
        printf("%d\n",(int)floor((CalcArea(tp,tpn)/50.0)));
    }
}
