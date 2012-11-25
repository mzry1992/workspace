#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int MAXEDGE = 500000;
const int MAXN = 2500;
const int inf = 0x3fffffff;
struct edges
{
    int cap,to,next,flow;
} edge[MAXEDGE];
struct nodes
{
    int head,label,pre,cur;
} node[MAXN];
int L,N;
int gap[MAXN];
void init(int n)
{
    L = 0;
    N = n;
    for (int i = 0; i < N; i++)
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
    for (int i = 0; i < N; i++)
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
            int minf = inf;
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre)
                minf = min(minf,edge[i].cap-edge[i].flow);
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre)
            {
                edge[i].flow += minf;
                edge[i^1].flow -= minf;
            }
            u = s;
            ans += minf;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = node[u].cur; i != -1; i = edge[i].next)
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
        int minf = N;
        for (int i = node[u].head; i != -1; i = edge[i].next)
            if (edge[i].cap-edge[i].flow && node[edge[i].to].label < minf)
                minf = node[edge[i].to].label;
        gap[node[u].label]--;
        if (!gap[node[u].label])    return ans;
        node[u].label = minf+1;
        gap[node[u].label]++;
        if (u != s) u = edge[node[u].pre^1].to;
    }
    return ans;
}

int n,k;
vector<int> res[100];

int main()
{
    init(2102);
    scanf("%d%d",&n,&k);
    for (int i = 0; i < 2000; i++)
        add_edge(2100,i,k,0);
    for (int i = 0; i < n; i++)
    {
        add_edge(2000+i,2101,2,0);
        int s,t;
        scanf("%d%d",&s,&t);
        for (int j = s; j < s+t; j++)
            add_edge(j,2000+i,1,0);
    }
    if (maxflow(2100,2101) == 2*n)
    {
        puts("Yes");
        for (int i = 0;i < 2000;i++)
            for (int j = node[i].head;j != -1;j = edge[j].next)
                if (edge[j].flow == 1)
                    res[edge[j].to-2000].push_back(i);
        for (int i = 0;i < n;i++)
            printf("%d %d\n",res[i][0],res[i][1]);
    }
    else
        puts("No");
    return 0;
}
