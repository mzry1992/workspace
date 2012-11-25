#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[10],f[10];

int LIS()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] > a[j])
                f[i] = max(f[i],f[j]+1);
        ans = max(ans,f[i]);
    }
    return ans;
}

int LDS()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
            if (a[i] < a[j])
                f[i] = max(f[i],f[j]+1);
        ans = max(ans,f[i]);
    }
    return ans;
}

int main()
{
    for (n = 1; n < 11; n++)
    {
        for (int i = 0; i < n; i++)
            a[i] = i;
        int ans = n;
        do
        {
            ans = min(ans,max(LIS(),LDS()));
        }
        while (next_permutation(a,a+n));
        do
        {
            if (max(LIS(),LDS()) == ans)
            {
                for (int i = 0; i < n; i++)
                    printf("%d ",a[i]);
                printf("\n");
                break;
            }

        }
        while (next_permutation(a,a+n));
    }
    return 0;
}
