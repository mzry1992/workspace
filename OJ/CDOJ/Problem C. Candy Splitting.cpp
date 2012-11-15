#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long c[1200];
int dig[40];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("AAAAAA.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        long long sum = 0;
        long long minc = 19921005LL;
        memset(dig,0,sizeof(dig));
        for (int i = 1;i <= n;i++)
        {
            scanf("%lld",&c[i]);
            for (int j = 1;j <= 32;j++)
            if (((c[i]>>(j-1))&1) == 1)
                dig[j]++;
            sum += c[i];
            if (c[i] < minc)    minc = c[i];
        }
        bool hasres = true;
        for (int i = 1;i <= 32;i++)
        if (dig[i]%2 != 0)
        {
            hasres = false;
            break;
        }
        if (hasres == false)
            printf("Case #%d: NO\n",ft);
        else
        {
            long long res = sum-minc;
            printf("Case #%d: %lld\n",ft,res);
        }
    }
}
