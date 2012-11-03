#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[10000],sum[10000],sa,sb;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        sum[0] = a[0];
        for (int i = 1; i < n; i++)
            sum[i] = sum[i-1]+a[i];

        int res = -1;

        if (n%2 == 0)
        {
            for (int i = n/2-1; i <= n/2; i++)
            {
                //0 - i
                //i - n-1
                sa = sum[i];
                sb = sum[n-1]-sum[i]+a[i];

                if (sa > sb)
                    res = 1;
                else if (sa == sb && res < 0)
                    res = 0;
            }
        }
        else
        {
            int tmp=-1;
            sa = sum[n-1>>1];
            sb = sum[n-1]-sum[n-1>>1]+a[n-1>>1];
            if (sa>sb)
                tmp=1;
            else if (sa==sb)
                tmp=0;
            sa = sum[n+1>>1];
            sb = sum[n-1]-sum[n+1>>1]+a[n+1>>1];
            if (sa>sb)
                res=1;
            else if (sa==sb)
                res=0;
            sa = sum[n-3>>1];
            sb = sum[n-1]-sum[n-3>>1]+a[n-3>>1];
            if (sa>sb)
                res=1;
            else if (sa==sb && res<0)
                res=0;
            res=min(tmp,res);
        }
        printf("Case #%d: ",ft);
        if (res > 0)
            puts("win");
        else if (res == 0)
            puts("tie");
        else
            puts("lose");

    }
    return 0;
}
