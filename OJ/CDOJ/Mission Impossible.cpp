#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,tmp;
double pro[201][201];
double g[201][201],c;
bool mid[201];
double dp[201][201];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%lf",&pro[i][j]);
        for (int i = 1; i <= n; i++)
            mid[i] = false;
        mid[1] = mid[2] = true;
        scanf("%d",&m);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d",&tmp);
            mid[tmp] = true;
        }
        scanf("%lf",&c);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = 0.01*pro[i][j];
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    g[i][j] = max(g[i][j],g[i][k]*g[k][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (g[i][j] > 1e-12)
                    g[i][j] = c/g[i][j];
                else
                    g[i][j] = 1e100;
        for (int i = 1; i <= n; i++)
            for (int j = 1;j <= n;j++)
                dp[i][j] = 1e100;
        for (int i = 1;i <= n;i++)
            if (mid[i] == true)
                for (int j = 1;j <= n;j++)
                    if (mid[j] == true)
                        dp[i][j] = g[i][j];
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
        printf("%.7f\n",dp[1][2]);
    }
    return 0;
}
