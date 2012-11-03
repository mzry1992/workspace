#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
struct point
{
    int x,y;
}p[1200];
int dx[1200];

bool cmpx(point a,point b)
{
    return a.x < b.x;
}

bool cmpy(point a,point b)
{
    return a.y < b.y;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        sort(p+1,p+1+n,cmpx);
        p[0] = p[1];
        p[n+1] = p[n];
        for (int i = 1;i <= n;i++)
            dx[i] = p[i+1].x-p[i-1].x;
        sort(dx+1,dx+1+n);
        sort(p+1,p+1+n,cmpy);
        double sum = 0;
        for (int i = 1;i <= n;i++)
            sum += (double)(dx[i]*p[i].y);
        printf("%.1f\n",sum/2.0);
    }
}
