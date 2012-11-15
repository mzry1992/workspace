#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 19921005;

struct Point
{
    int x,y,z;
};

Point p[1010];
int n,X,Y,Z,L,dis[1010][1010];

int DIS(Point a,Point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
}

void init(int n)
{
    L = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] = inf;
}

struct Edge
{
    int u,v,cost;
};

Edge e[1001*1001];

int pre[1001],id[1001],visit[1001],in[1001];

int zhuliu(int root,int n,int m,Edge e[])
{
    int res = 0,u,v;
    while (true)
    {
        for (int i = 0; i < n; i++)
            in[i] = inf;
        for (int i = 0; i < m; i++)
            if (e[i].u != e[i].v && e[i].cost < in[e[i].v])
            {
                pre[e[i].v] = e[i].u;
                in[e[i].v] = e[i].cost;
            }
        for (int i = 0; i < n; i++)
            if (i != root)
                if (in[i] == inf)   return -1;
        int tn = 0;
        memset(id,-1,sizeof(id));
        memset(visit,-1,sizeof(visit));
        in[root] = 0;
        for (int i = 0; i < n; i++)
        {
            res += in[i];
            v = i;
            while (visit[v] != i && id[v] == -1 && v != root)
            {
                visit[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1)
            {
                for(int u = pre[v] ; u != v ; u = pre[u])
                    id[u] = tn;
                id[v] = tn++;
            }
        }
        if(tn == 0)    break;
        for (int i = 0; i < n; i++)
            if (id[i] == -1)
                id[i] = tn++;
        for (int i = 0; i < m;)
        {
            int v = e[i].v;
            e[i].u = id[e[i].u];
            e[i].v = id[e[i].v];
            if (e[i].u != e[i].v)
                e[i++].cost -= in[v];
            else
                swap(e[i],e[--m]);
        }
        n = tn;
        root = id[root];
    }
    return res;
}
int wg;
char ch;
bool ng;

inline int readint() //整数，包括负数
{
    ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))    ch = getchar();
    if (ch == '-')
    {
        ng = true;
        ch = getchar();
    }
    else ng = false;
    wg = ch-'0';
    ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        wg = wg*10+ch-'0';
        ch = getchar();
    }
    if (ng == true) wg = -wg;
    return wg;
}

int main()
{
    while (true)
    {
        scanf("%d%d%d%d",&n,&X,&Y,&Z);
        if (n == 0 && X == 0 && Y == 0 && Z == 0)   break;
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        init(n+1);
        for (int i = 1; i <= n; i++)
            dis[0][i] = min(dis[0][i],p[i].z*X);
        for (int i = 1; i <= n; i++)
        {
            int k,to;
            scanf("%d",&k);
            for (int j = 0; j < k; j++)
            {
                to = readint();
                //scanf("%d",&to);
                if (i == to)    continue;
                if (p[i].z >= p[to].z)
                    dis[i][to] = min(dis[i][to],DIS(p[i],p[to])*Y);
                else
                    dis[i][to] = min(dis[i][to],DIS(p[i],p[to])*Y+Z);
            }
        }
        n++;
        L = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dis[i][j] != inf)
                {
                    e[L].u = i;
                    e[L].v = j;
                    e[L++].cost = dis[i][j];
                }
        printf("%d\n",zhuliu(0,n,L,e));
    }
    return 0;
}
