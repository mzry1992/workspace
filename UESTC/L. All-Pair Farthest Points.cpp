#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    long long x,y;
    Point() {}
    Point(long long _x,long long _y)
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

long long xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

int res[30000];
int n;
Point p[30000];

long long CalcDis(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void updata(int i,int j)
{
    if (res[i] == -1)   res[i] = j;
    else if (CalcDis(p[i],p[res[i]]) < CalcDis(p[i],p[j]))
        res[i] = j;
    else if (res[i] > j && CalcDis(p[i],p[res[i]]) == CalcDis(p[i],p[j]))
        res[i] = j;
}

void bdupdata(int i,int j)
{
    updata(i,j);
    updata(j,i);
}

void solve()
{
    Point v;
    int cur = 1;
    for (int i = 0; i < n; i++)
    {
        v = Point(p[(i+1)%n],p[i]);
        while (xmult(Point(p[i],p[(i+1)%n]),Point(p[i],p[cur])) == 0)
            cur = (cur+1)%n;
        while (xmult(v,Point(p[cur],p[(cur+1)%n])) <= 0)
            cur = (cur+1)%n;
        //p[cur] 和 p[i] 、 p[cur] 和 p[i+1] 是对踵点
        bdupdata((i-1+n)%n,(cur-1+n)%n);
        bdupdata((i-1+n)%n,cur);
        bdupdata((i-1+n)%n,(cur+1)%n);
        bdupdata(i,(cur-1+n)%n);
        bdupdata(i,cur);
        bdupdata(i,(cur+1)%n);
        bdupdata((i+1+n)%n,(cur-1+n)%n);
        bdupdata((i+1+n)%n,cur);
        bdupdata((i+1+n)%n,(cur+1)%n);
    }
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            scanf("%lld%lld",&p[i].x,&p[i].y);
        memset(res,-1,sizeof(res));
        solve();
        for (int i = 0; i < n; i++)
            printf("%d\n",res[i]+1);
    }
    return 0;
}
