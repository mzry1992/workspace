#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int si,ni,ki;
char oi[10];
struct graph
{
    int to;
    int next;
    int dis;
}g[1000];
int totg;

void addedge(int u,int v,int dis)
{
    totg++;
    g[totg].to = v;
    g[totg].dis = dis;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf("%d",&m);
        totg = n;
        for (int i = 0;i <= n;i++)
            g[i].next = -1;
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d%s%d",&si,&ni,oi,&ki);
            if (strcmp(oi,"gt") == 0)
                addedge(si+ni,si-1,-ki);
            else
                addedge(si-1,si+ni,ki);
        }
    }
}
