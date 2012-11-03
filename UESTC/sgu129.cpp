#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-10;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    double x,y;
    Point(){};
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    friend Point operator - (Point s,Point e)
    {
        return Point(s.x-e.x,s.y-e.y);
    }
    friend double operator * (Point a,Point b)
    {
        return a.x*b.y-a.y*b.x;
    }
    double length2()
    {
        return x*x+y*y;
    }
};

Point LineToLine(Point as,Point ae,Point bs,Point be,int& sta)
{
    Point res = as;
    if (cmp((as-ae)*(bs-be),0) == 0)
        sta = 0;
    else
        sta = 1;
    double t = ((as-bs)*(bs-be))/((as-ae)*(bs-be));
    res.x += (ae.x-as.x)*t;
    res.y += (ae.y-as.y)*t;
    return res;
}

int n,tn,m,totl,sta;
Point p[410],tp[410],l[10],xp;
double res;

bool OnSeg(Point as,Point ae,Point b)
{
    return (cmp((as-b)*(ae-b),0) == 0 &&
            cmp((b.x-as.x)*(b.x-ae.x),0) <= 0 &&
            cmp((b.y-as.y)*(b.y-ae.y),0) <= 0);
}

bool lcmp(Point a,Point b)
{
    return cmp((a-l[0]).length2(),(b-l[0]).length2()) < 0;
}

bool gcmp(Point a,Point b)
{
    if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void gs(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,gcmp);
    for (int i = 0;i < n;)
        if (resn < 2 || cmp((res[resn-1]-res[resn-2])*(p[i]-res[resn-1]),0) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || cmp((res[resn-1]-res[resn-2])*(p[i]-res[resn-1]),0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
}

double calc(Point s,Point e)
{
    Point mid = Point((s.x+e.x)/2,(s.y+e.y)/2);
    int c = 2;
    for (int i = 0;i < n;i++)
        c = min(c,cmp((p[i]-mid)*(p[(i+1)%n]-mid),0));
    if (c == 1) return sqrt((s-e).length2());
    return 0;
}

int main()
{
    scanf("%d",&tn);
    for (int i = 0;i < tn;i++)
        scanf("%lf%lf",&tp[i].x,&tp[i].y);
    gs(tp,tn,p,n);
    scanf("%d",&m);
    for (int i = 0;i < m;i++)
    {
        scanf("%lf%lf%lf%lf",&l[0].x,&l[0].y,&l[1].x,&l[1].y);
        totl = 2;
        for (int j = 0;j < n;j++)
        {
            xp = LineToLine(l[0],l[1],p[j],p[(j+1)%n],sta);
            if (sta == 0)   continue;
            if (OnSeg(l[0],l[1],xp) == true && OnSeg(p[j],p[(j+1)%n],xp) == true)
                l[totl++] = xp;
        }
        sort(l+1,l+totl,lcmp);
        res = 0;
        for (int j = 1;j < totl;j++)
            res += calc(l[j-1],l[j]);
        printf("%.6f\n",res);
    }
    return 0;
}
