#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long dp[2][3],a[3];

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%*lld%lld%lld",&dp[0][1],&dp[0][2]);
        dp[0][0] = 1992100500;
        dp[0][2] = dp[0][1]+dp[0][2];
        for (int i = 1;i < n;i++)
        {
            scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
            dp[i%2][0] = min(dp[(i+1)%2][0],dp[(i+1)%2][1])+a[0];
            dp[i%2][1] = min(min(min(dp[(i+1)%2][0],dp[(i+1)%2][1]),dp[(i+1)%2][2]),dp[i%2][0])+a[1];
            dp[i%2][2] = min(min(dp[(i+1)%2][1],dp[(i+1)%2][2]),dp[i%2][1])+a[2];
        }
        ft++;
        printf("%d. %lld\n",ft,dp[(n-1)%2][1]);
    }
    return 0;
}
