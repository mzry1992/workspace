#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long a[1000001],resa,resb,cura,curb,tgcd;
int n,m;

long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

void easy(long long& a,long long& b)
{
    tgcd = gcd(a,b);
    a /= tgcd;
    b /= tgcd;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        a[0] = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%lld",&a[i]);
            a[i] += a[i-1];
        }
        resa = 0;
        resb = 1;
        for (int i = m;i <= n;i++)
            for (int j = i;j <= n;j++)
            {
                cura = a[j]-a[j-i];
                curb = i;
                easy(cura,curb);
                if (resa*curb < resb*cura)
                {
                    resa = cura;
                    resb = curb;
                }
            }
        if (resb == 1)
            printf("%lld\n",resa);
        else printf("%lld/%lld\n",resa,resb);
    }
}
