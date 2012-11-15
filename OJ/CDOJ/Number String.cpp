#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1100];
int n;
const int mod = 1000000007;
int dp[1100][1100],psum[1100][1100];

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    while (scanf("%s",s) != EOF)
    {
        n = strlen(s)+1;
        memset(dp,0,sizeof(dp));
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        psum[0][0] = dp[0][0];
        for (int j = 1; j <= n; j++)
            psum[0][j] = (psum[0][j-1]+dp[0][j])%mod;
        for (int i = 1; i < n+1; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[i-1] == 'D')
                {
                    for (int k = 0; k <= j; k++)
                        dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
                }
                else if (s[i-1] == 'I')
                {
                    for (int k = j+1; k <= n-i; k++)
                        dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
                }
                else
                {
                    for (int k = 0; k <= n-i; k++)
                        dp[i][j] = (dp[i][j]+dp[i-1][k])%mod;
                }
            }
            psum[i][0] = dp[i][0];
            for (int j = 1; j <= n; j++)
                psum[i][j] = (psum[i][j-1]+dp[i][j])%mod;
        }
        printf("%d\n",dp[n][0]);
    }
    return 0;
}
