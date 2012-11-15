#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,p[10],v[10][10],b[10][10];
int dp[11][1<<10];
int val[10][1<<10];

int Calc(int pos,int sta)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        if (((sta>>i)&1) == 0)
        {
            res -= p[pos];
            res += v[i][pos];
            for (int j = i; j < n; j++)
                if (((sta>>j)&1) == 0)
                    res += b[i][j];
        }
    return res;
}

int main()
{
    //freopen("in.txt","r",stdin);
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0; i < m; i++)
            scanf("%d",&p[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d",&v[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d",&b[i][j]);
        for (int i = 0;i <= m;i++)
            for (int j = 0;j < (1<<n);j++)
                dp[i][j] = -1;
        for (int i = 0;i < m;i++)
            for (int j = 0;j < (1<<n);j++)
                val[i][j] = Calc(i,j);
        dp[0][0] = 0;
        int res = 0;
        for (int i = 0;i < m;i++)
            for (int j = 0;j < (1<<n);j++)
                if (dp[i][j] >= 0)
                {
                    for (int k = 0;k < n;k++)
                        if (((j>>k)&1) == 0)
                            dp[i][j|(1<<k)] = max(dp[i][j|(1<<k)],dp[i][j]);
                    dp[i+1][j] = max(dp[i+1][j],dp[i][j]+val[i][j]);
                    res = max(res,dp[i+1][j]);
                }
        if (res == 0)
            puts("STAY HOME");
        else
            printf("%d\n",res);
    }
    return 0;
}
