#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;
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
struct Interval
{
    double l,r;
    Interval(){}
    Interval(double _l,double _r)
        {
            l = _l;
            r = _r;
        }
};

bool cmp(Interval a,Interval b)
{
    if (a.l == b.l)    return a.r < b.r;
    return a.l < b.l;
}

Interval Gao(Point light,Circle c)
{
    double cx = c.c.x, cy = c.c.y, r = c.r, bx = light.x, by = light.y;

    double delta = (bx-cx)*(bx-cx) + (by-cy)*(by-cy);
    double k2 = r/sqrt(delta - r*r);
    double k1 = -(bx-cx)/(by-cy);

    return Interval((k1-k2)/(1+k1*k2)*by + bx,(k1+k2)/(1-k1*k2)*by + bx);
}

int n,totres;
Point light;
Circle c;
Interval res[500];

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%lf%lf",&light.x,&light.y);
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf%lf",&c.c.x,&c.c.y,&c.r);
            res[i] = Gao(light,c);
        }
        sort(res,res+n,cmp);
        totres = 1;
        for (int i = 1;i < n;i++)
            if (res[i].l > res[totres-1].r)
                res[totres++] = res[i];
            else
                res[totres-1].r = max(res[totres-1].r,res[i].r);
        for (int i = 0;i < totres;i++)
            if (res[i].r < 0.0) res[i].r -= 1e-6;
            else res[i].r += 1e-6;
        for (int i = 0;i < totres;i++)
            printf("%.2f %.2f\n",res[i].l,res[i].r);
        printf("\n");
    }
    return 0;
}
