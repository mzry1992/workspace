#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int n,m,q,a[300];
int t,b,l,r,tot;
int sum[300];

int main()
{
    freopen("parterre.in","w",stdout);
    for (int ft = 1;ft <= 100;ft++)
    {
        n = rand()%100+1;
        m = rand()%100+1;
        printf("%d %d\n",n,m);
        tot = (min(n,m)+1)/2;
        for (int i = 0; i < tot; i++)
        {
            a[i] = rand()%250+1;
            printf("%d\n",a[i]);
        }
        q = 10;
        printf("%d\n",q);
        for (int fq = 0; fq < q; fq++)
        {
            while (true)
            {
                t = rand()%n;
                l = rand()%m;
                b = rand()%n;
                r = rand()%m;
                if (t > b || l > r) continue;
                printf("%d %d %d %d\n",t,l,b,r);
                break;
            }
        }
    }
    return 0;
}

