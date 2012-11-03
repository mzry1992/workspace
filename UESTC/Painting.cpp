#include <iostream>
#include <cstdio>
using namespace std;

int n,m,map[20][20];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            scanf("%d",&map[i][j]);
        int tot = 0;
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
        {
            if (map[i][j] > 0)  tot++;
            for (int k = 1;k <= map[i][j];k++)
            {
                tot += 6;
                tot -= 2;
                if (i > 1)
                    if (map[i-1][j] >= k)   tot -= 2;
                if (j > 1)
                    if (map[i][j-1] >= k)   tot -= 2;
            }
        }
        printf("Case #%d: %d\n",ft,tot);
    }
}
