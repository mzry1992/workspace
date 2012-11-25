#include <cstdio>
#include <algorithm>
using namespace std;
int a[1001][1001];
long long count(long long x)
{
    return x*(x-1)*(x-2)/6;
}
int main()
{
    for (int i=1;i<=1000;i++)
        for (int j=i;j<=1000;j++)
            a[i][j]=a[j][i]=__gcd(i,j)-1;
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        int tot=n*m+n+m+1;
        long long ans=count(tot)-count(n+1)*(m+1)-count(m+1)*(n+1);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                ans-=(long long)(n-i+1)*(m-j+1)*a[i][j]*2;
        printf("%lld\n",ans);
    }
    return 0;
}
