#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,mp[100][100];

void contract(int x,int y)
{
    for (int i = 0;i < n;i++)
        if (i != x)
            mp[x][i] += mp[y][i],mp[i][x] += mp[i][y];
    for (int i = y+1;i < n;i++)
        for (int j = 0;j < n;j++)
        {
            mp[i-1][j] = mp[i][j];
            mp[j][i-1] = mp[j][i];
        }
    n--;
}

int w[100],c[100],sx,tx;

int mincut()
{
    memset(c,0,sizeof(c));
    c[0] = 1;
    for (int i = 0;i < n;i++)
        w[i] = mp[0][i];

}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        memset(mp,0,sizeof(mp));
        for (int i = 0;i < m;i++)
        {
            int u,v;
            scanf("(%d,%d)",&u,&v);
            mp[u][v] += 1;
            mp[v][u] += 1;
        }
        int mint = 999999999;
        while (n > 1)
        {
            int k = mincut();
            if (k < mint)   mint = k;
            contract(sx,tx);
        }
        printf("%d\n",mint);
    }
	return 0;
}
