#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-12;
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
    double Len()
    {
        return sqrt(x*x+y*y);
    }
};
struct Circle
{
    Point c;
    double r;
    Circle() {}
    Circle(Point _c,double _r)
    {
        c = _c;
        r = _r;
    }
};
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
};

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

bool Eventcmp(const Event& a,const Event& b)
{
    if (cmp(a.tim,b.tim) == 0)  return a.typ > b.typ;
    return cmp(a.tim,b.tim) < 0;
}

int n,tn,tote;
Circle c[1000];
bool del[1000];
Event e[1000];

double calc(double x)
{
    double res = 0.0,A,B,C;
    tote = 0;
    for (int i = 0; i < n; i++)
        if (cmp(fabs(x-c[i].c.x),c[i].r) <= 0)
        {
            C = c[i].r;
            B = fabs(x-c[i].c.x);
            A = sqrt(C*C-B*B);
            e[tote++] = Event(c[i].c.y-A,1);
            e[tote++] = Event(c[i].c.y+A,-1);
        }
    int cur = 0;
    double pre = 0.0;
    sort(e,e+tote,Eventcmp);
    for (int i = 0; i < tote; i++)
    {
        if (cur == 1 && cmp(e[i].tim,pre) != 0)
            res += e[i].tim-pre;
        cur += e[i].typ;
        if (cur == 1)   pre = e[i].tim;
    }
    return res;
}

double Simp(double l,double r)
{
    double h = (r-l)/2.0;
    return h*(calc(l)+4*calc((l+r)/2.0)+calc(r))/3.0;
}

double rSimp(double l,double r)
{
    double mid = (l+r)/2.0;
    if (abs((Simp(l,r)-Simp(l,mid)-Simp(mid,r)))/15 < eps)
        return Simp(l,r);
    else
        return rSimp(l,mid)+rSimp(mid,r);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf",&c[i].c.x,&c[i].c.y,&c[i].r);
            del[i] = false;
        }
        for (int i = 0; i < n; i++)
            if (del[i] == false)
            {
                if (c[i].r == 0.0)  del[i] = true;
                for (int j = 0; j < n; j++)
                    if (i != j)
                        if (del[j] == false)
                            if (cmp(Point(c[i].c,c[j].c).Len()+c[i].r,c[j].r) <= 0)
                                del[i] = true;
            }
        tn = n;
        n = 0;
        for (int i = 0; i < tn; i++)
            if (del[i] == false)
                c[n++] = c[i];
        double l,r;
        l = r = c[0].c.x-c[0].r;
        for (int i = 0; i < n; i++)
        {
            if (cmp(l,c[i].c.x-c[i].r) > 0)
                l = c[i].c.x-c[i].r;
            if (cmp(r,c[i].c.x+c[i].r) < 0)
                r = c[i].c.x+c[i].r;
        }
        double len = (r-l)/100,res;
        res = 0.0;
        for (int i = 0;i < 100;i++)
            res += rSimp(l+i*len,l+(i+1)*len);
        printf("%.3f\n",res);
    }
    return 0;
}

