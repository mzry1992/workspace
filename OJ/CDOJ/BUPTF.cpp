#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;
ll n,m,k;
ll w[50];
ll dp[50][50];

int main()
{
    int i,j;
    while (scanf("%lld%lld",&n,&m) != EOF)
    {
          scanf("%lld",&k);
          for (i = 1;i <= k;i++)
              scanf("%lld",&w[i]);
          memset(dp,0,sizeof(dp));
          for (i = 1;i <= k;i++)
          for (j = 0;j <= i-1;j++)
          {
              if (dp[i][j] < dp[i-1][j])
                 dp[i][j] = dp[i-1][j];
              if (dp[i][j+1] < dp[i-1][j]+w[i])
              if (dp[i-1][j]+w[i] <= m)
                 dp[i][j+1] = dp[i-1][j]+w[i];  
          }
          for (i = 0;i <= n;i++)
          if (dp[k][n] < dp[k][i])
             dp[k][n] = dp[k][i];
          printf("%lld\n",dp[k][n]); 
    }
    return 0;
}
