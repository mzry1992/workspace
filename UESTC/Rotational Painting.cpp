#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    friend bool operator < (const Point& a,const Point& b)
    {
        if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
        return cmp(a.x,b.x) < 0;
    }
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

Point CenterOfPolygon(Point poly[],int n)
{
    Point p,p0,p1,p2,p3;
    double m,m0;

    p1 = poly[0];
    p2 = poly[1];
    p.x = p.y = m = 0;
    for (int i = 2;i < n;i++)
    {
        p3 = poly[i];
        p0.x = (p1.x+p2.x+p3.x)/3.0;
        p0.y = (p1.y+p2.y+p3.y)/3.0;
        m0 = p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-
                p1.y*p2.x-p2.y*p3.x-p3.y*p1.x;
        if (cmp(m+m0,0.0) == 0)
            m0 += eps;
        p.x = (m*p.x+m0*p0.x)/(m+m0);
        p.y = (m*p.y+m0*p0.y)/(m+m0);
        m = m+m0;
        p2 = p3;
    }
    return p;
}

double pmult(Point a,Point b)
{
    return a.x*b.x+a.y*b.y;
}

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

void GS(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n);
    for (int i = 0;i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0.0) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0.0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
        resn--;
        if (resn < 3)   resn = 0;
}

int n;
Point p[50000],cent,p0,p1;
Point tp[50000];
int tpn;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        cent = CenterOfPolygon(p,n);
        GS(p,n,tp,tpn);
        int res = 0;
        for (int i = 0;i < tpn;i++)
        {
            p0 = tp[i];
            p1 = tp[(i+1)%tpn];
            if (cmp(pmult(Point(p0,p1),Point(p0,cent)),0.0)
                *cmp(pmult(Point(p1,p0),Point(p1,cent)),0.0) > 0)
                res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
