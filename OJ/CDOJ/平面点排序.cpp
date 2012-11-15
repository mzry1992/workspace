#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct point
{
    int x,y;
}p[1000000];
int n;

bool cmp1(point a,point b)
{
    if (a.x == b.x) return a.y > b.y;
    return a.x > b.x;
}

bool cmp2(point a,point b)
{
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main()
{
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
    sort(p+1,p+1+n,cmp2);
    for (int i = 1;i <= n;i++)
        printf("(%d,%d) ",p[i].x,p[i].y);
    printf("\n");
    sort(p+1,p+1+n,cmp1);
    for (int i = 1;i <= n;i++)
        printf("(%d,%d) ",p[i].x,p[i].y);
    printf("\n");
}
