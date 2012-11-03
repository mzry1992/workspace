#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,q,a[300];
int t,b,l,r,tot,id,curmax,dif;
int sum[300];

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        tot = (min(n,m)+1)/2;
        for (int i = 0; i < tot; i++)
            scanf("%d",&a[i]);
        scanf("%d",&q);
        for (int fq = 0; fq < q; fq++)
        {
            scanf("%d%d%d%d",&t,&l,&b,&r);
            for (int i = 1; i <= 250; i++)
                sum[i] = 0;
            for (int i = 0; i < tot; i++)
            {
                id = a[i];
                if (i != n-1-i && i != m-1-i)
                {
                    //(i,i) - (i,m-1-i-1)
                    if (t <= i && i <= b)
                        if (!((i > r) || (m-1-i-1 < l)))
                            sum[id] += min(m-1-i-1,r)-max(i,l)+1;
                    //(i,m-1-i) - (n-1-i-1,m-1-i)
                    if (l <= m-1-i && m-1-i <= r)
                        if (!((i > b) || (n-1-i-1 < t)))
                            sum[id] += min(n-1-i-1,b)-max(i,t)+1;
                    //(i+1,i) - (n-1-i,i)
                    if (l <= i && i <= r)
                        if (!((i+1 > b) || (n-1-i < t)))
                            sum[id] += min(n-1-i,b)-max(i+1,t)+1;
                    //(n-1-i,i+1) - (n-1-i,m-1-i)
                    if (t <= n-1-i && n-1-i <= b)
                        if (!((i+1 > r) || (m-1-i < l)))
                            sum[id] += min(m-1-i,r)-max(i+1,l)+1;
                }
                else if (i == n-1-i)
                {
                    //(i,i) - (i,m-i-1)
                    if (t <= i && i <= b)
                        if (!((i > r) || (m-i-1 < l)))
                            sum[id] += min(m-i-1,r)-max(i,l)+1;
                }
                else if (i == m-1-i)
                {
                    //(i,i) - (n-1-i,i)
                    if (l <= i && i <= r)
                        if (!((i > b) || (n-1-i < t)))
                            sum[id] += min(n-1-i,b)-max(i,t)+1;
                }
            }
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
