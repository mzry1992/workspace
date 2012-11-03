#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;

const int TIME = 8;

long long factor[100];
int tot;

long long gcd(long long small,long long big)
{
    while (small)
    {
        swap(small,big);
        small %= big;
    }
    return abs(big);
}

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

bool miller_rabin(long long n,int times)
{
    if (n == 2) return true;
    if (n < 2 || !(n&1))    return false;
    long long a,u = n-1,x,y;
    int t = 0;
    while (u%2 == 0)
    {
        t++;
        u /= 2;
    }
    srand(time(0));
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

long long pollard_rho(long long n,int c)
{
    long long x,y,d,i=1,k=2;
    srand(time(0));
    x = rand()%(n-1)+1;
    y = x;
    while (true)
    {
        i++;
        x = (muti_mod(x,x,n)+c)%n;
        d = gcd(y-x,n);
        if (1 < d && d < n) return d;
        if (y == x) return n;
        if (i == k)
        {
            y = x;
            k <<= 1;
        }
    }
}

void findFactor(long long n,int k)
{
    if (n == 1) return;
    if (miller_rabin(n,TIME))
    {
        factor[tot++] = n;
        return;
    }
    long long p = n;
    while (p >= n)
        p = pollard_rho(p,k--);
    findFactor(p,k);
    findFactor(n/p,k);
}

long long k,n;
long long fac[100];
int num[100],dif;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%I64d%I64d",&n,&k);
        if (k == 1)
        {
            printf("Case %d: inf\n",ft);
            continue;
        }
        tot = 0;
        findFactor(k,107);
        sort(factor,factor+tot);
        fac[0] = factor[0];
        num[0] = 1;
        dif = 1;
        for (int i = 1;i < tot;i++)
            if (factor[i] != fac[dif-1])
            {
                fac[dif] = factor[i];
                num[dif] = 1;
                dif++;
            }
            else
                num[dif-1]++;
        long long ans=0x7fffffffffffffffLL;
        for (int i=0;i<dif;i++)
        {
            long long tmp=0;
            long long j = fac[i];
            while (true)
            {
                tmp += n/j;
                if ((double)j*fac[i] > n)   break;
                j *= fac[i];
            }
            if (ans>tmp/num[i])
                ans=tmp/num[i];
        }
        printf("Case %d: %I64d\n",ft,ans);
    }
    return 0;
}
