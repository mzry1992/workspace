#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
int a[20];
double R[50][50];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n+1; i++)
            scanf("%d",&a[i]);
        if (n == 0)
        {
            printf("No!\n");
            continue;
        }
        for (int i = 1;i <= 2*n-1;i++)
        for (int j = 1;j <= 2*n-1;j++)
        {
            if (i >= 1 && i <= n-1)
            {
                if (j-i < 0 || j-i > n)
                    R[i][j] = 0.0;
                else
                    R[i][j] = a[j-i];
            }
            else
            {
                if (j+n-i-1 < 0 || j+n-i-1 > n)
                    R[i][j] = 0.0;
                else
                    R[i][j] = (i-j+1)*a[j+n-i-1];
            }
        }
        for (int i = 1;i <= 2*n-2;i++)
        {
            int minpos = 0;
            for (int j = i;j <= 2*n-1;j++)
            if (R[j][i] != 0.0)
            {
                minpos = j;
                break;
            }
            if (minpos == 0)    continue;
            for (int j = 1;j <= 2*n-1;j++)
            {
                int temp = R[i][j];
                R[i][j] = R[minpos][j];
                R[minpos][j] = temp;
            }
            for (int j = i+1;j <= 2*n-1;j++)
            if (R[j][i] != 0.0)
            {
                double temp = R[j][i]/R[i][i];
                for (int k = 1;k <= 2*n-1;k++)
                    R[j][k] = R[j][k]-R[i][k]*temp;
            }
        }
        double det = 1.0;
        for (int i = 1;i <= 2*n-1;i++)
            det = det*R[i][i];
        bool res = true;
        if (det <= 0.0)
            res = false;
        if (res == false)
        {
            printf("No!\n");
        }
        else
        {
            printf("Yes!\n");
        }
    }
}
