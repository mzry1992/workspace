#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
int n,m;
int head[100005],e;
struct N
{
    int v,next;
    int cost;
}edge[200005];
void addedge(int u,int v,int c)
{
    edge[e].v=v;
    edge[e].cost=c;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].cost=c;
    edge[e].next=head[v];
    head[v]=e++;
}
bool vis[100005],im[100005];
int val[100005];
long long dp[100005][2];
const long long inf = 1ll<<60;
void dfs(int s)
{
    vis[s]=true;
    int i,v;
    bool flag=true;
    long long dt=inf;
    dp[s][0]=dp[s][1]=0;
    for(i=head[s];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
        {
            val[v]=edge[i].cost;
            flag=false;
            dfs(v);
            if(im[s])
            {
                dp[s][0]+=dp[v][0];
                dp[s][1]+=dp[v][0];
            }
            else
            {
                dt=min(dt,dp[v][1]-dp[v][0]);
                dp[s][0]+=dp[v][0];
                dp[s][1]+=dp[v][0];
            }
        }
    }
    if(flag)
    {
        if(im[s])
        {
            dp[s][0]=val[s];
            dp[s][1]=0;
        }
        else
        {
            dp[s][0]=0;
            dp[s][1]=0;
        }
    }
    else
    {
        if(im[s])
            dp[s][0]+=val[s];
        else
        {
            dp[s][0]=min(dp[s][0],dp[s][1]+dt+val[s]);
            dp[s][1]+=dt;
        }
    }
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d",&n,&m);
	    int i;
	    memset(head,-1,sizeof(head));
	    e=0;
	    for(i=0;i<n-1;i++)
	    {
	        int a,b,c;
	        scanf("%d%d%d",&a,&b,&c);
	        addedge(a,b,c);
	    }
	    memset(vis,false,sizeof(vis));
	    memset(im,false,sizeof(im));
	    for(i=0;i<m;i++)
	    {
	        int a;
	        scanf("%d",&a);
	        im[a]=true;
	    }
	    val[0]=0;
	    dfs(0);
	    printf("%I64d\n",min(dp[0][0],dp[0][1]));
	}
	return 0;
}
