#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

double eps = 1e-12;
double pi = acos(-1.0);

struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x,y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator *(const Point& b)const
    {
        return x*b.y-y*b.x;
    }
    double operator &(const Point& b)const
    {
        return x*b.x+y*b.y;
    }
    Point Rotate(double theta)
    {
        return Point(x*cos(theta)-y*sin(theta),x*sin(theta)+y*cos(theta));
    }
};

bool GScmp(Point a,Point b)
{
    if (fabs(a.x-b.x) < eps)
        return a.y < b.y-eps;
    return a.x < b.x-eps;
}

void GS(Point p[],int n,Point res[],int &resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,GScmp);
    for (int i = 0; i < n;)
        if (resn < 2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > eps)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > eps)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
}

double dist2(Point a,Point b)
{
    return (a-b)&(a-b);
}

int tn,n,q;
double r;
Point tp[30],p[30];

int main()
{
    while (true)
    {
        scanf("%d%lf%d",&tn,&r,&q);
        if (tn == 0) break;
        for (int i = 0; i < tn; i++)
            scanf("%lf%lf",&tp[i].x,&tp[i].y);
        GS(tp,tn,p,n);
        int pre;
        for (int i = 0; i < n; i++)
            if (fabs((p[i]&p[i])-r*r) < eps)
                pre = i;

        for (int tim = 0; tim < q; tim++)
        {
            double mintheta = 1e100;
            int pos;
            for (int i = 0; i < n; i++)
                if (i != pre)
                {
                    double theta = acos(1-dist2(p[pre],p[i])/(2.0*r*r));
                    double theta0 = atan2(p[pre].y,p[pre].x)-theta;
                    Point nxt = Point(r*cos(theta0),r*sin(theta0));

                    theta = atan2(nxt.y-p[pre].y,nxt.x-p[pre].x)-
                            atan2(p[i].y-p[pre].y,p[i].x-p[pre].x);

                    if (theta < 0)
                        theta = 2*pi-theta;

                    if (theta < mintheta)
                    {
                        mintheta = theta;
                        pos = i;
                    }
                }

            double maxdis = 0;
            for (int i = 0; i < n; i++)
                if (i != pre)
                {
                    Point tv = (p[i]-p[pre]);
                    tv = tv.Rotate(mintheta);
                    p[i] = Point(p[pre].x+tv.x,p[pre].y+tv.y);

                    if (fabs((p[i]&p[i])-r*r) < eps)
                        if (sqrt(dist2(p[pre],p[i])) > maxdis)
                            pos = i;
                }

            printf("%.12f %.12f\n",p[pos].x,p[pos].y);
            pre = pos;
        }
    }
    return 0;
}
