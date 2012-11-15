#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long res[50];

int main()
{
    res[0] = 0;
    res[1] = 1;
    for (int i = 2;i < 30;i++)
        res[i] = res[i-2]*2+1+res[i-1];
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",res[n]);
    }
}
