#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

double x[50000],w[50000];
int n;

inline double xxx(double x)
{
    return x*x*x;
}

inline double calc(double pos)
{
    double res = 0;
    for (int i = 0;i < n;i++)
        res += xxx(fabs(pos-x[i]))*w[i];
    return res;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%lf%lf",&x[i],&w[i]);
        double l = -1000000,r = 1000000,mid1,mid2;
        for (int tim = 0;tim < 100;tim++)
        {
            mid1 = l+(r-l)/3;
            mid2 = r-(r-l)/3;
            if (calc(mid1) < calc(mid2))
                r = mid2;
            else
                l = mid1;
        }
        printf("Case #%d: %.0f\n",cas,floor(calc(l)+0.5));
	}
	return 0;
}
