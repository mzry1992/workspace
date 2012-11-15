#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long n;
const long long mod = 10000LL;
long long f[2][2],res[2][2],tmp[2][2];

void power(long long n)
{
    if (n == 1)
    {
        for (int i = 0;i < 2;i++)
        for (int j = 0;j < 2;j++)
            res[i][j] = f[i][j];
        return;
    }
    power(n/2);
    memset(tmp,0,sizeof(tmp));
    for (int i = 0;i < 2;i++)
    for (int j = 0;j < 2;j++)
    for (int k = 0;k < 2;k++)
        tmp[i][j] = (tmp[i][j]+res[i][k]*res[k][j])%mod;
    for (int i = 0;i < 2;i++)
    for (int j = 0;j < 2;j++)
        res[i][j] = tmp[i][j];
    if (n%2 == 1)
    {
        memset(tmp,0,sizeof(tmp));
        for (int i = 0;i < 2;i++)
        for (int j = 0;j < 2;j++)
        for (int k = 0;k < 2;k++)
            tmp[i][j] = (tmp[i][j]+res[i][k]*f[k][j])%mod;
        for (int i = 0;i < 2;i++)
        for (int j = 0;j < 2;j++)
            res[i][j] = tmp[i][j];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lld",&n);
        f[0][1] = f[1][0] = f[1][1] = 1;
        f[0][0] = 0;
        power(n+1);
        printf("%lld\n",res[1][1]);
    }
}
