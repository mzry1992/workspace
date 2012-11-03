#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char temp[1200];
char a[1200];
long long dp[1200][1200];
const long long mod = 1000000007LL;
int n;

long long getval(int i,int j)
{
    if (j < 0)  return 0;
    return dp[i][j];
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%s",temp);
        int l = strlen(temp);
        int tl = 0;
        for (int i = 0;i < l;i++)
        if (temp[i] != 'E')
        {
            a[tl] = temp[i];
            tl++;
        }
        a[tl] = 0;
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        n = strlen(a);
        for (int i = 1;i <= n;i++)
        for (int j = 0;j <= i;j++)
        {
            if (a[i] == 'U')
            {
                dp[i][j] = ()%mod;
            }
            else
            {
            }
        }
        printf("Case %d: %lld\n",ft,dp[n][0]);
    }
}
