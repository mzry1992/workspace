#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXM = 103*103*4;
const int MAXN = 203;
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
int L,N;
int K;
struct edges
{
    int to,next;
    long long cap,flow,cost;
}edge[MAXM*2];
struct nodes
{
    long long dis;
    int pre,head;
    bool visit;
}node[MAXN];
void init(int n)
{
    N = n;
    L = 0;
    for (int i = 0;i < N;i++)
        node[i].head = -1;
}
void add_edge(int x,int y,long long cap,long long cost)
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
        node[i].dis = inf;
        node[i].pre = -1;
        node[i].visit= 0;
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
        long long flow = inf;
        for (int i = node[t].pre;i != -1;i = node[edge[i^1].to].pre)
            flow = min(flow,edge[i].cap-edge[i].flow);
        for (int i = node[t].pre;i != -1;i = node[edge[i^1].to].pre)
        {
            edge[i].flow += flow;
            edge[i^1].flow -= flow;
            cost += edge[i].cost*flow;
        }
    }
    return cost;
}
long long mp[101][101];
int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        int m,k;
        scanf("%d%d",&m,&k);
        init(n*2+3);
        memset(mp,63,sizeof(mp));
        for (int i=0;i<=n;i++)
            mp[i][i]=0;
        for (int i=0;i<m;i++)
        {
            int u,v,len;
            scanf("%d%d%d",&u,&v,&len);
            mp[u][v]=mp[v][u]=min(mp[u][v],(long long)len);
        }
        for (int k=0;k<=n;k++)
            for (int i=0;i<=n;i++)
                for (int j=0;j<=n;j++)
                    mp[i][j]=min(mp[i][k]+mp[k][j],mp[i][j]);
        for (int i=0;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                add_edge(i*2+1,j*2,inf,mp[i][j]);
        for (int i=1;i<=n;i++)
        {
            add_edge(i*2,i*2+1,1,-(inf/100));
            add_edge(i*2,i*2+1,inf,0);
        }
        add_edge(0,1,k,0);
        for (int i=0;i<=n;i++)
            add_edge(i*2+1,n*2+2,inf,mp[i][0]);
        printf("%I64d\n",mcmf(0,n*2+2)+inf/100*n);
    }
	return 0;
}
