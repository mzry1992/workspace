#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

struct Point
{
    double x,y,r;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator &(const Point &b)const
    {
        return x*b.x+y*b.y;
    }
    Point Rotate(double theta)
    {
        return Point(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));
    }
};

int n;
Point red,plat,c;

struct Event
{
    int typ;
    double tim;
    Event() {}
    Event(double _tim,int _typ)
    {
        typ = _typ;
        tim = _tim;
    }
    bool operator <(const Event &b)const
    {
        if (fabs(tim-b.tim) < eps)
            return typ < b.typ;
        return tim < b.tim;
    }
};

Event e[1000];
int tote;

void add(double l,double r)
{
    if (l > pi)
        l -= 2*pi;
    if (l < -pi)
        l += 2*pi;

    if (r > pi)
        r -= 2*pi;
    if (r < -pi)
        r -= 2*pi;

    //printf("add %.6f %.6f\n",l,r);

    e[tote++] = Event(l,1);
    e[tote++] = Event(r,-1);

    if (l > r)
    {
        e[tote++] = Event(pi,-1);
        e[tote++] = Event(-pi,1);
    }
}

double dist(Point a,Point b)
{
    return sqrt((a-b)&(a-b));
}

Point NPT(Point p1,Point p2,Point p)
{
    Point res;
    double a, b, t;
    a = p2.x - p1.x;
    b = p2.y - p1.y;
    t = ((p.x - p1.x) * a + (p.y - p1.y) * b) / (a * a + b * b);
    res.x = p1.x + a * t;
    res.y = p1.y + b * t;
    return res;
}

double cut(Point a,Point b)
{
    Point near = NPT(a,b,plat);
    Point tv = b-a;
    double A = near&near;
    double C = plat.r;
    double B = C*C-A;
    double tvl = tv&tv;

    double tmp = sqrt(B/tvl);

    Point pa = Point(near.x+tmp*tv.x,near.y+tmp*tv.y);
    if (((pa-a)&(b-a)) < 0)
        pa = Point(near.x-tmp*tv.x,near.y-tmp*tv.y);

    //printf("Cut (%.2f %.2f) (%.2f %.2f) = (%.2f %.2f)\n",a.x,a.y,b.x,b.y,pa.x,pa.y);
    return atan2(pa.y,pa.x);
}

int main()
{
    while (true)
    {
        scanf("%d%lf%lf%lf%lf",&n,&plat.r,&red.x,&red.y,&red.r);
        plat.x = plat.y = 0;
        if (n == 0) break;
        tote = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf",&c.x,&c.y,&c.r);
            Point v = c-red,rv = red-c;
            double dist = sqrt(v&v);
            double theta = pi/2-asin((c.r+red.r)/dist);

            double vlen = sqrt(v&v),rvlen = sqrt(rv&rv);
            v = Point(red.r*v.x/vlen,red.r*v.y/vlen);
            rv = Point(c.r*rv.x/rvlen,c.r*rv.y/rvlen);

            Point pa,pb,pc,pd;
            pa = v.Rotate(theta);
            pb = rv.Rotate(theta);
            pc = v.Rotate(-theta);
            pd = rv.Rotate(-theta);

            //printf("(%.2f %.2f) (%.2f %.2f)\n",pa.x,pa.y,pb.x,pb.y);

            pa = Point(red.x+pa.x,red.y+pa.y);
            pb = Point(c.x+pb.x,c.y+pb.y);
            pc = Point(red.x+pc.x,red.y+pc.y);
            pd = Point(c.x+pd.x,c.y+pd.y);

            //add(cut(pa,pb),cut(pc,pd));
            add(cut(pc,pd),cut(pa,pb));
        }
        sort(e,e+tote);
        double res = 0,pre = 0;
        int cur = 0;
        for (int i = 0; i < tote; i++)
        {
            if (cur == n)
                res += e[i].tim-pre;
            cur += e[i].typ;
            pre = e[i].tim;
        }
        //printf("%.6f %.6f\n",res,2*pi);
        printf("%.4f\n",res/(2*pi));
    }
    return 0;
}
