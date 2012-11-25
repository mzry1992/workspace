#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
double x,y,a[100010],b[100010],dp[100010],sum[100010];

int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
    while (scanf("%d%lf%lf",&n,&x,&y) != EOF)
    {
        sum[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%lf%lf",&a[i],&b[i]);
            sum[i] = sum[i-1]+b[i];
        }

        for (int i = 1;i <= n;i++)
        {
            dp[i] = y+(x+sum[i-1]*y)/a[i];
            for (int j = 1;j < i;j++)
                dp[i]=max(dp[i],dp[j]+(sum[i-1]-sum[j-1])*dp[j]/a[i]);

        }

        /*for (int i = 0;i <= n;i++)
            printf("%.2f ",dp[i]);
        puts("");*/

        double res = x+y*sum[n];
        for (int i = 1;i <= n;i++)
            res = max(res,dp[i]*(sum[n]-sum[i-1]));
        printf("%.2f\n",res);
    }
	return 0;
}
