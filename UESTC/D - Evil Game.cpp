#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX(X,Y) (((X)>(Y))?(X):(Y))
#define ABS(X) (((X)>0)?(X):(-(X)))
using namespace std;

int m,n;
int a[120][120];
int sx[120][120];
int pre[120][120],next[120][120];
int dp[120][120];

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d%d",&m,&n);
        for (int i = 1;i <= m;i++)
        for (int j = 1;j <= n;j++)
            scanf("%d",&a[i][j]);
        for (int i = 1;i <= m;i++)
        {
            sx[i][0] = 0;
            for (int j = 1;j <= n;j++)
                sx[i][j] = sx[i][j-1]+a[i][j];
        }
        for (int i = 1;i <= m;i++)
        {
            pre[i][0] = 0;
            for (int j = 1;j <= n;j++)
            {
                int temp = a[i][j];
                pre[i][j] = temp;
                for (int k = j-1;k >= 1;k--)
                {
                    temp += a[i][k]-ABS(a[i][k+1]);
                    pre[i][j] = MAX(pre[i][j],temp);
                }
            }
        }
        for (int i = 1;i <= m;i++)
        {
            next[i][n+1] = 0;
            for (int j = 1;j <= n;j++)
            {
                int temp = a[i][j];
                next[i][j] = temp;
                for (int k = j+1;k <= n;k++)
                {
                    temp += a[i][k]-ABS(a[i][k-1]);
                    next[i][j] = MAX(next[i][j],temp);
                }
            }
        }
        for (int i = 0;i <= m;i++)
        for (int j = 0;j <= n;j++)
            dp[i][j] = -(1<<30);
        dp[0][1] = 0;
        for (int i = 1;i <= m;i++)
        for (int j = 1;j <= n;j++)
        for (int k = 1;k <= n;k++)
        {
            if (k > j)
                dp[i][k] = MAX(dp[i][k],dp[i-1][j]+sx[i][k-1]-sx[i][j]+pre[i][j]+next[i][k]);
            else if (k < j)
                dp[i][k] = MAX(dp[i][k],dp[i-1][j]+sx[i][j-1]-sx[i][k]+pre[i][k]+next[i][j]);
            else
                dp[i][k] = MAX(dp[i][k],dp[i-1][j]+pre[i][k]+next[i][j]-a[i][k]);
        }
        printf("%d\n",dp[m][n]);
    }
}
