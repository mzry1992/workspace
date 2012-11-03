#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
	int to,next;
}edge[2000*2000];
int head[2000],L,n;

int dfsnum[2000];
int low[2000];
int stack[2000];
int top,ans,an;
int be[2000];
int flag[2000];

void dfs(int x)
{
	dfsnum[x] = low[x] = ans++;
	stack[++top] = x;
	flag[x] = 1;
	for (int i = head[x];i != -1;i = edge[i].next)
	{
		int y = edge[i].to;
		if (dfsnum[y] == -1)
		{
			dfs(y);
			low[x] = min(low[x],low[y]);
		}
		else if (flag[y] == 1)
			low[x] = min(low[x],dfsnum[y]);
	}
	if (dfsnum[x] == low[x])
	{
		while (stack[top] != x)
		{
			flag[stack[top]] = 0;
			be[stack[top]] = an;
			top--;
		}
		flag[x] = 0;
		be[x] = an++;
		top--;
	}
}

void SC()
{
	memset(dfsnum,-1,sizeof(dfsnum));
	memset(flag,0,sizeof(flag));
	top = an = ans = 0;
	for (int i = 0;i < n;i++)
		if (dfsnum[i] == -1)
			dfs(i);
}

void init()
{
	L = 0;
	memset(head,-1,sizeof(head));
}

void addedge(int u,int v)
{
	edge[L].to = v;
	edge[L].next = head[u];
	head[u] = L++;
}

int m;

int main()
{
	while (true)
	{
		scanf("%d%d",&n,&m);
		init();
		for (int i = 0;i < m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
		}

		SC();
		for (int i = 0;i < n;i++)
			printf("%d ",be[i]);
		printf("\n");
	}
	return 0;
}
