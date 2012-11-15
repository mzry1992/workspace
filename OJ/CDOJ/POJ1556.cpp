#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double EPS = 1e-8;
int n;
struct doors
{
    double p;
    double x[5];
}d[1000];
struct point
{
    double x,y;
};
double dp[1000][4];

bool cmp(doors a,doors b)
{
    return a.p < b.p;
}

double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double det(double x1,double y1,double x2,double y2)
{
    return x1*y2-x2*y1;
}

double cross(point a,point b,point c)
{
    return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}

int dblcmp(double d)
{
    if (fabs(d) < EPS)
        return 0;
    return (d>0)?1:-1;
}

bool segcrossSimple(point a,point b,point c,point d)
{
    return ((dblcmp(cross(a,c,d))*dblcmp(cross(b,c,d)) < 0) &&
            (dblcmp(cross(c,a,b))*dblcmp(cross(d,a,b)) < 0));
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == -1)
            break;
        for (int i = 1;i <= n;i++)
            scanf("%lf%lf%lf%lf%lf",&d[i].p,&d[i].x[1],&d[i].x[2],&d[i].x[3],&d[i].x[4]);
        sort(d+1,d+n+1,cmp);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= 4;j++)
                dp[i][j] = 1e100;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= 4;j++)
            {
                bool flag = true;
                point p1,p2,p3,p4;
                p1.x = d[i].p;
                p1.y = d[i].x[j];
                p2.x = 0;
                p2.y = 5;
                for (int k = 1;k < i;k++)
                {
                    p3.x = p4.x = d[k].p;
                    p3.y = d[k].x[1];
                    p4.y = d[k].x[2];
                    if (segcrossSimple(p1,p2,p3,p4))
                        continue;
                    p3.y = d[k].x[3];
                    p4.y = d[k].x[4];
                    if (segcrossSimple(p1,p2,p3,p4))
                        continue;
                    flag = false;
                }
                dp[i][j] = dist(0.0,5.0,d[i].p,d[i].x[j]);
            }
        for (int i = 2;i <= n;i++)
            for (int j = 1;j <= 4;j++)
                for (int k = 1;k < i;k++)
                    for (int q = 1;q <= 4;q++)
                    {
                        bool flag = true;
                        point p1,p2,p3,p4;
                        p1.x = d[i].p;
                        p1.y = d[i].x[j];
                        p2.x = d[k].p;
                        p2.y = d[k].x[q];
                        for (int q = k+1;q <= i-1;q++)
                        {
                            p3.x = p4.x = d[q].p;
                            p3.y = d[q].x[1];
                            p4.y = d[q].x[2];
                            if (segcrossSimple(p1,p2,p3,p4))
                                continue;
                            p3.y = d[q].x[3];
                            p4.y = d[q].x[4];
                            if (segcrossSimple(p1,p2,p3,p4))
                                continue;
                            flag = false;
                        }
                        if (flag)
                        {
                            if (dp[i][j] > dist(p1.x,p1.y,p2.x,p2.y)+dp[k][q])
                                dp[i][j] = dist(p1.x,p1.y,p2.x,p2.y)+dp[k][q];
                        }
                    }
        double ans = 1e100;
        for (int k = 1;k <= 1;k++)
        {
            point p1,p2,p3,p4;
            p1.x = 0;
            p1.y = 5;
            p2.x = 10;
            p2.y = 5;
            bool flag = true;
            for (int i = 1;i <= n;i++)
            {
                p3.x = p4.x = d[i].p;
                p3.y = d[i].x[1];
                p4.y = d[i].x[2];
                if (segcrossSimple(p1,p2,p3,p4))
                    continue;
                p3.y = d[i].x[3];
                p4.y = d[i].x[4];
                if (segcrossSimple(p1,p2,p3,p4))
                    continue;
                flag = false;
            }
            if (flag)
                ans = 10.0;
        }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= 4;j++)
            {
                point p1,p2,p3,p4;
                p1.x = d[i].p;
                p1.y = d[i].x[j];
                p2.x = 10;
                p2.y = 5;
                bool flag = true;
                for (int k = i+1;k <= n;k++)
                {
                    p3.x = p4.x = d[k].p;
                    p3.y = d[k].x[1];
                    p4.y = d[k].x[2];
                    if (segcrossSimple(p1,p2,p3,p4))
                        continue;
                    p3.y = d[k].x[3];
                    p4.y = d[k].x[4];
                    if (segcrossSimple(p1,p2,p3,p4))
                        continue;
                    flag = false;
                }
                if (flag)
                {
                    if (ans > dist(p1.x,p1.y,p2.x,p2.y)+dp[i][j])
                        ans = dist(p1.x,p1.y,p2.x,p2.y)+dp[i][j];
                }
            }
        printf("%.2lf\n",ans);
    }
}
