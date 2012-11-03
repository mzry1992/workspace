#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
double a[11][12],mp[12][12];

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        for (int i = 0;i < 12;i++)
            for (int j = 0;j < 12;j++)
                scanf("%lf",&mp[i][j]);
        for (int i = 0;i < 11;i++)
        {
            a[i][11] = mp[i][11]*mp[i][11]-mp[i+1][11]*mp[i+1][11];
            for (int j = 0;j < 11;j++)
            {
                a[i][j] = -2*mp[i][j]+2*mp[i+1][j];
                a[i][11] -= mp[i][j]*mp[i][j]-mp[i+1][j]*mp[i+1][j];
            }
        }

//        for (int i = 0;i < 11;i++)
//        {
//            for (int j = 0;j < 12;j++)
//                printf("%.2f ",a[i][j]);
//            printf("\n");
//        }

        for (int i = 0;i < 11;i++)
        {
            for (int j = i;j < 11;j++)
                if (fabs(a[j][i]) > fabs(a[i][i]))
                {
                    for (int k = i;k < 12;k++)
                        swap(a[i][k],a[j][k]);
                }

            for (int j = 0;j < 11;j++)
                if (i != j)
                {
                    double det = a[j][i]/a[i][i];
                    for (int k = i;k < 12;k++)
                        a[j][k] -= a[i][k]*det;
                }
        }

        for (int i = 0;i < 11;i++)
        {
            a[i][11] /= a[i][i];
            if (fabs(a[i][11]) < eps)
                a[i][11] = 0;
        }

        printf("%.2f",a[0][11]);
        for (int i = 1;i < 11;i++)
            printf(" %.2f",a[i][11]);
        printf("\n");
    }
    return 0;
}

