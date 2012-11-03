#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
int a[100100];
int td[100100];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        memset(td,0,sizeof(td));
        long long sum = 0;
        for (int i = 1;i <= n;i++)
        {
            sum += a[i];
            td[sum%m]++;
        }
        long long res = 0;
        res = td[0];
        for (int i = 0;i < m;i++)
            if (td[i] >= 2)
                res += (long long)(td[i]-1)*(long long)(td[i])/2;
        printf("Case #%d: %lld\n",ft,res);
    }
}
