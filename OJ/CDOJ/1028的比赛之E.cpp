#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int s,n;
struct goods
{
    int v,a,b;
}g[150];
int dp[1500];

bool cmp(goods a,goods b)
{
    return a.a > b.a;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&s,&n);
        for (int i = 1;i <= n;i++)
            scanf("%d%d%d",&g[i].v,&g[i].a,&g[i].b);
        sort(g+1,g+1+n,cmp);
        memset(dp,0,sizeof(dp));
        for (int i = 1;i <= n;i++)
        for (int j = s;j >= g[i].a;j--)
        if (dp[j-g[i].b] < dp[j-g[i].a]+g[i].v)
            dp[j-g[i].b] = dp[j-g[i].a]+g[i].v;
        int res = 0;
        for (int i = 0;i <= s;i++)
            if (dp[i] > res)
                res = dp[i];
        printf("%d\n",res);
    }
}
