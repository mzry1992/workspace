#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
	int to,next;
};
Edge edge[100000];
int head[50000],L;
int n;

void addedge(int u,int v)
{
	edge[L].to = v;
	edge[L].next = head[u];
	head[u] = L++;
}

int ans;
int cnt[50000];
void DFS(int u,int fa)
{
	cnt[u] = 1;
	int tans = 0;
	for (int i = head[u];i != -1;i = edge[i].next)
	{
		int v = edge[i].to;
		if (v == fa)	continue;
		DFS(v,u);

		cnt[u] += cnt[v];
		tans = max(tans,cnt[v]);
	}
	if (fa != -1)
		tans = max(tans,n-cnt[u]);

	ans = max(ans,n-tans);
}

int main()
{
	while (scanf("%d",&n) != EOF)
	{
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
		ans = 0;
		DFS(0,-1);
		printf("%d\n",ans);
	}
	return 0;
}
