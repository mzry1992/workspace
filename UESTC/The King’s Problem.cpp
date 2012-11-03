#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct edge
{
    int to,next;
}g[100001],rg[100001];
int head[5001],rhead[5001],totg;
int n,m,u,v;
int id[5001],tim[5001],nowtim,totSC;
bool visit[5001];

void addedge(int u,int v)
{
    g[totg].to = v;
    g[totg].next = head[u];
    head[u] = totg;
    rg[totg].to = u;
    rg[totg].next = rhead[v];
    rhead[v] = totg++;
}

void addedge2(int u,int v)
{
    g[totg].to = v;
    g[totg].next = head[u];
    head[u] = totg++;
}

void DFS1(int now)
{
    visit[now] = true;
    for (int i = head[now];i != -1;i = g[i].next)
        if (visit[g[i].to] == false)
            DFS1(g[i].to);
    tim[++nowtim] = now;
}

void DFS2(int now)
{
    visit[now] = true;
    id[now] = totSC;
    for (int i = rhead[now];i != -1;i = rg[i].next)
        if (visit[rg[i].to] == false)
            DFS2(rg[i].to);
}

void GaoSC()
{
    memset(visit,false,sizeof(visit));
    nowtim = 0;
    for (int i = 1;i <= n;i++)
        if (visit[i] == false)
            DFS1(i);
    memset(visit,false,sizeof(visit));
    totSC = 0;
    for (int i = nowtim;i >= 1;i--)
        if (visit[tim[i]] == false)
        {
            totSC++;
            DFS2(tim[i]);
        }
    for (int i = 1;i <= totSC;i++)
        head[i] = -1;
    totg = 0;
    for (int i = 1;i <= n;i++)
        for (int j = rhead[i];j != -1;j = rg[j].next)
            if (id[i] != id[rg[j].to])
                addedge2(id[rg[j].to],id[i]);
    n = totSC;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            head[i] = rhead[i] = -1;
        totg = 0;
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        GaoSC();
    }
}
