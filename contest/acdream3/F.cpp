#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
	int to,next,w;
}edge[200000];
int head[100000],L;
int n,Q;

void addedge(int u,int v,int w)
{
	edge[L].to = v;
	edge[L].w = w;
	edge[L].next = head[u];
	head[u] = L++;
}

int dp[100000][2];
int maxodd,maxeven;

void DP(int u,int fa)
{
	dp[u][0] = 0;
	dp[u][1] = -0x3f3f3f3f;
	int curmaxodd,curmaxeven,curodd,cureven;
	curmaxodd = curmaxeven = -0x3f3f3f3f;
	for (int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == fa)	continue;
		DP(v,u);
		
		if (edge[i].w == 1)
		{
			curodd = dp[v][0]+edge[i].w;
			cureven = dp[v][1]+edge[i].w;
		}
		else
		{
			curodd = dp[v][1]+edge[i].w;
			cureven = dp[v][0]+edge[i].w;
		}
		dp[u][0] = max(dp[u][0],cureven);
		dp[u][1] = max(dp[u][1],curodd);
//		printf("u = %d, v = %d, w = %d, curodd = %d, cureven = %d\n",u,v,edge[i].w,curodd,cureven);

		maxodd = max(maxodd,max(curodd+curmaxeven,cureven+curmaxodd));
		maxeven = max(maxeven,max(curodd+curmaxodd,cureven+curmaxeven));

		curmaxodd = max(curmaxodd,curodd);
		curmaxeven = max(curmaxeven,cureven);
	}
	maxeven = max(maxeven,dp[u][0]);
	maxodd = max(maxodd,dp[u][1]);
//	printf("dp %d = (%d, %d)\n",u,dp[u][0],dp[u][1]);
}

int main()
{
	scanf("%d%d",&n,&Q);
	for (int i = 0;i < n;i++)
		head[i] = -1;
	L = 0;
	for (int i = 0;i < n-1;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		u--;
		v--;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	maxodd = -1;
	maxeven = 0;
	DP(0,-1);
//	printf("odd = %d, even = %d\n",maxodd,maxeven);
	for (int i = 0;i < Q;i++)
	{
		int w;
		scanf("%d",&w);
		if (w < 0)
		{
			puts("No");
			continue;
		}
		bool res;
		if (w%2 == 0)
			res = (w <= maxeven);
		else
			res = (w <= maxodd);
		if (res == true)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
