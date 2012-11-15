#include <iostream>
#include <cstdio>
using namespace std;

int n;
long long a[50];

int main()
{
    int t;
    scanf("%d",&t);
    a[1] = 5;
    for (int i = 2;i <= 40;i++)
        a[i] = 3*a[i-1];
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        printf("Case #%d: %lld\n",ft,a[n]);
    }
}
