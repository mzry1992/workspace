#include <stdio.h>

int t,ft,n,i;
int a[50001],l[50001],r[50001],f1[50001],f2[50001],m1[50001],m2[50001];
long result,sum1,sum2,sum;

int main()
{
    scanf("%d",&t);
    for (ft = 0;ft < t;ft++)
    {
        scanf("%d",&n);
        l[0] = 0;
        r[n+1] = 0;
        for (i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        sum1 = 0;
        sum2 = 0;
        f1[0] = 0;
        f2[n+1] = 0;
        m1[0] = -12345;
        m2[n+1] = -12345;
        result = -12345-12345;
        for (i = 1;i <= n;i++)
        {
            sum1 += a[i];
            if (a[i] > 0) f1[i] = 1;
            m1[i] = m1[i-1];
            if (a[i] > m1[i]) m1[i] = a[i];
            if (sum1 < 0) sum1 = 0;
            l[i] = sum1;
            if (l[i] < l[i-1]) l[i] = l[i-1];
            sum2 += a[n+1-i];
            if (a[n+1-i] > 0) f2[n+1-i] = 1;
            m2[n+1-i] = m2[n+2-i];
            if (a[n+1-i] > m2[n+1-i]) m2[n+1-i] = a[n+1-i];
            if (sum2 < 0) sum2 = 0;
            r[n+1-i] = sum2;
            if (r[n+1-i] < r[n+2-i]) r[n+1-i] = r[n+2-i];
        }
        for (i = 1;i <= n-1;i++)
        {
            if (f1[i] == 0) l[i] = m1[i];
            if (f2[i+1] == 0) r[i+1] = m2[i+1];
            sum = l[i]+r[i+1];
            if (result < sum) result = sum;
        }
        printf("%ld\n",result);
    }
    return 0;
}
