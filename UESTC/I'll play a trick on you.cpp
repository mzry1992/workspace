#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[120];
int len;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        int res = 0;
        scanf("%s",a);
        len = strlen(a);
        for (int i = 0;i < len;i++)
            res += a[i]-'0';
        scanf("%s",a);
        len = strlen(a);
        for (int i = 0;i < len;i++)
            res += a[i]-'0';
        printf("Case %d: %d\n",ft,res);
    }
    return 0;
}
