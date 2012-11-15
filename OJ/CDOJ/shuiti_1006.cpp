#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t,n,k,a,b,ans;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&k);
        if (k == 13)
            k = 12;
        ans = a = n/k;
        b = n%k;
        if (b == 0)
            ans = a;
        else
            ans = a+1;
        if (((k == 14) || (a == 0))  && (b == 13))
            ans++;
        printf("%d\n",ans);
    }
}
