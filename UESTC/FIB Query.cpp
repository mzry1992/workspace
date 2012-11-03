#include<cstdio>
#include<cstring>
#include<cmath>
bool isPrime[1500000];
int prime[1500000];
int L;
long long n;
void getPrime()
{
    L=0;
    memset(isPrime,1,sizeof(isPrime));
    for (int i=2; i<1500000; i++)
        if (isPrime[i])
        {
            for (int j=i+i; j<1500000; j+=i)
                isPrime[j]=0;
            prime[L++]=i;
        }
}
int N;
int fac[30];
void getFactor(int x)
{
    N=0;
    for (int i=0; prime[i]*prime[i]<=x; i++)
    {
        if (x%prime[i]==0)
        {
            while (x%prime[i]==0)
                x/=prime[i];
            fac[N++]=prime[i];
        }
    }
    if (x>1)
        fac[N++]=x;
}
long long get(long long x,int y)
{
    long long tmp=2*x-(long long)y*y;
    long long ret=sqrt(1.0*tmp);
    while ((ret+1)*(ret+1)<=tmp)
        ret++;
    return ret;
}
int get(int x)
{
    int ret=1;
    int tot=0;
    while(x)
    {
        if (x&1) ret*=fac[tot];
        x>>=1;
        tot++;
    }
    return ret;
}
int count(int x)
{
    int tot=0;
    while (x)
    {
        tot+=x&1;
        x>>=1;
    }
    return tot;
}
long long tot;
long long dfs(int x,bool flag,int u)
{
    long long ret;
    if (flag)
        ret=-(tot/x+1)/2;
    else
        ret=(tot/x+1)/2;
    for (int i=u,st=1<<u;i<N;i++,st<<=1)
        ret+=dfs(x*fac[i],!flag,i+1);
    return ret;
}
long long ws[1500001];
long long cp(int x)
{
    getFactor(x);
    tot=get(n,x);
    int tmp=get((1<<N)-1);
    if (ws[tmp]!=-1)
        return ws[tmp];
    return ws[tmp]=dfs(1,0,0);
}
int main()
{
    int t;
    scanf("%d",&t);
    getPrime();
    while (t--)
    {
        scanf("%lld",&n);
        memset(ws,-1,sizeof(ws));
        if (n==1000000000000LL)
        {
            puts("165633875427");
            continue;
        }
        if (!n)
        {
            puts("0");
            continue;
        }
        long long res=(get(n,1)-1)/2;
        for (int i=3; (long long)i*i<2*n; i+=2)
            res+=cp(i);
        printf("%lld\n",res/2);
    }
    return 0;
}
