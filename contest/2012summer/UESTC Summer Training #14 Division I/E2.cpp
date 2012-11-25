#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Edge
{
    int to,next,len;
    bool del;
} edge[810000];
int dis[21000],head[21000],L,n;

void init()
{
    L = 0;
    for (int i = 0; i < 21000; i++)
    {
        head[i] = -1;
        dis[i] = 0x3fffffff;
    }
}

int sp(int s,int t)
{
    queue<int> Q;
    Q.push(s);
    dis[s] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        for (int i = head[now]; i != -1; i = edge[i].next)
            if (edge[i].len)
                if (dis[edge[i].to] > dis[now]+1)
                {
                    dis[edge[i].to] = dis[now]+1;
                    Q.push(edge[i].to);
                }
    }
    for (int i = 0; i < n; i++)
        for (int j = head[i]; j != -1; j = edge[j].next)
            if (dis[edge[j].to] != dis[i]+1)
                edge[j].del = true;
}

void addedge(int u,int v,int len)
{
    edge[L].to = v;
    edge[L].len = len;
    edge[L].del=0;
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
        if (!edge[i].del)
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
        n = 21000;
        scanf("%d",&m);
        for (int i = 0; i < m; i++)
        {
            scanf("%s%s",sa,sb);
            int u = getid(sa);
            int v = getid(sb);
            addedge(u,v,1);
            addedge(v,u,1);
        }
        scanf("%d",&m);
        scanf("%s",sa);
        for (int i = 1; i <= m; i++)
        {
            scanf("%s",sb);
            int u = getid(sa);
            int v = getid(sb);
            addedge(u,v,0);
            if (i == 1)
                s = u;
            if (i == m)
                t = v;
            strcpy(sa,sb);
        }
        sp(s,t);
        memset(dis,63,4*n);
        printf("%d\n",calc(s));
    }
    return 0;
}

