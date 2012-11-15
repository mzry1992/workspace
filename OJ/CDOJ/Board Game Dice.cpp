#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long n,m;
int x;

long long gcd(long long a,long long b)
{
    return (b == 0)?a:gcd(b,a%b);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%I64d%I64d",&n,&m);
        long long tmp = 1;
        x = 1;
        for (;;x++)
        {
            tmp *= m;
            if (tmp >= n) break;
        }
        long long resa,resb,tgcd;
        resa = tmp*x;
        resb = n;
        tgcd = gcd(resa,resb);
        resa /= tgcd;
        resb /= tgcd;
        printf("Case %d: %I64d/%I64d\n",ft,resa,resb);
    }
}
