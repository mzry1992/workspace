#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Point
{
    int x,y,a,b;
};

Point pn[110],pm[410];
int mn,mm;

int Dis2(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool mp[110][410];
int ha[110],hb[410],n,m;

bool Gao()
{
    scanf("%d%d",&mn,&mm);
    n = mn;
    for (int i = 0;i < mn;i++)
        scanf("%d%d%d%d",&pn[i].x,&pn[i].y,&pn[i].a,&pn[i].b);
    m = 0;
    for (int i = 0;i < mm;i++)
    {
        scanf("%d%d%d",&pm[m].x,&pm[m].y,&pm[m].a);
        bool flag = false;
        for (int j = 0;j < n;j++)
            if (Dis2(pm[m],pn[j]) <= pn[j].b*pn[j].b)
            {
                if (j == 0)
                {
                    pn[j].a += pm[m].a;
                    flag = false;
                    break;
                }
                flag = true;
                break;
            }
        if (flag == true)
            m++;
    }
    memset(mp,false,sizeof(mp));
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            if (Dis2(pm[j],pn[i]) <= pn[i].b*pn[i].b)
                mp[i][j] = true;
    for (int i = 0;i < n;i++)
        ha[i] = pn[i].a;
    for (int i = 0;i < m;i++)
        hb[i] = pm[i].a;
    for (int i = 1;i < n;i++)
        if (ha[i] > ha[0])  return false;
    return true;
}
const int MAXEDGE=204000;
const int MAXN=5020;
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
int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        if (!Gao())
            puts("Lonesome Willy");
        init(n+m+1);
        for (int i=1;i<n;i++)
            for (int j=0;j<m;j++)
                if (mp[i][j])
                    add_edge(i,n+j,inf,0);
        for (int i=1;i<n;i++)
            add_edge(0,i,ha[0]-ha[i],0);
        int tot=0;
        for (int i=0;i<m;i++)
        {
            add_edge(i+n,n+m,hb[i],0);
            tot+=hb[i];
        }
        if (maxflow(0,n+m)<tot)
            puts("Lonesome Willy");
        else
            puts("Suiting Success");
    }
    return 0;
}
