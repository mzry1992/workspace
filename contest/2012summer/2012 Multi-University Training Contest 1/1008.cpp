#include <cstdio>
#include <cstring>
const int MAXEDGE=1000*1000*2+1000*50;
const int MAXN=1002;
const long long inf =0x7fffffffffffffffLL;
struct edges
{
    long long flow;
    int to,next;
}edge[MAXEDGE+100];
struct nodes
{
    int head,label,pre,cur;
}node[MAXN+100];

int L,N;
int gap[MAXN+100];
void init(int n)
{
    L = 0;
    N = n;
    for (int i = 0;i < N;i++)
        node[i].head = -1;
}
void add_edge(int x,int y,long long z,long long w)
{
    edge[L].flow = z;
    edge[L].to = y;
    edge[L].next = node[x].head;
    node[x].head = L++;
    edge[L].flow = w;
    edge[L].to = x;
    edge[L].next = node[y].head;
    node[y].head = L++;
}
long long maxflow(int s,int t)
{
    memset(gap,0,sizeof(gap));
    gap[0] = N;
    int u;
    long long ans = 0;
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
            long long min = inf;
            for (int i = node[u].pre;i != -1;i = node[edge[i^1].to].pre)
                if (min > edge[i].flow)
                    min = edge[i].flow;
            for (int i = node[u].pre;i != -1;i = node[edge[i^1].to].pre)
            {
                edge[i].flow -= min;
                edge[i^1].flow += min;
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
            if (edge[i].flow && node[v].label+1 == node[u].label)
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
            if (edge[i].flow && node[edge[i].to].label < min)
                min = node[edge[i].to].label;
        gap[node[u].label]--;
        if (!gap[node[u].label])    return ans;
        node[u].label = min+1;
        gap[node[u].label]++;
        if (u != s) u = edge[node[u].pre^1].to;
    }
    return ans;
}

int c[MAXN],sum[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        memset(sum,0,4*n);
        init(n+2);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                int x;
                scanf("%d",&x);
                if (i!=j)
                {
                    add_edge(i,j,x,x);
                    sum[i]+=x;
                    sum[j]+=x;
                }
                else
                    c[i]=x;
            }
        for (int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            add_edge(n,i,inf/n,0);
            add_edge(i,n+1,inf/n-sum[i]+(x-c[i])*2,0);
        }
        printf("%I64d\n",inf/n*n-maxflow(n,n+1)>>1);
    }
    return 0;
}
