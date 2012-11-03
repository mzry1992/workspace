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
    int x,y;
    double theta;
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

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)    return 0;
    if (a < b)  return -1;
    return 1;
};

bool pcmp(const Point& a,const Point& b)
{
    return cmp(a.theta,b.theta) < 0;
}

Point p[1500],np[3500];
int n,res,totnp;

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        res = n*(n-1)*(n-2)/6;
        if (n >= 3)
        {
            for (int i = 0;i < n;i++)
            {
                totnp = 0;
                for (int j = 0;j < n;j++)
                    if (i != j)
                    {
                        np[totnp].theta = atan2(Point(p[i],p[j]).y,Point(p[i],p[j]).x);
                        np[totnp].x = p[j].x;
                        np[totnp++].y = p[j].y;
                        np[totnp].theta = atan2(Point(p[i],p[j]).y,Point(p[i],p[j]).x)+2*pi;
                        np[totnp].x = p[j].x;
                        np[totnp++].y = p[j].y;
                    }
                sort(np,np+totnp,pcmp);
                int cura,curb,tot;
                cura = curb = tot = 0;
                while (cura+1 < totnp && cmp(np[0].theta+0.5*pi,np[cura+1].theta) > 0)
                    cura++;
                curb = cura;
                for (int j = 0;j < totnp/2;j++)
                {
                    while (cura+1 < totnp && cmp(np[j].theta+0.5*pi,np[cura+1].theta) > 0)
                    {
                        cura++;
                        tot--;
                    }
                    while (curb+1 < totnp && cmp(np[j].theta+pi,np[curb+1].theta) > 0)
                    {
                        curb++;
                        tot++;
                    }
                    res -= tot;
                }
            }
        }
        ft++;
        printf("Scenario %d:\n",ft);
        printf("There are %d sites for making valid tracks\n",res);
    }
    return 0;
}
