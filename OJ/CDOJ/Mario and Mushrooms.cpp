#include<cstdio>
int dp[100][1000];
int main()
{
    int a=2;
    int n=2;
    for (int a = 1; a <= 10; a++)
    {
        for (int n = 1; n <= 8; n++)
        {
            for (int i=0; i<=n; i++)
                for (int j=0; j<=a*n+1; j++)
                    dp[i][j]=0;
            dp[0][0]=1;
            for (int i=0; i<=n; i++)
                for (int j=0; j<=a*n+1; j++)
                {
                    if (j<=i*a) continue;
                    dp[i][j]=0;
                    if (i) dp[i][j]=dp[i-1][j];
                    if (j>i*a)
                        dp[i][j]+=dp[i][j-1];
                }
            printf("%9d ",dp[n][n*a+1]);
        }
        printf("\n");
    }
}
