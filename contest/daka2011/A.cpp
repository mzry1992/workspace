#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXM=6600;
const int MAXN=1100;
const int inf=0x3fffffff;
int L,N;
int K;
struct edges
{
    int to,next,cap,flow,cost;
} edge[MAXM];
struct nodes
{
    int dis,pre,head;
    bool visit;
} node[MAXN];
void init(int n)
{
    N=n;
    L=0;
    for (int i=0; i<N; i++)
        node[i].head=-1;
}
void add_edge(int x,int y,int cap,int cost)
{
    edge[L].to=y;
    edge[L].cap=cap;
    edge[L].cost=cost;
    edge[L].flow=0;
    edge[L].next=node[x].head;
    node[x].head=L++;
    edge[L].to=x;
    edge[L].cap=0;
    edge[L].cost=-cost;
    edge[L].flow=0;
    edge[L].next=node[y].head;
    node[y].head=L++;
}
bool spfa(int s,int t)
{
    queue <int> q;
    for (int i=0; i<N; i++)
    {
        node[i].dis=0x3fffffff;
        node[i].pre=-1;
        node[i].visit=0;
    }
    node[s].dis=0;
    node[s].visit=1;
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();
        node[u].visit=0;
        for (int i=node[u].head; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if (edge[i].cap>edge[i].flow &&
                    node[v].dis>node[u].dis+edge[i].cost)
            {
                node[v].dis=node[u].dis+edge[i].cost;
                node[v].pre=i;
                if (!node[v].visit)
                {
                    node[v].visit=1;
                    q.push(v);
                }
            }
        }
        q.pop();
    }
    if (node[t].pre==-1)
        return 0;
    else
        return 1;
}
int mcmf(int s,int t)
{
    int flow=0,cost=0;
    while (spfa(s,t))
    {
        int max=inf;
        for (int i=node[t].pre; i!=-1; i=node[edge[i^1].to].pre)
        {
            if (max>edge[i].cap-edge[i].flow)
                max=edge[i].cap-edge[i].flow;
        }
        for (int i=node[t].pre; i!=-1; i=node[edge[i^1].to].pre)
        {
            edge[i].flow+=max;
            edge[i^1].flow-=max;
            cost+=edge[i].cost*max;
        }
        flow+=max;
    }
    return cost;
}

int n,m,v[1100];
char mp[1100][1100];

int calc(int n,int avg)
{
    init(n+2);
    for (int i=0; i<n; i++)
    {
        if (v[i]>avg)
            add_edge(n,i,v[i]-avg,0);
        if (v[i]<avg)
            add_edge(i,n+1,avg-v[i],0);
        add_edge(i,(i+1)%n,inf,1);
        add_edge((i+1)%n,i,inf,1);
    }
    return mcmf(n,n+1);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++)
            scanf("%s",mp[i]);
        int tot = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mp[i][j] == '1')
                    tot++;

        int resrow = 0;
        if (tot%n == 0)
        {
            for (int i = 0; i < n; i++)
            {
                v[i] = 0;
                for (int j = 0; j < m; j++)
                    if (mp[i][j] == '1')
                        v[i]++;
            }
            resrow = calc(n,tot/n);
        }
        int rescol = 0;
        if (tot%m == 0)
        {
            for (int i = 0; i < m; i++)
            {
                v[i] = 0;
                for (int j = 0; j < n; j++)
                    if (mp[j][i] == '1')
                        v[i]++;
            }
            rescol = calc(m,tot/m);
        }

        if (tot%n == 0 && tot%m == 0)
        {
            //both
            printf("Case %d: both %d\n",ft,resrow+rescol);
        }
        else if (tot%n == 0)
        {
            //row
            printf("Case %d: row %d\n",ft,resrow);
        }
        else if (tot%m == 0)
        {
            //col
            printf("Case %d: column %d\n",ft,rescol);
        }
        else
            printf("Case %d: impossible\n",ft);
    }
    return 0;
}


