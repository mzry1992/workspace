#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
double a[11][12],mp[12][12];

void Guess(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
            if (fabs(a[j][i]) > eps)
            {
                for (int k = i; k <= n; k++)
                    swap(a[i][k],a[j][k]);
                break;
            }

		if (fabs(a[i][i]) < eps)	continue;

        for (int j = 0; j < n; j++)
            if (i != j && fabs(a[j][i]) > eps)
            {
                double det = a[j][i]/a[i][i];
                for (int k = i; k <= n; k++)
                    a[j][k] -= a[i][k]*det;
            }
    }

    for (int i = 0; i < n; i++)
    {
    	if (fabs(a[i][i]) < eps)
    	{
    		if (fabs(a[i][n]) > eps)
    		{
				//无解
				puts("Fuck");
    		}
			//否则$x_i$可以是任意解
    	}
    	else
        {
        	a[i][n] /= a[i][i];
			if (fabs(a[i][n]) < eps)
				a[i][n] = 0;
        }
    }

}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 12; j++)
                scanf("%lf",&mp[i][j]);
        for (int i = 0; i < 11; i++)
        {
            a[i][11] = mp[i][11]*mp[i][11]-mp[i+1][11]*mp[i+1][11];
            for (int j = 0; j < 11; j++)
            {
                a[i][j] = -2*mp[i][j]+2*mp[i+1][j];
                a[i][11] -= mp[i][j]*mp[i][j]-mp[i+1][j]*mp[i+1][j];
            }
        }

		Guess(11);
        printf("%.2f",a[0][11]);
        for (int i = 1; i < 11; i++)
            printf(" %.2f",a[i][11]);
        printf("\n");
    }
    return 0;
}
