#include<stdio.h>
#include<string.h>
const int MAXEDGE=3000000;
const int MAXN=3003;
const int inf=0x3fffffff;
struct edges
{
    int cap,to,next,flow;
} edge[MAXEDGE+100];
struct nodes
{
    int head,label,pre,cur;
} node[MAXN+100];
int L,N;
int gap[MAXN+100];
void init(int n)
{
    L=0;
    N=n;
    for (int i=0; i<N; i++)
        node[i].head=-1;
}
void add_edge(int x,int y,int z,int w)
{
    edge[L].cap=z;
    edge[L].flow=0;
    edge[L].to=y;
    edge[L].next=node[x].head;
    node[x].head=L++;
    edge[L].cap=w;
    edge[L].flow=0;
    edge[L].to=x;
    edge[L].next=node[y].head;
    node[y].head=L++;
}
int maxflow(int s,int t)
{
    memset(gap,0,sizeof(gap));
    gap[0]=N;
    int u,ans=0;
    for (int i=0; i<N; i++)
    {
        node[i].cur=node[i].head;
        node[i].label=0;
    }
    u=s;
    node[u].pre=-1;
    while (node[s].label<N)
    {
        if (u==t)
        {
            int min=inf;
            for (int i=node[u].pre; i!=-1; i=node[edge[i^1].to].pre)
                if (min>edge[i].cap-edge[i].flow)
                    min=edge[i].cap-edge[i].flow;
            for (int i=node[u].pre; i!=-1; i=node[edge[i^1].to].pre)
            {
                edge[i].flow+=min;
                edge[i^1].flow-=min;
            }
            u=s;
            ans+=min;
            continue;
        }
        bool flag=false;
        int v;
        for (int i=node[u].cur; i!=-1; i=edge[i].next)
        {
            v=edge[i].to;
            if (edge[i].cap-edge[i].flow && node[v].label+1==node[u].label)
            {
                flag=true;
                node[u].cur=node[v].pre=i;
                break;
            }
        }
        if (flag)
        {
            u=v;
            continue;
        }
        node[u].cur=node[u].head;
        int min=N;
        for (int i=node[u].head; i!=-1; i=edge[i].next)
            if (edge[i].cap-edge[i].flow && node[edge[i].to].label<min) min=node[edge[i].to].label;
        gap[node[u].label]--;
        if (!gap[node[u].label]) return ans;
        node[u].label=min+1;
        gap[node[u].label]++;
        if (u!=s) u=edge[node[u].pre^1].to;
    }
    return ans;
}
inline long long min(long long a,long long b)
{
    return a < b ? a:b;
}
struct graph
{
    int to,next;
};
int head[1000],totg;
graph g[1000000];
long long dis[101][101];
int qu_time[1001];
int qu_pos[1001];
int main()
{
    int T;
    scanf("%d",&T);
    for(int ii = 1; ii<=T; ii++)
    {
        int n , m ;
        int Qn;
        scanf("%d%d%d",&n,&m,&Qn);
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                dis[i][j] = -1;
        for(int i = 0 ; i < m ; i++)
        {
            int a, b;
            long long c;
            scanf("%d%d%I64d",&a,&b,&c);
            if (dis[a][b] == -1 || dis[a][b] > c)
            {
                dis[a][b] = c;
                dis[b][a] = c;
            }
        }

        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    if (dis[i][k] != -1 && dis[k][j] != -1)
                        if (dis[i][j] != -1)
                            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        else
                            dis[i][j] = dis[i][k]+dis[k][j];
        for(int Qi = 0 ; Qi < Qn ; Qi++)
        {
            scanf("%d%d",&qu_pos[Qi],&qu_time[Qi]);
        }
        init(Qn*2+2);
        int S = Qn*2;
        int T = Qn*2+1;
        totg = 0;
        for(int i = 0 ; i < Qn ; i++)
            for(int j = 0 ; j < Qn ; j++)
            {
                if(i == j) continue;
                int qd = qu_time[i] - qu_time[j];
                if(qd > 0) continue;
                qd = -qd;

                if(dis[qu_pos[i]][qu_pos[j]] != -1 && qd >= dis[qu_pos[i]][qu_pos[j]])
                    addedge(i*2,j*2+1);
                    //add_edge(i*2,j*2+1,1,0);
            }
        for(int i = 0 ; i < Qn; i++)
        {
            add_edge(S,i*2,1,0);
            add_edge(i*2+1,T,1,0);
        }
        int ans = Qn - maxflow(S,T);
        printf("Case %d: %d\n",ii,ans-1);
    }
    return 0;
}
