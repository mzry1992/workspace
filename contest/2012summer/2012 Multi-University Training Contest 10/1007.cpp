#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MaxN = 5000;
const int MaxM = 200000;

struct Edge
{
    int to,next,cost;
}edge[MaxM];
int head[MaxN],L;

int n,m;

void init()
{
    L = 0;
    for (int i = 0;i < n;i++)
        head[i] = -1;
}

void addedge(int u,int v,int cost)
{
    edge[L].cost = cost;
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int dist[MaxN][60];
bool inq[MaxN][60];

int SPFA(int s,int t,int k)
{
    queue<pair<int,int> > Q;
    memset(dist,-1,sizeof(dist));
    memset(inq,false,sizeof(inq));

    Q.push(make_pair(s,0));
    dist[s][0] = 0;
    while (!Q.empty())
    {
        pair<int,int> now = Q.front();
        Q.pop();
        inq[now.first][now.second] = false;

        for (int i = head[now.first];i != -1;i = edge[i].next)
        {
            pair<int,int> nxt = make_pair(edge[i].to,now.second+1);
            if (nxt.second > k)
                nxt.second = k+1;
            if (dist[nxt.first][nxt.second] == -1 ||
                dist[nxt.first][nxt.second] > dist[now.first][now.second]+edge[i].cost)
                {
                    dist[nxt.first][nxt.second] = dist[now.first][now.second]+edge[i].cost;
                    if (inq[nxt.first][nxt.second] == false)
                    {
                        inq[nxt.first][nxt.second] = true;
                        Q.push(nxt);
                    }
                }
        }
    }
    if (dist[t][k] == -1 || dist[t][k+1] < dist[t][k])
        dist[t][k] = dist[t][k+1];
    return dist[t][k];
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        init();
        for (int i = 0;i < m;i++)
        {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            u--;
            v--;
            addedge(u,v,cost);
            addedge(v,u,cost);
        }
        int s,t,k;
        scanf("%d%d%d",&s,&t,&k);
        s--;
        t--;
        k = (k+9)/10;
        printf("%d\n",SPFA(s,t,k));
    }
	return 0;
}
