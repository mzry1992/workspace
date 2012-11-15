#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n,m;
char map[20][20];

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)
            break;
        for (int i = 0;i <= 20;i++)
        for (int j = 0;j <= 20;j++)
            map[i][j] = '#';
        char ts[20];
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",ts);
            for (int j = 1;j <= m;j++)
                map[i][j] = ts[j-1];
        }
    }
}
