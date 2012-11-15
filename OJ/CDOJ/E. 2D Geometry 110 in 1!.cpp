#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    double x,y;
    Point() {}
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
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};
struct Line
{
    Point s,e;
    Line() {}
    Line(Point _s,Point _e)
    {
        s = _s;
        e = _e;
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

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

Point p[3],tp,v,tv;
Line l[3];
double r,len[3],tr;

void CircumscribedCircle()
{
    for (int i = 0; i < 3; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    tp = Point((p[0].x+p[1].x)/2,(p[0].y+p[1].y)/2);
    l[0] = Line(tp,Point(tp.x-(p[1].y-p[0].y),tp.y+(p[1].x-p[0].x)));
    tp = Point((p[0].x+p[2].x)/2,(p[0].y+p[2].y)/2);
    l[1] = Line(tp,Point(tp.x-(p[2].y-p[0].y),tp.y+(p[2].x-p[0].x)));
    tp = LineToLine(l[0],l[1]);
    r = Point(tp,p[0]).Length();
    printf("(%.6f,%.6f,%.6f)\n",tp.x,tp.y,r);
}

void InscribedCircle()
{
    for (int i = 0; i < 3; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    if (xmult(Point(p[0],p[1]),Point(p[0],p[2])) < 0)
        swap(p[1],p[2]);
    for (int i = 0; i < 3; i++)
        len[i] = Point(p[i],p[(i+1)%3]).Length();
    tr = (len[0]+len[1]+len[2])/2;
    r = sqrt((tr-len[0])*(tr-len[1])*(tr-len[2])/tr);
    for (int i = 0; i < 2; i++)
    {
        v = Point(p[i],p[i+1]);
        tv = Point(-v.y,v.x);
        tr = tv.Length();
        tv = Point(tv.x*r/tr,tv.y*r/tr);
        tp = Point(p[i].x+tv.x,p[i].y+tv.y);
        l[i].s = tp;
        tp = Point(p[i+1].x+tv.x,p[i+1].y+tv.y);
        l[i].e = tp;
    }
    tp = LineToLine(l[0],l[1]);
    printf("(%.6f,%.6f,%.6f)\n",tp.x,tp.y,r);
}

void TangentLineThroughPoint()
{

}

char com[50];

int main()
{
    while (scanf("%s",com) != EOF)
    {
        if (strcmp(com,"CircumscribedCircle") == 0)
            CircumscribedCircle();
        else if (strcmp(com,"InscribedCircle") == 0)
            InscribedCircle();
        else if (strcmp(com,"TangentLineThroughPoint") == 0)
            TangentLineThroughPoint();
    }
    return 0;
}
