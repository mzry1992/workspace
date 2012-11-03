#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long p[3002],q[3002],dp[3002][2];

int main()
{
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        scanf("%lld%lld",&p[i],&q[i]);
    p[n+1] = q[n+1] = 0;
    memset(dp,0,sizeof(dp));
    for (int i = 1;i <= n+1;i++)
    {
        long long tmp1,tmp2;
        tmp1 = tmp2 = 0LL;
        for (int j = i;j >= 1;j--)
        {
            tmp1 += p[j]*(long long)(i-j);
            tmp2 += q[j]*(long long)(i-j);
            dp[i][0] = max(dp[i][0],dp[j-1][1]+tmp1);
            dp[i][1] = max(dp[i][1],dp[j-1][0]+tmp2);
        }
    }
    printf("%lld\n",max(dp[n+1][0],dp[n+1][1]));
}
