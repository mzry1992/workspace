#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int to,next;
};

Edge edge[32000];
int head[16000],L,u,v,f[16000][2];
int n,a[16000];

void init()
{
    for (int i = 0;i < n;i++)
        head[i] = -1;
    L = 0;
}

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

void DP(int now,int root)
{
    for (int i = head[now];i != -1;i = edge[i].next)
        if (edge[i].to != root)
            DP(edge[i].to,now);
    f[now][0] = a[now];
    for (int i = head[now];i != -1;i = edge[i].next)
        if (edge[i].to != root)
            if (f[edge[i].to][0] > 0)
                f[now][0] += f[edge[i].to][0];
    f[now][1] = -1992100500;
    for (int i = head[now];i != -1;i = edge[i].next)
        if (edge[i].to != root)
        {
            f[now][1] = max(f[now][1],f[edge[i].to][0]);
            f[now][1] = max(f[now][1],f[edge[i].to][1]);
        }
}

int main()
{
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    init();
    for (int i = 0;i < n-1;i++)
    {
        scanf("%d%d",&u,&v);
        v--;
        u--;
        addedge(u,v);
        addedge(v,u);
    }
    DP(0,-1);
    printf("%d\n",max(f[0][0],f[0][1]));
	return 0;
}
