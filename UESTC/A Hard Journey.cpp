#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,m,p,q,mp[21][21][16][16],mincost[21][21][2][2],att0[21][21],att1[21][21],att2[21][21];
bool am[16][16],use[16];
int pre[16];

bool check(int u)
{
    for (int v=1; v<=m; v++)
        if (am[u][v] && !use[v])
        {
            use[v]=1;
            if (pre[v]==-1 || check(pre[v]))
            {
                pre[v]=u;
                return 1;
            }
        }
    return 0;
}

int match()
{
    int ret=0;
    memset(pre,-1,sizeof(pre));
    for (int u=1; u<=m; u++)
    {
        memset(use,0,sizeof(use));
        if (check(u))
            ret++;
    }
    return ret;
}

int getid(int x,int y,int form)
{
    return ((x-1)*n+y)*2-1+form;
}

struct edge
{
    int to,next,cost;
}g[30*30*30];
int head[21*21*2],totg;

void addedge(int u,int v,int c)
{
    g[totg].to = v;
    g[totg].cost = c;
    g[totg].next = head[u];
    head[u] = totg++;
}

queue<int> Q;
bool visit[21*21*2];
int dis[21*21*2];

int SPFA(int s,int t)
{
    Q.push(s);
    memset(visit,false,sizeof(visit));
    memset(dis,63,sizeof(dis));
    visit[s] = true;
    dis[s] = 0;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        visit[now] = false;
        for (int i = head[now];i != -1;i = g[i].next)
            if (dis[g[i].to] > dis[now]+g[i].cost)
            {
                dis[g[i].to] = dis[now]+g[i].cost;
                if (visit[g[i].to] == false)
                {
                    visit[g[i].to] = true;
                    Q.push(g[i].to);
                }
            }
    }
    return dis[t];
}

int main()
{
    while (scanf("%d%d%d%d",&n,&m,&p,&q) != EOF)
    {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
            {
                att0[i][j] = att1[i][j] = att2[i][j] = 0;
                for (int x = 1;x <= m;x++)
                    for (int y = 1;y <= m;y++)
                        scanf("%d",&mp[i][j][x][y]);
                for (int x = 1;x <= m;x++)
                    for (int y = 1;y <= m;y++)
                        if (mp[i][j][x][y] == 1)
                        {
                            att0[i][j]++;
                            break;
                        }
                for (int y = 1;y <= m;y++)
                    for (int x = 1;x <= m;x++)
                        if (mp[i][j][x][y] == 1)
                        {
                            att1[i][j]++;
                            break;
                        }
                memset(am,false,sizeof(am));
                for (int x = 1;x <= m;x++)
                    for (int y = 1;y <= m;y++)
                        if (mp[i][j][x][y] == 1)
                            am[x][y] = true;
                att2[i][j] = match();
                att0[i][j] *= p;
                att1[i][j] *= p;
                att2[i][j] *= p;
                att2[i][j] += q;
                mincost[i][j][0][0] = min(min(att0[i][j],q+att1[i][j]+q),att2[i][j]+q);
                mincost[i][j][0][1] = min(min(att0[i][j]+q,q+att1[i][j]),att2[i][j]);
                mincost[i][j][1][0] = min(min(q+att0[i][j],att1[i][j]+q),att2[i][j]);
                mincost[i][j][1][1] = min(min(q+att0[i][j]+q,att1[i][j]),att2[i][j]+q);
            }
        for (int i = 0;i <= n*n*2+1;i++)
            head[i] = -1;
        totg = 0;
        addedge(0,getid(1,1,0),min(mincost[1][1][0][0],mincost[1][1][1][0]));
        addedge(0,getid(1,1,1),min(mincost[1][1][0][1],mincost[1][1][1][1]));
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
            {
                if (i < n)
                {
                    addedge(getid(i,j,0),getid(i+1,j,0),mincost[i+1][j][0][0]);
                    addedge(getid(i,j,0),getid(i+1,j,1),mincost[i+1][j][0][1]);
                    addedge(getid(i,j,1),getid(i+1,j,0),q+mincost[i+1][j][0][0]);
                    addedge(getid(i,j,1),getid(i+1,j,1),q+mincost[i+1][j][0][1]);
                }
                if (j < n)
                {
                    addedge(getid(i,j,1),getid(i,j+1,0),mincost[i][j+1][1][0]);
                    addedge(getid(i,j,1),getid(i,j+1,1),mincost[i][j+1][1][1]);
                    addedge(getid(i,j,0),getid(i,j+1,0),q+mincost[i][j+1][1][0]);
                    addedge(getid(i,j,0),getid(i,j+1,1),q+mincost[i][j+1][1][1]);
                }
            }
        addedge(getid(n,n,0),n*n*2+1,0);
        addedge(getid(n,n,1),n*n*2+1,0);
        printf("%d\n",SPFA(0,n*n*2+1));
    }
}
