#include <cstdio>
#include <cstring>
const int mod=1000000000;
int dp[1428][1428];
int main()
{
    memset(dp,0,sizeof(dp));
    dp[1][0]=dp[3][1]=1;
    dp[2][1]=2;
    for (int i=4; i<1428; i++)
        for (int j=2; j<=i; j++)
            for (int k=1; k<i; k++)
                dp[i][j]=(dp[i][j]+(long long)dp[k][j-1]*dp[i-k-1][j-1]+(long long)dp[k][j-2]*dp[i-k-1][j-1]+(long long)dp[k][j-1]*dp[i-k-1][j-2])%mod;
    freopen("data.txt","w",stdout);
    for (int n=1; n<=1427; n++)
    {
        int ans=0;
        for (int i=0; i<=n; i++)
            ans=(ans+dp[n][i])%mod;
        printf("%d %d\n",n,ans);
    }
    return 0;
}
