#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,T,S;
long long val[150005],dp[150005][2];
void init()
{
    dp[S][0] = dp[S][1]=0;
    dp[S+1][0]=dp[S-1][0]=0;
    dp[S-1][1]=val[S-1];
    dp[S+1][1]=val[S+1];
    for (int i = S-2;i >= S-n;i--)
        for (int j = 0;j < 2;j++)
        {
            dp[i][j] = dp[i+1][j];
            if (i+2 <= S)
                dp[i][j] = max(dp[i][j],dp[i+2][j]+val[i]);
        }
    for (int i = S+2;i <= S+n;i++)
        for (int j = 0;j < 2;j++)
        {
            dp[i][j] = dp[i-1][j];
            if (i-2 >= S)
                dp[i][j] = max(dp[i][j],dp[i-2][j]+val[i]);
        }
}
long long solve(int l,int r)
{
    if (r-l+1 == n)
        return max(dp[S+n][0],dp[S+n-1][1]);
    return max(dp[r][0]+dp[l][0]+val[S],max(dp[r][1]+dp[l][1],max(dp[r][1]+dp[l][0],dp[r][0]+dp[l][1])));
}
int main()
{
	while(scanf("%d%d%d",&n,&T,&S)==3)
	{
	    int i;
	    for(i=1;i<=n;i++)
	    {
            scanf("%lld",&val[i]);
            val[i+n]=val[i+2*n]=val[i];
	    }
        S+=n;
	    init();
        long long ans=0;
        for(i=max(S-T,S-n+1);i<=S;i++)
        {
            int r=max(T-S+2*i,(T+S+i)/2);
            r=min(r,i+n-1);
            r=max(r,S);
            ans=max(ans,solve(i,r));
        }
        printf("%lld\n",ans);
	}
	return 0;
}
