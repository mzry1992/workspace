#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#define MAXN 30000
#define MAXM 60000
using namespace std;

int n,m;
struct graph
{
    int to,next;
}g[MAXN+MAXM];
int totg;
int bel[MAXN];
int state[MAXN];
int low[MAXN];
int id[MAXN];
stack<int> s;
int t,cnt;
int in[MAXN],out[MAXN];

void addEdge(int u,int v)
{
    totg++;
    g[totg].to = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

void dfs(int u,int t,int &clr)
{
    low[u] = id[u] = t++;
    state[u] = 1;
    s.push(u);
    for (int i = g[u].next;i != 0;i = g[i].next)
    {
        if (state[g[i].to] == 0)
        {
            dfs(g[i].to,t,clr);
            low[u] = min(low[g[i].to],low[u]);
        }
        else if (state[g[i].to] == 1)
            low[u] = min(low[g[i].to],low[u]);
    }
    if (low[u] == id[u])
    {
        int v;
        clr++;
        do
        {
            v = s.top();
            s.pop();
            state[v] = 2;
            bel[v] = clr;
        }while (v != u);
    }
}

void tarjan()
{
    memset(state,0,sizeof(state));
    memset(low,0,sizeof(low));
    memset(id,0,sizeof(id));
    memset(bel,0,sizeof(bel));
    t = 0;
    cnt = 0;
    for (int i = 1;i <= n;i++)
        if (!state[i]) dfs(i,t,cnt);
}

int main()
{
    int _t;
    scanf("%d",&_t);
    for (int ft = 1;ft <= _t;ft++)
    {
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        totg = n;
        for (int i = 1;i <= m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
        tarjan();
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for (int i = 1;i <= n;i++)
        for (int j = g[i].next;j != 0;j = g[j].next)
        if (bel[i] != bel[g[j].to])
        {
            in[bel[g[j].to]]++;
            out[bel[i]]++;
        }
        int ru,chu;
        ru = chu = 0;
        for (int i = 1;i <= cnt;i++)
        {
            if (in[i] == 0) ru++;
            if (out[i] == 0) chu++;
        }
        if (cnt == 1)
            puts("0");
        else
            printf("%d\n",ru>chu?ru:chu);
    }
}
