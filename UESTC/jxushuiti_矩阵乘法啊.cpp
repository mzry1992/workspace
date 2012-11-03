#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    int a,b,c;
    int ma[20][20],mb[20][20],mc[20][20];
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&a,&b,&c);
        for (int i = 1;i <= a;i++)
        for (int j = 1;j <= b;j++)
            scanf("%d",&ma[i][j]);
        for (int i = 1;i <= b;i++)
        for (int j = 1;j <= c;j++)
            scanf("%d",&mb[i][j]);
        memset(mc,0,sizeof(mc));
        for (int i = 1;i <= a;i++)
        for (int k = 1;k <= b;k++)
        for (int j = 1;j <= c;j++)
            mc[i][j] += ma[i][k]*mb[k][j];
        for (int i = 1;i <= a;i++)
        {
            for (int j = 1;j <= c;j++)
                printf("%d ",mc[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}
