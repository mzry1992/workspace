#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[20*20];

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n*(n-1)/2;i++)
            scanf("%d",&a[i]);
    }
}
