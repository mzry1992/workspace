#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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

long long xmult(Point a,Point b)
{
    return (long long)a.x*(long long)b.y-(long long)a.y*(long long)b.x;
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

Point basePoint;

bool convexHullCmp(Point a,Point b)
{
    if (xmult(Point(basePoint,a),Point(basePoint,b)) == 0)
        return Point(basePoint,a).len() < Point(basePoint,b).len();
    return xmult(Point(basePoint,a),Point(basePoint,b)) > 0;
}

void convexHull(Point p[],int n,int res[],int& resn,int hullType) // 1 del the point on edge , 0 does not
{
    resn = 0;
    if (n < 3 || conPoint(p,n) == true || conLine(p,n) == true)  return;
    for (int i = 1;i < n;i++)
        if (p[i].x < p[0].x || (p[i].x == p[0].x && p[i].y < p[0].y))
            swap(p[i],p[0]);
    basePoint = p[0];
    sort(p+1,p+n,convexHullCmp);
    resn = 2;
    res[0] = 0;
    res[1] = 1;
    for (int i = 2;i < n;i++)
    {
        while (resn > 1 && xmult(Point(p[res[resn-2]],p[res[resn-1]]),Point(p[res[resn-1]],p[i]))+(long long)hullType > 0)
            resn--;
        res[resn] = i;
        resn++;
    }
    if (resn < 3)   resn = 0;
}

int n,res,newn,tpn,tp[3000];
bool del[3000];
Point p[3000];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)   scanf("%d%d",&p[i].x,&p[i].y);
        res = 0;
        while (true)
        {
            convexHull(p,n,tp,tpn,1);
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
