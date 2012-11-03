#include <iostream>
#include <cstdio>
#include <cstring>
#define MIN(X,Y) (((X)>(Y))?(Y):(X))
using namespace std;

int n;
int a[120],p[120];
int dp[120];
int sum[120];

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d",&n);
        sum[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&a[i],&p[i]);
            sum[i] = sum[i-1]+a[i];
        }
        dp[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            dp[i] = 1992100500;
            for (int j = 0;j < i;j++)
                dp[i] = MIN(dp[i],dp[j]+(sum[i]-sum[j]+10)*p[i]);
        }
        printf("%d\n",dp[n]);
    }
}
