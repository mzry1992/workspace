#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

#define MAXN 330
#define INF 100000000

int n;
int dis[MAXN];
int g[MAXN][MAXN];

bool vis[MAXN];

priority_queue < pair<int,int> > pq;

int dijkstra()
{
	int i,S=0,T=n-1;
	vis[0]=dis[0]=0;
	pq.push(make_pair(0,S));
	for(i=1;i<n;i++) dis[i]=INF,vis[i]=false;
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(i=0;i<n;i++)
		{
			if(dis[i]>dis[u]+g[u][i])
			{
				dis[i]=dis[u]+g[u][i];
				pq.push(make_pair(-dis[i],i));
			}
		}	
	}
	return dis[T];
}

int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
	while(~scanf("%d",&n))
	{
		int i,j;
		for(i=0;i<n;i++)
		for(j=0;j<n;j++) scanf("%d",&g[i][j]);
		printf("%d\n",dijkstra());
	}
	return 0;
}
