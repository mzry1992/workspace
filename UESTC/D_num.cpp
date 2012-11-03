#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#define bint long long
using namespace std;

const int TIME = 8;
bint factor[100];
int totfac;

bint gcd(bint small,bint big)
{
    while (small)
    {
        swap(small,big);
        small %= big;
    }
    return abs(big);
}

bint muti_mod(bint a,bint b,bint n)
{
    bint exp = a%n,res = 0;
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

bint mod_exp(bint a,bint p,bint m)
{
    bint exp = a%m,res = 1;
    while (p > 1)
    {
        if (p&1)
            res = muti_mod(res,exp,m);
        exp = muti_mod(exp,exp,m);
        p >>= 1;
    }
    return muti_mod(res,exp,m);
}

bool miller_rabin(bint n,int times)
{
    if (n==2)   return 1;
    if (n<2 || !(n&1))  return 0;
    bint a,u = n-1,x,y;
    int t = 0;
    while (u%2 == 0)
    {
        t++;
        u /= 2;
    }
    srand(19930703);
    for (int i = 0;i < times;i++)
    {
        a = rand()%(n-1)+1;
        x = mod_exp(a,u,n);
        for (int j = 0;j < t;j++)
        {
            y = muti_mod(x,x,n);
            if (y == 1 && x != 1 && x != n-1)
                return false;
            x = y;
        }
        if (y != 1) return false;
    }
    return true;
}

bint pollar_rho(bint n,int c)
{
    bint x,y,d,i = 1,k = 2;
    srand(19921005);
    x = rand()%(n-1)+1;
    y = x;
    while (true)
    {
        i++;
        x = (muti_mod(x,x,n)+c)%n;
        d = gcd(y-x,n);
        if (1<d&&d<n)   return d;
        if (y == x) return n;
        if (i == k)
        {
            y = x;
            k <<= 1;
        }
    }
}

void findFactor(bint n,int k)
{
    if (n == 1) return;
    if (miller_rabin(n,TIME))
    {
        factor[totfac++] = n;
        return;
    }
    bint p = n;
    while (p >= n)
        p = pollar_rho(p,k--);
    findFactor(p,k);
    findFactor(n/p,k);
}

bint n;

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%I64d",&n);
        totfac = 0;
        findFactor(n,107);
        for (int i = 0;i < totfac;i++)
            printf("%I64d ",factor[i]);
        printf("\n");
    }
}
