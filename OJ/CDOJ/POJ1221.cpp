#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long dp[300][300];
long long res[300];

int main()
{
    memset(dp,0,sizeof(dp));
    for (int i = 1;i <= 250;i++)
    {
        dp[i][i] = 1;
        if (i%2 == 0)
            dp[i][i/2] = 1;
        for (int j = 1;j <= i/2;j++)
        {
            if (j <= i-2*j)
                dp[i][j] += dp[i-2*j][i-2*j];
            for (int k = j;k <= (i-2*j)/2;k++)
                dp[i][j] += dp[i-2*j][k];
        }
    }
    memset(res,0,sizeof(res));
    for (int i = 1;i <= 250;i++)
    for (int j = 1;j <= 250;j++)
        res[i] += dp[i][j];
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        cout << n << ' ' << res[n] << endl;
    }
}
