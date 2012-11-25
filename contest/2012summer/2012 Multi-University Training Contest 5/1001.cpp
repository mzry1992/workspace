#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int val[2][105];
int head[105],e;
int dp[105][2][105];
int seg[105];
struct N
{
    int v,next;
}edge[205];
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].next=head[v];
    head[v]=e++;
}
int findseg(int x)
{
    if(seg[x]==x)
        return x;
    else
        return seg[x]=findseg(seg[x]);
}
bool vis[105];
const int inf = 1<<30;
int mi[2][105];
void dfs(int s)
{
    vis[s]=true;
    int i,v,j,k,l,sum[2];
    seg[s]=s;
    sum[0]=sum[1]=0;
    for(i=1;i<=n;i++)
    {
        mi[0][i]=mi[1][i]=inf;
        dp[s][0][i]=inf;
        dp[s][1][i]=inf;
    }
    for(i=head[s];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
        {
            dfs(v);
            for(j=1;j<=n;j++)
                if(findseg(j)==s&&j!=s)
                {
                    for(k=1;k<=n;k++)
                        if(findseg(k)==v)
                            for(l=0;l<2;l++)
                            {
                                if(val[l][k]>val[l][j])
                                    mi[l][j]=min(mi[l][j],dp[v][l][k]+val[l][k]/2);
                                else
                                    mi[l][k]=min(mi[l][k],dp[s][l][j]+val[l][j]/2);
                                mi[l][j]=min(mi[l][j],dp[v][l^1][k]+val[l^1][k]);
                                mi[l][k]=min(mi[l][k],dp[s][l^1][j]+val[l^1][j]);
                            }
                    dp[s][0][j]+=mi[0][j];
                    dp[s][1][j]+=mi[1][j];
                }
            int a=inf,b=inf;
            for(k=1;k<=n;k++)
                if(findseg(k)==v)
                {
                    a=min(a,dp[v][0][k]+val[0][k]);
                    b=min(b,dp[v][1][k]+val[1][k]);
                    dp[s][0][k]=mi[0][k]+dp[v][0][k];
                    dp[s][1][k]=mi[1][k]+dp[v][1][k];
                }
            sum[0]+=a;sum[1]+=b;
            seg[v]=s;
        }
    }
    for(i=1;i<=n;i++)
        if(findseg(i)==s&&i!=s)
            for(l=0;l<2;l++)
            {
                if(val[l][i]>val[l][s])
                    dp[s][l][s]=min(dp[s][l][s],dp[s][l][i]+val[l][i]/2);
                else
                    dp[s][l][i]+=val[l][s]/2;
            }
    dp[s][0][s]=min(dp[s][0][s],sum[1]);
    dp[s][1][s]=min(dp[s][1][s],sum[0]);
}
int main()
{
	while(scanf("%d",&n)==1)
	{
	    int i;
	    for(i=0;i<n;i++)
            scanf("%d",&val[0][i]);
        for(i=0;i<n;i++)
            scanf("%d",&val[1][i]);
        memset(head,-1,sizeof(head));
        e=0;
        for(i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        memset(vis,false,sizeof(vis));
        dfs(1);
        int ans=inf;
        for(i=1;i<=n;i++)
            ans=min(ans,min(dp[1][0][i]+val[0][1],dp[1][1][i]+val[1][1]));
        printf("%d\n",ans);
	}
	return 0;
}
