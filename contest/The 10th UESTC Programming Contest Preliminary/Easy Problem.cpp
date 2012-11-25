#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,dp[100][2],l,r;
char mp[101][101];

int main()
{
	int t;
	scanf("%d",&t);
	for (int ft = 1;ft <= t;ft++)
	{
        scanf("%d%d",&n,&m);
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",mp[i]);
            l = 0;
            r = m-1;
            for (int j = 0;j < m;j++)
                if (mp[i][j] == '*')
                {
                    l = j;
                    break;
                }
            for (int j = m-1;j >= 0;j--)
                if (mp[i][j] == '*')
                {
                    r = j;
                    break;
                }
            if (l == 0)
            {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
            else
            {
                dp[i][0] = min(dp[i-1][0]+r*2,dp[i-1][1]+m-1);
                dp[i][1] = min(dp[i-1][0]+m-1,dp[i-1][1]+(m-1-l)*2);
            }
            //cout << dp[i][0] << ' ' << dp[i][1] << ' ' << l << ' ' << r << endl;
        }
        printf("Case #%d: %d\n",ft,min(dp[n][0],dp[n][1])+n-1);
	}
	return 0;
}
