#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a[500],b[500];
int tot;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        if (n == 1)
        {
            printf("1=1\n");
            continue;
        }
        tot = 0;
        int tn = n;
        for (int i = 2;n != 1;i++)
        if (n%i == 0)
        {
            tot++;
            a[tot] = i;
            b[tot] = 0;
            while (n%i == 0)
            {
                b[tot]++;
                n /= i;
            }
        }
        printf("%d=",tn);
        for (int i = 1;i <= tot;i++)
        {
            printf("%d",a[i]);
            if (b[i] > 1)
                printf("^%d",b[i]);
            if (i < tot)
                printf("*");
        }
        printf("\n");
    }
}
