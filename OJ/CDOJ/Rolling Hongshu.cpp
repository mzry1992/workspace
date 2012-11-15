#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int n,m;
int x[1000],y[1000],p[1001],v[1001],maxy;
const double g = 20;

double geth(int nx)
{
    for (int i = 0;i < n-1;i++)
        if (x[i] <= nx && x[i+1] >= nx)
        {
            double res = (double)y[i]+(double)(y[i+1]-y[i])*(double)(nx-x[i])/(double)(x[i+1]-x[i]);
            return res;
        }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%*d",&n,&m);
        for (int i = 0;i < n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for (int i = 0;i < m;i++)
            scanf("%d%d%*d",&p[i],&v[i]);
        maxy = y[0];
        for (int i = 0;i < n;i++)
            maxy = max(maxy,y[i]);
        for (int i = 0;i < n;i++)
            if (y[i] == maxy)
            {
                p[m] = x[i];
                v[m] = 0;
                m++;
                break;
            }
        double res = 0.0;
        for (int i = 0;i < m;i++)
            res = max(res,sqrt((double)v[i]*(double)v[i]+2*g*(geth(p[i])-y[0])));
        printf("Case %d: %.2f\n",ft,res);
    }
    return 0;
}
