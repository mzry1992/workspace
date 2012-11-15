#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
struct graph
{
    int to,next;
}g[100000+200000+100];
int totg;
int w[100000+10];
int dp[100000+10];
bool visit[100000+10];
int maxres;

void addedge(int u,int v)
{
    totg++;
    g[totg].to = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

void DFS(int root)
{
    dp[root] = w[root];
    visit[root] = true;
    int cur = 0;
    for (int vv = g[root].next;vv != -1;vv = g[vv].next)
    if (visit[g[vv].to] == false)
    {
        DFS(g[vv].to);
        if (dp[g[vv].to] > 0)
            cur += dp[g[vv].to];
    }
    dp[root] += cur;
    if (dp[root] > maxres)  maxres = dp[root];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&w[i]);
            g[i].next = -1;
        }
        totg = n;
        for (int i = 1;i < n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        memset(visit,false,sizeof(visit));
        memset(dp,0,sizeof(dp));
        maxres = -19921005;
        DFS(1);
        printf("%d\n",maxres);
    }
}
