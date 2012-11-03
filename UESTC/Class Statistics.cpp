#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[60];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        int res = 0;
        for (int i = 1;i < n;i++)
            res = max(res,a[i]-a[i-1]);
        printf("Class %d\n",ft);
        printf("Max %d, Min %d, Largest gap %d\n",a[n-1],a[0],res);
    }
}
