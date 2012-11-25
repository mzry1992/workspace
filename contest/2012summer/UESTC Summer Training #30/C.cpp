#include <cstdio>
double dp[401][401],sum[401][401];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n-1;i++)
        for (int j=0;j<=i;j++)
            dp[i][j]=0;
    dp[0][0]=1;
    for (int i=0;i<n-1;i++)
        sum[0][i]=1;
    for (int i=1;i<n-1;i++)
    {
        for (int j=1;j<=i;j++)
        {
            for (int k=0;k<i;k++)
            {
                if (j>1)
                    dp[i][j]+=dp[k][j-1]*sum[i-k-1][j-2]*2/i;
                /*for (int l=0;l<j-1;l++)
                    dp[i][j]+=dp[k][j-1]*dp[i-k-1][l]*2/i;*/
                dp[i][j]+=dp[k][j-1]*dp[i-k-1][j-1]/i;
            }
            sum[i][j]=sum[i][j-1]+dp[i][j];
        }
        for (int j=i+1;j<n-1;j++)
            sum[i][j]=sum[i][j-1];
    }
    double ans=0;
    for (int i=0;i<=n-2;i++)
        ans+=dp[n-2][i]*i;
    printf("%.15f\n",ans*10);
    return 0;
}
