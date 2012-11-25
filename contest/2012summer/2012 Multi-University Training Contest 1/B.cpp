#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 100000007;
int dp[2][2001][8],res[1001][2001];
int n,m;

int main()
{
    memset(dp,0,sizeof(dp));
    bool flag=0;
    dp[0][0][5] = 1;
    n = 1000,m = 2000;
    for (int i = 0; i < n; i++,flag=!flag)
    {
        memset(dp[!flag],0,sizeof(dp[!flag]));
        for (int j = 0; j <= m; j++)
            for (int k = 0; k < 8; k++)
                if (dp[flag][j][k] > 0)
                {
                    if (k == 0)
                    {
                        dp[!flag][j][0] = (dp[!flag][j][0]+dp[flag][j][k])%mod;
                        dp[!flag][j][1] = (dp[!flag][j][1]+dp[flag][j][k])%mod;
                        dp[!flag][j][4] = (dp[!flag][j][4]+dp[flag][j][k])%mod;
                        if (j+1 <= m)
                            dp[!flag][j+1][5] = (dp[!flag][j+1][5]+dp[flag][j][k])%mod;
                    }
                    else if (k == 1 || k == 2 || k == 4)
                    {
                        dp[!flag][j][2] = (dp[!flag][j][2]+dp[flag][j][k])%mod;
                        if (j+1 <= m)
                        {
                            dp[!flag][j+1][3] = (dp[!flag][j+1][3]+dp[flag][j][k])%mod;
                            dp[!flag][j+1][6] = (dp[!flag][j+1][6]+dp[flag][j][k])%mod;
                        }
                        if (j+2 <= m)
                            dp[!flag][j+2][7] = (dp[!flag][j+2][7]+dp[flag][j][k])%mod;
                    }
                    else if (k == 3 || k == 5 || k == 6 || k == 7)
                    {
                        dp[!flag][j][0] = (dp[!flag][j][0]+dp[flag][j][k])%mod;
                        dp[!flag][j][1] = (dp[!flag][j][1]+dp[flag][j][k])%mod;
                        dp[!flag][j][2] = (dp[!flag][j][2]+dp[flag][j][k])%mod;
                        dp[!flag][j][4] = (dp[!flag][j][4]+dp[flag][j][k])%mod;
                        if (j+1 <= m)
                        {
                            dp[!flag][j+1][3] = (dp[!flag][j+1][3]+dp[flag][j][k])%mod;
                            dp[!flag][j+1][5] = (dp[!flag][j+1][5]+dp[flag][j][k])%mod;
                            dp[!flag][j+1][6] = (dp[!flag][j+1][6]+dp[flag][j][k])%mod;
                        }
                        if (j+2 <= m)
                            dp[!flag][j+2][7] = (dp[!flag][j+2][7]+dp[flag][j][k])%mod;
                    }
                }
        for (int j = 0;j <= 2000;j++)
            res[i+1][j] = (dp[!flag][j][7]+dp[!flag][j][5])%mod;
    }
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",res[n][m]);
    }
    return 0;
}
