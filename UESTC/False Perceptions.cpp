#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int MAXEDGE=110000;
const int MAXN=7000;
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

struct Edge
{
    int to,next;
};
Edge g[MAXEDGE];
int totg,head[MAXN];
int ne,na,nt,t,u,v,val[100],pre[100],maxf,fullf,ind[100];
char sv[30];

void addedge(int u,int v)
{
    g[totg].to = v;
    g[totg].next = head[u];
    head[u] = totg++;
}

int main()
{
    int ft = 1;
    while (true)
    {
        scanf("%d%d%d",&ne,&na,&nt);
        if (ne == 0 && na == 0 && nt == 0)  break;
        totg = 0;
        for (int i = 0; i < ne+na+nt; i++)
            head[i] = -1;
        memset(ind,0,sizeof(ind));
        for (int i = 0; i < ne; i++)
        {
            scanf("\nExtract%d",&u);
            scanf("%d",&t);
            for (int j = 0; j < t; j++)
            {
                scanf("%s",sv);
                if (sv[0] == 'A')
                {
                    sscanf(sv,"Assumption%d",&v);
                    addedge(u,ne+v);
                }
                else
                {
                    sscanf(sv,"Theory%d",&v);
                    ind[v]++;
                    addedge(u,ne+na+v);
                }
            }
            scanf("%s",sv);
        }
        for (int i = 0; i < na; i++)
        {
            scanf("\nAssumption%d",&u);
            scanf("%d",&t);
            for (int j = 0; j < t; j++)
            {
                scanf("%s",sv);
                if (sv[0] == 'A')
                {
                    sscanf(sv,"Assumption%d",&v);
                    addedge(ne+u,ne+v);
                }
                else
                {
                    sscanf(sv,"Theory%d",&v);
                    ind[v]++;
                    addedge(ne+u,ne+na+v);
                }
            }
            scanf("%s",sv);
        }
        for (int i = 0; i < nt; i++)
        {
            scanf("\nTheory%d",&u);
            scanf("%d",&t);
            val[t-1] = u;
            if (i+1 < nt)
                scanf("%s",sv);
        }
        memset(pre,false,sizeof(pre));
        for (int i = nt-1;i >= 0;i--)
        {
            init(ne+na+nt+2);
            for (int j = 0;j < ne;j++)
                add_edge(ne+na+nt,j,1,0);
            pre[i] = true;
            for (int j = 0;j < ne+na+nt;j++)
                for (int k = head[j];k != -1;k = g[k].next)
                    add_edge(j,g[k].to,1,0);
            fullf = 0;
            for (int j = nt-1;j >= i;j--)
            {
                add_edge(ne+na+j,ne+na+nt+1,ind[j],0);
                fullf += ind[j];
            }
            maxf = maxflow(ne+na+nt,ne+na+nt+1);
            if (maxf != fullf)
                pre[i] = false;
        }
        printf("Case %d:\n",ft++);
        for (int i = 0;i < nt;i++)
            if (pre[i] == true)
                printf("Theory%d ",i+1);
        printf("\n");
        puts("");
    }
    return 0;
}
