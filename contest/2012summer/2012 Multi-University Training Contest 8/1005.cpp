#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 0x3fffffff;
int n,m,sx,move;
int dp[2][10001],a[10001],s[10001],head,tail,sum[10001];

int main()
{
    while (scanf("%d%d%d%d",&n,&m,&sx,&move) != EOF)
    {
        bool flag = 0;
        for (int i = 0;i <= m;i++)
            dp[flag][i] = -inf;
        dp[flag][sx] = 0;

        for (int i = 0;i < n;i++,flag = !flag)
        {
            sum[0] = 0;
            for (int j = 1;j <= m;j++)
            {
                dp[!flag][j] = -inf;
                scanf("%d",&a[j]);
                sum[j] = sum[j-1]+a[j];
            }

            if (i == 0)
            {
                for (int j=max(1,sx-move);j<=sx;j++)
                    dp[!flag][j]=sum[sx]-sum[j-1];
                for (int j=sx+1;j<=m && j<=sx+move;j++)
                    dp[!flag][j]=sum[j]-sum[sx-1];
                continue;
            }
            head = tail = 0;
            for (int j = 1;j <= m;j++)
            {
                while (head < tail && j-s[head] > move)
                    head++;
                while (head < tail && dp[flag][j]-sum[j-1] >= dp[flag][s[tail-1]]-sum[s[tail-1]-1])
                    tail--;
                s[tail++] = j;
                //printf("%d %d %d\n",i,j,s[head]);
                dp[!flag][j] = max(dp[!flag][j],sum[j]-sum[s[head]-1]+dp[flag][s[head]]);
            }
            head = tail = 0;
            for (int j = m;j >= 1;j--)
            {
                while (head < tail && s[head]-j > move)
                    head++;
                while (head < tail && dp[flag][j]+sum[j] >= dp[flag][s[tail-1]]+sum[s[tail-1]])
                    tail--;
                s[tail++] = j;
                dp[!flag][j] = max(dp[!flag][j],dp[flag][s[head]]+sum[s[head]]-sum[j-1]);
            }

        }
        int ans = -inf;
        for (int i = 1;i <= m;i++)
            ans = max(ans,dp[flag][i]);
        printf("%d\n",ans);
    }
	return 0;
}
