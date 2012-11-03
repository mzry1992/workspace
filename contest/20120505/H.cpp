#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long mut(long long x,long long y,long long mod)
{
    long long ret=0;
    for (long long a=x%mod; y; y>>=1,a=(a+a)%mod)
        if (y&1)
            ret=(ret+a)%mod;
    return ret;
}

long long power(long long x,long long y,long long mod)
{
    long long ret=1;
    for (long long a=x%mod; y; y>>=1,a=mut(a,a,mod))
        if (y&1)
            ret = mut(ret,a,mod);
    return ret;
}

long long n,b,d,m;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%lld%lld%lld%lld",&n,&b,&d,&m);
        long long tb = b-1;
        long long mod = tb*m;
        long long a = d*(power(b,n,mod)-1+mod)%mod;
        a /= tb;
        printf("Case %d: %lld\n",cas,a);
    }
    return 0;
}
