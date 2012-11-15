#include <cstdio>
#include <cstring>
long long c[1000010] , F[1000010];
long long inv[1000010];
const int mod=112233;
const int pmod=64080;
int n3,n11,n19,n179;
long long gcd(long long x,long long y)
{
    if (y) return gcd(y,x%y);
    else return x;
}
long long power(long long x,long long y)
{
    long long ret=1;
    for (long long a=x;y;y>>=1,a=a*a%mod)
        if (y&1)
            ret=ret*a%mod;
    return ret;
}

long long getInv(long long x)
{
    return power(x,pmod-1);
}
void getInv2()
{
    inv[1]=1;
    for (int i=2;i<112233;i++)
        inv[i]=getInv(i);
}
void calc_C(int n)
{
    c[0]=1;
    n3=n11=n19=n179=0;
    for (int i=n,j=1;i;i--,j++)
    {
        int ti=i,tj=j;
        int p3=n3,p11=n11,p19=n19,p179=n179;
        while (ti%3==0)
        {
            n3++;
            ti/=3;
        }
        while (ti%11==0)
        {
            n11++;
            ti/=11;
        }
        while (ti%19==0)
        {
            n19++;
            ti/=19;
        }
        while (ti%179==0)
        {
            n179++;
            ti/=179;
        }
        while (tj%3==0)
        {
            n3--;
            tj/=3;
        }
        while (tj%11==0)
        {
            n11--;
            tj/=11;
        }
        while (tj%19==0)
        {
            n19--;
            tj/=19;
        }
        while (tj%179==0)
        {
            n179--;
            tj/=179;
        }
        //printf("%d %d\n",ti,tj);
        c[j]=c[j-1]*ti%mod*inv[tj%mod]%mod;
        c[j-1]=c[j-1]*power(3,p3)%mod*power(11,p11)%mod*power(19,p19)%mod*
        power(179,p179)%mod;
        //printf("c[j]=%d\n",getInv(2));
    }
    //printf("%d %d %d %d\n",n3,n11,n19,n179);
}
int main() {
    int n;
    getInv2();
    while(scanf("%d",&n) == 1){
        for(int i = 1 ; i <= n ;i++) scanf("%lld",&F[i]);
        int K = 1;
        calc_C(n);
        /*for (int i=0;i<=n;i++)
            printf("%d\n",c[i]);
        continue;*/
        long long ans = 0;
        for(int i = n;i>=1;i--){
            ans = ((ans+K*c[i-1]*F[i])%mod+mod)%mod;
            K= -K;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

