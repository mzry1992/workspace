#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-12;
const double pi = acos(-1.0);

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x,y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double operator *(const Point &b)const
    {
        return x*b.y-y*b.x;
    }
    double operator &(const Point &b)const
    {
        return x*b.x+y*b.y;
    }
};

struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s,e = _e;
    }
    Point operator &(const Line &b)const
    {
        Point res = s;
        double t = ((s-b.s)*(b.s-b.e))/((s-e)*(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return res;
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
    for (int i = 0;i < n;)
        if (resn < 2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > eps)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || (res[resn-1]-res[resn-2])*(p[i]-res[resn-1]) > eps)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

const int maxn = 100000;
int n,tn,m;
Point p[maxn],tp[maxn];
double theta[maxn];

double dist2(Point a,Point b)
{
    return (a-b)&(a-b);
}

double dist2(Line line,Point p)
{
    Point res;
    double a,b,t;
    a = line.e.x-line.s.x;
    b = line.e.y-line.s.y;
    t = ((p.x-line.s.x)*a+(p.y-line.s.y)*b)/(a*a+b*b);
    res.x = line.s.x+a*t;
    res.y = line.s.y+b*t;
    return dist2(p,res);
}

double area[maxn],sum[maxn];

int Gao(int la,int lb,Line line)
{
    if (la > lb)
        lb += n;
    int l = la,r = lb,mid;
    while (l < r)
    {
        mid = l+r+1>>1;
        if (cmp((line.e-line.s)*(p[la]-line.s),0)*cmp((line.e-line.s)*(p[mid]-line.s),0) >= 0)
            l = mid;
        else
            r = mid-1;
    }
    return l%n;
}

double Calc(Line l)
{
    double tnow;
    Point v = l.e-l.s;
    tnow = atan2(v.y,v.x);
    if (cmp(tnow,theta[0]) < 0)    tnow += 2*pi;
    int pl = lower_bound(theta,theta+n,tnow)-theta;
    tnow = atan2(-v.y,-v.x);
    if (cmp(tnow,theta[0]) < 0)    tnow += 2*pi;
    int pr = lower_bound(theta,theta+n,tnow)-theta;

    pl = pl%n;
    pr = pr%n;

    if (cmp(v*(p[pl]-l.s),0)*cmp(v*(p[pr]-l.s),0) >= 0)
        return 0.0;

    int xa = Gao(pl,pr,l);
    int xb = Gao(pr,pl,l);

    if (xa > xb)    swap(xa,xb);

    if (cmp(v*(p[xa+1]-p[xa]),0) == 0)  return 0.0;
    if (cmp(v*(p[xb+1]-p[xb]),0) == 0)  return 0.0;

    Point pa,pb;
    pa = Line(p[xa],p[xa+1])&l;
    pb = Line(p[xb],p[xb+1])&l;

    double area0 = sum[xb]-sum[xa+1]+(pa*p[xa+1])/2.0+(p[xb]*pb)/2.0+(pb*pa)/2.0;
    double area1 = sum[xa+n]-sum[xb+1]+(pb*p[xb+1])/2.0+(p[xa]*pa)/2.0+(pa*pb)/2.0;

    return min(area0,area1);
}

int main()
{
    scanf("%d",&tn);
    for (int i = 0;i < tn;i++)
        scanf("%lf%lf",&tp[i].x,&tp[i].y);
    GS(tp,tn,p,n);
    for (int i = 0;i < n;i++)
    {
        Point v = p[(i+1)%n]-p[i];
        theta[i] = atan2(v.y,v.x);
    }
    for (int i = 1;i < n;i++)
        if (theta[i-1] > theta[i]+eps)
            theta[i] += 2*pi;
    for (int i = 0;i < n;i++)
        p[n+i] = p[i];

    sum[0] = 0;
    for (int i = 1;i < 2*n;i++)
    {
        area[i] = (p[i-1]*p[i])/2.0;
        sum[i] = sum[i-1]+area[i];
    }
    scanf("%d",&m);
    for (int i = 0;i < m;i++)
    {
        Line l;
        scanf("%lf%lf%lf%lf",&l.s.x,&l.s.y,&l.e.x,&l.e.y);
        printf("%.10f\n",Calc(l));
    }
	return 0;
}
