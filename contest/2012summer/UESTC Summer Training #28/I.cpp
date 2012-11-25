#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int head[10005],e;
struct N
{
    int v,next;
}edge[20005];
void addedge(int u,int v)
{
    edge[e].v=v;
    edge[e].next=head[u];
    head[u]=e++;
}
bool vis[10005];
int dp[10005][2];
const int inf = 1<<29;
void dfs(int u)
{
    vis[u]=true;
    int i,v,mi1,mi2;
    mi1=mi2=inf;
    dp[u][0]=dp[u][1]=0;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
        {
            dfs(v);
            int tmp=dp[v][0]-dp[v][1];
            if(tmp<mi1)
            {
                mi2=mi1;
                mi1=tmp;
            }
            else if(tmp<mi2)
                mi2=tmp;
            dp[u][1]+=min(dp[v][0],dp[v][1]);
            dp[u][0]+=dp[v][1];
        }
    }
    dp[u][1]=min(min(dp[u][0]+100,dp[u][0]+mi1+175),dp[u][1]+500);
    dp[u][0]=min(min(dp[u][0]+mi1+100,dp[u][0]+mi1+mi2+175),dp[u][0]);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    memset(head,-1,sizeof(head));
	    e=0;
	    int i;
	    for(i=0;i<n-1;i++)
	    {
	        int a,b;
	        scanf("%d%d",&a,&b);
	        addedge(a,b);
	        addedge(b,a);
	    }
	    memset(vis,false,sizeof(vis));
	    dfs(0);
	    printf("$%d\n",min(dp[0][0],dp[0][1]));
	}
	return 0;
}
