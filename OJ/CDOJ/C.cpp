#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,maxw,totk,a,b,c;
int w[11][101],v[11][101],tot[11],dp[11][10001],tmp[10001];

int main()
{
    while (scanf("%d%d%d",&n,&maxw,&totk) != EOF)
    {
        for (int i = 1;i <= totk;i++)
            tot[i] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            tot[a]++;
            w[a][tot[a]] = b;
            v[a][tot[a]] = c;
        }
        for (int i = 0;i <= maxw;i++)
            dp[0][i] = -1;
        dp[0][0] = 0;
        for (int i = 1;i <= totk;i++)
        {
            for (int k = 0;k <= maxw;k++)
                dp[i][k] = -1;
            for (int j = 1;j <= tot[i];j++)
            {
                for (int k = 0;k <= maxw;k++)
                    tmp[k] = -1;
                //必须选的
                for (int k = w[i][j];k <= maxw;k++)
                    if (dp[i-1][k-w[i][j]] != -1)
                        tmp[k] = dp[i-1][k-w[i][j]]+v[i][j];
                //剩下的进行01背包
                for (int k = j+1;k <= tot[i];k++)
                    for (int q = maxw;q >= w[i][k];q--)
                        if (tmp[q-w[i][k]] != -1)
                            tmp[q] = max(tmp[q],tmp[q-w[i][k]]+v[i][k]);
                //用tmp更新dp[i]
                for (int k = 0;k <= maxw;k++)
                    if (tmp[k] != -1)
                        dp[i][k] = max(dp[i][k],tmp[k]);
            }
        }
        int res = -1;
        for (int i = 0;i <= maxw;i++)
            res = max(res,dp[totk][i]);
        if (res == -1)
            puts("Impossible");
        else
            printf("%d\n",res);
    }
    return 0;
}
