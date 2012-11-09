#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Point
{
    int x,y;
    Point(){}
    Point (int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    int operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
    int operator &(const Point& b)const
    {
        return x*b.x+y*b.y;
    }
};
Point p[20];
int n;
double v,b,g;

int main()
{
    while (true)
    {
        scanf("%lf%lf%lf",&v,&b,&g);
        if (v == 0 && b == 0 && g == 0) break;

        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);

        double tim;
        if (g == 0)
        {
            double maxy = p[0].y;
            for (int i = 0;i < n;i++)
                maxy = max(maxy,p[i].y);
            tim = maxy/b;
        }
        else
        {
            double miny = p[0].y;
            for (int i = 0;i < n;i++)
                miny = min(miny,p[i].y);
            tim =
        }
    }
    return 0;
}

