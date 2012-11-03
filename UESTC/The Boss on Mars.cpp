#include<cstdio>
const int mod=1000000007;
int fac[100],N;
void getFactor(int x)
{
    N=0;
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
        {
            fac[N++]=i;
            while (x%i==0)
                x/=i;
        }
    if (x>1)
        fac[N++]=x;
}
int power(int x,int p)
{
    long long ret=1;
    for (long long a=x%mod;p;p>>=1,a=a*a%mod)
        if (p&1)
            ret=ret*a%mod;
    return ret;
}
int getInv(int x)
{
    return power(x,mod-2);
}
int get(int x)
{
    return ((long long)6*x%mod*x%mod*x%mod*x%mod*x%mod
            +15*x%mod*x%mod*x%mod*x%mod+10*x%mod*x%mod*x%mod-x+mod)%mod*getInv(30)%mod;
}
int ans;
void dfs(int pos,int now,bool p,int n)
{
    if (pos==N)
    {
        if (p)
            ans=(ans+(long long)get(n/now)*now%mod*now%mod*now%mod*now%mod)%mod;
        else
            ans=(ans+mod-(long long)get(n/now)*now%mod*now%mod*now%mod*now%mod)%mod;
        return ;
    }
    dfs(pos+1,now,p,n);
    dfs(pos+1,now*fac[pos],!p,n);
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        ans=0;
        getFactor(n);
        dfs(0,1,1,n);
        printf("%d\n",ans);
    }
    return 0;
}
