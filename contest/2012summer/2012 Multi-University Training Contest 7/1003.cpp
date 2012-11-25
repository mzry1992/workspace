#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 0x3f3f3f3f;
int n,m,sx;
pair<int,int> p[50][1000];
int dp[50][1000];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d%d",&n,&m,&sx);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf("%d",&p[i][j].first);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf("%d",&p[i][j].second);
        for (int i = 0;i < n;i++)
            sort(p[i],p[i]+m);
        memset(dp,63,sizeof(dp));
        for (int i=0;i<m;i++)
            dp[0][i]=p[0][i].second+abs(sx-p[0][i].first);
        for (int i = 1;i < n;i++)
        {
            int mins=inf;
            for (int j=0,k=0;j<m;j++)
            {
                for (;k<m && p[i-1][k].first<=p[i][j].first;k++)
                    mins=min(mins,dp[i-1][k]-p[i-1][k].first);
                dp[i][j]=mins+p[i][j].second+p[i][j].first;
                if (dp[i][j] > inf)
                    dp[i][j] = inf;
            }
            mins=inf;
            for (int j=m-1,k=m-1;j>=0;j--)
            {
                for (;k>=0 && p[i-1][k].first>=p[i][j].first;k--)
                    mins=min(mins,dp[i-1][k]+p[i-1][k].first);
                dp[i][j]=min(dp[i][j],mins+p[i][j].second-p[i][j].first);
            }
        }
        int ans = inf;
        for (int i = 0;i < m;i++)
            ans = min(ans,dp[n-1][i]);
        printf("%d\n",ans);
    }
	return 0;
}
