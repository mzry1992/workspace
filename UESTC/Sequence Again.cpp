#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[20010],res;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
    }
    return 0;
}
