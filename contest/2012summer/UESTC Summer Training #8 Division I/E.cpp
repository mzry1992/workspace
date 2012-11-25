#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

const int maxn = 420;
int n,m;
bool graph[maxn][maxn];
int match[maxn];
bool inqueue[maxn],inpath[maxn],inblossom[maxn];int head,tail;
int queue[maxn];
int start,finish;
int newbase;
int father[maxn],base[maxn];
int count;

void push(int u)
{
    queue[tail++] = u;
    inqueue[u] = true;
}

int pop()
{
    return queue[head++];
}

int findcommonancestor(int u,int v)
{
    memset(inpath,false,sizeof(inpath));
    while (true)
    {
        u = base[u];
        inpath[u] = true;
        if (u == start) break;
        u = father[match[u]];
    }
    while (true)
    {
        v = base[v];
        if (inpath[v])  break;
        v = father[match[v]];
    }
    return v;
}

void resettrace(int u)
{
    int v;
    while (base[u] != newbase)
    {
        v = match[u];
        inblossom[base[u]] = inblossom[base[v]] = true;
        u = father[v];
        if (base[u] != newbase) father[u] = v;
    }
}

void blossomcontract(int u,int v)
{
    newbase = findcommonancestor(u,v);
    memset(inblossom,false,sizeof(inblossom));
    resettrace(u);
    resettrace(v);
    if (base[u] != newbase) father[u] = v;
    if (base[v] != newbase) father[v] = u;
    for (int tu = 1;tu <= n;tu++)
        if (inblossom[base[tu]])
        {
            base[tu] = newbase;
            if (!inqueue[tu])   push(tu);
        }
}

void findaugmentingpath()
{
    memset(inqueue,false,sizeof(inqueue));
    memset(father,0,sizeof(father));
    for (int i = 1;i <= n;i++)
        base[i] = i;
    head = tail = 1;
    push(start);
    finish = 0;
    while (head < tail)
    {
        int u = pop();
        for (int v = 1;v <= n;v++)
            if (graph[u][v] && base[u] != base[v] && match[u] != v)
            {
                if ((v == start) || ((match[v] > 0) && (father[match[v]] > 0)))
                    blossomcontract(u,v);
                else if (father[v] == 0)
                {
                    father[v] = u;
                    if (match[v] > 0)
                        push(match[v]);
                    else
                    {
                        finish = v;
                        return;
                    }
                }
            }
    }
}

void augmentpath()
{
    int u,v,w;
    u = finish;
    while (u > 0)
    {
        v = father[u];
        w = match[v];
        match[v] = u;
        match[u] = v;
        u = w;
    }
}

void edmonds()
{
    memset(match,0,sizeof(match));
    for (int u = 1;u <= n;u++)
        if (match[u] == 0)
        {
            start = u;
            findaugmentingpath();
            if (finish > 0) augmentpath();
        }
}

set<int> b;
int a[500];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        b.clear();
        for (int i = 0;i < m;i++)
        {
            int v;
            scanf("%d",&v);
            b.insert(v);
        }
        memset(graph,false,sizeof(graph));
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                if (b.find(a[i]+a[j]) != b.end())
                    graph[i+1][j+1] = graph[j+1][i+1] = true;
        edmonds();
        int res = 0;
        for (int i = 1;i <= n;i++)
            if (match[i] > 0)
                res++;
        printf("%d\n",res/2);
    }
	return 0;
}
