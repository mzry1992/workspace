#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,dp[111][111];
int t1,t2,t3,f1,f2;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%d%d",&n,&m);
	    memset(dp,63,sizeof(dp));
	    dp[0][m] = 0;
	    for (int i = 1;i <= n;i++)
	    {
	        scanf("%d%d%d%d%d",&t1,&t2,&t3,&f1,&f2);
	        for (int j = 0;j <= m-f1;j++)
	            dp[i][j] = min(dp[i][j],dp[i-1][j+f1]+t1);
            for (int j = 0;j <= m;j++)
                dp[i][j] = min(dp[i][j],dp[i-1][j]+t2);
            for (int j = 0;j <= m;j++)
                dp[i][min(m,j+f2)] = min(dp[i][min(m,j+f2)],dp[i-1][j]+t3);
	    }
	    int res = dp[n][0];
	    for (int i = 1;i <= m;i++)
            res = min(res,dp[n][i]);
        printf("%d\n",res);
	}
	return 0;
}
