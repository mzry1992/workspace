#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
    long long x,y;
    Point(){};
    Point(long long _x,long long _y)
        {
            x = _x;
            y = _y;
        }
    Point(Point _a,Point _b)
        {
            x = _b.x-_a.x;
            y = _b.y-_a.y;
        }
    long long len()
        {
            return x*x+y*y;
        }
};

bool EQ(Point a,Point b)
{
    return a.x == b.x && b.y == a.y;
}

long long xmult(Point a,Point b)
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

void grahamScan(Point p[],int n,int res[],int& resn)
{
    resn = 0;
    if (n < 3 || conPoint(p,n) == true || conLine(p,n) == true) return;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    for (int i = 0;i < n;)
        if (resn < 2 || xmult(Point(p[res[resn-2]],p[res[resn-1]]),Point(p[res[resn-1]],p[i])) >= 0)
            res[resn++] = i++;
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || xmult(Point(p[res[resn-2]],p[res[resn-1]]),Point(p[res[resn-1]],p[i])) >= 0)
            res[resn++] = i--;
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

int n,res,newn,tpn,tp[3000];
bool del[3000];
Point p[3000];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)   scanf("%lld%lld",&p[i].x,&p[i].y);
        res = 0;
        while (true)
        {
            grahamScan(p,n,tp,tpn);
            if (tpn == 0)   break;
            memset(del,false,sizeof(del));
            for (int i = 0;i < tpn;i++)
                del[tp[i]] = true;
            newn = 0;
            for (int i = 0;i < n;i++)
                if (del[i] == false)
                {
                    p[newn] = p[i];
                    newn++;
                }
            n = newn;
            res++;
            /*cout << tpn << endl;
            for (int i = 0;i < tpn;i++)
                cout << p[tp[i]].x << ' ' << p[tp[i]].y << endl;
            cout << n << endl;
            for (int i = 0;i < n;i++)
                cout << p[i].x << ' ' << p[i].y << endl;*/
        }
        printf("%d\n",res);
    }
}
