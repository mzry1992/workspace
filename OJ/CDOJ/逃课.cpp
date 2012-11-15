#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
double dp[2001][10];

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1.0;
        for (int i = 1;i <= 2000;i++)
            for (int j = 0;j < m;j++)
            {
                if (j > 0)  dp[i][j] += dp[i-1][j-1]*0.5;
                dp[i][0] += dp[i-1][j]*0.5;
            }
        double res = 1.0;
        for (int i = 0;i < m;i++)
            res -= dp[n][i];
        printf("%.2f\n",res);
    }
    return 0;
}
