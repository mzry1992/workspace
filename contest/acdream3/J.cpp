#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
	int to,next;
}edge[4000];
int head[2000],L;
int n;
int w[2000],cnt[2000];

void addedge(int u,int v)
{
	edge[L].to = v;
	edge[L].next = head[u];
	head[u] = L++;
}

int dp[2000][2001];
int DP(int u,int fa)
{
	dp[u][0] = 0;
	cnt[u] = 0;
	for (int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == fa)	continue;
		DP(v,u);
		cnt[u] += cnt[v];

		for (int x = cnt[u];x >= 0;x--)
			for (int y = 0;y <= cnt[v] && y <= x;y++)
				dp[u][x] = min(dp[u][x],dp[u][x-y]+dp[v][y]);
	}
	cnt[u]++;
	for (int x = cnt[u];x >= 1;x--)
		dp[u][x] = dp[u][x-1]+w[u];
//	printf("u = %d, cnt = %d\n",u,cnt[u]);
//	for (int i = 0;i <= cnt[u];i++)
//		printf("%d ",dp[u][i]);
//	printf("\n");
}

int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&w[i]);
		head[i] = -1;
	}
	L = 0;
	for (int i = 0;i < n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;
		v--;
		addedge(u,v);
		addedge(v,u);
	}
	memset(dp,63,sizeof(dp));
	DP(0,-1);
	for (int i = 1;i <= n;i++)
	{
		int ans = 0x3f3f3f3f;
		for (int j = 0;j < n;j++)
			ans = min(ans,dp[j][i]);
		printf("%d",ans);
		if (i < n)
			printf(" ");
	}
	printf("\n");
	return 0;
}
