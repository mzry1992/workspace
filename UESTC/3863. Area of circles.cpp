#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;
struct Point
{
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
    double Len()
        {
            return sqrt(x*x+y*y);
        }
};
struct Circle
{
    Point c;
    double r;
    Circle(){}
    Circle(Point _c,double _r)
        {
            c = _c;
            r = _r;
        }
    double Area()
        {
            return pi*r*r;
        }
};
struct Event
{
    double tim;
    int typ;
    Event(){}
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

double Area(double theta,double r)
{
    return 0.5*r*r*(theta-sin(theta));
}

double xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

int n,tn,toteve,cur;
Circle c[1000];
bool del[1000];
double ans,pre,parea;
Event eve[2000];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
        {
            scanf("%lf%lf%lf",&c[i].c.x,&c[i].c.y,&c[i].r);
            del[i] = false;
        }
        for (int i = 0;i < n;i++)
            if (del[i] == false)
            {
                if (c[i].r == 0.0)  del[i] = true;
                for (int j = 0;j < n;j++)
                    if (i != j)
                        if (del[j] == false)
                            if (cmp(Point(c[i].c,c[j].c).Len()+c[i].r,c[j].r) <= 0)
                                del[i] = true;
            }
        tn = n;
        n = 0;
        for (int i = 0;i < tn;i++)
            if (del[i] == false)
                c[n++] = c[i];
        ans = 0.0;
        for (int i = 0;i < n;i++)
        {
            toteve = 0;
            eve[toteve++] = Event(0.0,1);
            eve[toteve++] = Event(2*pi,-1);
            for (int j = 0;j < n;j++)
                if (i != j)
                    if (cmp(Point(c[i].c,c[j].c).Len(),c[i].r+c[j].r) < 0)
                    {
                        double AB,AC,BC,theta,fai,a0,a1;
                        AB = Point(c[i].c,c[j].c).Len();
                        AC = c[i].r;
                        BC = c[j].r;
                        theta = atan2(Point(c[i].c,c[j].c).y,Point(c[i].c,c[j].c).x);
                        if (cmp(theta,0.0) < 0) theta += 2*pi;
                        fai = acos((AC*AC+AB*AB-BC*BC)/(2.0*AC*AB));
                        a0 = theta-fai;
                        a1 = theta+fai;
                        if (cmp(a0,0.0) < 0)    a0 += 2*pi;
                        if (cmp(a1,2*pi) > 0)   a1 -= 2*pi;
                        if (cmp(a0,a1) < 0)
                        {
                            eve[toteve++] = Event(a0,1);
                            eve[toteve++] = Event(a1,-1);
                        }
                        else
                        {
                            eve[toteve++] = Event(a0,1);
                            eve[toteve++] = Event(2*pi,-1);
                            eve[toteve++] = Event(0.0,1);
                            eve[toteve++] = Event(a1,-1);
                        }
                    }
            sort(eve,eve+toteve,Eventcmp);
            cur = 0;
            pre = 0.0;
            for (int j = 0;j < toteve;j++)
            {
                if (cur == 1 && cmp(eve[j].tim,pre) != 0)
                {
                    ans += Area(eve[j].tim-pre,c[i].r);
                    ans -= xmult(Point(c[i].c.x+c[i].r*cos(eve[j].tim),c[i].c.y+c[i].r*sin(eve[j].tim)),
                                 Point(c[i].c.x+c[i].r*cos(pre),c[i].c.y+c[i].r*sin(pre)))/2.0;
                }
                cur += eve[j].typ;
                if (cur == 1)   pre = eve[j].tim;
            }
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
