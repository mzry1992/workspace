#include <iostream>
#include <cstdio>
using namespace std;

int n;
struct graph
{
    int next;
    int to;
    int index;
}g[1000];
int totg;
struct bridge
{
    int u,v;
}b[50000];
int totb;
int color[400];
bool illegal;

void addEdge(int index,int u,int v)
{
    totg++;
    g[totg].index = index;
    g[totg].to = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

void DFS(int now)
{
    for (int i = g[now].next;i != 0;i = g[i].next)
    {
        if (color[g[i].to] == 0)
        {
            color[g[i].to] = (color[now] == 1)?2:1;
            DFS(g[i].to);
        }
        else
        {
            if (color[g[i].to] == color[g[now].to])
            {
                illegal = true;
            }
        }
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        totg = n;
        memset(g,0,sizeof(g));
        totb = 0;
        while (true)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if (a==0&&b==0&&c==0) break;
            addEdge(a,b,c);
            totb++;
            b[totb].u = b;
            b[totb].v = c;
        }
        illegal = false;
        memset(color,0,sizeof(color));
        color[min(b[1].u,b[1].v)] = 1;
        DFS(min(b[1].u,b[1].v));
        if (illegal)
            printf("Your hero has fallen!");
        else
        {

        }
    }
}
