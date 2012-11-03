#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int n;
double a[1600],g[1600];

int main()
{
    g[2] = 0.5;
    a[1] = 1;
    a[2] = 1.5;
    a[3] = 2.0;
    for (int i = 4;i < 1550;i++)
    {
        if (i%2 == 0)
            g[i] = g[i-2]*(i-1)/i;
        else
            g[i] = g[i-1];
        a[i] = a[i-1]+g[i];
    }
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        printf("Case %d: %.6f\n",ft,a[n]);
    }
    return 0;
}
