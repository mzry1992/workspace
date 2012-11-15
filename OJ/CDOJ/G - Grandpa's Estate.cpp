#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x,y,id;
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

void grahamScan(Point p[],int n,Point res[],int& resn,int hulltype)
{
    resn = 0;
    if (n < 3 || conPoint(p,n) == true || conLine(p,n) == true) return;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    for (int i = 0;i < n;)
        if (resn < 2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i]))+hulltype > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i]))+hulltype > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

int n,p0n,p1n,nxt[1000];
Point p[1000],p0[1000],p1[1000];
bool res;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].id = i;
        }
        grahamScan(p,n,p0,p0n,0);
        grahamScan(p,n,p1,p1n,1);
        for (int i = 0;i < p1n;i++)
            nxt[p1[i].id] = p1[(i+1)%p1n].id;
        res = true;
        for (int i = 0;i < p0n;i++)
            if (p0[(i+1)%p0n].id == nxt[p0[i].id])
            {
                res = false;
                break;
            }
        if (conLine(p,n) == true || conPoint(p,n) == true)   res = false;
        if (res == true)    puts("YES");
        else puts("NO");
    }
    return 0;
}
