#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const int MaxN = 30000;
const int MaxM = 50000;
struct mEdge
{
    int u,v,w;
    bool operator < (const mEdge& b)const
    {
        return w > b.w;
    }
};
mEdge mm[MaxM];
int f[MaxN],a[MaxN];
int n,m;

struct Edge
{
    int to,next;
};
Edge edge[MaxN*2];
int head[MaxN],L;

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

void init()
{
    for (int i = 0;i < n;i++)
    {
        head[i] = -1;
        f[i] = i;
    }
    L = 0;
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}
int fa[MaxN][20],mins[MaxN][20],maxs[MaxN][20],down[MaxN][20],up[MaxN][20];
int dep[MaxN];
void dfs(int u,int fu)
{
    memset(fa[u],0,sizeof(fa[u]));
    fa[u][0]=u;
    mins[u][0]=maxs[u][0]=a[u];
    up[u][0]=down[u][0]=0;
    for (int i=1,tmp=fu;i<20;tmp=fa[tmp][i-1],i++)
    {
        fa[u][i]=fa[tmp][i-1];
        mins[u][i]=min(mins[u][i-1],mins[tmp][i-1]);
        maxs[u][i]=max(maxs[u][i-1],maxs[tmp][i-1]);
        up[u][i]=max(up[u][i-1],up[tmp][i-1]);
        up[u][i]=max(up[u][i],maxs[tmp][i-1]-mins[u][i-1]);
        down[u][i]=max(down[u][i-1],down[tmp][i-1]);
        down[u][i]=max(down[u][i],maxs[u][i-1]-mins[tmp][i-1]);
    }
    for (int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu)
            continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
    }
}
int getLca(int u,int v)
{
    if (dep[u]<dep[v])
        swap(u,v);
    for (int det=dep[u]-dep[v],i=1;det;det>>=1,i++)
    {
        if (det&1)
            u=fa[u][i];
    }
    if (u==v)
        return u;
    for (int i=19;i;i--)
    {
        if (fa[u][i]==fa[v][i])
            continue;
        u=fa[u][i];
        v=fa[v][i];
    }
    return fa[u][1];
}
int getMax(int u,int v)
{
    int ret=0;
    for (int det=dep[u]-dep[v],i=1;det;det>>=1,i++)
        if (det&1)
        {
            ret=max(ret,maxs[u][i]);
            u=fa[u][i];
        }
    return ret;
}
int getMin(int u,int v)
{
    int ret=inf;
    for (int det=dep[u]-dep[v],i=1;det;det>>=1,i++)
        if (det&1)
        {
            ret=min(ret,mins[u][i]);
            u=fa[u][i];
        }
    return ret;
}
int getUp(int u,int v)
{
    int ret=0;
    for (int det=dep[u]-dep[v],i=1;det;det>>=1,i++)
        if (det&1)
        {
            ret=max(ret,up[u][i]);
            ret=max(ret,getMax(fa[u][i],v)-mins[u][i]);
            u=fa[u][i];
        }
    return ret;
}
int getDown(int u,int v)
{
    int ret=0;
    for (int det=dep[u]-dep[v],i=1;det;det>>=1,i++)
        if (det&1)
        {
            ret=max(ret,down[u][i]);
            ret=max(ret,maxs[u][i]-getMin(fa[u][i],v));
            u=fa[u][i];
        }
    return ret;
}

int getAns(int u,int v)
{
    int anc=getLca(u,v);
    int ret=getMax(v,anc)-getMin(u,anc);
    ret=max(ret,getUp(u,anc));
    ret=max(ret,getDown(v,anc));
    return ret;
}
int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);

        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&mm[i].u,&mm[i].v,&mm[i].w);
            mm[i].u--;
            mm[i].v--;
        }
        init();
        sort(mm,mm+m);
        int ans=0;
        for (int i = 0,j = 0;i < n-1;i++)
        {
            while (findf(mm[j].u) == findf(mm[j].v))    j++;
            ans+=mm[j].w;
            f[findf(mm[j].u)] = findf(mm[j].v);
            addedge(mm[j].u,mm[j].v);
            addedge(mm[j].v,mm[j].u);
        }
        dep[0]=0;
        dfs(0,0);
        printf("%d\n",ans);
        int q;
        scanf("%d",&q);
        while (q--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            printf("%d\n",getAns(u-1,v-1));
        }
    }
    return 0;
}

