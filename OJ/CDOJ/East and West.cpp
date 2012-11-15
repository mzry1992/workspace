#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int head[1000000],L,deg[1000000];
long long N,E,W;
struct edges
{
    int to,next;
}edge[1999998];
void init(int n)
{
    N=n;L=0;
    memset(head,-1,4*n);
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
int sum[1000000];
int X,Y;
bool dfs(int u,int fu)
{
    sum[u]=u<E;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu) continue;
        if (dfs(v,u)) return 1;
        sum[u]+=sum[v];
    }
    if (sum[u]==E)
    {
        X=u;Y=fu;
        return 1;
    }
    else return 0;
}
void dfs2(int u,int fu,int DEG)
{
    deg[u]=DEG;
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu) continue;
        dfs2(v,u,DEG+1);
    }
}
int east[1000000],west[1000000];
int main()
{
    int n;
    while (scanf("%d%*d%d%d",&n,&E,&W)!=EOF)
    {
        init(n);
        for (int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(--u,--v);
            add_edge(v,u);
        }
        dfs(n-1,-1);
        dfs2(X,Y,0);
        dfs2(Y,X,0);
        int w=0,idx=n-W;
        int p;
        scanf("%d",&p);
        for (int i=0;i<p;i++)
        {
            int x;
            scanf("%d",&x);
            east[i]=deg[x-1];
        }
        for (int i=idx;i<n;i++)
            west[w++]=deg[i];
        sort(east,east+p);
        sort(west,west+w);
        int now=0,ans=0;
        for (int i=0;i<p;i++,now++)
        {
            if (now<east[i]) now=east[i];
            if (now+west[p-i-1]+1>ans) ans=now+west[p-i-1]+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
