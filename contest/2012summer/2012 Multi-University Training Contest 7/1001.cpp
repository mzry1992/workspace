#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 1500;
const int MAXM = 30000;

struct Edge
{
    int to,next,cost,type;
}edge[MAXM];
int head[MAXN],L;
int n,m;

void init(int n)
{
    for (int i = 0;i < n;i++)
        head[i] = -1;
    L = 0;
}

void addedge(int u,int v,int cost,char typ)
{
    if (typ == 'L')
        edge[L].type = 0;
    else if (typ == 'O')
        edge[L].type = 1;
    else if (typ == 'V')
        edge[L].type = 2;
    else
        edge[L].type = 3;
    edge[L].cost = cost;
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

const long long inf = 0x3f3f3f3f3f3f3f3fLL;
pair<long long,int> dist[MAXN][4];
bool inq[MAXN][4];

pair<long long,int> SPFA()
{
    queue<pair<int,int> > Q;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < 4;j++)
            dist[i][j] = make_pair(inf,0);
    memset(inq,false,sizeof(inq));
    for (int i = head[0];i != -1;i = edge[i].next)
        if (edge[i].type == 0)
        {
            if (dist[edge[i].to][edge[i].type].first > edge[i].cost)
            {
                dist[edge[i].to][edge[i].type] = make_pair(edge[i].cost,1);
                if (inq[edge[i].to][edge[i].type] == false)
                {
                    Q.push(make_pair(edge[i].to,edge[i].type));
                    inq[edge[i].to][edge[i].type] = true;
                }
            }
        }
    while (!Q.empty())
    {
        pair<int,int> now = Q.front();
        Q.pop();
        inq[now.first][now.second] = false;
        for (int i = head[now.first];i != -1;i = edge[i].next)
            if (edge[i].type == (now.second+1)%4)
            {
                pair<long long,int> nxt = make_pair(dist[now.first][now.second].first+edge[i].cost,dist[now.first][now.second].second+1);
                if (dist[edge[i].to][edge[i].type].first > nxt.first ||
                    (dist[edge[i].to][edge[i].type].first == nxt.first &&
                     dist[edge[i].to][edge[i].type].second < nxt.second))
                    {
                        dist[edge[i].to][edge[i].type] = nxt;
                        if (inq[edge[i].to][edge[i].type] == false)
                        {
                            Q.push(make_pair(edge[i].to,edge[i].type));
                            inq[edge[i].to][edge[i].type] = true;
                        }
                    }
            }
    }
    return dist[n-1][3];
}

int dis[4];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d%d",&n,&m);
	    init(n);
	    for (int i = 0;i < m;i++)
	    {
	        int u,v,cost;
	        char typ;
	        scanf("%d%d%d %c",&u,&v,&cost,&typ);
	        u--;v--;
	        addedge(u,v,cost,typ);
	        addedge(v,u,cost,typ);
	    }
	    pair<long long,int> res = SPFA();
	    printf("Case %d: ",cas);
	    if (res.first == inf)
            puts("Binbin you disappoint Sangsang again, damn it!");
        else
            printf("Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",res.first,res.second/4);
	}
	return 0;
}
