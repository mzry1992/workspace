#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
double a[2000][2000];
double temp;

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        memset(a,0,sizeof(a));
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                a[(i-1)*m+j][(i-1)*m+j] = -1.0;
                a[(i-1)*m+j][n*m+1] = 1.0;
            }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                scanf("%lf",&temp);
                if (i+1 <= n)
                    a[(i-1)*m+j][(i)*m+j] = temp;
            }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                scanf("%lf",&temp);
                if (j+1 <= m)
                    a[(i-1)*m+j][(i-1)*m+j+1] = temp;
            }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                scanf("%lf",&temp);
                if (i-1 > 0)
                    a[(i-1)*m+j][(i-2)*m+j] = temp;
            }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                scanf("%lf",&temp);
                if (j-1 > 0)
                    a[(i-1)*m+j][(i-1)*m+j-1] = temp;
            }
        int tn,tm;
        tn = n*m;
        tm = n*m+1;
        for (int i = 1;i <= tn;i++)
        {
            for (int j = i+1;j <= tn;j++)
                if (j != i)
                    if (a[j][i] > 0)
                    {
                        double mul = a[j][i]/a[i][i];
                        for (int k = i;k <= tm;k++)
                            a[j][k] = a[j][k]-a[i][k]*mul;
                    }
        }
        a[tn][tm] = 0;
        for (int i = tn;i >= 1;i--)
        {
            a[i][tm] = a[i][tm]/a[i][i];
            for (int j = 1;j < i;j++)
                a[j][tm] = a[j][tm]-a[i][tm]*a[j][i];
        }
        printf("%.5lf\n",a[1][tm]/a[1][1]);
    }
}
