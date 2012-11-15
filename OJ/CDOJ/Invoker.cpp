#include<cstdio>
const int mod=1000000007;
int gcd(int x,int y)
{
    if (y) return gcd(y,x%y);
    else return x;
}
int power(int x,int y)
{
    long long ret=1;
    for (long long a=x%mod; y; y>>=1,a=a*a%mod)
        if (y&1)
            ret=ret*a%mod;
    return ret;
}
int getInv(int x)
{
    return power(x,mod-2);
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        printf("Case #%d: ",cas);
        if (n&1)
        {
            long long ans=0;
            for (int i=0;i<n;i++)
                ans=(ans+power(m,gcd(i,n)))%mod;
            ans+=power(m,(n+1)/2)%mod*n%mod;
            ans%=mod;
            ans=ans*getInv(n*2)%mod;
            printf("%I64d\n",ans);
        }
        else
        {
            long long ans=0;
            for (int i=0;i<n;i++)
                ans=(ans+power(m,gcd(i,n)))%mod;
            ans+=power(m,n/2)%mod*n/2%mod;
            ans%=mod;
            ans+=power(m,n/2+1)%mod*n/2%mod;
            ans%=mod;
            ans=ans*getInv(n*2)%mod;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
