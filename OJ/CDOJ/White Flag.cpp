#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

struct point
{
    double x,y;
}p1[120],p2[120];
int n1,n2;
const double eps = 1e-8;

int dblcmp(double d)
{
    if (fabs(d) < eps)
        return 0;
    return (d > 0) ? 1 : -1;
}

double dmult(point a,point b,point c,point d)
{
    return ((b.x-a.x)*(d.x-c.x)+(b.y-a.y)*(d.y-c.y));
}

double xmult(point a,point b,point c)
{
    return ((b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x));
}

double dist(point a,point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d",&n1);
        for (int i = 1;i <= n1;i++)
            scanf("%lf%lf",&p1[i].x,&p1[i].y);
        scanf("%d",&n2);
        for (int i = 1;i <= n2;i++)
            scanf("%lf%lf",&p2[i].x,&p2[i].y);
        double res = 1e100;
        p2[n2+1].x = p2[1].x;
        p2[n2+1].y = p2[1].y;
        p1[n1+1].x = p1[1].x;
        p1[n1+1].y = p1[1].y;
        for (int i = 1;i <= n1;i++)
            for (int j = 1;j <= n2;j++)
            {
                double temp = fabs(xmult(p2[j],p2[j+1],p1[i]))/dist(p2[j],p2[j+1]);
                if (dblcmp(dmult(p2[j],p2[j+1],p2[j+1],p1[i]))*dblcmp(dmult(p2[j],p2[j+1],p2[j],p1[i])) > 0)
                    temp = min(dist(p1[i],p2[j]),dist(p1[i],p2[j+1]));
                if (temp < res)
                    res = temp;
            }
        for (int i = 1;i <= n2;i++)
            for (int j = 1;j <= n1;j++)
            {
                double temp = fabs(xmult(p1[j],p1[j+1],p2[i]))/dist(p1[j],p1[j+1]);
                if (dblcmp(dmult(p1[j],p1[j+1],p1[j+1],p2[i]))*dblcmp(dmult(p1[j],p1[j+1],p1[j],p2[i])) > 0)
                    temp = min(dist(p2[i],p1[j]),dist(p2[i],p1[j+1]));
                if (temp < res)
                    res = temp;
            }
        printf("%lf\n",res/2.0);
    }
}
