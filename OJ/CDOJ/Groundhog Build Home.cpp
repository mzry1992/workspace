#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-6;
struct Point
{
    int x,y;
    Point(){};
    Point(int _x,int _y)
        {
            x = _x;
            y = _y;
        }
    Point(Point _a,Point _b)
        {
            x = _b.x-_a.x;
            y = _b.y-_a.y;
        }
    int len()
        {
            return x*x+y*y;
        }
    double Length()
        {
            return sqrt((double)(x*x+y*y));
        }
};

bool EQ(Point a,Point b)
{
    return a.x == b.x && b.y == a.y;
}

int xmult(Point a,Point b)
{
    return a.x*b.y-a.y*b.x;
}

bool conPoint(Point p[],int n)
{
    for (int i = 1;i < n;i++)
        if (EQ(p[i],p[0]) == false) return false;
    return true;
}

bool conLine(Point p[],int n)
{
    for (int i = 2;i < n;i++)
        if (xmult(Point(p[0],p[1]),Point(p[0],p[i])) != 0)  return false;
    return true;
}

bool grahamScanCmp(Point a,Point b)
{
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}

void grahamScan(Point p[],int n,Point res[],int& resn)
{
    resn = 0;
    if (n < 3 || conPoint(p,n) == true || conLine(p,n) == true) return;
    int top = 0;
    sort(p,p+n,grahamScanCmp);
    for (int i = 0;i < n;)
        if (resn < 2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) > 0)
            res[resn++] = p[i++];
        else
            --resn;
    top = resn-1;
    for (int i = n-2;i >= 0;)
        if (resn < top+2 || xmult(Point(res[resn-2],res[resn-1]),Point(res[resn-1],p[i])) > 0)
            res[resn++] = p[i--];
        else
            --resn;
    resn--;
    if (resn < 3)   resn = 0;
}

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

Event e[4010];
int tote;
int n,newn,tpn,x,y;
Point p[1010],tp[1010],pmin,pmax;
double res;

int main()
{
    while (scanf("%d%d%d",&x,&y,&tpn) != EOF)
    {
        for (int i = 0;i < tpn;i++)   scanf("%d%d",&tp[i].x,&tp[i].y);
        if (conPoint(tp,tpn) == true)
        {
            printf("(%.1f,%.1f).\n",(double)tp[0].x,(double)tp[0].y);
            printf("%.1f\n",0.0);
            continue;
        }
        if (conLine(tp,tpn) == true)
        {
            pmin = pmax = tp[0];
            for (int i = 0;i < tpn;i++)
            {
                if ((tp[i].x == pmin.x && tp[i].y < pmin.y) || tp[i].x < pmin.x)
                    pmin = tp[i];
                if ((tp[i].x == pmax.x && tp[i].y > pmax.y) || tp[i].x > pmax.x)
                    pmax = tp[i];
            }
            printf("(%.1f,%.1f).\n",(double)(pmin.x+pmax.x)/2.0,(double)(pmin.y+pmax.y)/2.0);
            printf("%.1f\n",Point(pmin,pmax).Length()/2.0);
            continue;
        }
        grahamScan(tp,tpn,p,n);
        double resr,resx,resy;
        resr = 1e100;
        for (int i = 0;i < n;i++)
        {
            double l,r,mid;
            l = 0.0;
            r = sqrt((double)(x*x+y*y))/2.0;
            for (int tims = 0;tims <= 50;tims++)
            {
                mid = (l+r)/2.0;
                tote = 0;
                e[tote++] = Event(-pi,1);
                e[tote++] = Event(pi,-1);
                for (int j = 0;j < n;j++)
                    if (i != j)
                        if (cmp(Point(p[i],p[j]).Length(),2.0*mid) <= 0)
                        {
                            double A,B,C,theta,fai,a0,a1;
                            A = Point(p[i],p[j]).Length()/2.0;
                            C = mid;
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
                int res = 0;
                int tres = 0;
                double th;
                for (int j = 0;j < tote;j++)
                {
                    tres += e[j].typ;
                    if (tres == n)
                        th = e[j].pos;
                    if (tres > res)
                        res = tres;
                }
                if (res == n)
                {
                    r = mid;
                    if (cmp(resr,r) > 0)
                    {
                        resr = r;
                        resx = p[i].x+cos(th)*r;
                        resy = p[i].y+sin(th)*r;
                    }
                }
                else
                    l = mid;
            }
        }
        printf("(%.1f,%.1f).\n",resx,resy);
        printf("%.1f\n",resr);
    }
    return 0;
}
