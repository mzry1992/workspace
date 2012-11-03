#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
        {
            x = _x;
            y = _y;
        }
};

struct Line
{
    Point s,e;
    double k;
    Line(){}
    Line(Point _s,Point _e)
        {
            s = _s;
            e = _e;
            k = atan2(e.y-s.y,e.x-s.x);
        }
};

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

Point p[3],e[3][2],res;
Line l[2];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        for (int i = 0;i < 3;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        for (int i = 0;i < 3;i++)
        {
            e[i][0] = Point(p[i].x-(p[(i+1)%3].y-p[i].y),p[i].y+p[(i+1)%3].x-p[i].x);
            e[i][1] = Point(p[(i+1)%3].x-(p[(i+1)%3].y-p[i].y),p[(i+1)%3].y+p[(i+1)%3].x-p[i].x);
        }
        for (int i = 0;i < 2;i++)
            l[i] = Line(Point(
                        (e[i][1].x+e[i+1][0].x)/2.0,
                        (e[i][1].y+e[i+1][0].y)/2.0
                              )
                        ,p[i+1]);
        res = LineToLine(l[0],l[1]);
        printf("%.4f %.4f\n",res.x,res.y);
    }
    return 0;
}
