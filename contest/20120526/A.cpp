#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <deque>
using namespace std;

const int MAXM = 200000;
const int MAXN = 2000;
const int inf = 0x3fffffff;
int L,N;
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
    N = n;
    L = 0;
    for (int i = 0; i < N; i++)
        node[i].head = -1;
}
void add_edge(int x,int y,int cap,int cost)
{
    edge[L].to = y;
    edge[L].cap = cap;
    edge[L].cost = cost;
    edge[L].flow = 0;
    edge[L].next = node[x].head;
    node[x].head = L++;
    edge[L].to = x;
    edge[L].cap = 0;
    edge[L].cost = -cost;
    edge[L].flow = 0;
    edge[L].next = node[y].head;
    node[y].head = L++;
}
bool spfa(int s,int t)
{
    deque<int> q;
    for (int i = 0; i < N; i++)
    {
        node[i].dis = inf;
        node[i].pre = -1;
        node[i].visit = 0;
    }
    node[s].dis = 0;
    node[s].visit = 1;
    q.push_front(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        node[u].visit = 0;
        for (int i = node[u].head; i != -1; i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].cap > edge[i].flow && node[v].dis > node[u].dis+edge[i].cost)
            {
                node[v].dis = node[u].dis+edge[i].cost;
                node[v].pre = i;
                if (!node[v].visit)
                {
                    node[v].visit = 1;
                    if (rand()&1)
                        q.push_front(v);
                    else
                        q.push_back(v);
                }
            }
        }
    }
    return (node[t].pre != -1);
}
int totcar;
long long mcmf(int s,int t)
{
    long long cost = 0;
    long long ans = 0x7fffffffffffffffLL;
    while (spfa(s,t))
    {
        int maxf = inf;
        for (int i=node[t].pre; i!=-1; i=node[edge[i^1].to].pre)
            maxf = min(maxf,edge[i].cap-edge[i].flow);
        for (int i = node[t].pre; i != -1; i = node[edge[i^1].to].pre)
        {
            edge[i].flow += maxf;
            edge[i^1].flow -= maxf;
            cost += edge[i].cost*maxf;
        }
        if (cost+(totcar-1)*2000000 < 0)
            ans = min(ans,cost+totcar*2000000);
        //cout << cost+totcar*999999 << ' ' << cost+totcar*1000000 << ' ' << cost << ' ' << totcar << ' ' << ans << endl;
    }
    return ans;
}
int n,C,R;
int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d%d",&n,&C,&R);
        init(n*2+2);
        totcar = 0;
        add_edge(n*2-1,n*2+1,inf,0);
        add_edge(n*2-2,n*2+1,inf,0);
        for (int i = 0; i < n; i++)
        {
            int r;
            scanf("%d",&r);
            totcar += r;
            add_edge(i*2,i*2+1,r,-2000000);
            if (i+1 < n)
            {
                add_edge(i*2,i*2+2,inf,0);
                add_edge(i*2+1,i*2+3,inf,0);
            }
        }
        for (int i = 0; i < C; i++)
        {
            int ck,pk;
            scanf("%d%d",&ck,&pk);
            add_edge(n*2,0,ck,pk);
        }
        for (int i = 0; i < R; i++)
        {
            int di,si;
            scanf("%d%d",&di,&si);
            for (int j = 0; j+di+1 < n; j++)
                add_edge(j*2+1,(j+di+1)*2,inf,si);
        }
        printf("Case %d: ",cas);
        long long res = mcmf(n*2,n*2+1);
        if (res == 0x7fffffffffffffffLL)
            puts("impossible");
        else
            printf("%lld\n",res);
    }
    return 0;
}
