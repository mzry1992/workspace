#include <iostream>
#include <cstdio>
using namespace std;

int n,a,b,c,m,k;
long long s[2000000];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d%d%d%d",&n,&a,&b,&c,&m,&k);
        s[1] = a;
        s[2] = b;
        for (int i = 3;i <= n;i++)
            s[i] = ((long long)(s[i-2]*s[i-1]+c))%m;
        long long res = 0;
        long long sum = 0;
        int l = 1;
        for (int i = 1;i <= n;i++)
        {
            sum += s[i];
            while (sum >= k)
            {
                sum -= s[l];
                l++;
                if (l > i)  break;
            }
            res += (i-l+1);
        }
        printf("Case #%d: %lld\n",ft,res);
    }
}
