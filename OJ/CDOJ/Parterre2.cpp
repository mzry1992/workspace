#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,q,a[300];
int t,b,l,r,tot,id,curmax,dif;
int sum[300],mp[600][600];

int main()
{
    freopen("parterre.in","r",stdin);
    freopen("parterre2.out","w",stdout);
    while (scanf("%d%d",&n,&m) != EOF)
    {
        tot = (min(n,m)+1)/2;
        for (int i = 0; i < tot; i++)
        {
            scanf("%d",&a[i]);
            for (int j = i;j <= m-1-i;j++)
                mp[n-1-i][j] = mp[i][j] = a[i];
            for (int j = i;j <= n-1-i;j++)
                mp[j][i] = mp[j][m-1-i] = a[i];
        }
        scanf("%d",&q);
        for (int fq = 0; fq < q; fq++)
        {
            scanf("%d%d%d%d",&t,&l,&b,&r);
            for (int i = 1; i <= 250; i++)
                sum[i] = 0;
            for (int i = t;i <= b;i++)
                for (int j = l;j <= r;j++)
                    sum[mp[i][j]]++;
            curmax = dif = 0;
            for (int i = 1; i <= 250; i++)
            {
                curmax = max(curmax,sum[i]);
                if (sum[i] > 0)
                    dif++;
            }
            printf("%d ",dif);
            for (int i = 1; i <= 250; i++)
                if (curmax == sum[i])
                {
                    printf("%d %d\n",i,curmax);
                    break;
                }
        }
    }
    return 0;
}

