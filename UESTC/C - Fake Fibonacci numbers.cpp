#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,f[20];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= 4;i++)
            scanf("%d",&f[i]);
        for (int i = 5;i <= n;i++)
            f[i] = f[i-4]+f[i-1];
        sort(f+1,f+1+n);
        printf("%d\n",f[n/2+1]);
    }
    return 0;
}
