#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,m,s[51],p[51][51],a[51][51],T,t[51],pre[51][51];
double dp[51][51];

void output(int day,int now)
{
    if (day == 0)   return;
    output(day-1,pre[day][now]);
    printf("%d ",now);
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1;i <= n;i++)
            scanf("%d",&s[i]);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                scanf("%d",&p[i][j]);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                scanf("%d",&a[i][j]);
        scanf("%d",&T);
        for (int i = 1;i <= T;i++)
            scanf("%d",&t[i]);
        memset(dp,0,sizeof(dp));
        for (int i = 1;i <= n;i++)
            dp[1][i] = (double)s[i]/100.0*(double)a[i][t[1]]/100.0;
        for (int i = 2;i <= T;i++)
            for (int j = 1;j <= n;j++)
            {
                for (int k = 1;k <= n;k++)
                    if (dp[i-1][k]*(double)p[k][j]/100.0 > dp[i][j])
                    {
                        dp[i][j] = dp[i-1][k]*(double)p[k][j]/100.0;
                        pre[i][j] = k;
                    }
                dp[i][j] = dp[i][j]*(double)a[j][t[i]]/100.0;
            }
        double maxpro = 0.0;
        int now = 1;
        for (int i = 1;i <= n;i++)
            if (dp[T][i] > maxpro)
            {
                maxpro = dp[T][i];
                now = i;
            }
        output(T,now);
        printf("\n");
    }
    return 0;
}
