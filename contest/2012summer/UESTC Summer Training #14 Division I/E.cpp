#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct Edge
{
    int to,next,len;
} edge0[410000],edge[810000];
int dis[17576],head[17576],L,n,head0[17576],L0;

void init()
{
    L = L0 = 0;
    for (int i = 0; i < 17576; i++)
        head0[i] = head[i] = -1;
}

void BFS(int s)
{
    queue<int> Q;
    Q.push(s);
    memset(dis,63,4*17576);
    dis[s] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for (int i = head0[now]; i != -1; i = edge0[i].next)
            if (dis[edge0[i].to] > dis[now]+1)
            {
                dis[edge0[i].to] = dis[now]+1;
                Q.push(edge0[i].to);
            }
    }
}

void addedge0(int u,int v,int len)
{
    edge0[L0].to = v;
    edge0[L0].len = len;
    edge0[L0].next = head0[u];
    head0[u] = L0++;
}

void addedge(int u,int v,int len)
{
    edge[L].to = v;
    edge[L].len = len;
    edge[L].next = head[u];
    head[u] = L++;
}

char sa[10],sb[10];
int m,s,t;

int getid(char s[])
{
    return (s[2]-'A')*26*26+(s[1]-'A')*26+s[0]-'A';
}

int calc(int u)
{
    if (dis[u]!=0x3f3f3f3f)
        return dis[u];
    if (u==t)
        return dis[t]=0;
    for (int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        dis[u]=min(dis[u],calc(v)+edge[i].len);
    }
    return dis[u];
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        init();
        n = 0;
        scanf("%d",&m);
        for (int i = 0; i < m; i++)
        {
            scanf("%s%s",sa,sb);
            int u = getid(sa);
            int v = getid(sb);
            addedge0(u,v,1);
            addedge0(v,u,1);
        }
        scanf("%d",&m);
        scanf("%s",sa);
        BFS(getid(sa));
        for (int i = 1; i <= m; i++)
        {
            scanf("%s",sb);
            int u = getid(sa);
            int v = getid(sb);
            addedge0(u,v,0);
            if (i == 1)
                s = u;
            if (i == m)
                t = v;
            strcpy(sa,sb);
        }
        for (int i = 0; i < 17576; i++)
            for (int j = head0[i]; j != -1; j = edge0[j].next)
                if (dis[edge0[j].to] == dis[i]+1)
                    addedge(i,edge0[j].to,edge0[j].len);
        memset(dis,63,4*n);
        printf("%d\n",calc(s));
    }
    return 0;
}
