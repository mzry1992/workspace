#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxK = 3001;
const int MaxE = 25000000;

int n,m,tax[5001];

struct graph
{
    int to,next,com,cost;
}road[MaxK],rroad[MaxK];

struct graph2
{
    int to,next;
}g[MaxE],rg[MaxE];

int head[1001],L,rhead[1001],totg,h[5001],rh[5001];
int u,v,com,cost;

void addedge(int u,int v,int com,int cost)
{
    road[L].to = v;
    road[L].com = com;
    road[L].cost = cost;
    road[L].next = head[u];
    head[u] = L++;
    rroad[L].to = u;
    rroad[L].com = com;
    rroad[L].cost = cost;
    rroad[L].next = rhead[v];
    rhead[v] = L++;
}

void addedge2(int u,int v)
{
    g[L].to = v;
    g[L].next = h[u];
    h[u] = L;
    rg[L].to = u;
    rg[L].next = rh[v];
    rh[v] = L++;
}

bool visit[5001];
int tim[5001],nowtim,totsc,sc[5001];

void DFS1(int now)
{
    visit[now] = true;
    for (int i = h[now];i != -1;i = g[i].next)
        if (visit[g[i].to] == false)
            DFS1(g[i].to);
    tim[++nowtim] = now;
}

void DFS2(int now)
{
    visit[now] = true;
    sc[now] = totsc;
    for (int i = rh[now];i != -1;i = rg[i].next)
        if (visit[rg[i].to] == false)
            DFS2(rg[i].to);
}

void SC()
{
    memset(visit,false,sizeof(visit));
    nowtim = 0;
    for (int i = 1;i <= m;i++)
        if (visit[i] == false)
            DFS1(i);
    memset(visit,false,sizeof(visit));
    totsc = 0;
    for (int i = m;i >= 1;i--)
        if (visit[tim[i]] == false)
        {
            totsc++;
            DFS2(tim[i]);
        }
}

int K;

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 1;i <= m;i++)
            scanf("%d",&tax[i]);
        for (int i = 1;i <= n;i++)
            head[i] = rhead[i] = -1;
        L = 0;
        scanf("%d",&K);
        for (int i = 1;i <= K;i++)
        {
            scanf("%d%d%d%d",&u,&v,&com,&cost);
            addedge(u,v,com,cost);
            tax[com] -= cost;
        }
        L = 0;
        for (int i = 1;i <= m;i++)
            h[i] = rh[i] = -1;
        for (int i = 1;i <= n;i++)
            for (int j = head[i];j != -1;j = road[j].next)
                for (int k = rhead[i];k != -1;k = rroad[k].next)
                    if (road[j].com != rroad[k].com)
                        addedge2(rroad[k].com,road[j].com);
        SC();
    }
    return 0;
}
