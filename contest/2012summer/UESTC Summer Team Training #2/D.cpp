#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000007;
int dp[11000][110],f[101][11000];
int n,a[110],sum[110];

int mut(long long a,long long b)
{
    long long tmp = a*b;
    tmp %= mod;
    return (int)tmp;
}

int main()
{
    memset(dp[0],0,sizeof(dp[0]));
    dp[0][0] = 1;
    for (int i = 1;i <= 10010;i++)
        for (int j = 0;j <= 100;j++)
        {
            dp[i][j] = 0;
            for (int k = 0;k <= j;k++)
                dp[i][j] = (dp[i][j]+dp[i-1][j-k])%mod;
        }
	int cas = 0;
	while (scanf("%d",&n) != EOF)
	{
	    cas++;
	    sum[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        memset(f[0],0,sizeof(f[0]));
        f[0][0] = 1;
        for (int i = 1;i <= n;i++)
            for (int j = 0;j <= sum[i];j++)
            {
                f[i][j] = 0;
                for (int k = 0;k <= j && k <= a[i];k++)
                    if (j-k <= sum[i-1])
                        f[i][j] = (f[i][j]+mut((long long)f[i-1][j-k],(long long)dp[j-k+1][k]))%mod;
            }
        int res = 0;
        for (int i = 1;i <= sum[n];i++)
        {
            res = (res+f[n][i])%mod;
            //printf("%d ",f[n][i]);
        }
        //printf("\n");
        printf("Case %d: %d\n",cas,res);
	}
	return 0;
}
