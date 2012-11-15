#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n,k;
struct point
{
    int x,y,id;
    double angle;
}p[11000];

double calcangle(point a,point b)
{
    point temp;
    temp.x = b.x-a.x;
    temp.y = b.y-a.y;
    return atan2(temp.y,temp.x);
}

bool cmp(point a,point b)
{
    return a.angle < b.angle;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&k);
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].id = i;
        }
        for (int i = 2;i <= n;i++)
            p[i].angle = calcangle(p[1],p[i]);
        sort(p+2,p+1+n,cmp);
        printf("1\n");
        for (int i = 2;i <= k;i++)
            printf("%d\n",p[i].id);
    }
}
