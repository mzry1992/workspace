#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double const pi = acos(-1.0);

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
    Point transXY(int tB)
    {
        double B = pi*tB/180;
        double tx = x,ty = y;
        Point res;
        res.x = tx*cos(B) - ty*sin(B);
        res.y = tx*sin(B) + ty*cos(B);
        return res;
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

int ACB, CAE, EAB, CBD, DBA;
Point vae,vad,vbd,vbe;
Line lae,lad,lbd,lbe;
Point a,b,c,d,e;

double CalcDis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    while (true)
    {
        scanf("%d%d%d%d%d",&ACB, &CAE, &EAB, &CBD, &DBA);
        if (ACB == 0) break;
        if (ACB+CAE+EAB+CBD+DBA != 180)
        {
            printf("Impossible\n");
            continue;
        }
        vae = Point(100,0).transXY(EAB);
        vad = Point(100,0).transXY(CAE+EAB);
        lae = Line(Point(0,0),vae);
        lad = Line(Point(0,0),vad);
        vbd = Point(100,0).transXY(180-DBA);
        vbe = Point(100,0).transXY(180-(DBA+CBD));
        lbd = Line(Point(100,0),Point(100+vbd.x,vbd.y));
        lbe = Line(Point(100,0),Point(100+vbe.x,vbe.y));
        a = Point(0,0);
        b = Point(100,0);
        c = LineToLine(lad,lbe);
        d = LineToLine(lad,lbd);
        e = LineToLine(lae,lbe);
        double res,ae,ad,de;
        ae = CalcDis(a,e);
        ad = CalcDis(a,d);
        de = CalcDis(d,e);
        res = acos((ae*ae+de*de-ad*ad)/(2*ae*de));
        printf("%.2f\n",180*res/pi);
    }
    return 0;
}
