#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,cost;
string g;
vector<int> P;
char buf[5010];
bool inq[5010];
int dist[5010];

int SPFA(int spos,int epos)
{
	queue<int> Q;
	memset(inq,false,sizeof(inq));
	memset(dist,63,sizeof(dist));
	dist[spos] = 0;
	Q.push(spos);
	while (!Q.empty())
	{
		int now = Q.front();
		inq[now] = false;
		Q.pop();
		if (now == epos)	return dist[now];
		
		int x = now/m;
		int y = now%m;

		for (int k = 0;k < 4;k++)
		{
			int nxtx = x+step[k][0];
			int nxty = y+step[k][1];
			int nxt = nxtx*m+nxty;
			if (nxtx < 0 || nxtx >= n || nxty < 0 || nxty >= m || g[nxt] == '#')
				continue;

			int dis = 0;
			if (g[nxt] == '*')
				dis = 1;
			if (dist[nxt] > dist[now]+dis)
			{
				dist[nxt] = dist[now]+dis;
				if (inq[nxt] == false)
				{
					Q.push(nxt);
					inq[nxt] = true;
				}
			}
		}

		if (g[now] == 'P')
		{
			for (int k = 0;k < P.size();k++)
			{
				if (dist[P[k]] > dist[now])
				{
					dist[P[k]] = dist[now];
					if (inq[P[k]] == false)
					{
						Q.push(P[k]);
						inq[P[k]] = true;
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	while (scanf("%d%d%d",&n,&m,&cost) != EOF)
	{
		g = "";
		for (int i = 0;i < n;i++)
		{
			scanf("%s",buf);
			g += buf;
		}
		P.clear();
		int spos,epos;
		for (int i = 0;i < g.length();i++)
			if (g[i] == 'Y')
				spos = i;
			else if (g[i] == 'C')
				epos = i;
			else if (g[i] == 'P')
				P.push_back(i);
		int res = SPFA(spos,epos);
		if (res == -1)
			puts("Damn teoy!");
		else
			printf("%d\n",res*cost);
	}
	return 0;
}
