#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,s;
char mp[30][30];

int Gao()
{
    int tot = 0;
    for (int x = 1; x < n-1; x++)
        for (int y = 1; y < m-1; y++)
            if ((x+y+1)&1)
            {
                mp[x][y] = '#';
                tot++;
                if (tot == s)   return tot;
            }
    return tot;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%d%d",&n,&m,&s);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mp[i][j] = '.';
        int res = Gao();
        if (res < s)
            puts("Impossible");
        else
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    putchar(mp[i][j]);
                puts("");
            }
        }
        if (ft != t)
            puts("");
    }
    return 0;
}
