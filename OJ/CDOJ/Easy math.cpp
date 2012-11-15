#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

long long muti_mod(long long a,long long b,long long n)
{
    long long exp = a%n,res = 0;
    while (b)
    {
        if (b&1)
        {
            res += exp;
            if (res > n)    res -= n;
        }
        exp <<= 1;
        if (exp > n)    exp -= n;
        b >>= 1;
    }
    return res;
}

long long mod_exp(long long a,long long p,long long m)
{
    long long exp = a%m,res = 1;
    while (p > 1)
    {
        if (p&1)
            res = muti_mod(res,exp,m);
        exp = muti_mod(exp,exp,m);
        p >>= 1;
    }
    return muti_mod(res,exp,m);
}

const long long mod = 1000000007LL;
const long long phi = 1000000006LL;
long long a,b,c,e;

int main()
{
    while (scanf("%lld%lld%lld",&a,&b,&c) != EOF)
    {
        if ((double)c*log((double)b) > log((double)phi))
            e = mod_exp(b,c,phi)+phi;
        else
            e = mod_exp(b,c,phi);
        printf("%lld\n",mod_exp(a,e,mod));
    }
}
