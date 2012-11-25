#include <cstdio>
#include <algorithm>
using namespace std;
struct frac
{
    long long a,b;
    frac() {}
    frac(long long _a,long long _b)
    {
        a=_a;
        b=_b;
    }
    frac sim()
    {
        long long g=__gcd(a,b);
        return frac(a/g,b/g);
    }
    frac operator+(const frac &x)
    {
        return frac(a*x.b+b*x.a,x.b*b).sim();
    }
    frac operator*(const int &x)
    {
        return frac(a*x,b).sim();
    }
    frac operator/(const int &x)
    {
        return frac(a,b*x).sim();
    }
    void out()
    {
        if (a==b)
            puts("1");
        else if (!a)
            puts("0");
        else
            printf("%lld/%lld\n",a,b);
    }
};
frac dp[11][11][11][11];
bool calced[11][11][11][11];
frac solve(int n,int m,int k,int own)
{
    if (calced[n][m][k][own])
        return dp[n][m][k][own];
    calced[n][m][k][own]=1;
    frac &ret=dp[n][m][k][own]=frac(0,1);
    if (!m)
        return ret=frac(!k,1);
    if (n>own)
        ret=ret+solve(n,m-1,k-1,own+1)*(n-own)/n;
    if (own)
        ret=ret+solve(n,m-1,k,own)*own/n;
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        solve(n,m,k,0).out();
    }
}
