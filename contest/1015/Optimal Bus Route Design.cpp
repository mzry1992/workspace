#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=0x7fffffff;
const int MAXN=300;
const int MAXM=90000;
struct edges
{
    int to,next,cost,cap,flow;
}edge[MAXM*2];
int head[MAXN],dis[MAXN],pre[MAXN];
bool visit[MAXN];
int L,N;
void init(int n)
{
    L=0;N=n;
    memset(head,-1,4*n);
}
void add_edge(int u,int v,int cap,int cost)
{
    edge[L].to=v;
    edge[L].cap=cap;
    edge[L].flow=0;
    edge[L].cost=cost;
    edge[L].next=head[u];
    head[u]=L++;
    edge[L].to=u;
    edge[L].cap=0;
    edge[L].flow=0;
    edge[L].cost=-cost;
    edge[L].next=head[v];
    head[v]=L++;
}
bool spfa(int s,int t)
{
    memset(dis,63,4*N);
    memset(visit,0,N);
    memset(pre,-1,4*N);
    queue<int> que;
    que.push(s);
    dis[s]=0;
    while (!que.empty())
    {
        int u=que.front();
        que.pop();
        visit[u]=0;
        for (int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if (dis[v]>dis[u]+edge[i].cost && edge[i].flow<edge[i].cap)
            {
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if (!visit[v])
                {
                    visit[v]=1;
                    que.push(v);
                }
            }
        }
    }
    return pre[t]!=-1;
}
int mcmf(int s,int t)
{
    int cost=0,tot=0;
    while (spfa(s,t))
    {
        int flow=inf;
        for (int i=pre[t];i!=-1;i=pre[edge[i^1].to])
            flow=min(flow,edge[i].cap-edge[i].flow);
        for (int i=pre[t];i!=-1;i=pre[edge[i^1].to])
        {
            edge[i].flow+=flow;
            edge[i^1].flow-=flow;
            cost+=edge[i].cost*flow;
        }
        tot+=flow;
    }
    if (tot<N/2-1)
        return -1;
    else
        return cost;
}
int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        init(n*2+2);
        for (int i=1;i<=n;i++)
        {
            add_edge(0,i,1,0);
            add_edge(i+n,n+n+1,1,0);
        }
        for (int u=1;u<=n;u++)
        {
            int v,k;
            while (scanf("%d",&v),v)
            {
                scanf("%d",&k);
                add_edge(u,n+v,1,k);
            }
        }
        int ret=mcmf(0,n*2+1);
        if (ret==-1)
            puts("N");
        else
            printf("%d\n",ret);
    }
    return 0;
}
