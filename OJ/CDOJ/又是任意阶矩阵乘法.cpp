#include <iostream>
#include <cstdio>
using namespace std;

int a,b,c;
int d[500][500],e[500][500],f[500][500];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&a,&b,&c);
        for (int i = 1;i <= a;i++)
        for (int j = 1;j <= b;j++)
            scanf("%d",&d[i][j]);
        for (int i = 1;i <= b;i++)
        for (int j = 1;j <= c;j++)
            scanf("%d",&e[i][j]);
        for (int i = 1;i <= a;i++)
        {
            for (int j = 1;j <= c;j++)
            {
                f[i][j] = 0;
                for (int k = 1;k <= b;k++)
                    f[i][j] += d[i][k]*e[k][j];
                printf("%d ",f[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
