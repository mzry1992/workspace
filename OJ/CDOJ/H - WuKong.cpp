#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int g[301][301],len[301][301];
int n,m,sa,ea,sb,eb;

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        memset(len,0,sizeof(len));
        memset(g,-1,sizeof(g));
        for (int i = 1;i <= m;i++)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            if (g[u][v] == -1 || g[u][v] > d)
            {
                g[u][v] = g[v][u] = d;
                len[u][v] = len[v][u] = 2;
            }
        }
        for (int i = 1;i <= n;i++)
        {
            g[i][i] = 0;
            len[i][i] = 1;
        }
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                    if (g[i][k] != -1 && g[k][j] != -1)
                    {
                        if (g[i][j] == -1)
                        {
                            g[i][j] = g[i][k]+g[k][j];
                            len[i][j] = len[i][k]+len[k][j]-1;
                        }
                        else if (g[i][j] > g[i][k]+g[k][j])
                        {
                            g[i][j] = g[i][k]+g[k][j];
                            len[i][j] = len[i][k]+len[k][j]-1;
                        }
                        else if (g[i][j] == g[i][k]+g[k][j] && len[i][j] < len[i][k]+len[k][j]-1)
                            len[i][j] = len[i][k]+len[k][j]-1;
                    }
        scanf("%d%d%d%d",&sa,&ea,&sb,&eb);
        int res = 0;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (g[sa][i]+g[i][j]+g[j][ea] == g[sa][ea])
                {
                    if (g[sb][i]+g[i][j]+g[j][eb] == g[sb][eb])
                        res = max(res,len[i][j]);
                    if (g[eb][i]+g[i][j]+g[j][sb] == g[eb][sb])
                        res = max(res,len[i][j]);
                }
        printf("%d\n",res);
    }
}
