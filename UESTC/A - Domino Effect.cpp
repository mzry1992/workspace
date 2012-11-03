#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int map[600][600];
int dis[600],pre[600];
bool visit[600];

int abs(int x)
{
    if (x < 0)    return -x;
    return x;
}

int max(int a,int b)
{
    if (a < b)  return b;
    return a;
}

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            map[i][j] = -1;
        for (int i = 1;i <= n;i++)
            map[i][i] = 0;
        for (int i = 1;i <= m;i++)
        {
            int u,v,l;
            scanf("%d%d%d",&u,&v,&l);
            if (map[u][v] == -1 || map[u][v] > l)
                map[u][v] = map[v][u] = l;
        }
        for (int i = 1;i <= n;i++)
        {
            dis[i] = map[1][i];
            pre[i] = 1;
        }
        dis[1] = 0;
        memset(visit, false, sizeof(visit));
        visit[1] = true;
        for (int k = 1;k < n;k++)
        {
            int u = 0;
            int min = 1992100500;
            for (int i = 1;i <= n;i++)
                if (!visit[i] && dis[i] != -1 && dis[i] < min)
                {
                    min = dis[i];
                    u = i;
                }
            visit[u] = true;
            for (int i = 1;i <= n;i++)
                if (!visit[i] && map[u][i] != -1 && (dis[i] == -1 || dis[i] > dis[u]+map[u][i]))
                {
                    dis[i] = dis[u] + map[u][i];
                    pre[i] = u;
                }
        }
        int res;
        bool two;
        int n1,n2;
        n1 = 1;
        two = false;
        res = 0;
        for (int i = 1;i <= n;i++)
        if (res < dis[i])
        {
            res = dis[i];
            n1 = i;
        }
        for (int i = 1;i <= n;i++)
        for (int j = i+1;j <= n;j++)
        if (pre[i] != j && pre[j] != i && map[i][j] != -1)
        {
            if (abs(dis[i]-dis[j]) < map[i][j])
            {
                if (res <= max(dis[i],dis[j])+(map[i][j]-abs(dis[i]-dis[j])-1)/2)
                {
                    res = max(dis[i],dis[j])+(map[i][j]-abs(dis[i]-dis[j])-1)/2;
                    n1 = i;
                    n2 = j;
                    two = true;
                }
            }
        }
        ft++;
        printf("System #%d\n",ft);
        if (two == true)
            printf("The last domino falls after %d.5 seconds, between key dominoes %d and %d.\n\n",res,n1,n2);
        else
            printf("The last domino falls after %d.0 seconds, at key domino %d.\n\n",res,n1);
    }
}
