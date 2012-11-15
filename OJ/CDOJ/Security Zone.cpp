#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y,r;
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
};

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool grahamScanCmp(Point a,Point b)
{
    if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    for (int i = 0; i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0) //将等号去掉就是求不保留凸包边上的点
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

int n,tn,tc;
Point p[5000],tp[5000],c[25];

void Gao()
{
    tn = 0;
    Point a,b,vab;
    double tab,tt,dis,theta;
    for (int i = 0; i < tc; i++)
        for (int j = 0; j < tc; j++)
            if (i != j)
            {
                a = c[i];
                b = c[j];
                vab = Point(a,b);
                tab = atan2(vab.y,vab.x);
                dis = sqrt(vab.x*vab.x+vab.y*vab.y);
                if (b.r > a.r)
                    tt = asin((b.r-a.r)/dis);
                else
                    tt = -asin((a.r-b.r)/dis);
                theta = tab+pi/2+tt;
                tp[tn++] = Point(a.x+a.r*cos(theta),a.y+a.r*sin(theta));
                tp[tn++] = Point(b.x+b.r*cos(theta),b.y+b.r*sin(theta));
            }
}

double CalcDis(Point a,Point b)
{
    int ba,bb;
    Point tv;
    for (int i = 0; i < tc; i++)
    {
        tv = Point(c[i],a);
        if (cmp(tv.x*tv.x+tv.y*tv.y,c[i].r*c[i].r) == 0)
            ba = i;
        tv = Point(c[i],b);
        if (cmp(tv.x*tv.x+tv.y*tv.y,c[i].r*c[i].r) == 0)
            bb = i;
    }
    if (ba == bb)
    {
        double theta0,theta1,theta;
        tv = Point(c[ba],a);
        theta0 = atan2(tv.y,tv.x);
        tv = Point(c[bb],b);
        theta1 = atan2(tv.y,tv.x);
        if (theta0 < -pi) theta0 += 2*pi;
        if (theta0 > pi)    theta0 -= 2*pi;
        if (theta1 < -pi) theta1 += 2*pi;
        if (theta1 > pi)    theta1 -= 2*pi;
        if (theta0 < theta1)    theta = theta1-theta0;
        else
            theta = 2*pi+theta1-theta0;
        return theta*c[ba].r;
    }
    else
    {
        tv = Point(a,b);
        return sqrt(tv.x*tv.x+tv.y*tv.y);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 0; ft < t; ft++)
    {
        scanf("%d",&tc);
        for (int i = 0; i < tc; i++)
            scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
        double res;
        if (tc == 1)
            res = c[0].r*2*pi;
        else
        {
            Gao();
            grahamScan(tp,tn,p,n);
            res = 0;
            for (int i = 0; i < n; i++)
                res += CalcDis(p[i],p[(i+1)%n]);
        }
        printf("%.10f\n",res);
    }
    return 0;
}
