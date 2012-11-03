#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,c,m;
int a[120];
int map[120][120];

int main()
{
    while (scanf("%d%d",&n,&c) != EOF)
    {
        for (int i = 1;i <= c;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        memset(map,0,sizeof(map));
        for (int i = 1;i <= m;i++)
        {
            int tu,tv,tc;
            scanf("%d%d%d",&tu,&tv,&tc);
            map[tu][tv] = tc;
        }
        for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
        if (k != i)
        if (k != j)
        if (i != j)
        if (map[i][k] != 0)
        if (map[k][j] != 0)
        {
            if (map[i][j] == 0) map[i][j] = map[i][k]+map[k][j];
            else
                if (map[i][j] > map[i][k]+map[k][j])
                    map[i][j] = map[i][k]+map[k][j];
        }
        int res,pos;
        res = 19921005;
        pos = 0;
        for (int i = 1;i <= c;i++)
        for (int j = 1;j <= n;j++)
        if (a[i] != j)
        if (map[a[i]][j] != 0)
        if (map[j][a[i]] != 0)
        if (res > map[a[i]][j]+map[j][a[i]])
        {
            res = map[a[i]][j]+map[j][a[i]];
            pos = a[i];
        }
        if (pos == 0)
            printf("I will nerver go to that city!\n");
        else
            printf("%d\n",pos);
    }
}

