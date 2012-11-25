#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int to,c,next;
};

Edge edge[400000],nedge[400000];
queue<int> Q;
int dis[100000],head[100000],nhead[100000],nxt[100000],rnk[100000],nxc[100000],fg[100000],tfg,nL,L,n,m,u,v,c;
bool inq[100000];

void init(int n)
{
    nL = L = 0;
    for (int i = 0; i < n; i++)
        head[i] = nhead[i] = -1;
}

void addedge0(int u,int v,int c)
{
    nedge[nL].to = v;
    nedge[nL].c = c;
    nedge[nL].next = nhead[u];
    nhead[u] = nL++;
}

void addedge(int u,int v,int c)
{
    edge[L].to = v;
    edge[L].c = c;
    edge[L].next = head[u];
    head[u] = L++;
}

bool fgcmp(int a,int b)
{
    if (nxc[fg[a]] == nxc[fg[b]])
        return rnk[nxt[fg[a]]] < rnk[nxt[fg[b]]];
    return nxc[fg[a]] < nxc[fg[b]];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            u--;
            v--;
            addedge0(u,v,c);
            addedge0(v,u,c);
        }
        for (int i = 0;i < n;i++)
            dis[i] = 19921005;
        for (int i = 0;i < n;i++)
            inq[i] = false;
        dis[0] = 0;
        Q.push(0);
        int now;
        while (!Q.empty())
        {
            now = Q.front();
            Q.pop();
            inq[now] = false;
            for (int i = nhead[now]; i != -1; i = nedge[i].next)
                if (dis[nedge[i].to] > dis[now]+1)
                {
                    dis[nedge[i].to] = dis[now]+1;
                    if (inq[nedge[i].to] == false)
                    {
                        inq[nedge[i].to] = true;
                        Q.push(nedge[i].to);
                    }
                }
        }
        for (int i = 0; i < n; i++)
            for (int j = nhead[i]; j != -1; j = nedge[j].next)
                if (dis[nedge[j].to] == dis[i]+1)
                    addedge(nedge[j].to,i,nedge[j].c);
        for (int i = 0;i < n;i++)
            nxt[i] = -1;
        for (int i = 0;i < n;i++)
            inq[i] = false;
        nxt[n-1] = rnk[n-1] = 0;
        Q.push(n-1);
        int nowdis = dis[n-1];
        tfg = 0;
        while (!Q.empty())
        {
            now = Q.front();
            Q.pop();
            if (dis[now] < nowdis)
            {
                sort(fg,fg+tfg,fgcmp);
                for (int i = 0; i < tfg; i++)
                    rnk[fg[i]] = i;
                nowdis = dis[now];
                tfg = 0;
            }
            fg[tfg++] = now;
            for (int i = head[now]; i != -1; i = edge[i].next)
                if (nxt[edge[i].to] == -1 || nxc[edge[i].to] > edge[i].c || (nxc[edge[i].to] == edge[i].c && rnk[nxt[edge[i].to]] > rnk[now]))
                {
                    nxt[edge[i].to] = now;
                    nxc[edge[i].to] = edge[i].c;
                    if (inq[edge[i].to] == false)
                    {
                        inq[edge[i].to] = true;
                        Q.push(edge[i].to);
                    }
                }
        }
        printf("%d\n",dis[n-1]);
        for (now = 0; now != n-1; now = nxt[now])
            printf("%d ",nxc[now]);
        printf("\n");
    }
    return 0;
}
