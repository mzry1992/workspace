#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long a[1200];
long long sum,res;
const long long mod = 1000000007LL;

///O(m) p is prime number, p*p < INT_MAX
///O(m)
///p is prime and p^k < INT_MAX
long long extended_gcd (long long a, long long b, long long &x, long long  &y);
long long  power2 (long long  x, long long k);
long long  combination_Mod_pk (long long  n, long long  m)
{
    const long long p = mod;
    const long long k = 1;
    if (m > n) return 0;
    m = (n - m < m) ? n - m : m;
    long long  a = 1, b = 1, x, y, pa = 1, pb = 1, pcnt = 0;
    long long  q = power2(p, k);
    for (int i = 1; i <= m; i++)
    {
        a *= n - i + 1, b *= i;
        while(a % p == 0) pa *= p, a /= p;
        while(b % p == 0) pb *= p, b /= p;
        while (pa % q == 0) pa /= q, pcnt++;
        while (pb % q == 0) pb /= q, pcnt--;
        b %= q, a %= q;
    }
    if(pa < pb) pcnt--, pa *= q;
    pa /= pb, a *= pa, a %= q;
    if (pcnt) return 0;
    extended_gcd(b, q, x, y);
    if (x < 0) x += q;
    x *= a, x %= q;
    return x;
}
/**
  * Extended Euclid's Algorithm
  * ax+by=gcd(a,b);
  **/
long long extended_gcd (long long a, long long b, long long &x, long long  &y)
{
    if (!b)
        return x = 1, y = 0, a;
    long long  ret = extended_gcd (b, a % b, x, y), tmp = x;
    x = y, y = tmp - (a / b) * y;
    return ret;
}
long long  power2 (long long  x, long long k)
{
    int result = 1;
    while (k)
    {
        if (k & 1)
            result *= x;
        x *= x, k >>= 1;
    }
    return result;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%lld",&a[i]);
        res = 1;
        sum = a[1];
        for (int i = 2;i <= n;i++)
        {
            sum += a[i];
            res = (res*combination_Mod_pk(sum-1,a[i]-1))%mod;
        }
        printf("Case %d: %lld\n",ft,res);

    }
}

