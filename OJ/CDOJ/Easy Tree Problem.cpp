#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,f,ans[200001],totg;
struct graph
{
    int to,next;
}g[200001*2];

void addedge(int u,int v)
{
    totg++;
    g[totg].to = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

void DFS(int now)
{
    ans[now] = 0;
    for (int i = g[now].next;i != -1;i = g[i].next)
    {
        DFS(g[i].to);
        ans[now] += ans[g[i].to]+1;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        totg = n;
        for (int i = 1;i <= n;i++)  g[i].next = -1;
        for (int i = 2;i <= n;i++)
        {
            scanf("%d",&f);
            addedge(f,i);
        }
        DFS(1);
        printf("Case #%d: ",ft);
        for (int i = 1;i < n;i++)   printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
}
