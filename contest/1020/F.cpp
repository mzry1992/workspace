#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int to,next;
} edge[100000];
struct trees
{
    int fa[20],min[20],max[20],up[20],down[20];
    int head,deg;
} tree[50000];
int L;
int a[50000];
void init(int n)
{
    L=0;
    for (int i=0; i<n; i++)
        tree[i].head=-1;
}
void dfs(int u,int fu,int deg)
{
    for (int i=1; i<20; i++)
        tree[u].fa[i]=0;
    tree[u].deg=deg;
    tree[u].fa[0]=fu;
    tree[u].min[0]=min(a[u],a[fu]);
    tree[u].max[0]=max(a[u],a[fu]);
    tree[u].up[0]=max(0,a[fu]-a[u]);
    tree[u].down[0]=max(0,a[u]-a[fu]);
    for (int i=fu,num=1; tree[i].deg; i=tree[u].fa[num++])
    {
        tree[u].fa[num]=tree[i].fa[num-1];
        tree[u].min[num]=min(tree[u].min[num-1],tree[i].min[num-1]);
        tree[u].max[num]=max(tree[u].max[num-1],tree[i].max[num-1]);
        tree[u].up[num]=max(tree[u].up[num-1],tree[i].up[num-1]);
        tree[u].up[num]=max(tree[u].up[num],-tree[u].min[num-1]+tree[i].max[num-1]);
        tree[u].down[num]=max(tree[u].down[num-1],tree[i].down[num-1]);
        tree[u].down[num]=max(tree[u].down[num],tree[u].max[num-1]-tree[i].min[num-1]);
    }
    for (int i=tree[u].head; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fu)
            continue;
        dfs(v,u,deg+1);
    }
}
int query(int u,int v)
{
    int lmin=0x7fffffff,rmin=0x7fffffff;
    int lmax=0,rmax=0;
    int ldown=0,rdown=0;
    int lup=0,rup=0;
    if (tree[u].deg<tree[v].deg)
    {
        for (int det=tree[v].deg-tree[u].deg,i=0; det; det>>=1,i++)
            if (det&1)
            {
                rdown=max(rdown,tree[v].down[i]);
                rdown=max(rdown,-tree[v].min[i]+rmax);
                rup=max(rup,tree[v].up[i]);
                rup=max(rup,tree[v].max[i]-rmin);
                rmin=min(rmin,tree[v].min[i]);
                rmax=max(rmax,tree[v].max[i]);
                v=tree[v].fa[i];
            }
    }
    else if (tree[u].deg>tree[v].deg)
    {
        for (int det=tree[u].deg-tree[v].deg,i=0; det; det>>=1,i++)
            if (det&1)
            {
                ldown=max(ldown,tree[u].down[i]);
                ldown=max(ldown,-tree[u].min[i]+lmax);
                lup=max(lup,tree[u].up[i]);
                lup=max(lup,tree[u].max[i]-lmin);
                lmin=min(lmin,tree[u].min[i]);
                lmax=max(lmax,tree[u].max[i]);
                u=tree[u].fa[i];
            }
    }
    if (u==v)
        return max(max(lup,rdown),rmax-lmin);
    for (int i=19; i>=0; i--)
    {
        if (tree[u].fa[i]==tree[v].fa[i])
            continue;
        rdown=max(rdown,tree[v].down[i]);
        rdown=max(rdown,-tree[v].min[i]+rmax);
        rup=max(rup,tree[v].up[i]);
        rup=max(rup,tree[v].max[i]-rmin);
        rmin=min(rmin,tree[v].min[i]);
        rmax=max(rmax,tree[v].max[i]);
        ldown=max(ldown,tree[u].down[i]);
        ldown=max(ldown,-tree[u].min[i]+lmax);
        lup=max(lup,tree[u].up[i]);
        lup=max(lup,tree[u].max[i]-lmin);
        lmin=min(lmin,tree[u].min[i]);
        lmax=max(lmax,tree[u].max[i]);
        v=tree[v].fa[i];
        u=tree[u].fa[i];
    }
    rdown=max(rdown,tree[v].down[0]);
    rdown=max(rdown,-tree[v].min[0]+rmax);
    rup=max(rup,tree[v].up[0]);
    rup=max(rup,tree[v].max[0]-rmin);
    rmin=min(rmin,tree[v].min[0]);
    rmax=max(rmax,tree[v].max[0]);
    ldown=max(ldown,tree[u].down[0]);
    ldown=max(ldown,-tree[u].min[0]+lmax);
    lup=max(lup,tree[u].up[0]);
    lup=max(lup,tree[u].max[0]-lmin);
    lmin=min(lmin,tree[u].min[0]);
    lmax=max(lmax,tree[u].max[0]);
    return max(max(lup,rdown),rmax-lmin);
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=tree[u].head;
    tree[u].head=L++;
}
int main()
{
    int n;
    scanf("%d",&n);
    init(n);
    for (int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    for (int i = 0; i < n-1; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        u--;
        v--;
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(0,0,0);
    int q;
    scanf("%d",&q);
    for (int i=0; i<q; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",query(u-1,v-1));
    }
    return 0;
}

