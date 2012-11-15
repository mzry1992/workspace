#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
struct tree
{
    int to,next;
}g[1501+1501+1501];
int totg,dp[1501][2];
bool visit[1501];

void addedge(int u,int v)
{
    g[totg].to = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
    totg++;
}

void DP(int now)
{
    visit[now] = true;
    int son[21],totson = 0;
    for (int i = g[now].next;i != -1;i = g[i].next)
        if (visit[g[i].to] == false)
        {
            DP(g[i].to);
            totson++;
            son[totson] = g[i].to;
        }
    dp[now][0] = 0;
    dp[now][1] = 1;
    if (totson != 0)
    {
        for (int i = 1;i <= totson;i++) dp[now][0] += dp[son[i]][1];
        for (int i = 1;i <= totson;i++) dp[now][1] += min(dp[son[i]][0],dp[son[i]][1]);
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)   g[i].next = -1;
        totg = n;
        for (int i = 1;i <= n;i++)
        {
            int u,tot,v;
            scanf("%d:(%d)",&u,&tot);
            for (int j = 1;j <= tot;j++)
            {
                scanf("%d",&v);
                addedge(u,v);
                addedge(v,u);
            }
        }
        memset(visit,false,sizeof(visit));
        DP(0);
        printf("%d\n",min(dp[0][0],dp[0][1]));
    }
}
