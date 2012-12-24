#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10],b[10],res[10];

int main()
{
    while (true)
    {
        int n = 5;
        for (int i = 0; i < n; i++)
        {
            b[i] = i;
            a[i] = rand()%10+1;
        }
        sort(a,a+n);
        int mindist = 0;
        for (int i = 1;i < n;i++)
            mindist += a[i];

        do
        {
            int dist = 0;
            for (int i = 1; i < n; i++)
                dist += max(a[b[i-1]],a[b[i]]);
            if (dist == mindist)
            {
                for (int i = 0; i < n; i++)
                    printf("%d ",a[b[i]]);
                printf("\n");
            }
        }
        while (next_permutation(b,b+n));
        getchar();
    }
    return 0;
}
