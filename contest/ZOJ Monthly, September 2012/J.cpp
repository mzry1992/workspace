#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,t,k,l;
const int inf = 1<<29;
int ans;
struct N
{
    int s,e;
    int val;
}seg[1005];
int dp[10005][125];
bool cmp(N a,N b)
{
    if(a.e==b.e)
        return a.s<b.s;
    return a.e<b.e;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
	    scanf("%d%d%d%d",&n,&t,&k,&l);
	    int i,j;
	    for(i=0;i<n;i++)
           scanf("%d%d%d",&seg[i].s,&seg[i].e,&seg[i].val);
        sort(seg,seg+n,cmp);
        for(i=0;i<=10000;i++)
            for(j=0;j<=t+l;j++)
                dp[i][j]=-inf;
        dp[0][0]=ans=0;
        int num=0;
        for(i=1;i<=10000;i++)
        {
            while(num <n && seg[num].e==i)
            {
                for(j=1;j<=min(t+l,i);j++)
                    if(j>=seg[num].e-seg[num].s)
                    {
                        int tmp=seg[num].e-seg[num].s;
                        if(j-tmp<=t)
                        {
                            if(j<=t)
                                dp[i][j]=max(dp[i][j],dp[i-tmp][j-tmp]+seg[num].val);
                            else
                                dp[i][j]=max(dp[i][j],dp[i-tmp][j-tmp]+seg[num].val-(j-t)*(j-t));
                        }
                        else
                            dp[i][j]=max(dp[i][j],dp[i-tmp][j-tmp]+seg[num].val+(j-tmp-t)*(j-tmp-t)-(j-t)*(j-t));
                    }
                num++;
            }
            for(j=1;j<=min(t+l,i);j++)
            {
                if(j>t)
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(j-1-t)*(j-1-t)-(j-t)*(j-t));
                else
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
                if(j>=t && i+k+j-t <= 10000)
                    dp[i+k+j-t][0]=max(dp[i+k+j-t][0],dp[i][j]);
            }

            for(j=0;j<=t+l;j++)
                ans=max(ans,dp[i][j]);
        }
        printf("%d\n",ans);
	}
    return 0;
}

