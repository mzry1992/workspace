#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
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
    double Length()
        {
            return sqrt(x*x+y*y);
        }
};

struct Event
{
    double pos;
    int typ;
    Event(){}
    Event(double _pos,int _typ)
        {
            pos = _pos;
            typ = _typ;
        }
};

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
}

bool EventCmp(const Event& a,const Event& b)
{
    if (cmp(a.pos,b.pos) == 0)
        return a.typ > b.typ;
    return cmp(a.pos,b.pos) < 0;
}

Point p[300];
int n,res,tote;
Event e[600];

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        res = 0;
        for (int i = 0;i < n;i++)
        {
            tote = 0;
            e[tote++] = Event(-pi,1);
            e[tote++] = Event(pi,-1);
            for (int j = 0;j < n;j++)
                if (i != j)
                    if (cmp(Point(p[i],p[j]).Length(),2.0) <= 0)
                    {
                        double A,B,C,theta,fai,a0,a1;
                        A = Point(p[i],p[j]).Length()/2.0;
                        C = 1.0;
                        B = sqrt(C*C-A*A);
                        theta = atan2(Point(p[i],p[j]).y,Point(p[i],p[j]).x);
                        fai = atan2(B,A);
                        a0 = theta-fai;
                        a1 = theta+fai;
                        if (cmp(a0,-pi) < 0)    a0 += 2*pi;
                        if (cmp(a1,pi) > 0)     a1 -= 2*pi;
                        if (cmp(a0,a1) <= 0)
                        {
                            e[tote++] = Event(a0,1);
                            e[tote++] = Event(a1,-1);
                        }
                        else
                        {
                            e[tote++] = Event(a0,1);
                            e[tote++] = Event(pi,-1);
                            e[tote++] = Event(-pi,1);
                            e[tote++] = Event(a1,-1);
                        }
                    }
            sort(e,e+tote,EventCmp);
            int tres = 0;
            for (int i = 0;i < tote;i++)
            {
                tres += e[i].typ;
                if (tres > res)
                    res = tres;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
