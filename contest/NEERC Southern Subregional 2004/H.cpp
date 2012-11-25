#include <cstdio>
int sum[250];
int dp[251][251];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[x-1]++;
    }
    for (int i=248;i>=0;i--)
        sum[i]+=sum[i+1];
    for (int i=0;i<=250;i++)
        dp[i][0]=1;
    for (int i=1;i<=k;i++)
        for (int j=249;j>=0;j--)
            dp[j][i]=dp[j+1][i]+dp[j+1][i-1]*(sum[j]-i+1);
    printf("%d\n",dp[0][k]);
}
