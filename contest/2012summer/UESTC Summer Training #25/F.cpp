#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXEDGE = 400;
const int MAXN = 20;
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
            int mi = inf;
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre)
                mi = min(mi,edge[i].cap-edge[i].flow);
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre)
            {
                edge[i].flow += mi;
                edge[i^1].flow -= mi;
            }
            u = s;
            ans += mi;
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
        int mi = N;
        for (int i = node[u].head; i != -1; i = edge[i].next)
            if (edge[i].cap-edge[i].flow && node[edge[i].to].label < mi)
                mi = node[edge[i].to].label;
        gap[node[u].label]--;
        if (!gap[node[u].label])    return ans;
        node[u].label = mi+1;
        gap[node[u].label]++;
        if (u != s) u = edge[node[u].pre^1].to;
    }
    return ans;
}
char buf[1000];
bool g[10][10];
int a[10],n,ind[10],outd[10];

bool check(int sta)
{
    for (int i = 0; i < n; i++)
    {
        outd[i] = a[i];
        ind[i] = n-1-a[i];
    }
    memset(g,false,sizeof(g));
    for (int i = 0; i < n; i++)
        if (((sta>>i)&1) == 1)
        {
            for (int j = 0; j < n; j++)
                if (a[j] > a[i])
                {
                    ind[j]--;
                    outd[i]--;
                    if (outd[i] < 0) return false;
                    if (ind[j] < 0)    return false;
                    g[i][j] = g[j][i] = true;
                }
        }
    init(n+2);
    int totflow = 0;
    for (int i = 0; i < n; i++)
        if (ind[i] > outd[i])
            add_edge(i,n+1,ind[i]-outd[i],0);
        else
        {
            add_edge(n,i,outd[i]-ind[i],0);
            totflow += outd[i]-ind[i];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && g[i][j] == false)
                add_edge(i,j,1,0);
    //cout << maxflow(n,n+1) << ' ' << totflow << endl;
    return maxflow(n,n+1) == totflow;
}

int cntbit(int sta)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        if (((sta>>i)&1) == 1)
            res++;
    return res;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    gets(buf);
    while (totcas--)
    {
        gets(buf);
        int npos = 0,pos = 0,len = strlen(buf);
        n = 0;
        while (sscanf(buf+pos,"%d%n",&a[n++],&npos) != EOF)
            pos += npos;
        n--;
        /*for (int i = 0;i < n;i++)
            printf("%d ",a[i]);
        printf("\n");*/
        int res = 0;
        for (int sta = 1; sta < (1<<n); sta++)
            if (check(sta))
                res = max(res,cntbit(sta));
        printf("%d\n",res);
    }
    return 0;
}
