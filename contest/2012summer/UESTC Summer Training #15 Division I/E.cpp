#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;
double a[10000],tl[10000],tr[10000],d;

bool check(double tim)
{
    double pre = a[0]+tim;
    for (int i = 1;i < n;i++)
    {
        if (a[i] <= pre+d)
            pre = min(pre+d,a[i]+tim);
        else
        {
            if (a[i]-pre-d > tim)   return false;
            pre = pre+d;
        }
    }
    return true;
}

int main()
{
    int cas = 1;
	while (true)
	{
	    scanf("%d",&n);
	    if (n == 0) break;
	    for (int i = 0;i < n;i++)
            scanf("%lf",&a[i]);
        scanf("%lf",&d);
        sort(a,a+n);
        double l,r,mid;
        l = 0;
        r = a[n-1]-a[0];
        while (fabs(l-r) > 1e-4)
        {
            mid = (l+r)/2.0;
            if (check(mid))
                r = mid;
            else
                l = mid;
        }
        printf("Case %d: %.3f\n",cas++,l);
	}
	return 0;
}
