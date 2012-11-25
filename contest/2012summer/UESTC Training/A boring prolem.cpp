#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Matrix
{
    int a[4][4];
    Matrix operator *(const Matrix& b)const
    {
        Matrix res;
        for (int i = 0;i < 4;i++)
            for (int j = 0;j < 4;j++)
            {
                res.a[i][j] = 0;
                for (int k = 0;k < 4;k++)
                    res.a[i][j] = ((res.a[i][j]+a[i][k]*b.a[k][j])%2012+2012)%2012;
            }
        return res;
    }
    Matrix operator ^(int y)const
    {
        Matrix res,b;
        for (int i = 0;i < 4;i++)
        {
            for (int j = 0;j < 4;j++)
                res.a[i][j] = 0,b.a[i][j] = a[i][j];
            res.a[i][i] = 1;
        }
        for (;y;y>>=1,b=b*b)
            if (y&1)
                res = res*b;
        return res;
    }
};

Matrix base,res,va;
int n,ans;

int main()
{
    for (int i = 0;i < 4;i++)
        for (int j = 0;j < 4;j++)
            base.a[i][j] = va.a[i][j] = 0;
    va.a[0][0] = 4,va.a[1][0] = 1;
    base.a[0][0] = 4,base.a[0][1] = -4,base.a[0][2] = base.a[1][0] = base.a[2][1] = base.a[3][2] = 1;
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    if (n == 1)
            ans = 1;
        else if (n == 2)
            ans = 4;
        else
        {
            n -= 2;
            res = (base^n)*va;
            ans = res.a[0][0];
        }
        printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
