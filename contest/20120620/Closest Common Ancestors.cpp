#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int to,next;
}edge[2000];
int head[1000],L,in[1000],deep[1000],res[1000];
int n,m,root;
bool visit[1000];
int a[1000][1000];

void init(int n)
{
    for (int i = 0;i < n;i++)
    {
        head[i] = -1;
        in[i] = 0;
    }
    L = 0;
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

void DFS(int now,int dp)
{
    deep[now] = dp;
    visit[now] = true;
    for (int i = head[now]; i != -1;i = edge[i].next)
        if (visit[edge[i].to] == false)
            DFS(edge[i].to,dp+1);
}

void Gao(int from,int now,int ac)
{
    a[from][now] = ac;
    visit[now] = true;
    for (int i = head[now];i != -1;i = edge[i].next)
        if (visit[edge[i].to] == false)
            Gao(from,edge[i].to,(deep[ac] > deep[edge[i].to])?edge[i].to:ac);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        init(n);
        for (int i = 0;i < n;i++)
        {
            int u,cnt,v;
            scanf("%d:(%d)",&u,&cnt);
            u--;
            for (int j = 0;j < cnt;j++)
            {
                scanf("%d",&v);
                v--;
                in[v]++;
                addedge(u,v);
                addedge(v,u);
            }
        }
        root = 0;
        for (int i = 0;i < n;i++)
            if (in[i] == 0)
                root = i;

        memset(visit,false,sizeof(visit));
        DFS(root,0);

        for (int i = 0;i < n;i++)
        {
            memset(visit,false,sizeof(visit));
            Gao(i,i,i);
        }

        memset(res,0,sizeof(res));
        scanf("%d",&m);
        for (int i = 0;i < m;i++)
        {
            int u,v;
            scanf(" (%d %d)",&u,&v);
            u--;
            v--;
            res[a[u][v]]++;
        }
        for (int i = 0;i < n;i++)
            if (res[i] > 0)
                printf("%d:%d\n",i+1,res[i]);
    }
	return 0;
}
