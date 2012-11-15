#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long a[1200];
long long sum,res;
const long long mod = 1000000007LL;
int prime[1200000],tot;
bool isprime[1200000];
int b[1200000];

void getprime()
{
     tot = 0;
     memset(isprime,true,sizeof(isprime));
     for (int i = 2;i <= 1000000;i++)
     {
         if (isprime[i] == true)
         {
                        tot++;
                        prime[tot] = i;
         }
         for (int j = 1;j <= tot && i*prime[j] <= 1000000;j++)
         {
             isprime[i*prime[j]] = false;
             if (i%prime[j] == 0) break;
         }
     }
}

long long power(long long a,int b)
{
    long long ret = 1;
    while(b)
    {
        if(b&1) ret = ret*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return ret;
}

long long calc(int n,int m)
{
    memset(b,0,sizeof(b));
    int tmax = 0;
    for (int i = 1;prime[i] <= n && i <= tot;i++)
    {
        for (long long j = prime[i];j <= n && i <= tot;j *= prime[i])
            b[i] += n/j-m/j-(n-m)/j;
    }
    long long res = 1;
    for (int i = 1;prime[i] <= n;i++)
        res = (res*power(prime[i],b[i]))%mod;
    return res;
}

int main()
{
    freopen("FOUM.txt","r",stdin);
    //freopen("FOUMout.txt","w",stdout);
    getprime();
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%lld",&a[i]);
        res = 1;
        sum = a[1];
        for (int i = 2;i <= n;i++)
        {
            sum += a[i];
            res = (res*calc(sum-1,a[i]-1))%mod;
        }
        printf("Case %d: %lld\n",ft,res);

    }
}

