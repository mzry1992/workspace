#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,totg,s,t;
struct edge
{
    int to,next,dis;
}g[1001+10001*2+100];
int dis[1001],cos[1001],mindis[1001];

void addedge(int u,int v,int w)
{
    totg++;
    g[totg].to = v;
    g[totg].dis = w;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

struct node
{
    int now,cango,cost;
    node(){}
    node(int _now,int _cango,int _cost)
        {
            now = _now;
            cost = _cost;
            cango = _cango;
        }
};

struct cmp
{
    bool operator() (const node& a,const node& b)
    {
        return a.cost > b.cost;
    }
};

priority_queue< node, vector<node>, cmp > Q;

long long BFS()
{
    if (s == t) return 0;
    while (!Q.empty())  Q.pop();
    Q.push(node(s,dis[s],cos[s]));
    node now;
    for (int i = 1;i <= n;i++)
        mindis[i] = -1;
    mindis[s] = 0;
    while (!Q.empty())
    {
        now = Q.top();
        Q.pop();
        if (now.now == t)   return now.cost;
        for (int i = g[now.now].next;i != -1;i = g[i].next)
            if (g[i].dis <= now.cango)
            {
                Q.push(node(g[i].to,now.cango-g[i].dis,now.cost));
                if (mindis[g[i].to] == -1 || mindis[g[i].to] > now.cost)
                {
                    mindis[g[i].to] = now.cost;
                    Q.push(node(g[i].to,dis[g[i].to],now.cost+cos[g[i].to]));
                }
            }
    }
    return -1;
}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);
    for (int i = 1;i <= n;i++)
        g[i].next = -1;
    totg = n;
    for (int i = 1;i <= m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    for (int i = 1;i <= n;i++)
        scanf("%d%d",&dis[i],&cos[i]);
    cout << BFS() << endl;
}
