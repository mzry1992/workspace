#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,m;
    int map[200][200];
    while (scanf("%d%d",&n,&m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            map[i][j] = 19930703;
        for (int i = 1;i <= m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            map[u][v] = map[v][u] = w;
        }
        for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
        if (i != k && k != j)
        if (map[i][j] > map[i][k]+map[k][j])
            map[i][j] = map[i][k]+map[k][j];
        printf("%d\n",map[1][n]);
    }
}
