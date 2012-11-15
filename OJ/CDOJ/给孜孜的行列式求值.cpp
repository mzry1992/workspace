#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long m[1100][1100];

long long gcd(long long a,long long b)
{
    if (b == 0)
        return a;
    return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return ((a*b)/gcd(a,b));
}

void output(long long a,long long b)
{
    if (a == 0)
        b = 1;
    else
    {
        long long tgcd = gcd(a,b);
        a /= tgcd;
        b /= tgcd;
        if (((a < 0) && (b < 0)) || ((a > 0) && (b < 0)))
        {
            a = -a;
            b = -b;
        }
    }
    if (b == 1)
        printf("%lld\n",a);
    else
        printf("%lld/%lld\n",a,b);
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            scanf("%lld",&m[i][j]);
        long long tfm = 1;
        for (int i = 1;i <= n;i++)
        {
            for (int j = i+1;j <= n;j++)
            if (m[i][j] != 0)
            {
                long long tlcm = lcm(m[i][i],m[i][j]);
                long long tdiv = tlcm/m[i][j];
                long long tmod = tlcm/m[i][i];
                tfm *= tdiv;
                for (int k = i;k <= n;k++)
                {
                    m[k][j] *= tdiv;
                    m[k][j] -= m[k][i]*tmod;
                }
            }
        }
        long long tfz = 1;
        for (int i = 1;i <= n;i++)
            tfz *= m[i][i];
        output(tfz,tfm);
    }
}
