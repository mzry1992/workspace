#include <iostream>
#include <cmath>
using namespace std;

int t,ft;
int n,i;
int a[123456];
__int64 sum;
__int64 ans;

int main()
{
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        sum = 0;
        for (i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        sum /= n;
        ans = 0;
        for (i = 1;i <= n;i++)
            ans += fabs(a[i]-sum);
        printf("Case %d: %I64d %I64d\n",ft,ans,sum);
    }
    return 0;
}
