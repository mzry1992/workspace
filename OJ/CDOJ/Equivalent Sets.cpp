#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int Maxn = 20010;
const int MaxM = 50010;
struct graph
{
    int to,next;
}g[MaxM],rg[MaxM];
int head[Maxn],rhead[Maxn],totg;

int n,m,tim[Maxn],nowtim,id[Maxn],totsc,ind[Maxn],outd[Maxn],in0,out0,in0out0;
bool visit[Maxn];

void DFS1(int now)
{
    visit[now] = true;
    for (int i = head[now];i != -1;i = g[i].next)
        if (visit[g[i].to] == false)
            DFS1(g[i].to);
    nowtim++;
    tim[nowtim] = now;
}

void DFS2(int now)
{
    visit[now] = true;
    id[now] = totsc;
    for (int i = rhead[now];i != -1;i = rg[i].next)
        if (visit[rg[i].to] == false)
            DFS2(rg[i].to);
}

void SC()
{
    memset(visit,false,sizeof(visit));
    nowtim = 0;
    for (int i = 1;i <= n;i++)
        if (visit[i] == false)
            DFS1(i);
    memset(visit,false,sizeof(visit));
    totsc = 0;
    for (int i = n;i >= 1;i--)
        if (visit[tim[i]] == false)
        {
            totsc++;
            DFS2(tim[i]);
        }
    memset(ind,0,sizeof(ind));
    memset(outd,0,sizeof(outd));
    for (int i = 1;i <= n;i++)
        for (int j = head[i];j != -1;j = g[j].next)
            if (id[i] != id[g[j].to])
            {
                ind[id[g[j].to]]++;
                outd[id[i]]++;
            }
}

void addedge(int u,int v)
{
    g[totg].to = v;
    g[totg].next = head[u];
    head[u] = totg;
    rg[totg].to = u;
    rg[totg].next = rhead[v];
    rhead[v] = totg;
    totg++;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1;i <= n;i++)  head[i] = rhead[i] = -1;
        totg = 0;
        for (int i = 1;i <= m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        SC();
        bool flag = true;
        for (int i = 1;i <= n;i++)
            if (id[i] != id[1]) flag = false;
        if (flag == true)
            printf("%d\n",0);
        else
        {
            in0 = out0 = in0out0 = 0;
            for (int i = 1;i <= totsc;i++)
                if (ind[i] == 0 && outd[i] > 0) in0++;
                else if (ind[i] > 0 && outd[i] == 0)    out0++;
                else if (ind[i] == 0 && outd[i] == 0)   in0out0++;
            cout << in0out0+max(in0,out0) << endl;
        }
    }
}
