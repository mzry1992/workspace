#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[1001][1001];
long long dp[1001],pmax[1001],res;

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        memset(dp,0,sizeof(dp));
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= i;j++)
                scanf("%d",&a[i][j]);
        for (int i = 0;i <= n;i++)
            pmax[i] = 0;
        res = 0;
        for (int j = 1;j <= n;j++)
        {
            long long sum = 0;
            for (int i = j;i <= n;i++)
            {
                sum += a[i][j];
                dp[i] = sum+pmax[i-1];
                res = max(res,dp[i]);
            }
            pmax[n] = dp[n];
            for (int i = n-1;i >= j;i--)
                pmax[i] = max(pmax[i+1],dp[i]);
        }
        printf("%lld\n",res);
    }
	return 0;
}
