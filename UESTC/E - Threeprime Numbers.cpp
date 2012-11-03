#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
long long dp[2][10][10][10];
bool prime[1200];
int tprime[1200][3];
int tot;
const long long mod = 1000000009LL;

bool isprime(int x)
{
    int res = 0;
    for (int i = 1;i <= x;i++)
    if (x%i == 0)   res++;
    if (res == 2)   return true;
    return false;
}

int main()
{
    memset(prime,false,sizeof(prime));
    for (int i = 100;i <= 999;i++)
    if (isprime(i) == true)
        prime[i] = true;
    tot = 0;
    for (int i = 0;i <= 9;i++)
    for (int j = 0;j <= 9;j++)
    for (int k = 0;k <= 9;k++)
    if (prime[i*100+j*10+k] == true)
    {
        tot++;
        tprime[tot][0] = i;
        tprime[tot][1] = j;
        tprime[tot][2] = k;
    }
    while (scanf("%d",&n) != EOF)
    {
        memset(dp,0,sizeof(dp));
        for (int i = 1;i <= tot;i++)
            dp[1][tprime[i][0]][tprime[i][1]][tprime[i][2]] = 1;
        for (int i = 4;i <= n;i++)
        {
            for (int a = 1;a <= tot;a++)
                dp[i%2][tprime[a][0]][tprime[a][1]][tprime[a][2]] = 0;
            for (int j = 1;j <= tot;j++)
            {
                int a = tprime[j][0];
                int b = tprime[j][1];
                int c = tprime[j][2];
                for (int d = 0;d <= 9;d++)
                if (prime[b*100+c*10+d] == true)
                    dp[i%2][b][c][d] = (dp[i%2][b][c][d]+dp[(i-1)%2][a][b][c])%mod;
            }
        }
        long long res = 0;
        for (int i = 0;i <= 9;i++)
        for (int j = 0;j <= 9;j++)
        for (int k = 0;k <= 9;k++)
            res = (res+dp[n%2][i][j][k])%mod;
        printf("%lld\n",res);
    }
}
