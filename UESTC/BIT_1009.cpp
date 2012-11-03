#include <iostream>

int m,n,mw,i,j,k,w,v,t,ft,dp[1200][1200];

int max(int a,int b)
{
    if (a > b)    return a;
    return b;
}

int main()
{
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&m,&mw);
        memset(dp,0,sizeof(dp));
        for (i = 0;i <= mw;i++)
        for (j = 1;j <= n;j++)
            dp[i][j] = -19921005;
        for (i = 1;i <= n;i++)
        {
            scanf("%d%d",&w,&v);
            for (j = mw;j >= w;j--)
            for (k = m;k >= 1;k--)
                dp[j][k] = max(dp[j][k],dp[j-w][k-1]+v);
        }
        if (dp[mw][m] < 0)
           dp[mw][m] = 0;
        printf("%d\n",dp[mw][m]);
    }
}
