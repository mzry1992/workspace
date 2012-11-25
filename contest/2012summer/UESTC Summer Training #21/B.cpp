#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[30],b[30],dp[350][350];

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d%d",&a[i],&b[i]);
        memset(dp,63,sizeof(dp));
        dp[m][0] = 0;
        int ans = 0x7fffffff;
        for (int i = m;i >= 0;i--)
            for (int j = 0;j <= m;j++)
            {
                if (i-j > 0)
                    dp[i-j][j] = min(dp[i-j][j],dp[i][j]+1);
                else
                    ans = min(ans,dp[i][j]+1);
                for (int k = 0;k < n;k++)
                    if (i-j*a[k] >= 0)
                        dp[i-j*a[k]][min(m,j+b[k])] = min(dp[i-j*a[k]][min(j+b[k],m)],dp[i][j]+a[k]);
            }
        printf("%d\n",ans);
    }
	return 0;
}
