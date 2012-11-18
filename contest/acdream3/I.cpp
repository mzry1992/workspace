#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
	int to,next;
}edge[200000];
int head[100000],L;
int n;
int dp[100000][2];

void addedge(int u,int v)
{
	edge[L].to = v;
	edge[L].next = head[u];
	head[u] = L++;
}

void DP(int u,int fa)
{
	int f[2][2],flag = 0;
	f[flag][0] = -0x3f3f3f3f;
	f[flag][1] = 0;
	for (int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == fa)	continue;
		DP(v,u);

		f[!flag][0] = f[!flag][1] = -0x3f3f3f3f;
		//不砍
		for (int x = 0;x < 2;x++)
			for (int y = 0;y < 2;y++)
				f[!flag][(x+y)%2] = max(f[!flag][(x+y)%2],f[flag][x]+dp[v][y]);
		//砍！
		for (int x = 0;x < 2;x++)
			f[!flag][x] = max(f[!flag][x],f[flag][x]+dp[v][0]+1);
		flag = !flag;
	}
	dp[u][0] = f[flag][0];
	dp[u][1] = f[flag][1];
	//printf("u = %5d, dp = (%5d, %5d)\n",u,dp[u][0],dp[u][1]);
}

int main()
{
	scanf("%d",&n);
	L = 0;
	for (int i = 0;i < n;i++)
		head[i] = -1;
	
	for (int i = 0;i < n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;
		v--;
		addedge(u,v);
		addedge(v,u);
	}
	DP(0,-1);
	printf("%d\n",dp[0][0]);
	return 0;
}
