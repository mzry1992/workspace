#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const double pi = acos(-1.0);
struct Point
{
    double x,y;
};

Point a,b,c;
double r,d,theta[4];

double dist2(Point a,Point b)
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double calcdis2(Point c,Point a,Point b)
{
    double dx = b.x-a.x;
    double dy = b.y-a.y;
    double t = ((c.x-a.x)*dx+(c.y-a.y)*dy)/(dx*dx+dy*dy);

    if (t >= 0 && t <= 1)
    {
        Point tmp;
        tmp.x = a.x+dx*t;
        tmp.y = a.y+dy*t;
        return dist2(c,tmp);
    }
    else
        return min(dist2(c,a),dist2(c,b));
}

int check()
{
    if (a.x == b.x && a.y == b.y)
    {
        if (dist2(a,c) > (r+d)*(r+d))   return 0;
        if (dist2(a,c) < (r-d)*(r-d))
            if (r > d)  return 2;
        return 1;
    }

    Point v,tv,ta,tb;
    double dis1,dis2;

    v.x = a.x-b.x;
    v.y = a.y-b.y;
    double len = sqrt(dist2(a,b));
    v.x /= len;
    v.y /= len;
    v.x *= r;
    v.y *= r;

    tv.x = -v.y;
    tv.y = v.x;
    ta.x = a.x+tv.x;
    ta.y = a.y+tv.y;
    tb.x = b.x+tv.x;
    tb.y = b.y+tv.y;
    dis1 = calcdis2(c,ta,tb);
    if (dis1 <= d*d)   return 1;

    tv.x = v.y;
    tv.y = -v.x;
    ta.x = a.x+tv.x;
    ta.y = a.y+tv.y;
    tb.x = b.x+tv.x;
    tb.y = b.y+tv.y;
    dis2 = calcdis2(c,ta,tb);
    if (dis2 <= d*d)   return 1;

    dis1 = sqrt(dis1);
    dis2 = sqrt(dis2);

    if (dist2(a,c) < (r-d)*(r-d))
            return 2;
    if (dist2(b,c) < (r-d)*(r-d))
            return 2;

    if (fabs(dis1+dis2-2*r) < 1e-8)
        return 2;

    if (dist2(a,c) > (r+d)*(r+d) && dist2(b,c) > (r+d)*(r+d))
        return 0;
    return 1;
}

int main()
{
    //freopen("H.in","r",stdin);
    //freopen("H2.out","w",stdout);
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
        scanf("%lf%lf",&r,&d);

        int cd = check();
        if (cd == 1)
            puts("It is life.");
        else if (cd == 0)
        {
            double dis,ta,tb;
            dis = sqrt(dist2(a,c));
            ta = atan2(a.y-c.y,a.x-c.x);
            tb = asin(r/dis);
            theta[0] = ta-tb;
            theta[1] = ta+tb;

            dis = sqrt(dist2(b,c));
            ta = atan2(b.y-c.y,b.x-c.x);
            tb = asin(r/dis);
            theta[2] = ta-tb;
            theta[3] = ta+tb;

            for (int i = 0; i < 4; i++)
                if (theta[i] < 0)
                    theta[i] += 2*pi;
                else if (theta[i] > 2*pi)
                    theta[i] -= 2*pi;

            double maxdis = 0;
            for (int i = 0; i < 4; i++)
                for (int j = i+1; j < 4; j++)
                {
                    dis = fabs(theta[i]-theta[j]);
                    if (dis > pi)   dis = 2*pi-dis;
                    maxdis = max(maxdis,dis);
                }
            printf("%.2f\n",2*maxdis*d);
        }
        else
            printf("%.2f\n",2*pi*d);
    }
    return 0;
}
