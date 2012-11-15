#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 310;
int mp[maxn][maxn];
int n;

void contract(int x,int y)
{
    for (int i = 0;i < n;i++)
        if (i != x)
        {
            mp[x][i] += mp[y][i];
            mp[i][x] += mp[i][y];
        }
    for (int i = y+1;i < n;i++)
        for (int j = 0;j < n;j++)
        {
            mp[i-1][j] = mp[i][j];
            mp[j][i-1] = mp[j][i];
        }
    n--;
}

int w[maxn],c[maxn];
int sx,tx;

int mincut()
{
    memset(c,0,sizeof(c));
    c[0] = 1;
    for (int i = 0;i < n;i++)
        w[i] = mp[0][i];
    int k,t;
    for (int i = 1;i+1 < n;i++)
    {
        t = k = -1;
        for (int j = 0;j < n;j++)
            if (c[j] == 0 && w[j] > k)
                k = w[t=j];
        c[sx=t] = 1;
        for (int j = 0;j < n;j++)
            w[j] += mp[t][j];
    }
    for (int i = 0;i < n;i++)
        if (c[i] == 0)
            return w[tx=i];
}

int m,u,v,cc;

int main()
{
    while (true)
    {
        scanf("%d%d%*d",&n,&m);
        if (n == 0) break;
        memset(mp,0,sizeof(mp));
        for (int i = 0;i < m;i++)
        {
            scanf("%d%d%d",&u,&v,&cc);
            u--;
            v--;
            mp[u][v] += cc;
            mp[v][u] += cc;
        }
        int mint = 1992100500;
        while (n > 1)
        {
            cc = mincut();
            if (cc < mint)
                mint = cc;
            contract(sx,tx);
        }
        printf("%d\n",mint);
    }
    return 0;
}
