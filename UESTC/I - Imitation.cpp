#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int to,next;
} g[10001],rg[10001];
int n,m,L,head[1001],rhead[1001],u,v;
bool visit[1001];

void addedge(int u,int v)
{
    g[L].to = v;
    g[L].next = head[u];
    head[u] = L;
    rg[L].to = u;
    rg[L].next = rhead[v];
    rhead[v] = L++;
}

void addedge2(int u,int v)
{
    g[L].to = v;
    g[L].next = head[u];
    head[u] = L++;
}

int nowtim,tim[1001],totsc,id[1001],val[1001];

void DFS1(int now)
{
    visit[now] = true;
    for (int i = head[now]; i != -1; i = g[i].next)
        if (visit[g[i].to] == false)
            DFS1(g[i].to);
    tim[++nowtim] = now;
}

void DFS2(int now)
{
    visit[now] = true;
    id[now] = totsc;
    val[totsc]++;
    for (int i = rhead[now]; i != -1; i = rg[i].next)
        if (visit[rg[i].to] == false)
            DFS2(rg[i].to);
}

void GaoSC()
{
    memset(visit,false,sizeof(visit[0])*n+1);
    nowtim = 0;
    for (int i = 1; i <= n; i++)
        if (visit[i] == false)
            DFS1(i);
    memset(visit,false,sizeof(visit[0])*n+1);
    totsc = 0;
    for (int i = n; i >= 1; i--)
        if (visit[tim[i]] == false)
        {
            totsc++;
            val[totsc] = 0;
            DFS2(tim[i]);
        }
}

bool hasadd[1001][1001];
bool flag[1001];
int num[1001];
void dfs(int u)
{
    flag[u]=1;
    for (int i=head[u];i!=-1;i=g[i].next)
    {
        int v=g[i].to;
        dfs(v);
    }
}

void addedge3(int u,int v)
{
    rg[L].to = u;
    rg[L].next = rhead[v];
    rhead[v] = L++;
}

int calc(int u)
{
    if (!flag[u]) return 0;
    if (num[u]!=-1) return num[u];
    num[u]=0;
    for (int i=rhead[u];i!=-1;i=rg[i].next)
    {
        int v=rg[i].to;
        num[u]+=calc(v);
    }
    return num[u];
}

int wg;
char ch;
bool ng;

inline int readint() //整数，包括负数
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))    ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1; i <= n; i++)
            rhead[i] = head[i] = -1;
        L = 0;
        for (int i = 1; i <= m; i++)
        {
            u = readint();
            v = readint();
            addedge(u,v);
        }
        GaoSC();
        for (int i = 1; i <= n; i++)
            head[i] = -1;
        L = 0;
        memset(hasadd,false,sizeof(hasadd[0])*n+4);
        for (int i = 1; i <= n; i++)
            for (int j = rhead[i]; j != -1; j = rg[j].next)
                if (id[i] != id[rg[j].to])
                    if (hasadd[id[rg[j].to]][id[i]] == false)
                    {
                        hasadd[id[rg[j].to]][id[i]] = true;
                        addedge2(id[rg[j].to],id[i]);
                    }
        n = totsc;
        for (int i = 1; i <= n; i++)
            rhead[i] = -1;
        L = 0;
        for (int i = 1;i <= n;i++)
            for (int j = head[i];j != -1;j = g[j].next)
                addedge3(i,g[j].to);
        int maxtot=0,mintot=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                flag[j]=0;
                num[j]=-1;
            }
            dfs(i);
            //printf("i=%d\n",i);
            maxtot+=val[i]*(val[i]-1);
            if (val[i]>1) mintot+=val[i];
            for (int j=1;j<=n;j++)
                if (i!=j && flag[j])
                {
                    maxtot+=val[j];
                    mintot+=1;
                }
            num[i]=1;
            for (int j=head[i];j!=-1;j=g[j].next)
            {
                if (calc(g[j].to)>1)
                    mintot-=val[g[j].to];
                //printf("%d %d %d\n",i,g[j].to,calc(g[j].to));
            }
        }
        printf("Case #%d: %d %d\n",ft,mintot,maxtot);
    }
    return 0;
}
