#include <stdio.h>

int t,ft,n,i,j;
int a[50000];
long result,sum,sum1,sum2,max1,max2,m1,m2;
int flag1,flag2;

int main()
{
    scanf("%d",&t);
    for (ft = 0;ft < t;ft++)
    {
        scanf("%d",&n);
        for (i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sum1 = 0;
        max1 = 0;
        flag1 = 0;`
        m1 = -12345;
        m2 = -12345;
        result = m1+m2;
        for (i = 0;i < n-1;i++)
        {
            if (a[i] >= 0) flag1 = 1;
            if (a[i] > m1) m1 = a[i];
            sum1 += a[i];
            if (sum1 < 0) sum1 = 0;
            if (sum1 > max1) max1 = sum1;
            sum2 = 0;
            max2 = 0;
            flag2 = 0;
            for (j = i+1;j < n;j++)
            {
                if (a[j] >= 0) flag2 = 1;
                if (a[j] > m2) m2 = a[j];
                sum2 += a[j];
                if (sum2 < 0) sum2 = 0;
                if (sum2 > max2) max2 = sum2;
                if (flag1 == 0) max1 = m1;
                if (flag2 == 0) max2 = m2;
                sum = max1+max2;
                if (sum > result)  result = sum;
            }
        }
        printf("%ld\n",result);
    }
    return 0;
}
