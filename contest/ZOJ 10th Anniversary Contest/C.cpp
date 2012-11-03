#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
    int to,next;
} edge[100*99];
int head[100],fa[100],deg[100],low[100];
bool sons[100],visited[100],outs[100];
int L;
int d;
vector<int> ans;
void init(int n)
{
    ans.clear();
    memset(head,-1,4*n);
    memset(visited,0,n);
    memset(outs,0,n);
    memset(sons,0,n);
    L=0;
}
void add_edge(int u,int v)
{
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
void dfs(int u,int de,bool flag)
{
    visited[u]=1;
    sons[u]=flag;
    deg[u]=low[u]=de;
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if (v==fa[u])
            continue;
        if (visited[v])
        {
            low[u]=min(low[u],deg[v]);
            continue;
        }
        fa[v]=u;
        dfs(v,de+1,flag||(v==d));
        low[u]=min(low[u],low[v]);
    }
    if (sons[u] && low[u]<deg[d])
        ans.push_back(u);
}
int main()
{
    int n,m,s;
    while (scanf("%d%d%d%d",&n,&m,&s,&d) != EOF)
    {
        init(n);
        for (int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
        ans.push_back(d);
        dfs(s,0,0);
        outs[s]=1;
        for (int i=0; i<ans.size(); i++)
            for (int j=ans[i];!outs[j];j=fa[j])
                outs[j]=1;
        int tot=n;
        for (int i=0; i<n; i++)
            tot-=outs[i];
        printf("%d\n",tot);
    }
    return 0;
}
