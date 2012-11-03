#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Edge
{
    int to,next;
};
int head[1000],L,rhead[1000];
Edge edge[10000],redge[10000];
int n,m,u,v;

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L;

    redge[L].to = u;
    redge[L].next = rhead[v];
    rhead[v] = L++;
}

void init(int n)
{
    for (int i = 0;i < n;i++)
        rhead[i] = head[i] = -1;
    L = 0;
}

bool visit[1000];
int timnow,tim[1000],SCid[1000],SCidnow;

void DFS1(int now)
{
    visit[now] = true;
    for (int i = head[now];i != -1;i = edge[i].next)
        if (visit[edge[i].to] == false)
            DFS1(edge[i].to);
    tim[timnow++] = now;
}

void DFS2(int now)
{
    visit[now] = true;
    for (int i = rhead[now];i != -1;i = redge[i].next)
        if (visit[redge[i].to] == false)
            DFS2(redge[i].to);
    SCid[now] = SCidnow;
}

void Gao()
{
    for (int i = 0;i < n;i++)
        visit[i] = false;
    timnow = 0;
    for (int i = 0;i < n;i++)
        if (visit[i] == false)
            DFS1(i);
    for (int i = 0;i < n;i++)
        visit[i] = false;
    SCidnow = 0;
    for (int i = n-1;i >= 0;i--)
        if (visit[tim[i]] == false)
        {
            DFS2(tim[i]);
            SCidnow++;
        }
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%d",&m);
        init(n);
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            addedge(u,v);
        }
        Gao();
        int res = 0;
        for (int i = 0;i < n;i++)
            for (int j = head[i];j != -1;j = edge[j].next)
                if (SCid[i] == SCid[edge[j].to])
                    res++;
        printf("%d\n",res);
    }
    return 0;
}
