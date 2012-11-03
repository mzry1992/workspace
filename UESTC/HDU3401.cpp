#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int Q[5000],head,tail;
int n,m,maxp,ap,bp,as,bs,dp[2001][2001],res;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d%d",&n,&maxp,&m);
        memset(dp,-63,sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d%d",&ap,&bp,&as,&bs);
            head = tail = 2500;
            for (int j = 0; j <= maxp; j++)
            {
                dp[i][j] = dp[i-1][j];
                if (j <= as)    dp[i][j] = max(dp[i][j],-ap*j);
                if (i-m-1 > 0)
                {
                    while (head < tail)
                    {
                        if (dp[i-m-1][Q[head]]+ap*Q[head] <= dp[i-m-1][j]+ap*j)   head++;
                        else    break;
                    }
                    Q[--head] = j;
                    while (head < tail)
                    {
                        if (Q[tail-1]+as < j)   tail--;
                        else    break;
                    }
                    dp[i][j] = max(dp[i][j],dp[i-m-1][Q[tail-1]]+ap*(Q[tail-1]-j));
                }
            }
            head = tail = 2500;
            for (int j = maxp; j >= 0; j--)
                if (i-m-1 >= 0)
                {
                    while (head < tail)
                    {
                        if (dp[i-m-1][Q[head]]+bp*Q[head] <= dp[i-m-1][j]+bp*j)   head++;
                        else    break;
                    }
                    Q[--head] = j;
                    while (head < tail)
                    {
                        if (Q[tail-1]-bs > j)   tail--;
                        else    break;
                    }
                    dp[i][j] = max(dp[i][j],dp[i-m-1][Q[tail-1]]+bp*(Q[tail-1]-j));
                }
        }
        res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= maxp; j++)
                res = max(res,dp[i][j]);
        printf("%d\n",res);
    }
    return 0;
}
