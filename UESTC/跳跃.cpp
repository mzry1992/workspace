#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cost(X) (((X)>0)?(X):(0))
using namespace std;

int n;
long long a[100001],dp[100001],tmax;

int main()
{
    //freopen("jump.in","r",stdin);
    //freopen("jump1.out","w",stdout);
    int ft = 0;
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i <= n;i++)
            scanf("%lld",&a[i]);
        dp[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            dp[i] = dp[i-1]+cost(a[i]-a[i-1]);
            tmax = a[i-1];
            for (int j = i-2;j >= 0;j--)
            {
                if (a[j] >= i-j && (!(tmax >= a[i] && tmax >= a[j])))
                    dp[i] = min(dp[i],dp[j]+cost(a[i]-a[j]));
                tmax = max(tmax,a[j]);
            }
        }
        ft++;
        printf("%d %lld\n",ft,dp[n]);
    }
}
