#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[1<<20],sum[1<<20];
int n,a[20],b[20];

int Calc(int msk)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        if (((msk>>i)&1) == 0)
            res += a[i];
    return res;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d",&a[i],&b[i]);
        for (int i = 0;i < (1<<n);i++)
            sum[i] = Calc(i);
        memset(dp,63,sizeof(dp));
        dp[0] = 0;
        int inf = dp[1];
        for (int i = 0; i < (1<<n); i++)
            if (dp[i] != inf)
                for (int j = 0; j < n; j++)
                    if (((i>>j)&1) == 0)
                        dp[i|(1<<j)] = min(dp[i|(1<<j)],dp[i]+b[j]*sum[i]);
        printf("%d\n",dp[(1<<n)-1]);
    }
    return 0;
}
