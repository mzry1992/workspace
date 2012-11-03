#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct Edge
{
    int to,next;
} edge[200000];
bool visited[10000];
int head[10000],ner2[10000],deg[10000];
int L;
void addEdge(int u,int v)
{
    deg[u]++;
    edge[L].to=v;
    edge[L].next=head[u];
    head[u]=L++;
}
int dfs(int u)
{
    visited[u]=1;
    int ret=1;
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if (deg[v]==2)
        {
            ner2[u]=v;
            continue;
        }
        if (visited[v])
            continue;
        ret+=dfs(v);
    }
    return ret;
}
vector<int> ans;
void euler(int u)
{
    visited[u]=1;
    if (deg[u]>2 && !visited[ner2[u]])
        euler(ner2[u]);
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if (visited[v])
            continue;
        euler(v);
    }
    ans.push_back(u);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(deg,0,4*n);
    memset(head,-1,4*n);
    memset(ner2,-1,4*n);
    memset(visited,0,n);
    L=0;
    for (int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(--u,--v);
        addEdge(v,u);
    }
    bool flag=0;
    for (int i=0; i<n && !flag; i++)
        if (deg[i]>2 && !visited[i])
            flag=dfs(i)&1;
    if (flag)
    {
        puts("-1");
        return 0;
    }
    memset(visited,0,n);
    euler(0);
    for (int i=0; i<ans.size(); i++)
        printf("%d ",ans[i]+1);
    return 0;
}
