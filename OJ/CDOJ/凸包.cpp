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
};

int n,res,tpn;
Point p[2000],tp[2000];

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

Point basePoint;

bool convexHullCmp(Point a,Point b)
{
    if (xmult(Point(basePoint,a),Point(basePoint,b)) == 0)
        return a.y > b.y;
    return xmult(Point(basePoint,a),Point(basePoint,b)) > 0;
}

void convexHull(Point p[],int n,Point res[],int& resn,int hullType) // 1 del the point on edge , 0 does not
{
    resn = 0;
    if (n < 3)  return;
    if (conPoint(p,n))  return;
    if (conLine(p,n))   return;
    basePoint = p[0];
    sort(p+1,p+n,convexHullCmp);
    resn = 2;
    res[0] = p[0];
    res[1] = p[1];
    for (int i = 2;i < n;i++)
    {
        while (resn > 1 && xmult(Point(res[resn-1],res[resn-2]),Point(res[resn-1],p[i]))+hullType > 0)
            resn--;
        res[resn] = p[i];
        resn++;
    }
    while (resn > 1 && xmult(Point(res[resn-1],res[resn-2]),Point(res[resn-1],res[0]))+hullType > 0)
        resn--;
    res[resn] = res[0];
    resn++;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)   scanf("%d%d",&p[i].x,&p[i].y);
        convexHull(p,n,tp,tpn,0);
        cout << tpn << endl;
        for (int i = 0;i < tpn;i++)
            cout << tp[i].x << ' ' << tp[i].y << endl;
        convexHull(p,n,tp,tpn,1);
        cout << tpn << endl;
        for (int i = 0;i < tpn;i++)
            cout << tp[i].x << ' ' << tp[i].y << endl;
    }
}

