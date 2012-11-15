#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point
{
    int x,y,id;
    Point(){}
    Point(int _x,int _y)
        {
            x = _x;
            y = _y;
        }
    Point(Point _s,Point _e)
        {
            x = _e.x-_s.x;
            y = _e.y-_s.y;
        }
    int len()
        {
            return x*x+y*y;
        }
};

int n,minx,miny,tn;
Point p[50],cur;

int xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool cmp(const Point& a,const Point& b)
{
    if (xmult(Point(cur,a),Point(cur,b)) == 0)
        return Point(cur,a).len() > Point(cur,b).len();
    return xmult(Point(cur,a),Point(cur,b)) < 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        minx = miny = 1000;
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d%d",&p[i].id,&p[i].x,&p[i].y);
            minx = min(minx,p[i].x);
            miny = min(miny,p[i].y);
        }
        tn = n;
        cur = Point(minx-1,miny);
        printf("%d ",n);
        for (int i = 0;i < tn;i++)
        {
            sort(p,p+n,cmp);
            cur = p[--n];
            printf("%d ",cur.id);
        }
        printf("\n");
    }
}
