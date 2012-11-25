#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1001;
int n;
long long dp[maxn][maxn],a[maxn][maxn];
const long long mod = 4294967296LL;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i=1; i<=n; i++)
        {
            dp[1][i] = i;
            dp[2][i] = i*i;
        }
        for (int i=3; i<=n; i++)
            for (int j=1; j<=n; j++)
            {
                if(j-2 >= 0)
                    a[i][j] = (a[i][j-1]+dp[i-2][j-2])%mod;
                dp[i][j] = (dp[i][j-1]+dp[i-1][j-1]+dp[i-2][j-1]+a[i][j])%mod;
            }
        cout << dp[n][n] << endl;
    }
    return 0;
}
