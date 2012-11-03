#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge
{
    int to,next,cost;
};

Edge edge[10000];
int head[100],L,dis[100],inq[100];
int n,m,k,xs,xe,x,y,mon;

void addedge(int u,int v,int c)
{
    edge[L].to = v;
    edge[L].cost = c;
    edge[L].next = head[u];
    head[u] = L++;
}

void SPFA()
{
    queue<int> Q;
    Q.push(xe);
    inq[xe] = true;
    dis[xe] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        inq[now] = false;
        for (int i = head[now]; i != -1; i = edge[i].next)
            if (dis[edge[i].to] == -1 || dis[edge[i].to] > dis[now]+edge[i].cost)
            {
                dis[edge[i].to] = dis[now]+edge[i].cost;
                if (inq[edge[i].to] == false)
                {
                    Q.push(edge[i].to);
                    inq[edge[i].to] = true;
                }
            }
    }
}

int cutoff,cutoffmin;
bool visit[100],findres;
int kth,road[100];

int f(int now,int g)
{
    return g+dis[now];
}

void IDAStar(int now,int g,int totroad)
{
    if (now == xe)
    {
        if (g == cutoff)
        {
            kth++;
            if (findres == true)    return;
            if (kth == k)
            {
                findres = true;
                printf("%d %d\n",g,totroad);
                for (int i = 0; i < totroad; i++)
                    printf("%d ",road[i]+1);
                printf("\n");
            }
        }
    }
    else
    {
        for (int i = head[now]; i != -1; i = edge[i].next)
            if (visit[edge[i].to] == false)
            {
                int tg = f(edge[i].to,g+edge[i].cost);
                if (tg <= cutoff)
                {
                    visit[edge[i].to] = true;
                    road[totroad] = edge[i].to;
                    IDAStar(edge[i].to,g+edge[i].cost,totroad+1);
                    visit[edge[i].to] = false;
                }
                else if (cutoffmin == -1 || cutoffmin > tg)
                    cutoffmin = tg;
            }
    }
}

void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        head[i] = dis[i] = -1;
        inq[i] = visit[i] = false;
    }
    L = 0;
}

int main()
{
    while (scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&x,&y,&mon);
            x--;
            y--;
            addedge(x,y,mon);
            addedge(y,x,mon);
        }
        scanf("%d%d",&xs,&xe);
        xs--;
        xe--;
        SPFA();
        kth = 0;
        findres = false;
        cutoff = f(xs,0);
        cutoffmin = -1;
        visit[xs] = true;
        road[0] = xs;
        while (findres == false)
        {
            IDAStar(xs,0,1);
            cutoff = cutoffmin;
            cutoffmin = -1;
        }
    }
    return 0;
}
