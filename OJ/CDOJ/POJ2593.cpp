#include <stdio.h>

int n,i,j,k,q,a[100001];
long sum,tsum,result,l[100001],r[100001];

int main()
{
    scanf("%d",&n);
    while (n > 0)
    {
        l[0] = -19921005;
        tsum = 0;
        for (i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            if ((a[i] < 0) && (l[i-1] < 0))
            {
                      l[i] = a[i];
                      if (l[i] < l[i-1]) l[i] = l[i-1];
            }
            if ((a[i] >= 0) && (l[i-1] < 0))
            {
                      tsum = a[i];
                      l[i] = tsum;
            }
            if (l[i-1] >= 0)
            {
                       tsum += a[i];
                       if (tsum < 0) tsum = 0;
                       l[i] = tsum;
                       if (l[i] < l[i-1]) l[i] = l[i-1];
            }
        }
        r[n+1] = -19921005;
        tsum = 0;
        for (i = 1;i <= n;i++)
        {
            j = n+1-i;
            if ((a[j] < 0) && (r[j+1] < 0))
            {
                      r[j] = a[j];
                      if (r[j] < r[j+1]) r[j] = r[j+1];
            }
            if ((a[j] >= 0) && (r[j+1] < 0))
            {
                      tsum = a[j];
                      r[j] = tsum;
            }
            if (r[j+1] >= 0)
            {
                        tsum += a[j];
                        if (tsum < 0) tsum = 0;
                        r[j] = tsum;
                        if (r[j] < r[j+1]) r[j] = r[j+1];
            }
        }
        result = -19921005;
        for (i = 1;i < n;i++)
        {
            sum = l[i]+r[i+1];
            if (sum > result) result = sum;
        }
        printf("%ld\n",result);
        scanf("%d",&n);
    }
    return 0;
}
            
            