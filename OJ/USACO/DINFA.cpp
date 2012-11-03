#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int map[300][300];
int n;

int main()
{
    freopen("DINFA.txt","w",stdout);
    srand(19921005);
    for (int ft = 1;ft <= 200;ft++)
    {
        memset(map,0,sizeof(map));
        n = rand()%10+1;
        printf("%d\n",n);
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        if (i != j)
        {
            map[i][j] = (rand()%50==49?1:0);
        }
        else map[i][j] = 1;
        for (int k = 0;k < n;k++)
        for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        if (k != i)
        if (k != j)
        if (i != j)
        if (map[i][k] == 1 && map[k][j] == 1)
            map[i][j] = 1;
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
                printf("%d ",map[i][j]);
            printf("\n");
        }
    }
}
