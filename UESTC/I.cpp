#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,m;
double a[100][100],b[100][100];

int cmp(double a,double b)
{
    if (fabs(a-b) < 1e-6)   return 0;
    if (a < b)  return -1;
    return 1;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                scanf("%lf",&a[i][j]);
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
                scanf("%lf",&b[j][i]);
        for (int i = 0;i < n;i++)
        {
            if (cmp(a[i][i],0.0) == 0)
                for (int j = i+1;j < n;j++)
                    if (cmp(a[j][i],0.0) != 0)
                    {
                        for (int k = i;k < n;k++)
                            swap(a[i][k],a[j][k]);
                        for (int k = 0;k < m;k++)
                            swap(b[i][k],b[j][k]);
                        break;
                    }
            for (int j = 0;j < n;j++)
                if (i != j && cmp(a[j][i],0.0) != 0)
                {
                    double tmp = a[j][i]/a[i][i];
                    for (int k = i;k < n;k++)
                        a[j][k] -= a[i][k]*tmp;
                    for (int k = 0;k < m;k++)
                        b[j][k] -= b[i][k]*tmp;
                }
        }
        for (int i = 0;i < m;i++)
        {
            for (int j = 0;j < n;j++)
                printf("%.2f ",b[j][i]/a[j][j]);
            printf("\n");
        }
    }
    return 0;
}
