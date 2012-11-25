#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXM = 200000;
const int MAXN = 301;
const int inf = 0x3fffffff;
int L,N,K;
struct edges
{
    int to,next,cap,flow,cost;
}edge[MAXM];
struct nodes
{
    int pre,head;
    long long dis;
    bool visit;
}node[MAXN];
void init(int n)
{
    N = n;
    L = 0;
    for (int i = 0;i < N;i++)
        node[i].head = -1;
}
void add_edge(int x,int y,int cap,int cost)
{
    edge[L].to = y;
    edge[L].cap = cap;
    edge[L].cost = cost;
    edge[L].flow = 0;
    edge[L].next = node[x].head;
    node[x].head = L++;
    edge[L].to = x;
    edge[L].cap = 0;
    edge[L].cost = -cost;
    edge[L].flow = 0;
    edge[L].next = node[y].head;
    node[y].head = L++;
}
bool spfa(int s,int t)
{
    queue<int> q;
    for (int i = 0;i < N;i++)
    {
        node[i].dis = 0x3fffffffffffffffLL;
        node[i].pre = -1;
        node[i].visit = 0;
    }
    node[s].dis = 0;
    node[s].visit = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        node[u].visit = 0;
        for (int i = node[u].head;i != -1;i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow && node[v].dis > node[u].dis+edge[i].cost)
            {
                node[v].dis = node[u].dis+edge[i].cost;
                node[v].pre = i;
                if (!node[v].visit)
                {
                    node[v].visit = 1;
                    q.push(v);
                }
            }
        }
        q.pop();
    }
    if (node[t].pre == -1)
        return 0;
    else
        return 1;
}
long long mcmf(int s,int t)
{
    long long cost = 0;
    while (spfa(s,t))
    {
        int mx = inf;
        for (int i = node[t].pre;i != -1;i = node[edge[i^1].to].pre)
            mx = min(mx,edge[i].cap-edge[i].flow);
        for (int i = node[t].pre;i != -1;i = node[edge[i^1].to].pre)
        {
            edge[i].flow += mx;
            edge[i^1].flow -= mx;
            cost += edge[i].cost*mx;
        }
    }
    return cost;
}

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        init(n+1);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                int x;
                scanf("%d",&x);
                if (i!=j && j!=0 && i!=n-1)
                    add_edge(i,j,1,x);
            }
        add_edge(n,0,1,0);
        printf("%I64d\n",mcmf(n,n-1));
    }
	return 0;
}
