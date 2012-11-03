#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[100000],g[100000],fa[100000],id[100000];
long long h[100000][2],dp[100000][2],sum[100000][2];
bool flag[100000],solved[100000];
int head[100000],L;
struct edges
{
    int to,next;
}edge[100000];
void init(int n)
{
    L=0;
    memset(flag,0,n);
    memset(solved,0,n);
    memset(head,-1,4*n);
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
int pre_dfs(int x)
{
    if (flag[x]) return x;
    flag[x]=1;
    return pre_dfs(fa[x]);
}
void dfs(int u,int fu)
{
    solved[u]=1;
    int tmp1=0,tmp2=0;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu) continue;
        dfs(v,u);
        tmp1+=dp[v][0];
        tmp2+=dp[v][1];
    }
    sum[u][0]=tmp1;
    sum[u][1]=tmp2;
    dp[u][0]=max(0,max(tmp1,f[u]+tmp2));
    dp[u][1]=max(0,max(tmp1,g[u]+tmp2));
}
long long solve(int x)
{
    int idx=pre_dfs(x);
    long long ret;
    int L=1;
    dfs(fa[idx],idx);
    id[0]=idx;
    for (int i=fa[idx];i!=idx;i=fa[i])
    {
        id[L++]=i;
        dfs(fa[i],i);
    }
    h[0][1]=h[0][0]=sum[idx][0];
    for (int i=1;i<L;i++)
    {
        h[i][0]=max(h[i-1][1]+sum[id[i]][1]+f[id[i]],h[i-1][0]+sum[id[i]][0]);
        h[i][1]=max(h[i-1][1]+sum[id[i]][1]+g[id[i]],h[i-1][0]+sum[id[i]][0]);
    }
    ret=h[L-1][0];
    h[0][1]=sum[idx][1]+g[idx];
    h[0][0]=sum[idx][1]+f[idx];
    for (int i=1;i<L;i++)
    {
        h[i][0]=max(h[i-1][1]+sum[id[i]][1]+f[id[i]],h[i-1][0]+sum[id[i]][0]);
        h[i][1]=max(h[i-1][1]+sum[id[i]][1]+g[id[i]],h[i-1][0]+sum[id[i]][0]);
    }
    ret=max(ret,h[L-1][1]);
    return ret;
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        init(n);
        for (int i=0;i<n;i++)
        {
            scanf("%d%d%d",&f[i],&g[i],&fa[i]);
            fa[i]--;
            g[i]+=f[i];
            add_edge(fa[i],i);
        }
        long long ans=0;
        for (int i=0;i<n;i++)
            if (!solved[i])
                ans+=solve(i);
        printf("%lld\n",ans);
    }
    return 0;
}
