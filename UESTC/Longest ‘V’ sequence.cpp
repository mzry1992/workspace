#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[1000][1000],g1[1000][1000],g2[1000][1000];

void Gao(int x,int y)
{
    if (x >= n || y >= m)   return;
    if (x-1 < 0 || y-1 < 0)
        g1[x][y] = a[x][y];
    else
        g1[x][y] = (a[x][y] == 1)?(g1[x-1][y-1]+1):0;
    Gao(x+1,y+1);
}

void GaoGao(int x,int y)
{
    if (x >= n || y < 0)   return;
    if (x-1 < 0 || y+1 >= m)
        g2[x][y] = a[x][y];
    else
        g2[x][y] = (a[x][y] == 1)?(g2[x-1][y+1]+1):0;
    GaoGao(x+1,y-1);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                scanf("%d",&a[i][j]);
        for (int i = 0;i < n;i++)
            Gao(i,0);
        for (int j = 0;j < m;j++)
            Gao(0,j);
        for (int i = 0;i < n;i++)
            GaoGao(i,m-1);
        for (int j = 0;j < m;j++)
            GaoGao(0,j);
        int res = -1;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (a[i][j] == 1 && g1[i][j] > 1 && g2[i][j] > 1)
                    res = max(res,g1[i][j]+g2[i][j]-1);
        printf("%d\n",res);
    }
    return 0;
}
