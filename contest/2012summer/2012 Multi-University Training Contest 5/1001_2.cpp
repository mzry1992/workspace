#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
    int to,next;
}edge[99*2];
long long dp[100][2][100];
long long mins[100][2];
bool son[100][100];
int a[100],b[100];
int head[100];
int n,L;
void init(int n)
{
    memset(head,-1,4*n);
    L=0;
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
void dfs(int u,int fu)
{
    for (int i=0;i<n;i++)
        if (son[u][i])
        {
            dp[u][0][i]=a[u]/2;
            dp[u][1][i]=b[u]/2;
        }
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu)
            continue;
        dfs(v,u);
        for (int x=0;x<n;x++)
            if (son[u][x])
                if (son[v][x])
                {
                    dp[u][0][x]+=dp[v][0][x];
                    dp[u][1][x]+=dp[v][1][x];
                }
                else
                {
                    dp[u][0][x]+=mins[v][0];
                    dp[u][1][x]+=mins[v][1];
                }
    }
    memset(mins[u],127,sizeof(mins[u]));
    for (int x=0;x<n;x++)
        if (son[u][x])
        {
            mins[u][0]=min(mins[u][0],min(dp[u][0][x],dp[u][1][x]+b[x]-b[x]/2));
            mins[u][1]=min(mins[u][1],min(dp[u][1][x],dp[u][0][x]+a[x]-a[x]/2));
        }
}
void predfs(int u,int fu)
{
    son[u][u]=1;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu)
            continue;
        predfs(v,u);
        for (int i=0;i<n;i++)
            son[u][i]|=son[v][i];
    }
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=0;i<n;i++)
            scanf("%d",&b[i]);
        init(n);
        for (int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u-1,v-1);
            add_edge(v-1,u-1);
        }
        memset(son,0,sizeof(son));
        predfs(0,-1);
        dfs(0,-1);
        long long ans=0x7fffffffffffffffLL;
        for (int i=0;i<n;i++)
            ans=min(ans,min(dp[0][0][i]+a[i]-a[i]/2,dp[0][1][i]+b[i]-b[i]/2));
        printf("%I64d\n",ans);
    }
    return 0;
}
