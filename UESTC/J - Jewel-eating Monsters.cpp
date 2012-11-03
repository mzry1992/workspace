#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long x,a,n,c;
const long long tmod = 10;

void output(long long a[])
{
    cout << "-------" << endl;
    cout << a[0] << endl;
    for (int i = a[0];i >= 1;i--)
        printf("%d",a[i]);
    printf("\n");
}

long long getlong(long long a[])
{
    for (int i = 99;i >= 1;i--)
        if (a[i] != 0)  return i;
    return 1;
}

int bigthen(long long a[],long long b[])
{
    if (a[0] > b[0])    return 0;
    if (a[0] < b[0])    return 2;
    for (int i = a[0];i >= 1;i--)
    {
        if (a[i] > b[i])    return 0;
        if (a[i] < b[i])    return 2;
    }
    return 1;
}

long long calc(long long ta,long long tb,long long mod)
{
    long long a[100],b[100],c[100],d[100];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    for (int i = 1;i <= 50;i++)
    {
        a[i] = ta%tmod; ta /= tmod;
        b[i] = tb%tmod; tb /= tmod;
        c[i] = mod%tmod; mod /= tmod;
    }
    a[0] = getlong(a);
    b[0] = getlong(b);
    c[0] = getlong(c);
    for (int i = 1;i <= a[0];i++)
    for (int j = 1;j <= b[0];j++)
    {
        d[i+j-1] = d[i+j-1]+a[i]*b[j];
        d[i+j] = d[i+j]+d[i+j-1]/tmod;
        d[i+j-1] = d[i+j-1]%tmod;
    }
    for (int i = 1;i <= 3;i++)
    {
        d[i+1] = d[i+1]+d[i]/tmod;
        d[i] %= tmod;
    }
    d[0] = getlong(d);
    for (int i = 0;i <= d[0];i++)
        a[i] = d[i];
    for (int i = 0;i <= c[0];i++)
        b[i] = c[i];
    for (int i = a[0]-b[0]+1;i >= 1;i--)
    {
        memset(c,0,sizeof(c));
        c[0] = b[0]+i-1;
        for (int j = 1;j <= b[0];j++)
            c[i-1+j] = b[j];
        int code = bigthen(a,c);
        while (code < 2)
        {
            memset(d,0,sizeof(d));
            for (int k = 1;k <= a[0];k++)
            {
                d[k] = a[k]-c[k];
                if (d[k] < 0)
                {
                    d[k] = d[k]+10;
                    a[k+1] = a[k+1]-1;
                }
            }
            d[0] = getlong(d);
            for (int k = 0;k <= d[0];k++)
                a[k] = d[k];
            code = bigthen(a,c);
        }
    }
    long long res = 0;
    for (int i = a[0];i >= 1;i--)
        res = res*10+a[i];
    return res;
}

long long power(long long a,long long n,long long mod)
{
    long long res = 1;
    if (n == 0) return res;
    long long tt = power(a,n/2,mod);
    res = calc(tt,tt,mod);
    if (n%2 == 1)
        res = calc(res,a,mod);
    return res;
}

int main()
{
    while (true)
    {
        scanf("%lld%lld%lld%lld",&x,&a,&n,&c);
        if (x == 0 && a == 0 && n == 0 && c == 0)   break;
        long long res1,res2,res3,res4;
        res1 = (x*(power(a,n,c)))%c;
        res2 = (a-1)*c;
        long long res22;
        res22 = calc(a,power(a,n,res2)-1,res2);
        res3 = res22/(a-1);
        res4 = (res1-res3+c)%c;
        printf("%lld\n",res4);
    }
}
