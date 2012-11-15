#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double map[110][110];
double a[110][110];
int n,m,x,y,r;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof(map));
        memset(a,0,sizeof(a));
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&x,&y,&r);
            if (map[x][y] == 0.0)
                map[x][y] = map[y][x] = (double)r;
            else
                map[x][y] = map[y][x] = ((double)r*map[x][y])/((double)r+map[x][y]);
        }
        m = n+1;
        a[1][m] = 1.0;
        a[n][n] = 1.0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= n; j++)
                if (map[i][j] != 0)
                {
                    a[i][i] += 1/map[i][j];
                    a[i][j] += -1/map[i][j];
                }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                if (j != i)
                    if (a[j][i] != 0)
                    {
                        double temp = a[j][i]/a[i][i];
                        for (int k = 1; k <= m; k++)
                            a[j][k] = a[j][k]-a[i][k]*temp;
                    }
        }
        printf("Case #%d: %.2lf\n",ft,a[1][m]/a[1][1]);
    }
    return 0;
}
