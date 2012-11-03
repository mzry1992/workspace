#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int to,next,w;
};

int n,m;
Edge edge[600000];
int head[3000],L;
int x[3000],y[3000];

void addedge(int u,int v,int w)
{
    edge[L].w = w;
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int be[3000],tot,id[3000];
bool visit[3000],col[3000];
bool DFS(int now,int c)
{
    id[now] = tot;
    be[tot++] = now;
    visit[now] = true;
    col[now] = c;
    for (int i = head[now]; i != -1; i = edge[i].next)
    {
        bool tcol = c;
        if ((abs(x[now]-x[edge[i].to])+abs(y[now]-y[edge[i].to])+edge[i].w)%2 == 1)
            tcol = 1-tcol;
        if (visit[edge[i].to] == false)
        {
            if (DFS(edge[i].to,tcol) == false)
                return false;
        }
        else
        {
            if (col[edge[i].to] != tcol)
                return false;
        }
    }
    return true;
}

const int step[2][2][2] = {{{0,0},{1,1}},{{0,1},{1,0}}};
int qL,qhead[6000];
Edge qedge[2400000];

int dfsnum[6000];
int low[6000];
int stack[6000];
int top,nowid,totsc;
int scid[6000];
int flag[6000];
void scdfs(int x)
{
    dfsnum[x] = low[x] = nowid++;
    stack[++top] = x;
    flag[x] = 1;
    for (int i = qhead[x];i != -1;i = qedge[i].next)
    {
        int y = qedge[i].to;
        if (dfsnum[y] == -1)
        {
            scdfs(y);
            low[x] = min(low[x],low[y]);
        }
        else if (flag[y] == 1)
            low[x] = min(low[x],dfsnum[y]);
    }
    if (dfsnum[x] == low[x])
    {
        while (stack[top] != x)
        {
            flag[stack[top]] = 0;
            scid[stack[top]] = totsc;
            top--;
        }
        flag[x] = 0;
        scid[x] = totsc++;
        top--;
    }
}

void qaddedge(int u,int v)
{
    //printf("add : %d -> %d\n",u,v);
    qedge[qL].to = v;
    qedge[qL].next = qhead[u];
    qhead[u] = qL++;
}
bool solve()
{
    for (int i = 0; i < tot; i++)
        col[be[i]] = 1-col[be[i]];

    //for (int i = 0;i < tot;i++)
    //    printf("be[i] = %d, col = %d\n",be[i],col[be[i]]);

    qL = 0;
    for (int i = 0; i < tot; i++)
        qhead[i*2] = qhead[i*2+1] = -1;
    for (int u = 0; u < tot; u++)
        for (int tj = head[be[u]]; tj != -1; tj = edge[tj].next)
        {
            int v = id[edge[tj].to];
            int ri = be[u],rj = be[v];

            if (ri < rj)
            {
                for (int i = 0; i < 2; i++)
                {
                    int xi = x[ri]+step[col[ri]][i][0];
                    int yi = y[ri]+step[col[ri]][i][1];
                    for (int j = 0; j < 2; j++)
                    {
                        int xj = x[rj]+step[col[rj]][j][0];
                        int yj = y[rj]+step[col[rj]][j][1];

                        if (abs(xi-xj)+abs(yi-yj) != edge[tj].w)
                        {
                            //printf("colu = %d, colv = %d, u = %d, v = %d, (%d,%d) -> (%d,%d)\n",col[ri],col[rj],u*2+i,v*2+j,xi,yi,xj,yj);
                            qaddedge(u*2+i,v*2+1-j);
                            qaddedge(v*2+j,u*2+1-i);
                        }
                    }
                }
            }
        }

    //printf("============\n");

    memset(dfsnum,-1,sizeof(dfsnum));
    memset(flag,0,sizeof(flag));
    top = totsc = nowid = 0;
    for (int i = 0;i < 2*tot;i++)
        if (dfsnum[i] == -1)
            scdfs(i);
//    for (int i = 0;i < 2*tot;i++)
//        printf("%d ",scid[i]);
//    printf("\n");
    for (int i = 0;i < tot;i++)
        if (scid[2*i] == scid[2*i+1])
        {
//            printf("sc %d\n",be[i]);
            return false;
        }
    return true;
}

bool color()
{
    memset(col,0,sizeof(col));
    memset(visit,0,sizeof(visit));
    for (int i = 0; i < n; i++)
        if (visit[i] == false)
        {
            tot = 0;
            if (DFS(i,0) == false)
                return false;

            if (solve() == false && solve() == false)
                return false;
        }
    return true;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            head[i] = -1;
        L = 0;

        for (int i = 0; i < n; i++)
            scanf("%d%d",&x[i],&y[i]);
        scanf("%d",&m);
        for (int i = 0; i < m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--;
            v--;
            addedge(u,v,w);
            addedge(v,u,w);
        }

        if (color() == false)
            puts("impossible");
        else
            puts("possible");

    }
    return 0;
}

