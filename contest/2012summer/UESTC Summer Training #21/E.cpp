#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int to,next,cost;
}edge[200];

int n,v[100],head[100],L,s,tim;

void addedge(int u,int v,int cost)
{
    edge[L].cost = cost;
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int dp[100][210];

void DP(int now,int fa)
{
    dp[now][0] = v[now];
    for (int i = head[now];i != -1;i = edge[i].next)
        if (edge[i].to != fa)
        {
            DP(edge[i].to,now);
            for (int j = tim;j >= edge[i].cost*2;j--)
                for (int k=0;k<=j-edge[i].cost*2;k++)
                    dp[now][j] = max(dp[now][j],dp[now][j-edge[i].cost*2-k]+dp[edge[i].to][k]);
        }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        L = 0;
        for (int i = 0;i < n;i++)
        {
            head[i] = -1;
            scanf("%d",&v[i]);
        }
        for (int i = 0;i < n-1;i++)
        {
            int u,v,t;
            scanf("%d%d%d",&u,&v,&t);
            u--,v--;
            addedge(u,v,t);
            addedge(v,u,t);
        }
        scanf("%d%d",&s,&tim);
        s--;
        memset(dp,-1,sizeof(dp));
        DP(s,-1);
        int ans = 0;
        for (int i = 0;i <= tim;i++)
            ans = max(ans,dp[s][i]);
        printf("%d\n",ans);
    }
	return 0;
}
