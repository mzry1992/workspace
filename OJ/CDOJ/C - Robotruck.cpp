#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int v,n;
int x[101000],y[101000],a[101000];
int dp[101000],dis[101000],tv[101000];

int abs(int x)
{
    if (x < 0)  return -x;
    return x;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        if (ft > 1) printf("\n");
        scanf("%d",&v);
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%d%d%d",&x[i],&y[i],&a[i]);
        for (int i = 1;i <= n;i++)  dp[i] = 1992100500;
        dp[0] = 0;
        dis[0] = 0;
        tv[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            dis[i] = dis[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
            tv[i] = tv[i-1]+a[i];
        }
        for (int i = 1;i <= n;i++)
        {
            for (int j = i;j > 0;j--)
            if (tv[i]-tv[j-1] <= v)
            {
                if (dp[i] > dp[j-1]+abs(x[j])+abs(y[j])+abs(x[i])+abs(y[i])+dis[i]-dis[j])
                    dp[i] = dp[j-1]+abs(x[j])+abs(y[j])+abs(x[i])+abs(y[i])+dis[i]-dis[j];
            }
        }
        printf("%d\n",dp[n]);
    }
}
