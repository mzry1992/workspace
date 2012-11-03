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
    if (n < 3) return;
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

void RotatingCalipers(Point p[],int n,int& res)
{
    int low = 0,anti = 0;
    for (int i = 1;i < n;i++)
    {
        if (p[i].x < p[low].x || (p[i].x == p[low].x && p[i].y < p[low].y))
            low = i;
        if (p[i].x > p[anti].x || (p[i].x == p[anti].x && p[i].y > p[anti].y))
            anti = i;
    }
    res = Point(p[low],p[anti]).len();
    for (int j = 0;j < n;j++,low = (low+1)%n)
    {
        for (;anti != low && xmult(Point(p[low],p[(low+1)%n]),Point(p[low],p[(anti+1)%n])) >= 0;anti = (anti+1)%n)
        {
            if (res < Point(p[low],p[anti]).len())
                res = Point(p[low],p[anti]).len();
        }
    }
}

int n,newn,tpn,res;
Point p[50000],tp[50000];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)   scanf("%d%d",&p[i].x,&p[i].y);
        if (conPoint(p,n) == true)
            res = 0;
        else if (conLine(p,n) == true)
        {
            sort(p,p+n,grahamScanCmp);
            res = Point(p[0],p[n-1]).len();
        }
        else
        {
            grahamScan(p,n,tp,tpn);
            RotatingCalipers(tp,tpn,res);
        }
        printf("%d\n",res);
    }
    return 0;
}
