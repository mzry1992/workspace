#include<cstdio>
#include<cstring>
bool isPrime[1000001];
long long prime[1000001];
int L,N;
int num[100];
long long fac[100];
void getPrime()
{
    L=0;
    memset(isPrime,1,sizeof(isPrime));
    for (int i=2;i<=1000000;i++)
        if (isPrime[i])
        {
            for (int j=i+i;j<=1000000;j+=i)
                isPrime[j]=0;
            prime[L++]=i;
        }
}
void getFactor(long long x)
{
    N=0;
    for (int i=0;prime[i]*prime[i]<=x;i++)
        if (x%prime[i]==0)
        {
            num[N]=0;
            while (x%prime[i]==0)
            {
                x/=prime[i];
                num[N]++;
            }
            fac[N++]=prime[i];
        }
    if (x>1)
    {
        num[N]=1;
        fac[N++]=x;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    getPrime();
    printf("%lld\n",prime[L-1]);
    while (t--)
    {
        long long n,k;
        scanf("%lld%lld",&n,&k);
        getFactor(k);
        long long min=0x7fffffffffffffffLL;
        for (int i=0;i<N;i++)
        {
            long long tot=0;
            for (long long j=fac[i];n/j;j*=fac[i])
            {
                tot+=n/j;
                if ((double)j*fac[i]>0x7fffffffffffffffLL)
                    break;
            }
            if (min>tot/num[i])
                min=tot/num[i];
        }
        printf("%lld\n",min);
    }
    return 0;
}
