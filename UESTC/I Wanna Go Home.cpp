#include <iostream>
#include <cstdio>
#define MAXN 700
#define MAXM 11000
#include <deque>
#include <cstring>
using namespace std;

int n,m;
struct graph
{
    int to,dist,next;
}g[MAXN+2*MAXM];
int zy[MAXN];
int totg;
int a[MAXN];
int b[MAXN];
deque<int> Q;
bool visit[MAXN];

void SPFA(int s)
{
    memset(visit,false,sizeof(visit));
    Q.clear();
    Q.push_back(s);
    visit[s] = true;
    for (int i = 1;i <= n;i++)
        b[i] = 19930703;
    b[s] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop_front();
        visit[now] = false;
        for (int i = g[now].next;i != 0;i = g[i].next)
        {
            int v = g[i].to;
            if (zy[v] != s) continue;
            if (b[v] > b[now]+g[i].dist)
            {
                b[v] = b[now]+g[i].dist;
                if (!visit[v])
                {
                    visit[v] = true;
                    Q.push_back(v);
                }
            }
        }
    }
}

void addEdge(int u,int v,int cost)
{
    totg++;
    g[totg].to = v;
    g[totg].dist = cost;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%d",&m);
        memset(g,0,sizeof(g));
        totg = n;
        for (int i = 1;i <= m;i++)
        {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            addEdge(u,v,cost);
            addEdge(v,u,cost);
        }
        for (int i = 1;i <= n;i++)
            scanf("%d",&zy[i]);
        SPFA(1);
        for (int i = 1;i <= n;i++)
            a[i] = b[i];
        SPFA(2);
        int ans = 19930703;
        for (int u = 1;u <= n;u++)
        if (zy[u] == 1)
        {
            for (int j = g[u].next;j != 0;j = g[j].next)
            {
                int v = g[j].to;
                if (zy[v] != 2) continue;
                if (ans > a[u]+b[v]+g[j].dist)
                    ans = a[u]+b[v]+g[j].dist;
            }
        }
        if (ans == 19930703)    ans = -1;
        printf("%d\n",ans);
    }
}
