#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[1200];

int main()
{
    freopen("D-large.in","r",stdin);
    freopen("AAAAAA.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        int dif = 0;
        for (int i = 1;i <= n;i++)
        if (a[i] != i)  dif++;
        printf("Case #%d: %d.000000\n",ft,dif);
    }
}
