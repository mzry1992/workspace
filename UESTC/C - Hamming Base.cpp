#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int g[2100][20];
int tot[2100];
int xx[2100],tt;

int aabs(int x)
{
    if (x < 0)  return -x;
    return x;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            scanf("%d",&g[i][j]);
        int res = 0;
        for (int j = 1;j <= m;j++)
        {
            memset(tot,0,sizeof(tot));
            for (int i = 1;i <= n;i++)
                tot[g[i][j]]++;
            tt = 0;
            for (int i = 0;i < n;i++)
            if (tot[i] == 0)
            {
                tt++;
                xx[tt] = i;
            }
            int uu = 1;
            for (int i = 0;i < n;i++)
            if (tot[i] > 1)
            for (int kk = 2;kk <= tot[i];kk++)
            {
                res += aabs(i-xx[uu]);
                uu++;
            }
        }
        printf("Case %d: %d\n",ft,res);
    }
}
