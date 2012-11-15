#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,neg;
long long a[100000],m;

void Gaoneg()
{
    if (neg%2 == 0) return;
    //有奇数个负数
    if (a[neg-1]+m >= 0) //能加到0
    {
        m += a[neg-1];
        a[neg-1] = 0;
        neg--;
        return;
    }
    else
    {
        a[neg-1] += m;
        m = 0;
        return;
        if (neg == 1) //只有一个
        {
            m = 0;
            a[0] += m;
            return;
        }
        else //多个
        {
            long long nowmin;
            int totmin;
            nowmin = a[0];
            totmin = 1;
            for (int i = 1; i < neg; i++)
            {
                if ((a[i]-nowmin)*totmin <= m)
                {
                    m -= (a[i]-nowmin)*totmin;
                    nowmin = a[i];
                    totmin++;
                }
                else
                {
                    long long tims = m/totmin;
                    nowmin += tims;
                    m -= tims*totmin;
                    for (int j = 0; j < i; j++)
                        a[j] = nowmin;
                    if (m == 0)
                        return;
                    else
                    {
                        for (int j = 0; j < m; j++)
                            a[j]++;
                        m = 0;
                        return;
                    }
                }
            }
            long long tims = m/totmin;
            nowmin += tims;
            m -= tims*totmin;
            for (int j = 0; j < neg; j++)
                a[j] = nowmin;
            if (m == 0)
                return;
            else
            {
                for (int j = 0; j < m; j++)
                    a[j]++;
                m = 0;
                return;
            }
        }
    }
}

long long tot2,tot3;

void Gaopos()
{
    if (m == 0) return;
    //先把0添成1
    for (int i = neg; i < n; i++)
    {
        if (a[i] == 0)
        {
            a[i]++;
            m--;
            if (m == 0) return;
        }
    }
    //把1添成2
    for (int i = neg; i < n; i++)
    {
        if (a[i] == 1)
        {
            a[i]++;
            m--;
            if (m == 0) return;
        }
    }
    //把2添成3
    for (int i = neg; i < n; i++)
    {
        if (a[i] == 2)
        {
            a[i]++;
            m--;
            if (m == 0) return;
        }
    }
    //无限添2和3
    tot3 = m/3;
    m -= tot3*3;
    tot2 = m/2;
    m -= tot2*2;
    if (m == 0) return;
    if (m == 1)
    {
        m = 0;
        if (tot3 > 0)
        {
            tot3--;
            tot2 += 2;
            return;
        }
        else
        {
            if (neg == n)   return;
            a[neg]++;
            return;
        }
    }
}

const long long mod = 1000000007LL;

long long power(long long x,long long y)
{
    long long ret=1;
    for (long long a=x%mod; y; y>>=1,a=a*a%mod)
        if (y&1)
            ret=ret*a%mod;
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d%I64d",&n,&m);
        for (int i = 0; i < n; i++)
            scanf("%I64d",&a[i]);
        sort(a,a+n);
        for (neg = 0; neg < n && a[neg] < 0; neg++);
        //处理负数
        Gaoneg();
        //处理正数
        sort(a,a+n);
        for (neg = 0; neg < n && a[neg] < 0; neg++);
        tot2 = tot3 = 0;
        Gaopos();
        long long res = 1;
        for (int i = 0;i < n;i++)
            res = (res*a[i])%mod;
        res = (res*power(2,tot2))%mod;
        res = (res*power(3,tot3))%mod;
        /*cout << "Gao : " << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
        cout << tot2 << ' ' << tot3 << endl;*/
        printf("Case %d: %I64d\n",ft,res);
    }
    return 0;
}
