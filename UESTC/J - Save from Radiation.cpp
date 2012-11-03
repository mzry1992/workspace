#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long n;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lld",&n);
        n++;
        int res = 0;
        while (n != 1)
        {
            res++;
            n = n-n/2;
        }
        printf("Case %d: %d\n",ft,res);
    }
}
