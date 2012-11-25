#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
struct Matrix
{
    double a[20][20];
    Matrix operator *(const Matrix& b)const
    {
        Matrix res;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
            {
                res.a[i][j] = 0;
                for (int k = 0;k < n;k++)
                    res.a[i][j] += a[i][k]*b.a[k][j];
            }
        return res;
    }
};

Matrix power(Matrix x,int y)
{
    Matrix res;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
            res.a[i][j] = 0;
        res.a[i][i] = 1;
    }
    for (Matrix a = x;y;y >>=1,a=a*a)
        if (y&1)
            res = res*a;
    return res;
}

Matrix b;
double a[20],res[20];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%lf",&a[i]);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                b.a[i][j] = 0;
	    for (int i = 0;i < n;i++)
	    {
	        int k;
	        scanf("%d",&k);
	        for (int j = 0;j < k;j++)
	        {
	            int v;
	            scanf("%d",&v);
	            v--;
	            b.a[v][i] = 1.0/k;
	        }
	        if (k == 0)
                b.a[i][i] = 1.0;
	    }
	    scanf("%d",&m);
        b = power(b,m);
        //for (int i = 0;i < n;i++)
        //{
        //    for (int j = 0;j < n;j++)
        //        printf("%.2f ",b.a[i][j]);
        //    printf("\n");
        //}
        for (int i = 0;i < n;i++)
        {
            res[i] = 0;
            for (int j = 0;j < n;j++)
                res[i] += b.a[i][j]*a[j];
        }
        printf("%.2f",res[0]);
        for (int i = 1;i < n;i++)
            printf(" %.2f",res[i]);
        printf("\n");
	}
	return 0;
}
