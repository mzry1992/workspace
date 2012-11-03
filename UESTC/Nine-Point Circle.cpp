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
    Point(Point _s,Point _e)
        {
            x = _e.x-_s.x;
            y = _e.y-_s.y;
        }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
        {
            s = _s;
            e = _e;
        }
};

Point p[3];

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

Line la,lb;
Point tp,np[3];

int main()
{
    while (true)
    {
        for (int i = 0;i < 3;i++)
            scanf("%lf%lf",&np[i].x,&np[i].y);
        if (np[0].x < 0) break;
        for (int i = 0;i < 3;i++)
            p[i] = Point((np[i].x+np[(i+1)%3].x)/2,(np[i].y+np[(i+1)%3].y)/2);
        tp = Point((p[0].x+p[1].x)/2,(p[0].y+p[1].y)/2);
        la = Line(tp,Point(tp.x-(p[1].y-p[0].y),tp.y+(p[1].x-p[0].x)));
        tp = Point((p[0].x+p[2].x)/2,(p[0].y+p[2].y)/2);
        lb = Line(tp,Point(tp.x-(p[2].y-p[0].y),tp.y+(p[2].x-p[0].x)));
        tp = LineToLine(la,lb);
        printf("%.6f %.6f %.6f\n",tp.x,tp.y,sqrt((tp.x-p[0].x)*(tp.x-p[0].x)+(tp.y-p[0].y)*(tp.y-p[0].y)));
    }
    return 0;
}
