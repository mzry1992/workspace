#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1000;
const int MAXM = 40000;
int N,L;
int head[MAXN];
struct Edge
{
    int to,next;
    long long cost;
}edge[MAXM];
long long dist[MAXN];
int n,m,h[MAXN],ra[MAXN],q,qs[MAXM],qt[MAXM];
long long res[MAXM];
class states
{
    public:
        long long cost;
        int id;
};
class cmp
{
    public:
        bool operator ()(const states &i,const states &j)
        {
            return i.cost > j.cost;
        }
};
void init(int n)
{
    N = n;
    L = 0;
    for (int i = 0;i < n;i++)
        head[i] = -1;
}
void add_edge(int x,int y,long long cost)
{
    edge[L].to = y;
    edge[L].cost = cost;
    edge[L].next = head[x];
    head[x] = L++;
}
void dijkstra(int s)
{
    memset(dist,-1,sizeof(dist));
    states u;
    u.id = s;
    u.cost = 0;
    dist[s] = 0;
    priority_queue<states,vector<states>,cmp> q;
    q.push(u);
    while (!q.empty())
    {
        u = q.top();
        q.pop();
        if (u.cost != dist[u.id])   continue;
        for (int i = head[u.id];i != -1;i = edge[i].next)
        {
            states v = u;
            v.id = edge[i].to;
            if (h[v.id] > h[s]) continue;
            if (dist[v.id] == -1 || dist[v.id] > dist[u.id]+edge[i].cost)
            {
                v.cost = dist[v.id] = dist[u.id]+edge[i].cost;
                q.push(v);
            }
        }
    }
}

bool cmp(int a,int b)
{
    return h[a] < h[b];
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        init(n);
        for (int i = 0;i < n;i++)
            scanf("%d",&h[i]);
        for (int i = 0;i < m;i++)
        {
            int u,v;
            long long c;
            scanf("%d%d%I64d",&u,&v,&c);
            u--;
            v--;
            add_edge(u,v,c);
            add_edge(v,u,c);
        }
        for (int i = 0;i < n;i++)
            ra[i] = i;
        sort(ra,ra+n,cmp);
        scanf("%d",&q);
        for (int i = 0;i < q;i++)
        {
            scanf("%d%d",&qs[i],&qt[i]);
            qs[i]--;
            qt[i]--;
            res[i] = -1;
        }
        for (int i = 0;i < n;i++)
        {
            dijkstra(ra[i]);
            for (int j = 0;j < q;j++)
            {
                long long da = dist[qs[j]];
                long long db = dist[qt[j]];
                if (da == -1 || db == -1)   continue;
                long long tmp = dist[qs[j]]+dist[qt[j]]+h[ra[i]];
                if (res[j] == -1)   res[j] = tmp;
                else
                    res[j] = min(res[j],tmp);
            }
        }
        for (int i = 0;i < q;i++)
            printf("%I64d\n",res[i]);
        printf("\n");
    }
	return 0;
}
