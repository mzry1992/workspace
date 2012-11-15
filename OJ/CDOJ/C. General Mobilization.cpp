#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
struct graph
{
    int to,next;
    int cap;
}g[5010+10010];
int f[5010];
int totg;
int v[5010];
int res[5010];
struct peoat
{
    int who,next;
}p[5010+5010];
struct node
{
    int who,at,v;
}tmp[5010];

void addedge(int a,int b,int c)
{
    totg++;
    g[totg].to = b;
    g[totg].cap = c;
    g[totg].next = g[a].next;
    g[a].next = totg;
}

void getfather(int now,int fat)
{
    f[now] = fat;
    for (int vv = g[now].next;vv != -1;vv = g[vv].next)
    if (f[g[vv].to] == 0)
        getfather(g[vv].to,now);
}

void DFS(int root)
{
    tottmp = 0;
    for (int vv = g[root].next;vv != -1;vv = g[vv].next)
    if (f[root] != g[vv].to)
    {
        for (int i = p[g[vv].to].next;)
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&v[i]);
            g[i].next = -1;
            p[i].next = n+i;
            p[n+i].next = -1;
            p[n+i].who = i;
        }
        totg = n;
        for (int i = 1;i <= n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addedge(a,b,c);
            addedge(b,a,c);
        }
        memset(f,0,sizeof(f));
        getfather(1,1);
        for (int tim = 0;tim < n;tim++)
        {
            for (int i = p[1].next;i != -1;i = p[i].next)
                res[p[i].who] = tim;
            p[1].next = -1;
            DFS(1);
        }
    }
}
