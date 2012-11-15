#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

pair<int,int> a[50010];
int n,m,tn,Q[50010][101],head[101],tail[101],j1,j2;
long long h[50010],w[50010],dp[50010][101],xa,xb,xc,ya,yb,yc;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        a[0].second = 0;
        for (int i = 1;i <= n;i++)  scanf("%d%d",&a[i].first,&a[i].second);
        sort(a+1,a+n+1);
        tn = n;
        n = 1;
        for (int i = 2;i <= tn;i++)
        {
            while (n > 0 && a[n].first <= a[i].first && a[n].second <= a[i].second)
                n--;
            a[++n] = a[i];
        }
        for (int i = 1;i <= n;i++)
            w[i] = a[i].first,h[i] = a[i].second;
        h[n+1] = 0;
        memset(head,0,sizeof(head));
        memset(tail,0,sizeof(tail));
        dp[0][0] = 0;
        Q[tail[0]++][0] = 0;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                while (head[j-1]+1 < tail[j-1])
                {
                    j1 = Q[head[j-1]][j-1];
                    j2 = Q[head[j-1]+1][j-1];
                    if (dp[j1][j-1]-dp[j2][j-1] > (h[j2+1]-h[j1+1])*w[i])    head[j-1]++;
                    else    break;
                }
                j1 = Q[head[j-1]][j-1];
                dp[i][j] = dp[j1][j-1]+h[j1+1]*w[i];
                xc = -h[i+1];
                yc = dp[i][j];
                while (head[j]+1 < tail[j])
                {
                    j1 = Q[tail[j]-2][j];
                    j2 = Q[tail[j]-1][j];
                    xa = -h[j1+1];  ya = dp[j1][j];
                    xb = -h[j2+1];  yb = dp[j2][j];
                    if ((xb-xa)*(yc-ya) < (xc-xa)*(yb-ya))   tail[j]--;
                    else    break;
                }
                Q[tail[j]++][j] = i;
            }
        long long ans = dp[n][1];
        for (int i = 1;i <= m;i++)
            ans = min(ans,dp[n][i]);
        printf("%I64d\n",ans);
    }
    return 0;
}
