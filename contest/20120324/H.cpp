#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char ma[1100][1100],mb[1100][1100],tmp[1100][1100];

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%s",ma[i]);
        for (int i = 0;i < n;i++)
            scanf("%s",mb[i]);
        for (int i = 0;i < 4;i++)
        {
            for (int x = 0;x < n;x++)
                for (int y = 0;y < n;y++)
                    if (ma[x][y] == 'O')
                        printf("%c",mb[x][y]);
            for (int x = 0;x < n;x++)
                for (int y = 0;y < n;y++)
                    tmp[y][n-x-1] = ma[x][y];
            for (int x = 0;x < n;x++)
                for (int y = 0;y < n;y++)
                    ma[x][y] = tmp[x][y];
        }
        puts("");
    }
	return 0;
}
