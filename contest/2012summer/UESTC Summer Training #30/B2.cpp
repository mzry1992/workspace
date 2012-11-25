#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double eps = 1e-9;
const double pi = acos(-1.0);

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

Point p[200];
int n,m;

inline double dist2(Point a,Point b)
{
    return (a-b)&(a-b);
}

struct Event
{
    double tim;
    int typ;
    Event() {}
    Event(double _tim,int _typ)
    {
        tim = _tim;
        typ = _typ;
    }
    bool operator <(const Event& b)const
    {
        if (fabs(tim-b.tim) < eps)
            return typ > b.typ;
        return tim < b.tim;
    }
} e[2000];
int tote;

void add(double l,double r)
{
    if (l < -pi)
    {
        l += 2*pi;
        r += 2*pi;
    }
    e[tote++] = Event(l,1);
    e[tote++] = Event(r,-1);
    e[tote++] = Event(2*pi+l,1);
    e[tote++] = Event(2*pi+r,-1);
}

inline int calc(double r)
{
    r += 0.5;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        tote = 0;
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                Point v = p[j]-p[i];
                double theta = atan2(v.y,v.x);
                if (dist2(p[i],p[j]) > 4*r*r)
                {
                    double vlen = sqrt(v&v)/2;
                    double theta2 = acos(r/vlen);
                    add(theta-pi/2,theta-theta2);
                    add(theta+theta2,theta+pi/2);
                }
                else
                    add(theta-pi/2,theta+pi/2);
            }
        sort(e,e+tote);
        int cnt = 0,nowmax = 0;
        for (int j = 0; j < tote; j++)
        {
            cnt += e[j].typ;
            nowmax = max(nowmax,cnt);
        }
        nowmax++;
        res = max(res,nowmax);
        if (res >= m)
            return res;
    }
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    if (calc(0) >= m)
        puts("0.000000");
    else
    {
        double l,r,mid;
        l = 0;
        r = 1e6;
        for (int tim = 0; tim < 45; tim++)
        {
            mid = (l+r)/2;
            if (calc(mid) < m)
                l = mid;
            else
                r = mid;
        }
        printf("%.8f\n",l*2);
    }
    return 0;
}
