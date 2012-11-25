#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[21][2048];
int main()
{
	freopen("1008.in","r",stdin);
	freopen("1008.out2","w",stdout);
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        memset(dp,63,sizeof(dp));
        dp[0][0]=0;
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            for (int j=0;j<2048;j++)
                if (dp[i][j]!=inf)
                    for (int p=x;p<2048;p++)
                        dp[i+1][p^j]=min(dp[i+1][p^j],dp[i][j]+p-x);
        }
        if (dp[n][0]<inf)
                printf("%d\n",dp[n][0]);
            else
                puts("impossible");
    }
    return 0;
}
