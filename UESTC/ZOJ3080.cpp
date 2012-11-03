#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int map[1200][1200];
int w[1200];
int n;
int blocks[1200];
int totb;

void DFS(int now)
{
    if (blocks[now] != 0)
        return;
    blocks[now] = totb;
    for (int i = 1;i <= n;i++)
        if (map[now][i] >= 0)
            DFS(i);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            scanf("%d",&map[i][j]);
        for (int i = 1;i <= n;i++)
            scanf("%d",&w[i]);
        for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
        if (map[i][k] != -1)
        if (map[k][j] != -1)
        if (map[i][j] > map[i][k]+map[k][j])
            map[i][j] = map[i][k]+map[k][j];
        memset(blocks,0,sizeof(blocks));
        totb = 0;
        for (int i = 1;i <= n;i++)
        if (blocks[i] == 0)
        {
            totb++;
            DFS(i);
        }
        int res = 0;
        for (int i = 1;i <= totb;i++)
        {
            int tmin = 19930703;
            for (int j = 1;j <= n;j++)
                if (blocks[j] == i)
                {
                    int tmax = 0;
                    for (int k = 1;k <= n;k++)
                        if (blocks[k] == i)
                            if (map[j][k] > tmax)
                                tmax = map[j][k];
                    if (tmax+w[j] < tmin)
                        tmin = tmax+w[j];
                }
            if (tmin > res)
                res = tmin;
        }
        printf("%d\n",res);
    }
}
