#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,c[100];

int main()
{
    scanf("%d",&n);
    for (int i = 0;i < n;i++)   scanf("%d",&c[i]);
    sort(c,c+n);
    int zero,neg,eg;
    zero = neg = eg = 0;
    for (int i = 0;i < n;i++)
        if (c[i] < 0)   neg++;
        else if (c[i] == 0) zero++;
        else eg++;
    if (eg == 0 && neg == 0)
        printf("0\n");
    else if (eg == 0 && neg == 1)
    {
        if (zero != 0)  printf("0\n");
        else printf("%d\n",c[0]);
    }
    else
    {
        for (int i = 0;i < n;i++)
            if (c[i] > 0)   printf("%d ",c[i]);
        if (neg%2 == 0)
        {
            for (int i = 0;i < n;i++)
                if (c[i] < 0)   printf("%d ",c[i]);
        }
        else
        {
            for (int i = 0;i < n;i++)
                if (c[i] < 0)
                {
                    neg--;
                    if (neg == 0)   break;
                    printf("%d ",c[i]);
                }
        }
        printf("\n");
    }
}
