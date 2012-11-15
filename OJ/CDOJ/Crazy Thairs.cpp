#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[60000],ls[60000],MaxN;
long long a1[60000],a2[60000],a3[60000],a4[60000];
struct gjd
{
    long long a[5];
}a5[60000];

long long read(int k,long long tree[])
{
    if (k == 0) return 0;
    long long sum = 0;
    while (k > 0)
    {
        sum += tree[k];
        k -= k & -k;
    }
    return sum;
}

void updata(int k,long long v,long long tree[])
{
    while (k <= MaxN)
    {
        tree[k] += v;
        k += k & -k;
    }
}

const long long mod = 1000000000LL;

gjd add(gjd a,gjd b)
{
    gjd res;
    memset(res.a,0,sizeof(res.a));
    for (int i = 0;i < 5;i++)
        res.a[i] = a.a[i]+b.a[i];
    for (int i = 0;i < 4;i++)
    {
        res.a[i+1] += res.a[i]/mod;
        res.a[i] %= mod;
    }
    return res;
}

gjd add2(gjd a,long long b)
{
    gjd res;
    memset(res.a,0,sizeof(res.a));
    for (int i = 0;i < 5;i++)
    {
        res.a[i] = a.a[i]+b%mod;
        b /= mod;
    }
    for (int i = 0;i < 4;i++)
    {
        res.a[i+1] += res.a[i]/mod;
        res.a[i] %= mod;
    }
    return res;
}

void outnum(long long num)
{
    printf("%09lld",num);
}

void output(gjd a)
{
    for (int i = 4;i >= 0;i--)
    if (a.a[i] != 0)
    {
        printf("%lld",a.a[i]);
        for (int j = i-1;j >= 0;j--)
            outnum(a.a[j]);
        break;
    }
    printf("\n");
}

gjd read2(int k)
{
    gjd sum;
    memset(sum.a,0,sizeof(sum.a));
    if (k == 0) return sum;
    while (k > 0)
    {
        sum = add(sum,a5[k]);
        k -= k & -k;
    }
    return sum;
}

void updata2(int k,long long v)
{
    while (k <= MaxN)
    {
        a5[k] = add2(a5[k],v);
        k += k & -k;
    }
}

int main()
{
    while (scanf("%lld",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
        {
            scanf("%lld",&a[i]);
            ls[i] = a[i];
        }
        sort(ls+1,ls+1+n);
        ls[0] = ls[1]-1;
        int ttot = 0;
        for (int i = 1;i <= n;i++)
        if (ls[i] != ls[i-1])
        {
            ttot++;
            ls[ttot] = ls[i];
        }
        for (int i = 1;i <= n;i++)
        {
            int *pos = lower_bound(ls+1,ls+1+ttot,a[i]);
            a[i] = (int)(pos-ls);
        }
        MaxN = ttot;
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(a3,0,sizeof(a3));
        memset(a4,0,sizeof(a4));
        memset(a5,0,sizeof(a5));
        for (int i = 1;i <= n;i++)
        {
            updata(a[i],1LL,a1);
            updata(a[i],read(a[i]-1,a1),a2);
            updata(a[i],read(a[i]-1,a2),a3);
            updata(a[i],read(a[i]-1,a3),a4);
            updata2(a[i],read(a[i]-1,a4));
        }
        output(read2(MaxN));
    }
}
