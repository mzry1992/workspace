#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long a[1200];
long long sum;
const long long mod = 1000000007LL;
long long c[1200][1200];
long long dp[1200];

int main()
{
    c[0][0] = 1;
    c[0][1] = 0;
    for (int i = 1;i <= 1000;i++)
    {
        c[i][0] = 1;
        for (int j = 1;j <= i;j++)
        {
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
        }
        c[i][i+1] = 0;
    }
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%lld",&a[i]);
        sum = a[1];
        long long res = 1;
        for (int i = 2;i <= n;i++)
        {
            int blank = sum+1;
            int ball = a[i]-1;
            sum += a[i];
            if (ball >= 1)
            {
                long long tres = 0;
                for (int i = 1;i <= min(blank,ball);i++)
                {
                    tres += c[blank][i]*c[ball-1][i-1];
                    tres %= mod;
                }
                res = (tres*res)%mod;
            }
        }
        printf("Case %d: %lld\n",ft,res);
    }
}
