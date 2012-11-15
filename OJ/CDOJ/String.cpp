#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[100010];
int p[100010],la,tim[100010];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%s",a);
        la = strlen(a);
        int j;
        p[0] = j = -1;
        for (int i = 1; i < la; i++)
        {
            while (j >= 0 && a[j+1] != a[i])    j = p[j];
            if (a[j+1] == a[i]) j++;
            p[i] = j;
        }
        long long res = 0;
        for (int i = 0;i < la;i++)
        {
            if (p[i] >= 0)
                tim[i] = 1+tim[p[i]];
            else
                tim[i] = 1;
            res += tim[i];
        }
        printf("%lld\n",res);
    }
    return 0;
}
