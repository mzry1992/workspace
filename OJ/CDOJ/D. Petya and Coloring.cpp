#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
long long k,res;

const long long mod = 1000000007LL;

long long calc(int tot)
{
    long long res;

    return res%mod;
}

int main()
{
    while (scanf("%d%d%I64d",&n,&m,&k) != EOF)
    {
        res = 0;
        for (int i = 1;i < m;i++)
            res = (res+(calc(n*i)*calc(n*(m-i)))%mod)%mod;
        printf("%I64d\n",res);
    }
    return 0;
}
