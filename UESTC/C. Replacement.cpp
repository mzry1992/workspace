#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[100000];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        if (a[n-1] != 1)
            a[n-1] = 1;
        else
            a[n-1] = 2;
        sort(a,a+n);
        for (int i = 0;i < n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
