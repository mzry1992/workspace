#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double a[4];

double calc(double a,double b,double c)
{
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

double calc(double len)
{
    return calc(len,a[0],a[1])+calc(len,a[2],a[3]);
}

double solve()
{
    double l,r,mid1,mid2;
    l = max(fabs(a[1]-a[0]),fabs(a[3]-a[2]));
    r = min(a[1]+a[0],a[2]+a[3]);

    for (int tim = 1; tim <= 200; tim++)
    {
        mid1 = l+(r-l)/3;
        mid2 = r-(r-l)/3;
        if (calc(mid1) < calc(mid2))
            l = mid1;
        else
            r = mid2;
    }
    double res = calc(r);

    l = max(fabs(a[1]-a[0]),fabs(a[3]-a[2]));
    r = min(a[1]+a[0],a[2]+a[3]);
    for (int tim = 1; tim <= 200; tim++)
    {
        mid1 = l+(r-l)/3;
        mid2 = r-(r-l)/3;
        if (calc(mid1,a[0],a[1]) < calc(mid2,a[0],a[1]))
            l = mid1;
        else
            r = mid2;
    }
    res = max(res,calc(l));

    l = max(fabs(a[1]-a[0]),fabs(a[3]-a[2]));
    r = min(a[1]+a[0],a[2]+a[3]);
    for (int tim = 1; tim <= 200; tim++)
    {
        mid1 = l+(r-l)/3;
        mid2 = r-(r-l)/3;
        if (calc(mid1,a[2],a[3]) < calc(mid2,a[2],a[3]))
            l = mid1;
        else
            r = mid2;
    }
    res = max(res,calc(l));

    return res;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        for (int i = 0; i < 4; i++)
            scanf("%lf",&a[i]);
        sort(a,a+4);
        double res;

        if (a[0]+a[1]+a[2] <= a[3])
            res = -1;
        else
        {
            res = solve();
            swap(a[1],a[2]);
            res = max(res,solve());
            swap(a[1],a[3]);
            res = max(res,solve());
        }

        printf("Case %d: ",cas);
        if (res < 0)
            puts("-1");
        else
            printf("%.6f\n",res);
    }
    return 0;
}
