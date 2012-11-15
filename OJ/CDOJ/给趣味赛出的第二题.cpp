#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n,m;
int a[30][30];
char map[310][310];

inline void put(int x,int y)
{
    map[x][y] = '+';map[x][y+1] = '-';map[x][y+2] = '+';
    map[x-1][y] = '|';map[x-1][y+1] = ' ';map[x-1][y+2] = '|';map[x-1][y+3] = '/';
    map[x-2][y] = '+';map[x-2][y+1] = '-';map[x-2][y+2] = '+';map[x-2][y+3] = ' ';map[x-2][y+4] = '+';
    map[x-3][y+1] = '/';map[x-3][y+2] = ' ';map[x-3][y+3] = '/';map[x-3][y+4] = '|';
    map[x-4][y+2] = '+';map[x-4][y+3] = '-';map[x-4][y+4] = '+';
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                scanf("%d",&a[i][j]);
        for (int i = 0;i <= 200;i++)
            for (int j = 0;j <= 200;j++)
                map[i][j] = ' ';
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                for (int k = 1;k <= a[i][j];k++)
                    put(200-2*(n-i+k-1),2*(n-i+j-1));
        int mx,my,tx,ty;
        mx = 200;
        my = 0;
        tx = 0;
        ty = 200;
        for (int i = 0;i <= 200;i++)
            for (int j = 0;j <= 200;j++)
                if (map[i][j] != ' ')
                {
                    if (mx > i) mx = i;
                    if (my < j) my = j;
                    if (tx < i) tx = i;
                    if (ty > j) ty = j;
                }
        for (int i = mx;i <= tx;i++)
        {
            for (int j = ty;j <= my;j++)
                putchar(map[i][j]);
            puts("");
        }
    }
}
