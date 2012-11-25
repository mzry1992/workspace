#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool check(int n)
{
    int res = 0;
    for (int i = 1;i <= n;i++)
        res += n/i;
    return res%2 == 0;
}

long long a,b;

long long calc(long long a)
{
    if (a < 1)    return a+1;
    long long k = (long long)sqrt(1.0*a);
    long long ret=0;
    if (k%2==0)
    {
        ret=a-k*k+1;
        k--;
    }
    ret+=(k+1)/2*k;
    return ret;
}

int main()
{
    while (scanf("%lld%lld",&a,&b) != EOF)
        printf("%lld\n",calc(b)-calc(a-1));
    return 0;
}
