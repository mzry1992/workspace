#include<cstdio>
#include<cstring>
int a[100000],head[100000],L;
long long N;
struct edges
{
    int to,key,next;
}edge[199998];
void init(int n)
{
    N=n;L=0;
    memset(head,-1,4*n);
}
void add_edge(int u,int v,int w)
{
    edge[L].to=v;
    edge[L].key=w;
    edge[L].next=head[u];
    head[u]=L++;
}
long long sum[100000],dp[100000],ans[100000],out;
void dfs(int u,int fu)
{
    sum[u]=a[u];dp[u]=0;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu) continue;
        dfs(v,u);
        sum[u]+=sum[v];
        dp[u]+=dp[v]+sum[v]*edge[i].key;
    }
}
void dfs2(int u,int fu)
{
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu) continue;
        ans[v]=ans[u]+(sum[0]-2*sum[v])*edge[i].key;
        if (out>ans[v]) out=ans[v];
        dfs2(v,u);
    }
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        init(n);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            add_edge(--x,--y,z);
            add_edge(y,x,z);
        }
        dfs(0,-1);
        out=ans[0]=dp[0];
        dfs2(0,-1);
        printf("%lld\n",out);
    }
    return 0;
}
