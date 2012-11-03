#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAXN = 1000;
const int MAXM = 1000000;
const int inf = 0x7fffffff;

struct Edge
{
    int u,v,next,cost;
};

Edge e[MAXM],edge[MAXM];
int n,m,u,v,cost,L;
int pre[MAXN],id[MAXN],visit[MAXN],in[MAXN],head[MAXN];

int zhuliu(int root,int n,int m,Edge e[])
{
    int res = 0;
    int u,v;
    while (true)
    {
        for (int i = 0; i < n; i++)
            in[i] = inf;
        for (int i = 0; i < m; i++)
            if (e[i].u != e[i].v && e[i].cost < in[e[i].v])
            {
                pre[e[i].v] = e[i].u;
                in[e[i].v] = e[i].cost;
            }
        for (int i = 0; i < n; i++)
            if (i != root)
                if (in[i] == inf)
                    return -1;
        int tn = 0;
        memset(id,-1,sizeof(id));
        memset(visit,-1,sizeof(visit));
        in[root] = 0;
        for (int i = 0; i < n; i++)
        {
            res += in[i];
            v = i;
            while (visit[v] != i && id[v] == -1 && v != root)
            {
                visit[v] = i;
                v = pre[v];
            }
            if (v != root && id[v] == -1)
            {
                for (int u = pre[v]; u != v; u = pre[u])
                    id[u] = tn;
                id[v] = tn++;
            }
        }
        if (tn == 0)    break;
        for (int i = 0; i < n; i++)
            if (id[i] == -1)
                id[i] = tn++;
        for (int i = 0; i < m;)
        {
            int v = e[i].v;
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
            if (e[i].u != e[i].v)
                e[i++].cost -= in[v];
            else
                swap(e[i],e[--m]);
        }
        n = tn;
        root = id[root];
    }
    return res;
}

void addedge(int u,int v,int cost)
{
    edge[L].u = u;
    edge[L].v = v;
    edge[L].cost = cost;
    edge[L].next = head[u];
    head[u] = L++;
}

int dis[MAXN];
bool inq[MAXN];

void init(int n)
{
    for (int i = 0;i < n;i++)
    {
        head[i] = -1;
        inq[i] = false;
        dis[i] = inf;
    }
    L = 0;
}

void spfa()
{
    queue<int> Q;
    dis[0] = 0;
    Q.push(0);
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        inq[now] = false;
        for (int i = head[now];i != -1;i = edge[i].next)
            if (dis[edge[i].v] > dis[now]+edge[i].cost)
            {
                dis[edge[i].v] = dis[now]+edge[i].cost;
                if (inq[edge[i].v] == false)
                {
                    inq[edge[i].v] = true;
                    Q.push(edge[i].v);
                }
            }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            u--;
            v--;
            addedge(u,v,cost);
        }
        spfa();
        int tl = L;
        L = 0;
        for (int i = 0;i < tl;i++)
            if (dis[edge[i].v] == dis[edge[i].u]+edge[i].cost)
                e[L++] = edge[i];
        printf("Case #%d: %d\n",ft,zhuliu(0,n,L,e));
    }
    return 0;
}

