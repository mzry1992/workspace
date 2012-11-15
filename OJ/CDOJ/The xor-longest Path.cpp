#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 110000
using namespace std;

int n;
struct graph
{
    int to,next,cost;
}g[MAXN+2*MAXN];
int totg;
int dis[MAXN];
bool visit[MAXN];
struct tire
{
    int next[2];
    int key;
}t[40*MAXN];
int totn;

void addEdge(int u,int v,int c)
{
    g[totg].to = v;
    g[totg].cost = c;
    g[totg].next = g[u].next;
    g[u].next = totg;
    totg++;
}

void DFS(int now,int val)
{
    visit[now] = true;
    for (int i = g[now].next;i != -1;i = g[i].next)
    {
        if (!visit[g[i].to])
        {
            dis[g[i].to] = (val^g[i].cost);
            DFS(g[i].to,dis[g[i].to]);
        }
    }
}

void inittire()
{
    totn = 0;
    t[totn].next[0] = -1;
    t[totn].next[1] = -1;
}

void addkey(int key)
{
    int root = 0;
    for (int i = 32;i >= 1;i--)
    {
        int bit = (key>>(i-1))&1;
        if (t[root].next[bit] == -1)
        {
            totn++;
            t[totn].next[0] = t[totn].next[1] = -1;
            t[root].next[bit] = totn;
        }
        root = t[root].next[bit];
    }
    t[root].key = key;
}

int findmaxkey(int key)
{
    int root = 0;
    for (int i = 32;i >= 1;i--)
    {
        int bit = (key>>(i-1))&1;
        bit = (bit == 1)?0:1;
        if (t[root].next[bit] == -1)    bit = (bit == 1)?0:1;
        root = t[root].next[bit];
    }
    return t[root].key;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)   g[i].next = -1;
        totg = n;
        for (int i = 1;i <= n-1;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addEdge(u,v,c);
            addEdge(v,u,c);
        }
        memset(visit,false,sizeof(visit));
        DFS(0,0);
        inittire();
        for (int i = 0;i < n;i++)
            addkey(dis[i]);
        int ans = 0;
        for (int i = 0;i < n;i++)
        {
            int key = findmaxkey(dis[i]);
            if (ans < (key^dis[i]))
                ans = key^dis[i];
        }
        printf("%d\n",ans);
    }
}
