#include <iostream>
using namespace std;

int n,m,i,u,v;
struct graphtype
{
       int next;
       int tonode;
}graph1[200000],graph2[200000];
int totnode1,totnode2;
int visit[20000],dfsorder[20000],dfsnow;
int tot;
int nodein[20000];
int sum[20000],outdegree[20000];
int ans,tans;

void addpath(int u,int v)
{
     totnode1++;
     graph1[totnode1].next = graph1[u].next;
     graph1[totnode1].tonode = v;
     graph1[u].next = totnode1;
     totnode2++;
     graph2[totnode2].next = graph2[v].next;
     graph2[totnode2].tonode = u;
     graph2[v].next = totnode2;
}

void dfs1(int i)
{
     int j;
     visit[i] = true;
     for (j = graph1[i].next;j != -1;j = graph1[j].next)
     if (visit[graph1[j].tonode] == false)
        dfs1(graph1[j].tonode);
     dfsnow++;
     dfsorder[dfsnow] = i;
}

void dfs2(int i)
{
     int j;
     visit[i] = true;
     nodein[i] = tot;
     for (j = graph2[i].next;j != -1;j = graph2[j].next)
     if (visit[graph2[j].tonode] == false)
        dfs2(graph2[j].tonode);
}

void kosaraju()
{
     int i;
     for (i = 1;i <= n;i++)
         visit[i] = false;
     dfsnow = 0;
     for (i = 1;i <= n;i++)
     if (visit[i] == false)
        dfs1(i);
     for (i = 1;i <= n;i++)
         visit[i] = false;
     for (i = n;i >= 1;i--)
     if (visit[dfsorder[i]] == false)
     {
                            tot++;
                            dfs2(dfsorder[i]);
     }
}

int main()
{
    while (scanf("%d %d",&n,&m) == 2)
    {
        totnode1 = totnode2 = 0;
        for (i = 1;i <= n;i++)
        {
            totnode1++;
            totnode2++;
            graph1[totnode1].next = -1;
            graph2[totnode2].next = -1;
        }
        for (i = 1;i <= m;i++)
        {
            scanf("%d %d",&u,&v);
            addpath(u,v);
        }
        tot = 0;
        kosaraju();
        for (i = 1;i <= tot;i++)
        {
            sum[i] = 0;
            outdegree[i] = 0;
        }
        for (i = 1;i <= n;i++)
            sum[nodein[i]]++;
        for (u = 1;u <= n;u++)
        {
            for (v = graph1[u].next;v != -1;v = graph1[v].next)
            if (nodein[u] != nodein[graph1[v].tonode])
               outdegree[nodein[u]]++;
        }
        ans = 0;
        tans = 0;
        for (i = 1;i <= tot;i++)
        if (outdegree[i] == 0)
        {
                         ans++;
                         tans = i;
        }
        if (ans != 1) tans = 0;
        else
            tans = sum[tans];
        printf("%d\n",tans);
    }
    return 0;
}
