#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int MAXM = 20010;
struct edges
{
    int to,next;
    bool cut,visit;
    int from;
} edge[MAXM];
int head[MAXN],low[MAXN],dfn[MAXN],L;
bool visit[MAXN],cut[MAXN];
int eu[MAXM],ev[MAXM];
int n,m;

int f[MAXN];
int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

void init(int n)
{
    L = 0;
    memset(head,-1,4*n);
}

void add_edge(int u,int v)
{
    edge[L].from = u;
    edge[L].cut = edge[L].visit = 0;
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int cnt[MAXN],totc;
int check(int ca)
{
    for (int i = 0; i < n; i++)
        cnt[i] = 0;
    totc = 0;
    for (int i = 0; i < n; i++)
        if (i != ca)
        {
            if (findf(i) == i)
                totc++;
            cnt[findf(i)]++;
        }
    return totc;
}

int ca;
int idx;
void dfs(int u,int fu)
{
    visit[u] = 1;
    low[u] = dfn[u] = idx++;
    int tot = 0;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == ca)    continue;
        if (edge[i].visit)
            continue;
        edge[i].visit = edge[i^1].visit = 1;
        if (visit[v])
        {
            low[u] = dfn[v]>low[u]?low[u]:dfn[v];
            continue;
        }
        dfs(v,u);
        edge[i].cut = edge[i^1].cut = low[v]>dfn[u] || edge[i].cut;
        if (u != fu)    cut[u] = low[v]>=dfn[u]?1:cut[u];
        low[u] = low[v]>low[u]?low[u]:low[v];
        tot++;
    }
    if (u == fu && tot > 1) cut[u] = 1;
}


int main()
{
    int cas = 1;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;

        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d",&eu[i],&ev[i]);
            eu[i]--;
            ev[i]--;
            add_edge(eu[i],ev[i]);
            add_edge(ev[i],eu[i]);
        }

        int res = 0;
        for (ca = 0; ca < n; ca++)
        {
            for (int i = 0; i < n;i++)
            {
                cut[i] = visit[i] = false;
                f[i] = i;
            }
            for (int i = 0;i < L;i++)
                edge[i].visit = false;
            for (int i = 0; i < m; i++)
                if (eu[i] != ca && ev[i] != ca)
                    f[findf(eu[i])] = findf(ev[i]);

            int ret = check(ca);
            if (ret == 1)
            {
                for (int i = 0; i < n; i++)
                    if (i != ca)
                    {
                        idx = 0;
                        dfs(i,i);
                        break;
                    }
                for (int i = 0; i < n; i++)
                    if (i != ca)
                        if (cut[i])
                        {
                            //printf("%d : %d\n",ca,i);
                            res++;
                        }
                //printf("%d\n",res);
            }
            else if (ret == 2)
            {
                for (int i = 0; i < n; i++)
                    if (cnt[i] > 1)
                        res += cnt[i];
            }
            else
                res += n-1;
        }
        printf("Case %d: %d\n",cas++,res/2);
    }
    return 0;
}



