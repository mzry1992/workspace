#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double x[3],y[3],r[3],a[3],b[3],c[3],d[3];
int m[3];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        for (int i = 0;i < 3;i++)
        {
            scanf("%lf%lf%lf%d",&x[i],&y[i],&r[i],&m[i]);
            a[i] = -2*x[i];
            b[i] = -2*y[i];
            c[i] = -2*r[i];
            d[i] = x[i]*x[i]+y[i]*y[i]-r[i]*r[i];
            if (m[i] == 0)
                c[i] = -c[i];
        }
        for (int i = 0;i < 2;i++)
        {
            a[i] = a[i]-a[i+1];
            b[i] = b[i]-b[i+1];
            c[i] = c[i]-c[i+1];
            d[i] = d[i]-d[i+1];
        }
    }
    return 0;
}
