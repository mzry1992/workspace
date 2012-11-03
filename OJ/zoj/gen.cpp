#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
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
    double x,y;
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

bool gcmp(const Point& a,const Point& b)
{
    if (cmp(a.x,b.x) == 0)  return cmp(a.y,b.y) < 0;
    return cmp(a.x,b.x) < 0;
}

void gscan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    int top = 0;
    sort(p,p+n,gcmp);
    for (int i = 0; i < n;)
        if (resn < 2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2; i >= 0;)
        if (resn < top+2 || cmp(xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])),0) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    if (resn < 3)   resn = 0;
}

int n;
Point p[5000],tp[5000];

bool check(int n)
{
    for (int i = 0;i < n;i++)
        if (cmp(p[i].x,p[n].x) == 0 && cmp(p[i].y,p[n].y) == 0) return false;
    return true;
}

int main()
{
    freopen("in.txt","w",stdout);
    for (int ft = 1; ft <= 1000; ft++)
    {
        tp[0] = Point(0,0);
        for (int i = 1; i < 500; i++)
            tp[i] = Point(-rand()%5000,rand()%5000);
        gscan(tp,500,p,n);
        /*p[0] = Point(0,0);
        n = 20;
        for (int i = 1;i < n;i++)
            while (true)
            {
                p[i] = Point(rand()%50,rand()%50);
                if (check(i) == true)
                    break;
            }*/
        Point s = Point(rand()%50+10000,rand()%50);
        if (n > 100)
            n = 100;
        printf("%d\n",n);
        for (int i = 0;i < n;i++)
            printf("%.0f %.0f\n",p[i].x,p[i].y);
        printf("%.0f %.0f\n",s.x,s.y);
    }
    return 0;
}
