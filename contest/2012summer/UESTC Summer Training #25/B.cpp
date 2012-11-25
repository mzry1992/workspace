#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Point
{
    double x,y;
    Point operator -(const Point& b)const
    {
        Point res;
        res.x = x-b.x;
        res.y = y-b.y;
        return res;
    }
    double operator *(const Point& b)const
    {
        return x*b.x+y*b.y;
    }
};

double dist(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

double len(Point a)
{
    return a.x*a.x+a.y*a.y;
}

double angle(Point a,Point b)
{
    return (a*b)/sqrt(len(a)*len(b));
}

Point p[100],fs,pre;
int n,now;
double d;

int main()
{
    while (true)
    {
        scanf("%lf%lf%d%d%lf",&fs.x,&fs.y,&n,&now,&d);
        if (n == 0)
            break;
        for (int i = 0;i < n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        now--;
        pre = fs;

        bool first = true;
        while (true)
        {
            if (!first)
                printf(" ");
            first = false;
            printf("%d",now+1);

            int id = -1;
            for (int i = 0;i < n;i++)
                if (i != now)
                    if (dist(p[i],p[now]) <= d*d)
                    {
                        if ((p[i]-p[now])*fs >= 0 && (p[i]-p[now])*pre >= 0)
                        {
                            if (id == -1)
                                id = i;
                            else if (angle(p[i]-p[now],fs) > angle(p[id]-p[now],fs))
                                id = i;
                        }
                    }
            if (id == -1)
                break;
            pre = p[id]-p[now];
            now = id;
        }
        printf("\n");
    }
	return 0;
}
