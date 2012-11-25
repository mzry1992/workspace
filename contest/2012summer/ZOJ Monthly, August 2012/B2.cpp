#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
double x,y,a[100010],b[100010],dp[100010],sum[100010];
int q[100010],head,tail;

int main()
{
	freopen("B.in","r",stdin);
	freopen("B2.out","w",stdout);
    while (scanf("%d%lf%lf",&n,&x,&y) != EOF)
    {
        sum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf",&a[i],&b[i]);
            sum[i] = sum[i-1]+b[i];
        }
        if (n == 0)
        {
            printf("%.2f\n",x);
            continue;
        }
        head=0;
        tail=1;
        q[head]=1;
        dp[1]=y+x/a[1];
        for (int i = 2; i <= n; i++)
        {
            dp[i] = y+(x+sum[i-1]*y)/a[i];
            //   for (int j = 1;j < i;j++)
            //      dp[i]=max(dp[i],dp[j]+(sum[i-1]-sum[j-1])*dp[j]/a[i]);

            while(head<tail-1&&
                  sum[q[head+1]-1]*dp[q[head+1]]-sum[q[head]-1]*dp[q[head]]<(dp[q[head+1]]-dp[q[head]])*(sum[i-1]+a[i]))
                head++;
            dp[i]=max(dp[i],dp[q[head]]+(sum[i-1]-sum[q[head]-1])*dp[q[head]]/a[i]);
            while(head<tail-1&&
                  ((sum[i-1]*dp[i]-sum[q[tail-1]-1]*dp[q[tail-1]])*(dp[q[tail-1]]-dp[q[tail-2]])<(sum[q[tail-1]-1]*dp[q[tail-1]]-sum[q[tail-2]-1]*dp[q[tail-2]])*(dp[i]-dp[q[tail-1]])))
                tail--;
            q[tail++]=i;

        }

        /*for (int i = 0;i <= n;i++)
            printf("%.2f ",dp[i]);
        puts("");*/

        double res = x+y*sum[n];
        for (int i = 1; i <= n; i++)
            res = max(res,dp[i]*(sum[n]-sum[i-1]));
        printf("%.2f\n",res+1e-8);
    }
    return 0;
}
