#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
double a[1000];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%lf",&a[i]);
        sort(a+1,a+n+1);
        if (n%2 == 0)
        {
            printf("%.3lf\n",(a[n/2]+a[n/2+1])/2.0);
        }
        else
        {
            printf("%.3lf\n",a[n/2+1]);
        }
    }
}
