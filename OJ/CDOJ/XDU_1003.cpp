#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[110000];
int prime[110000],tot;
bool isprime[110000];
int sum[110000];
int a,b;
int fac[110000][30];
int fact[110000];

int main()
{
    tot = 0;
    memset(isprime,true,sizeof(isprime));
    memset(fact,0,sizeof(fact));
    for (int i = 2;i <= 100000;i++)
    {
        if (isprime[i] == true)
        {
            tot++;
            prime[tot] = i;
            for (int j=i*2;j<=100000;j+=i)
            {
                isprime[j]=0;
                fact[j]++;
                fac[j][fact[j]] = i;
            }
        }
    }
    dp[1] = 0;
    for (int i = 2;i <= 100000;i++)
        dp[i] = 19921005;
    for (int i = 2;i <= 100000;i++)
    if (isprime[i] == true)
        dp[i] = 1;
    else
    {
        if (dp[i] > dp[i-1]+1)
            dp[i] = dp[i-1]+1;
        for (int j = 1;j <= fact[i];j++)
        if (i%fac[i][j] == 0)
        if (dp[i] > dp[i/fac[i][j]]+1)
            dp[i] = dp[i/fac[i][j]]+1;
    }
    sum[0] = 0;
    for (int i = 1;i <= 100000;i++)
        sum[i] = sum[i-1]+dp[i];
    while (scanf("%d%d",&a,&b) != EOF)
        printf("%d\n",sum[b]-sum[a-1]);
}
