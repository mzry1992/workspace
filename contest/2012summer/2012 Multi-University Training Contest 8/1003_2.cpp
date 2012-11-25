#include<cstdio>

int f[2001][2001],fac[2001],inv[2001],sum[2001][2001],c[2001][2001];
const int mod = 1000000007;

long long power(int x,int y,int m)
{
    long long res = 1;
    for (long long a = x%m;y;y>>=1,a = a*a%m)
        if (y&1)
            res = res*a%m;
    return res;
}

long long getInv(int x)
{
    return power(x,mod-2,mod);
}

int main()
{
    c[0][0] = 1;
    for (int i = 1;i <= 2000;i++)
    {
        c[i][0] = 1;
        for (int j = 1;j <= i;j++)
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
    }
    f[1][1] = 1;
    sum[1][1] = 1;
    fac[0] = 1;
    for (int i = 1;i <= 2000;i++)
        fac[i] = (long long)fac[i-1]*i%mod;
    for (int i = 0;i <= 2000;i++)
        inv[i] = getInv(fac[i]);
    for (int n = 2;n <= 2000;n++)
        for (int i = 1;i <= n;i++)
        {
            f[n][i] = sum[n-1][i-1];
            f[n][i] = (long long)f[n][i]*fac[n-2]%mod;
            sum[n][i] = (sum[n-1][i]+(long long)f[n][i]*inv[n-1]%mod)%mod;
        }
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,l,r;
        scanf("%d%d%d",&n,&l,&r);
        int res = 0;
        for (int m = 1;m <= n;m++)
            res = (res+(long long)f[m][l]*f[n-m+1][r]%mod*c[n-1][m-1])%mod;
        printf("%d\n",res);
    }
}
