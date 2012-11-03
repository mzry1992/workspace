#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int m,n;
double r;
struct point
{
    int x,y;
}s[200],d;

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%lf",&m,&n,&r);
        for (int i = 1;i <= m;i++)
            scanf("%d%d",&s[i].x,&s[i].y);
        int res = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&d.x,&d.y);
            bool flag = true;
            for (int j = 1;j <= m;j++)
            if (dist(s[j],d) <= r)
            if (flag == true)
            {
                res++;
                flag = false;
            }
        }
        printf("Case #%d: %d\n",ft,res);
    }
}
