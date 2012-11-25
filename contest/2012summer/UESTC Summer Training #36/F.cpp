#include <cstdio>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main()
{
    int n;
    scanf("%d",&n);
    if (n && n<3)
    {
        printf("%d.000\n",(n-1)*4+1);
        return 0;
    }
    dp[2][2]=5;
    int ans=0;
    for (int i=3;i<=n;i++)
        for (int j=2;j<=i;j++)
        {
            dp[i][j]=0;
            if (j>2)
                dp[i][j]=dp[i-1][j-1]+j*(i-j+2);
            if (j<i)
                dp[i][j]=max(dp[i][j],dp[i-1][j]+j*(i-j+2));
            ans=max(ans,dp[i][j]);
        }
    printf("%d.000\n",ans);
}
