#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-10;

int cmp(double a,double b)
{
    if (fabs(a-b) < eps)  return 0;
    if (a < b)  return -1;
    return 1;
}

struct Point
{
    int x,y,id,typ;
    double theta;
    Point() {}
    Point(int _x,int _y)
    {
        x = _x;
        y = _y;
    }
    void calctheta()
    {
        theta = atan2(y,x);
    }
    bool operator < (const Point& b)const
    {
        if (cmp(theta,b.theta) == 0)
            return typ > b.typ;
        return cmp(theta,b.theta) < 0;
    }
};
struct Line
{
    Point s,e;
};

int n;
Line l[1500];
Point c,p[6000];
bool in[1500];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%d%d%d%d",&l[i].s.x,&l[i].s.y,&l[i].e.x,&l[i].e.y);
        scanf("%d%d",&c.x,&c.y);
        for (int i = 0; i < n; i++)
        {
            l[i].s = Point(l[i].s.x-c.x,l[i].s.y-c.y);
            l[i].e = Point(l[i].e.x-c.x,l[i].e.y-c.y);
            p[i*2] = l[i].s;
            p[i*2+1] = l[i].e;
            p[i*2].calctheta();
            p[i*2+1].calctheta();
            p[i*2].id = p[i*2+1].id = i;
            double theta = p[i*2].theta-p[i*2+1].theta;
            if (cmp(theta,0) < 0)  theta += 2*pi;
            if (cmp(theta,pi) > 0)
            {
                p[i*2].typ = 1;
                p[i*2+1].typ = -1;
            }
            else
            {
                p[i*2].typ = -1;
                p[i*2+1].typ = 1;
            }
        }
        sort(p,p+2*n);
        for (int i = 0; i < 2*n; i++)
            p[2*n+i] = p[i];
        for (int i = 0; i < n; i++)
            in[i] = false;
        int res = 0;
        int tot = 0;
        for (int i = 0; i < 4*n; i++)
        {
            res = max(res,tot);
            if (p[i].typ == -1)
            {
                if (in[p[i].id] == true)
                {
                    in[p[i].id] = false;
                    tot--;
                }
            }
            else
            {
                if (in[p[i].id] == false)
                {
                    in[p[i].id] = true;
                    tot++;
                }
            }
            res = max(res,tot);
        }
        printf("%d\n",res);
    }
    return 0;
}
