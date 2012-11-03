#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int to,next;
}g[500001];
int head[50001],L;
int n,m,root;

void addedge(int u,int v)
{
    g[L].to = v;
    g[L].next = head[u];
    head[u] = L++;
}

bool visit[50001];

void Gao(int now)
{
}

int main()
{
    scanf("%d%d%d",&n,&m,&root);
    for (int i = 1;i <= n;i++)
        head[i] = -1;
    L = -1;
    for (int i = 1;i <= m;i++)
    {
        int ni,u,v;
        scanf("%d%d",&ni,&u);
        for (int j = 2;j <= ni;j++)
        {
            scanf("%d",&v);
            addedge(u,v);
            addedge(v,u);
            u = v;
        }
    }
    memset(visit,false,sizeof(visit));
    Gao(root);
}
