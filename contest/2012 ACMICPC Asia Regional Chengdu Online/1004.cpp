#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int mod;
const int mod0 = 1000000007;
const int mod1 = 2000000016;
const int mod2 = 96687360;

struct Matrix
{
    int a[2][2];
    Matrix operator *(const Matrix &b)const
    {
        Matrix res;
        for (int i = 0;i < 2;i++)
            for (int j = 0;j < 2;j++)
            {
                res.a[i][j] = 0;
                for (int k = 0;k < 2;k++)
                    res.a[i][j] = ((long long)a[i][k]*b.a[k][j]%mod+res.a[i][j])%mod;
            }
        return res;
    }
    Matrix operator ^(long long y)const
    {
        Matrix res,x;
        for (int i = 0;i < 2;i++)
        {
            for (int j = 0;j < 2;j++)
                res.a[i][j] = 0,x.a[i][j] = a[i][j];
            res.a[i][i] = 1;
        }
        for (;y;y>>=1,x=x*x)
            if (y&1)
                res = res*x;
        return res;
    }
};

Matrix base,res,first;

int g(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    res = first*(base^n);
    return res.a[0][0];
}

int g0(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    mod = mod0;
    res = first*(base^n);
    return res.a[0][0];
}

int g1(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    mod = mod1;
    res = first*(base^n);
    return res.a[0][0];
}

int g2(long long n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    mod = mod2;
    res = first*(base^n);
    return res.a[0][0];
}

int calc(long long n)
{
    return g0(g1(g2(n)));
}

int main()
{
    base.a[0][0] = 3,base.a[0][1] = base.a[1][0] = 1,base.a[1][1] = 0;
    first.a[0][0] = first.a[1][0] = first.a[1][1] = 0,first.a[0][1] = 1;

    long long n;
    while (scanf("%I64d",&n)!=EOF)
        printf("%d\n",calc(n));
        //printf("%3d: %d %d %d\n",n,g(n),gg(n),ggg(n));
	return 0;
}
