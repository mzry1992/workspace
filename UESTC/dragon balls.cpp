#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,typ[102010],val[102010],dp[102010];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("ly.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%d",&typ[i]);
        for (int i = 1;i <= n;i++)
            scanf("%d",&val[i]);
        dp[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            dp[i] = dp[i-1]+val[i];
            int tmax = val[i];
            for (int j = i-1;j >= 1 && typ[j] != typ[i];j--)
            {
                tmax = max(tmax,val[j]);
                dp[i] = min(dp[i],dp[j-1]+tmax);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
