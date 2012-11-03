#include <iostream>
using namespace std;

int t,ft,n,ans;

int main()
{
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        ans = (n-2)*2;
        if (n == 1)     ans = 1;
        if (n == 2)     ans = 2;
        printf("Case %d: %d\n",ft,ans);
    }
    return 0;
}
