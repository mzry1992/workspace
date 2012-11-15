#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y;
    Point() {}
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
    int Length2()
    {
        return x*x+y*y;
    }
};

int xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool conPoint(Point p[],int n)
{
    for (int i = 1; i < n; i++)
        if (p[i].x != p[i].y ||
                p[i].y != p[0].y) return false;
    return true;
}

bool conLine(Point p[],int n)
{
    for (int i = 2; i < n; i++)
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
        if (resn < 2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) > 0) //将等号去掉就是求不保留凸包边上的点
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
}

int solve(Point p[],int n)
{
    int res;
    Point v;
    res = 0;
    int cur = 1;
    for (int i = 0;i < n;i++)
    {
        v = Point(p[(i+1)%n],p[i]);
        while (xmult(v,Point(p[cur],p[(cur+1)%n])) < 0)
            cur = (cur+1)%n;
        //p[cur] 和 p[i] 、 p[cur] 和 p[i+1] 是对踵点
        //p[cur] 和 p[i]->p[i+1] 是点边对踵
        //如果p[cur]->p[cur+1] 和 p[i]->p[i+1] 平行那么就是边边对踵了。
        res = max(res,Point(p[i],p[cur]).Length2());
        res = max(res,Point(p[(i+1)%n],p[cur]).Length2());
    }
    return res;
}

Point p[50000],tp[50000];
int n,tn;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        grahamScan(p,n,tp,tn);
        int ans;
        if (tn == 1)
            ans = 0;
        else if (tn == 2)
            ans = Point(tp[0],tp[1]).Length2();
        else
            ans = solve(tp,tn);
        printf("%d\n",ans);
    }
    return 0;
}
