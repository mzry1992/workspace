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

long long combination_Mod_h2 (long long n, long long m)
{
    const long long h = mod;
    long long result = 1, cnt = 0, temp;
	for(int i = 1; i <= tot && prime[i] <= n; i++)
	{
		temp = n, cnt = 0;
		while(temp)
			temp /= prime[i], cnt += temp;
		temp = n - m;
		while(temp)
			temp /= prime[i], cnt -= temp;
		temp = m;
		while(temp)
			temp /= prime[i], cnt -= temp;
		temp = prime[i];
		while(cnt)
		{
			if(cnt & 1)
                                result *= temp, result %= h;
			temp *= temp, cnt >>= 1, temp %= h;
		}
		if(result == 0) return 0;
	}
	return result;
}

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

int main()
{
    //freopen("FOUM.txt","r",stdin);
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
            res = (res*combination_Mod_h2(sum-1,a[i]-1))%mod;
        }
        printf("Case %d: %lld\n",ft,res);
    }
}
