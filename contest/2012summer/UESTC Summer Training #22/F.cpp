#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int mod;
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
                    res.a[i][j] = (res.a[i][j]+(long long)a[i][k]*b.a[k][j])%mod;
            }
        return res;
    }
    Matrix operator ^(int y)const
    {
        Matrix res,x;
        for (int i = 0;i < 4;i++)
        {
            for (int j = 0;j < 4;j++)
                res.a[i][j] = 0,x.a[i][j] = (a[i][j]%mod+mod)%mod;
            res.a[i][i] = 1;
        }
        for (;y;y >>= 1,x = x*x)
            if (y&1)
                res = res*x;
        return res;
    }
};

int a2,n,c;
Matrix base,a;

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d%d%d",&a2,&n,&mod);
        c = 2*a2%mod;
        for (int i = 0;i < 4;i++)
            for (int j = 0;j < 4;j++)
                base.a[i][j] = a.a[i][j] = 0;
        base.a[0][0] = (long long)c*c%mod;
        base.a[0][1] = 1;
        base.a[0][2] = -2*c;
        base.a[1][0] = 1;
        base.a[2][0] = c;
        base.a[2][2] = -1;
        base.a[3][0] = 1;
        base.a[3][3] = 1;

        a.a[0][0] = (long long)a2*a2%mod;
        a.a[1][0] = 1;
        a.a[2][0] = a2;
        a.a[3][0] = 1;

        a = (base^(n-1))*a;

        printf("%d\n",a.a[3][0]);
    }
    return 0;
}
