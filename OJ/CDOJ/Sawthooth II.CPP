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
        res = (9*n*n-7*n)/2+1;
        printf("%lld\n",res);
    }
}
