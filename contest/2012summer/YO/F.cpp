#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,a[101];
double dp[101],tim[10001];
double b,v,e,f;
int r;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        if (n == 0) break;
        a[0] = 0;
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        scanf("%lf%d%lf%lf%lf",&b,&r,&v,&e,&f);
        tim[0] = 0;
        for (int i = 1;i <= a[n];i++)
            tim[i] = 1e100;
        for (int i = 1;i <= a[n];i++)
        {
            if (i-1 < r)
            {
                if (v-f*(r-i+1) <= 0)   break;
                tim[i] = tim[i-1]+1.0/(v-f*(r-i+1));
            }
            else
            {
                if (v-e*(i-1-r) <= 0)   break;
                tim[i] = tim[i-1]+1.0/(v-e*(i-1-r));
            }
        }
        dp[0] = -b;
        for (int i = 1;i <= n;i++)
        {
            dp[i] = 1e100;
            for (int j = 0;j < i;j++)
                dp[i] = min(dp[i],dp[j]+tim[a[i]-a[j]]+b);
        }
        printf("%.4f\n",dp[n]);
    }
	return 0;
}
