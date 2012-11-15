#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
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
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};
struct Circle
{
    Point c;
    double r;
    Circle(){}
    Circle(Point _c,double _r)
        {
            c = _c;
            r = _r;
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

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

Point NearestPoint(Point p,Line l)
{
    double a,b,t;

    a = l.e.x-l.s.x;
    b = l.e.y-l.s.y;
    t = ((p.x-l.s.x)*a+(p.y-l.s.y)*b)/(a*a+b*b);

    return Point(l.s.x+a*t,l.s.y+b*t);
}

Circle table,ball;
Point pos,v;
double T,speed;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lf%lf%lf",&table.c.x,&table.c.y,&table.r);
        scanf("%lf%lf%lf",&ball.c.x,&ball.c.y,&ball.r);
        scanf("%lf%lf%lf",&v.x,&v.y,&T);
        pos = ball.c;
        Point pc = NearestPoint(table.c,Line(pos,Point(pos.x+v.x,pos.y+v.y)));
        speed = v.Length();
        T *= speed;
        v = Point(v.x/v.Length(),v.y/v.Length());
        table.r -= ball.r;
        double ta,tb,tc,lab,rab,theta;
        ta = Point(table.c,pc).Length();
        tb = table.r;
        tc = sqrt(tb*tb-ta*ta);
        Point pl,res;
        double tim,la,polar;
        Point tp1,tp2;
        pl = Point(pc.x+tc*v.x,pc.y+tc*v.y);
        cout << pl.x << ' ' << pl.y << endl;
        if (Point(pos,pl).Length() >= T)
            res = Point(pos.x+T*v.x,pos.y+T*v.y);
        else
        {
            lab = tc*2;
            theta = atan2(tc,ta)*2;
            rab = table.r*theta;
            T -= Point(pos,pl).Length();
            tim = floor(T/lab);
            la = T-tim*lab;
            if (xmult(Point(pc,table.c),Point(pc,pl)) > 0)  theta = -theta;
            polar = atan2(Point(table.c,pl).y,Point(table.c,pl).x)+theta*tim;
            tp1 = Point(table.c.x+table.r*cos(polar),table.c.y+table.r*sin(polar));
            polar = atan2(Point(table.c,pl).y,Point(table.c,pl).x)+theta*(tim+1.0);
            tp2 = Point(table.c.x+table.r*cos(polar),table.c.y+table.r*sin(polar));
            polar = atan2(Point(tp1,tp2).y,Point(tp1,tp2).x);
            res = Point(tp1.x+la*cos(polar),tp1.y+la*sin(polar));
        }
        printf("%.1f %.1f\n",res.x,res.y);
    }
}
