#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Edge
{
    int to,next,w,c;
};

Edge e[20000];
int head[1000],tote;
int dis[1000];
bool inq[1000];
queue<int> Q;
int n,m,u,v,w,c,s,t;

void addedge(int u,int v,int w,int c)
{
    e[tote].to = v;
    e[tote].w = w;
    e[tote].c = c;
    e[tote].next = head[u];
    head[u] = tote++;
}

void init0(int n)
{
    for (int i = 0;i < n;i++)
    {
        head[i] = dis[i] = -1;
        inq[i] = false;
    }
    tote = 0;
}

void SPFA(int s)
{
    dis[s] = 0;
    inq[s] = true;
    Q.push(s);
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        inq[now] = false;
        for (int i = head[now];i != -1;i = e[i].next)
            if (dis[e[i].to] == -1 ||
                dis[e[i].to] > dis[now]+e[i].w)
                {
                    dis[e[i].to] = dis[now]+e[i].w;
                    if (inq[e[i].to] == false)
                    {
                        inq[e[i].to] = true;
                        Q.push(e[i].to);
                    }
                }
    }
}

const int inf = 0x3fffffff;
struct edges
{
    int cap,to,next,flow;
}edge[40000];
struct nodes
{
    int head,label,pre,cur;
}node[1000];
int L,N;
int gap[1000];
void init(int n)
{
    L = 0;
    N = n;
    for (int i = 0;i < N;i++)
        node[i].head = -1;
}
void add_edge(int x,int y,int z,int w)
{
    edge[L].cap = z;
    edge[L].flow = 0;
    edge[L].to = y;
    edge[L].next = node[x].head;
    node[x].head = L++;
    edge[L].cap = w;
    edge[L].flow = 0;
    edge[L].to = x;
    edge[L].next = node[y].head;
    node[y].head = L++;
}
int maxflow(int s,int t)
{
    memset(gap,0,sizeof(gap));
    gap[0] = N;
    int u,ans = 0;
    for (int i = 0;i < N;i++)
    {
        node[i].cur = node[i].head;
        node[i].label = 0;
    }
    u = s;
    node[u].pre = -1;
    while (node[s].label < N)
    {
        if (u == t)
        {
            int min = inf;
            for (int i = node[u].pre;i != -1;i = node[edge[i^1].to].pre)
                if (min > edge[i].cap-edge[i].flow)
                    min = edge[i].cap-edge[i].flow;
            for (int i = node[u].pre;i != -1;i = node[edge[i^1].to].pre)
            {
                edge[i].flow += min;
                edge[i^1].flow -= min;
            }
            u = s;
            ans += min;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = node[u].cur;i != -1;i = edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].cap-edge[i].flow && node[v].label+1 == node[u].label)
            {
                flag = true;
                node[u].cur = node[v].pre = i;
                break;
            }
        }
        if (flag)
        {
            u = v;
            continue;
        }
        node[u].cur = node[u].head;
        int min = N;
        for (int i = node[u].head;i != -1;i = edge[i].next)
            if (edge[i].cap-edge[i].flow && node[edge[i].to].label < min)
                min = node[edge[i].to].label;
        gap[node[u].label]--;
        if (!gap[node[u].label])    return ans;
        node[u].label = min+1;
        gap[node[u].label]++;
        if (u != s)
            u = edge[node[u].pre^1].to;
    }
    return ans;
}
int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        scanf("%d%d",&s,&t);
        s--;
        t--;
        init0(n);
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&w,&c);
            u--;
            v--;
            addedge(u,v,w,c);
            addedge(v,u,w,c);
        }
        SPFA(s);
        init(n);
        for (int i = 0;i < n;i++)
            for (int j = head[i];j != -1;j = e[j].next)
                if (dis[i]+e[j].w == dis[e[j].to])
                    add_edge(i,e[j].to,e[j].c,0);
        int res = maxflow(s,t);
        printf("Case %d: %d\n",++ft,res);
    }
    return 0;
}
