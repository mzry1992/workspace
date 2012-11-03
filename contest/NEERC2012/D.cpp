#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-10;
struct Point
{
    double x,y;
    Point() {}
    Point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    Point operator -(const Point& b)const
    {
        return Point(x-b.x,y-b.y);
    }
    double Length()
    {
        return sqrt(x*x+y*y);
    }
};
struct Circle
{
    Point c;
    double r;
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

int cmp(const double& a,const double& b)
{
    if (fabs(a-b) < eps)	return 0;
    if (a < b)	return -1;
    return 1;
}

bool Eventcmp(const Event& a,const Event& b)
{
    return cmp(a.tim,b.tim) < 0;
}

double dist(Point a,Point b)
{
    Point tmp = a-b;
    return tmp.Length();
}

int cur,tote;
Circle c[3];
double pre[3],AB,AC,BC,theta,fai,a0,a1;
Event e[20];
Point lab;

void Gao()
{
    if (cmp(dist(c[0].c,c[1].c),2*c[0].r) <= 0 &&
            cmp(dist(c[0].c,c[2].c),2*c[0].r) <= 0)
    {
        puts("Now we have enough power");
        Point ta = Point((c[0].c.x+c[1].c.x)/2.0,(c[0].c.y+c[1].c.y)/2.0);
        printf("%.10f %.10f\n",ta.x,ta.y);
        ta = Point((c[0].c.x+c[2].c.x)/2.0,(c[0].c.y+c[2].c.y)/2.0);
        printf("%.10f %.10f\n",ta.x,ta.y);
        return;
    }
    for (int mid = 0; mid < 3; mid++)
    {
        c[mid].r *= 2;

        Point ta = Point((c[(mid+1)%3].c.x+c[(mid+2)%3].c.x)/2,(c[(mid+1)%3].c.y+c[(mid+2)%3].c.y)/2);

        bool flag = true;
        for (int k = 0; k < 3; k++)
            if (cmp(dist(ta,c[k].c),c[k].r) > 0)
            {
                flag = false;
                break;
            }
        if (flag)
        {
            puts("Now we have enough power");
            printf("%.10f %.10f\n",ta.x,ta.y);
            ta = Point((ta.x+c[mid].c.x)/2.0,(ta.y+c[mid].c.y)/2.0);
            printf("%.10f %.10f\n",ta.x,ta.y);
            return;
        }

        for (int i = 0; i < 3; i++)
        {
            tote = 0;
            e[tote++] = Event(-pi,1);
            e[tote++] = Event(pi,-1);
            for (int j = 0; j < 3; j++)
                if (i != j)
                {
                    lab = Point(c[j].c.x-c[i].c.x,c[j].c.y-c[i].c.y);
                    AB = lab.Length();
                    AC = c[i].r;
                    BC = c[j].r;
                    if (cmp(AB+AC,BC) <= 0)
                    {
                        e[tote++] = Event(-pi,1);
                        e[tote++] = Event(pi,-1);
                        continue;
                    }
                    if (cmp(AB+BC,AC) <= 0)	continue;
                    if (cmp(AB,AC+BC) > 0)	continue;
                    theta = atan2(lab.y,lab.x);
                    fai = acos((AC*AC+AB*AB-BC*BC)/(2.0*AC*AB));
                    a0 = theta-fai;
                    if (cmp(a0,-pi) < 0)	a0 += 2*pi;
                    a1 = theta+fai;
                    if (cmp(a1,pi) > 0)	a1 -= 2*pi;
                    if (cmp(a0,a1) > 0)
                    {
                        e[tote++] = Event(a0,1);
                        e[tote++] = Event(pi,-1);
                        e[tote++] = Event(-pi,1);
                        e[tote++] = Event(a1,-1);
                    }
                    else
                    {
                        e[tote++] = Event(a0,1);
                        e[tote++] = Event(a1,-1);
                    }
                }
            sort(e,e+tote,Eventcmp);
            cur = 0;
            pre[0] = pre[1] = pre[2] = -pi;
            for (int j = 0; j < tote; j++)
            {
                if (cur != 0 && cmp(e[j].tim,pre[cur]) != 0)
                {
                    //if (cur == 3)
                    {
                        Point ta = Point(c[i].c.x+c[i].r*cos(pre[cur]),c[i].c.y+c[i].r*sin(pre[cur]));
                        Point tb = Point(c[i].c.x+c[i].r*cos(e[j].tim),c[i].c.y+c[i].r*sin(e[j].tim));

                        //ta -> tb;
                        //printf("ta = (%.3f %.3f) ,tb = (%.3f %.3f)\n",ta.x,ta.y,tb.x,tb.y);
                        ta = Point((ta.x+tb.x)/2.0,(ta.y+tb.y)/2.0);

                        bool flag = true;
                        for (int k = 0; k < 3; k++)
                            if (cmp(dist(ta,c[k].c),c[k].r) > 0)
                            {
                                flag = false;
                                break;
                            }
                        if (flag)
                        {
                            puts("Now we have enough power");
                            printf("%.10f %.10f\n",ta.x,ta.y);
                            ta = Point((ta.x+c[mid].c.x)/2.0,(ta.y+c[mid].c.y)/2.0);
                            printf("%.10f %.10f\n",ta.x,ta.y);
                            return;
                        }
                    }
                }
                cur += e[j].typ;
                pre[cur] = e[j].tim;
            }
        }

        c[mid].r /= 2;
    }

    puts("Death");
}

int main()
{
    double _r;
    scanf("%lf",&_r);
    c[0].r = c[1].r = c[2].r = _r;
    for (int i = 0; i < 3; i++)
        scanf("%lf%lf",&c[i].c.x,&c[i].c.y);
    Gao();
    return 0;
}
