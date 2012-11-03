#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct graph
{
    int to,next,id;
}g[200010];
int head[10010],totg;
map<string,int> name;
int n,m,totname;
struct edge
{
    char s1[20],s2[20];
}e[100010];

void addedge(int u,int v,int id)
{
    g[totg].to = v;
    g[totg].id = id;
    g[totg].next = head[u];
    head[u] = totg++;
}

int c[10010]; //0 - w 1 g 2 b
int d[10010];
int ance[10010];
int brid[200010],totb;

void DFS(int k,int fk,int deep)
{
    c[k] = 1;
    d[k] = deep;
    ance[k] = deep;
    int tot = 0;
    for (int ti = head[k];ti != -1;ti = g[ti].next)
    {
        int i = g[ti].to;
        if (i != fk && c[i] == 1)
            ance[k] = min(ance[k],d[i]);
        if (c[i] == 0)
        {
            DFS(i,k,deep+1);
            tot = tot+1;
            ance[k] = min(ance[k],ance[i]);
            if (ance[i] > d[k])
                brid[totb++] = g[ti].id;
        }
    }
    c[k] = 2;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        name.clear();
        totname = 0;
        totg = 0;
        for (int i = 0;i < n;i++)
            head[i] = -1;
        for (int i = 1;i <= m;i++)
        {
            scanf("%s%s",e[i].s1,e[i].s2);
            int id1,id2;
            if (name.find(e[i].s1) == name.end())
                name[e[i].s1] = totname++;
            if (name.find(e[i].s2) == name.end())
                name[e[i].s2] = totname++;
            id1 = name[e[i].s1];
            id2 = name[e[i].s2];
            addedge(id1,id2,i);
            addedge(id2,id1,i);
        }
        memset(c,0,sizeof(c));
        totb = 0;
        int flag = 0;
        for (int i = 0;i < n;i++)
            if (c[i] == 0)
            {
                DFS(i,-1,0);
                flag++;
            }
        sort(brid,brid+totb);
        totb = unique(brid,brid+totb) - brid;
        if (flag > 1)   totb = 0;
        printf("%d\n",totb);
        for (int i = 0;i < totb;i++)
            printf("%s %s\n",e[brid[i]].s1,e[brid[i]].s2);
    }
}
