#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

struct Edge
{
    int to,c,next;
};

Edge edge[400000],nedge[400000];
queue<int> Q;
int dis[100000],head[100000],nhead[100000],nL,L,n,m,u,v,c;

void init(int n)
{
    nL = L = 0;
    for (int i = 0;i < n;i++)
    {
        head[i] = nhead[i] = -1;
        dis[i] = 19921005;
    }
}

void addedge0(int u,int v,int c)
{
    nedge[nL].to = v;
    nedge[nL].c = c;
    nedge[nL].next = nhead[u];
    nhead[u] = nL++;
}

void addedge(int u,int v,int c)
{
    edge[L].to = v;
    edge[L].c = c;
    edge[L].next = head[u];
    head[u] = L++;
}

int pre[100000];

void Gao()
{
    while (!Q.empty())  Q.pop();
    dis[0] = 0;
    Q.push(0);
    int now;
    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();
        for (int i = nhead[now];i != -1;i = nedge[i].next)
            if (dis[nedge[i].to] > dis[now]+1)
            {
                dis[nedge[i].to] = dis[now]+1;
                Q.push(nedge[i].to);
            }
    }
    printf("%d\n",dis[n-1]);
    for (int i = 0;i < n;i++)
        for (int j = nhead[i];j != -1;j = nedge[j].next)
            if (dis[nedge[j].to] == dis[i]+1)
                addedge(i,nedge[j].to,nedge[j].c);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        init(n);
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            u--;
            v--;
            addedge0(u,v,c);
            addedge0(v,u,c);
        }
        Gao();
    }
    return 0;
}
