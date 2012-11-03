#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
double g[20][20],f[1<<16];

double dp(int x)
{
    if (f[x] >= 0.0)    return f[x];
    f[x] = 0.0;
    for (int i = 1;i <= n;i++)
        if (((x>>(i-1))&1) == 1)
            for (int j = 1;j <= n;j++)
                if (((x>>(j-1))&1) == 1)
                {
                    int y = (x^((i-1)<<1))^((j-1)<<1);
                    if (f[x] < f[y]+g[i][j])    f[x] = f[y]+g[i][j];
                }
    return f[x];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                scanf("%lf",&g[i][j]);
        for (int i = 0;i < (1<<n);i++)  f[i] = -1.0;
        f[0] = 0;
        printf("%.2f\n",dp((1<<n)-1));
    }
}
