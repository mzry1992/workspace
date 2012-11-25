#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int dp[105][505];
int head[105],e;
int val[105],pos[105],num,dist,last;
bool vis[105];
struct N
{
    int v,next;
    int len;
}edge[405];
void addedge(int u,int v,int l)
{
    edge[e].v=v;
    edge[e].len=l;
    edge[e].next=head[u];
    head[u]=e++;

    edge[e].v=u;
    edge[e].len=l;
    edge[e].next=head[v];
    head[v]=e++;
}
bool find(int u,int deep)
{
    pos[deep]=u;
    if(u==n)
    {
        num=deep;
        return true;
    }
    int i,v;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
        {
            vis[v]=true;
            dist+=edge[i].len;
            if(find(v,deep+1))
                return true;
            vis[v]=false;
            dist-=edge[i].len;
        }
    }
    return false;
}
void dfs(int u)
{
    vis[u]=true;
    int i,v;
    for(i=0;i<=last;i++)
        dp[u][i]=0;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(!vis[v])
        {
            dfs(v);
            int j,k;
            for(j=last;j>=0;j--)
                for(k=0;k+2*edge[i].len<=j;k++)
                    dp[u][j]=max(dp[u][j],dp[u][j-k-edge[i].len*2]+dp[v][k]);
        }
    }
    for(i=0;i<=last;i++)
        dp[u][i]+=val[u];
}
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
	    int i,j,k;
	    memset(head,-1,sizeof(head));
	    e=0;
	    for(i=0;i<n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
        }
        for(i=1;i<=n;i++)
            scanf("%d",&val[i]);
        dist=0;
        memset(vis,false,sizeof(vis));
        vis[1]=true;
        find(1,0);
        last=m-dist;
        if(dist>m)
        {
            printf("Human beings die in pursuit of wealth, and birds die in pursuit of food!\n");
            continue;
        }
        for(i=0;i<=num;i++)
            dfs(pos[i]);
//        for(i=0;i<=num;i++)
//        {
//            for(j=0;j<=last;j++)
//                printf("%d %d %d\n",pos[i],j,dp[pos[i]][j]);
//            printf("\n");
//        }
        for(i=1;i<=num;i++)
            for(j=last;j>=0;j--)
                for(k=last-j;k>=0;k--)
                    dp[pos[i]][j+k]=max(dp[pos[i]][j+k],dp[pos[i-1]][k]+dp[pos[i]][j]);
        printf("%d\n",dp[n][last]);
	}
	return 0;
}
