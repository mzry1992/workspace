#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,M,H;
int dp[17][1<<17];
int mp[105][105];
const int inf = 1<<29;
int city[17],D[17],C[17];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d%d",&n,&m,&M);
	    int i,j,k;
	    for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                if(i!=j)
                    mp[i][j]=inf;
                else
                    mp[i][j]=0;
            }
        for(i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            mp[a][b]=mp[b][a]=min(mp[b][a],c);
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
        scanf("%d",&H);
        city[0]=1;C[0]=D[i]=0;
        for(i=1;i<=H;i++)
            scanf("%d%d%d",&city[i],&C[i],&D[i]);
        memset(dp,-1,sizeof(dp));
        dp[0][0]=M;
        bool flag=false;
        int sum=1<<H;
        for(i=0;i<sum;i++)
        {
            for(j=0;j<=H;j++)
                if(dp[j][i]!=-1)
                    for(k=0;k<H;k++)
                        if(((i&(1<<k))==0)&&dp[j][i]>=D[k+1]+mp[city[j]][city[k+1]])
                            dp[k+1][i|(1<<k)]=max(dp[k+1][i|(1<<k)],dp[j][i]-D[k+1]-mp[city[j]][city[k+1]]+C[k+1]);
        }
        for(i=0;i<=H;i++)
            if(dp[i][sum-1]>=mp[city[i]][1])
                flag=true;
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
	}
	return 0;
}
