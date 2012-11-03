#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long a,b,c;
    int n;
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        a = 1;
        b = 1;
        for (int i = 1;i <= n;i++)
        {
            c = a;
            a = b;
            b = c+a;
        }
        printf("%lld %lld\n",a,b);
    }
}
