#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    long long n,m;
    long long ans;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lld%lld",&n,&m);
        ans = (n-1)+n*(m-1);
        printf("%lld\n",ans);
    }
}
