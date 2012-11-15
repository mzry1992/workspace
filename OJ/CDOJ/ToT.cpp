#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long h,x,y,res,n,m;

long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
        {
             x = _x;
             y = _y;
        }
};

struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
        {
            s = _s;
            e = _e;
        }
};

Point LineToLine(Line a,Line b)
{
    Point res = a.s;
    double t = ((a.s.x-b.s.x)*(b.s.y-b.e.y)-(a.s.y-b.s.y)*(b.s.x-b.e.x))/
                ((a.s.x-a.e.x)*(b.s.y-b.e.y)-(a.s.y-a.e.y)*(b.s.x-b.e.x));
    res.x += (a.e.x-a.s.x)*t;
    res.y += (a.e.y-a.s.y)*t;
    return res;
}

long long getline(long long xa,long long ya,long long xb,long long yb)
{
    if (xa == xb)   return yb-ya+1;
    if (ya == yb)   return xb-xa+1;
    return gcd(xb-xa,yb-ya)+1;
}

Point p;
long long tx,sum1,sum2;

long long getit(long long xa,long long ya,long long x)
{
    return ya*x/xa;
}

int main()
{
    while (scanf("%lld%lld%lld",&h,&x,&y) != EOF)
    {
        if (h == 0) res = 0;
        else if (x == y)
        {
            n = h*x;
            m = getline(0,0,0,h)+getline(0,0,x,y)+getline(0,h,x,y)-3;
            res = (n-m)/2+1+getline(0,0,0,h)+getline(0,h,x,y)-3;
        }
        else
        {
            p = LineToLine(Line(Point(0,0),Point(y,y)),Line(Point(0,h),Point(x,y)));
            tx = (long long)floor(p.x);
            /*n = h*tx;
            m = getline(0,0,0,h)+getline(0,0,tx,tx)+getline(0,h,tx,tx)-3;
            sum1 = (n+m)/2+1;
            n = tx-h;
            m = getline(0,h,tx,tx)+getline(0,h,tx-1,tx)+getline(tx-1,tx,tx,tx)-3;
            sum2 = (n-m)/2+1;
            if (tx*(y-h) == (tx-h)*x)   sum2 = 0;
            res = sum1+sum2-getline(0,0,tx,tx);*/
            res = 0;
            for (int i = 0;i <= tx;i++)
            {
                res += getit(x,y-h,i)+h-i;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}
