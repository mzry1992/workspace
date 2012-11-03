#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y,typ;
    Point(){}
    Point(int _x,int _y)
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

struct even
{
    double theta;
    int typ;
    even(){}
    even(double _theta,int _typ)
        {
            theta = _theta;
            typ = _typ;
        }
};

bool cmp(const even& a,const even& b)
{
    return a.theta < b.theta;
}

const double eps = 1e-7;
const double pi = acos(-1.0);
Point p[2000];
int n,res,tote,tot,val,cur,pre,precur;
even e[4000];

bool EQ(double x,double y)
{
    return fabs(x-y) < eps;
}

bool GT(double x,double y)
{
    return x-y >= eps;
}

bool GET(double x,double y)
{
    return GT(x,y) || EQ(x,y);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].typ = 0;
        }
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&p[n+i].x,&p[n+i].y);
            p[n+i].typ = 1;
        }
        res = 0;
        for (int i = 0;i < 2*n;i++)
        {
            tote = 0;
            for (int j = 0;j < 2*n;j++)
                if (i != j)
                    e[tote++] = even(atan2(Point(p[i],p[j]).y,Point(p[i],p[j]).x),p[j].typ);
            sort(e,e+tote,cmp);
            for (int j = 0;j < tote;j++)
                e[tote+j] = even(e[j].theta+2*pi,e[j].typ);
            tot = 1;
            val = p[i].typ;
            pre = 0;
            for (int j = 0;j < tote;j++)
            {
                while (GT(pi,e[pre].theta-e[j].theta))
                {
                    tot++;
                    val += e[pre].typ;
                    pre++;
                }
                tot--;
                val -= e[j].typ;
                if (tot == n && val*2 == n) res++;
            }
        }
        printf("%d\n",res/2);
    }
}
