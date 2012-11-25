#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const long long mod = 100000007LL;
long long ni[300000];

long long power(long long x,long long y)
{
    long long ret = 1;
    for (long long a = x%mod;y;y>>=1,a=a*a%mod)
        if (y&1)
            ret = ret*a%mod;
    return ret;
}

long long getInv(long long x)
{
    return power(x,mod-2);
}

long long c(int a,int b)
{
    return ni[a]*getInv(ni[b])%mod*getInv(ni[a-b])%mod;
}

int m,n,p,q;

int main()
{
    ni[0] = 1;
    for (int i = 1;i < 300000;i++)
        ni[i] = ni[i-1]*i%mod;
    while (scanf("%d%d%d%d",&n,&m,&p,&q) != EOF)
    {
        p = n-p;
        printf("%lld\n",(c(n+m,n)*c(p+q,p)%mod-c(n+q,n)*c(m+p,p)%mod+mod)%mod);
    }
    return 0;
}
