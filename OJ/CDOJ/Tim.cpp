#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
struct graph
{
    int to,next;
}g[10000+40000+10];
int totg;
int color[10000+10];
bool use[10];
bool flag;
int res;
int totuse[10];

void addedge(int u,int v)
{
    totg++;
    g[totg].to = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

void DFS(int now,int totcolor)
{
    if (now == n+1)
    {
        flag = true;
        res = 0;
        for (int i = 1;i <= totcolor;i++)
        if (color[i] > res) res = color[i];
    }
    if (flag == true)   return;
    memset(use,false,sizeof(use));
    for (int vv = g[now].next;vv != -1;vv = g[vv].next)
    if (color[g[vv].to] != 0)
        use[color[g[vv].to]] = true;
    for (int i = 1;i <= totcolor;i++)
    if (use[i] == false)
    {
        color[now] = i;
        totuse[i]++;
        DFS(now+1,totcolor);
        totuse[i]--;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            g[i].next = -1;
        totg = n;
        for (int i = 1;i <= m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        res = 0;
        for (int col = 1;col <= 4;col++)
        {
            flag = false;
            memset(color,0,sizeof(color));
            memset(totuse,0,sizeof(totuse));
            DFS(1,col);
            if (flag == true)   break;
        }
        printf("%d\n",res);
    }
}
