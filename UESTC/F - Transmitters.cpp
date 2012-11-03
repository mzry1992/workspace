#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
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

bool EQ(double x,double y)
{
    return fabs(x-y) < eps;
}

bool GT(double x,double y)
{
    return x-y >= eps;
}

bool GET(double x,double y)
{
    return GT(x,y) || EQ(x,y);
}

Point c;
double r,polar[300];
int tn,n,res;
Point p[150];

int main()
{
    while (true)
    {
        scanf("%lf%lf%lf",&c.x,&c.y,&r);
        if (GT(0,r))    break;
        scanf("%d",&tn);
        n = 0;
        for (int i = 0;i < tn;i++)
        {
            scanf("%lf%lf",&p[n].x,&p[n].y);
            if (GET(r,Point(c,p[n]).Length())) n++;
        }
        for (int i = 0;i < n;i++)
            polar[i] = atan2(Point(c,p[i]).y,Point(c,p[i]).x);
        sort(polar,polar+n);
        for (int i = 0;i < n;i++)
            polar[n+i] = polar[i]+2*pi;
        res = 0;
        int pre = 0;
        for (int i = 0;i < n;i++)
        {
            while (GET(pi,polar[pre]-polar[i])) pre++;
            if (pre-i > res)    res = pre-i;
        }
        printf("%d\n",res);
    }
    return 0;
}
