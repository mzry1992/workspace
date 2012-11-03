#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
bool a[10100];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        memset(a,false,sizeof(a));
        for (int i = 1;i <= n;i++)
        {
            int temp;
            scanf("%d",&temp);
            a[temp+5000] = true;
        }
        int tot = 0;
        for (int i = 0;i <= 10000;i++)
        if (a[i] == true)   tot++;
        printf("%d ",tot);
        for (int i = 0;i <= 10000;i++)
        if (a[i] == true)
            printf("%d ",i-5000);
        printf("\n");
    }
}
