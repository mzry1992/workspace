#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        long long n;
        scanf("%lld",&n);
        long long res = 0;
        for (int i = 1;i <= (int)sqrt(n);i++)
            res += n/(long long)i;
        res *= 2;
        res -= ((long long)sqrt(n))*((long long)sqrt(n))+n;
        printf("%lld\n",res);
    }
}
