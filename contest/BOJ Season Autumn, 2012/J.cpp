#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const double eps = 1e-12;

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
};

bool GScmp(Point a,Point b)
{
    if (fabs(a.x-b.x) < eps)
        return a.y < b.y-eps;
    return a.x < b.x-eps;
}

void GS(Point p[],int n,Point res[],int& resn)
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

//y = aa*x^2+ab*x;
double aa,ab;
inline double calcy(double x)
{
    return aa*x*x+ab*x;
}

bool OnSeg(Point a,Point s,Point e)
{
    return ((e-a)&(s-a)) < -eps;
}

bool check(Point s,Point e)
{
    if (s.x > e.x+eps)
        swap(s,e);
    if (fabs(s.x-e.x) < eps)
    {
        if (s.y > e.y+eps)
            swap(s,e);
        double py = calcy(s.x);
        if (py < s.y+eps || py > e.y-eps)   return false;
        return true;
    }
    else
    {
        double la = (s.y-e.y)/(s.x-e.x);
        double lb = s.y-la*s.x;

        double a = aa;
        double b = ab-la;
        double c = -lb;

        double deta = b*b-4*a*c;
        if (deta < eps) return false;
        Point tmp;
        tmp.x = (-b+sqrt(deta))/(2*a);
        tmp.y = calcy(tmp.x);

        if (OnSeg(tmp,s,e))
            return true;

        tmp.x = (-b-sqrt(deta))/(2*a);
        tmp.y = calcy(tmp.x);
        if (OnSeg(tmp,s,e))
            return true;
    }
    return false;
}

Point p[100],tp[100],v;
double g;
int n,tn;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%lf%lf%lf",&tn,&v.x,&v.y,&g);

        aa = -g/(2*v.x*v.x);
        ab = v.y/v.x;

        for (int i = 0; i < tn; i++)
            scanf("%lf%lf",&tp[i].x,&tp[i].y);

        GS(tp,tn,p,n);

        bool flag = false;
        for (int i = 0; i < n; i++)
            flag |= check(p[i],p[(i+1)%n]);

        if (flag)
        {
            puts("INF");
            continue;
        }

        int cnta = 0,cntb = 0;
        for (int i = 0; i < n; i++)
        {
            Point mid = Point((p[i].x+p[(i+1)%n].x)/2,(p[i].y+p[(i+1)%n].y)/2);
            double py = calcy(mid.x);

            if (py < mid.y-eps)
                cnta ++;
            else if (py > mid.y+eps)
                cntb ++;
        }

        if (cnta > 0 && cntb > 0)
        {
            puts("INF");
            continue;
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            double py = calcy(p[i].x);
            if (fabs(py-p[i].y) < eps)  res++;

            Point s = p[i];
            Point e = p[(i+1)%n];

            if (s.x > e.x+eps)
                swap(s,e);

            double la = (s.y-e.y)/(s.x-e.x);
            double lb = s.y-la*s.x;

            double a = aa;
            double b = ab-la;
            double c = -lb;

            double deta = b*b-4*a*c;
            if (fabs(deta) < eps)
            {
                Point tmp;
                tmp.x = (-b)/(2*a);
                tmp.y = calcy(tmp.x);
                if (OnSeg(tmp,s,e))
                    res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

