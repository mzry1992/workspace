#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct Edge
{
    int to,next;
};
Edge edge[10000];
int head[1000],L;
int n,m;
int u,v;
bool g0[1000][1000],g1[1000][1000],visit[1000];

void init(int n)
{
    L = 0;
    for (int i = 0;i < n;i++)
        head[i] = -1;
    memset(g0,false,sizeof(g0));
    memset(g1,false,sizeof(g1));
}

void addedge(int u,int v)
{
    g0[u][v] = true;
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

void Gao(int s,int now)
{
    visit[now] = g1[s][now] = true;
    for (int i = head[now];i != -1;i = edge[i].next)
        if (visit[edge[i].to] == false)
            Gao(s,edge[i].to);
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        init(n);
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            addedge(u,v);
        }
        for (int i = 0;i < n;i++)
        {
            memset(visit,false,sizeof(visit));
            Gao(i,i);
        }
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (g1[i][j] == true && i != j)
                    for (int k = head[j];k != -1;k = edge[k].next)
                        g0[i][edge[k].to] = false;
        int res = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (g0[i][j] == true)
                    res++;
        printf("%d\n",res);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (g0[i][j] == true)
                    printf("%d %d\n",i+1,j+1);
    }
    return 0;
}
