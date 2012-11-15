#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const long long mod = 10000019LL;
long long n;
int t;
bool isprime[110000];
int prime[110000];
int tot;

void getprime()
{
     memset(isprime,true,sizeof(isprime));
     for (int i = 2;i <= 100000;i++)
     {
         if (isprime[i] == true)
         {
                tot++;
                prime[tot] = i;
                for (int j = 2;j*i <= 100000;j++)
                    isprime[j*i] = false;
         }
     }
}

long long power(long long a,int k)
{
    if (k == 0) return 1;
    long long res = power(a,k/2);
    res = (res*res)%mod;
    if (k%2 == 1)   res = (res*a)%mod;
    return res;
}

int main()
{
    getprime();
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%lld%d",&n,&t);
        long long res = 1;
        for (int i = 1;prime[i] <= n;i++)
        {
            int tt = 0;
            for (int j = prime[i];j <= n;j *= prime[i])
                tt = tt+n/j;
            res = (res*power(prime[i],tt/t))%mod;
        }
        if (res==1) res=-1;
        printf("Case %d: %lld\n",ft,res);
    }
}
