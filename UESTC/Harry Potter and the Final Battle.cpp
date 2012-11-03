#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Edge
{
    int to,next,dis;
};

int head[1000],L,e[1000][1000];
Edge g[100000];
int n,m,u,v,w;

void addedge(int u,int v,int w)
{
    g[L].to = v;
    g[L].dis = w;
    g[L].next = head[u];
    head[u] = L++;
}

bool visit[1000];
int dis[1000];

queue<int> Q;

void SPFA(int s,int fob)
{
    Q.push(s);
    for (int i = 0;i < n;i++)
    {
        visit[i] = false;
        dis[i] = 19921005;
    }
    visit[s] = true;
    dis[s] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        visit[now] = false;
        for (int i = head[now];i != -1;i = g[i].next)
            if (i != fob && i != (fob^1))
            if (dis[g[i].to] > dis[now]+g[i].dis)
            {
                dis[g[i].to] = dis[now]+g[i].dis;
                if (visit[g[i].to] == false)
                {
                    visit[g[i].to] = true;
                    Q.push(g[i].to);
                }
            }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
            head[i] = -1;
        L = 0;
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            u--;
            v--;
            addedge(u,v,w);
            addedge(v,u,w);
        }
        for (int i = 0;i < n;i++)
        {
            SPFA(i,L+100);
            for (int j = 0;j < n;j++)
                e[i][j] = dis[j];
        }
        int res = 0;
        for (int i = 0;i < n;i++)
            for (int j = head[i];j != -1;j = g[j].next)
                if (e[0][n-1] == e[0][i]+g[j].dis+e[g[j].to][n-1])
                {
                    SPFA(0,j);
                    res = max(res,dis[n-1]);
                }
        if (res == 19921005)
            res = -1;
        printf("%d\n",res);
    }
    return 0;
}
