#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,k,p;
const int mod = 1000000007;
int flag,dp[2][301][101],sum;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&k,&p);
        p++;
        memset(dp,0,sizeof(dp));
        flag = 0;
        dp[0][0][0] = 1;
        for (int i = 1;i <= n;i++,flag = !flag)
        {
            memset(dp[!flag],0,sizeof(dp[!flag]));
            for (int v = 1;v <= p;v++)
            {
                sum = dp[flag][0][v-1];
                for (int j = 1;j <= k;j++)
                {
                    dp[!flag][j][v] = ((long long)dp[flag][j][v]*j)%mod;
                    dp[!flag][j][v] = (dp[!flag][j][v]+sum)%mod;
                    sum = (sum+dp[flag][j][v-1])%mod;
                }
            }
        }
        sum = 0;
        for (int j = 1;j <= k;j++)
            sum = (sum+dp[flag][j][p])%mod;
        printf("%d\n",sum);
    }
    return 0;
}
