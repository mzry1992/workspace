#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long n;
long long res;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lld",&n);
        res = 0;
        for (int i = 1;i < n;i += 2)
            res += n-i;
        printf("%lld\n",res);
    }
}
