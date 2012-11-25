#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime[31622];
int prime[31622];
int L;

void getPrime()
{
    L = 0;
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i < 31622; i++)
        if (isPrime[i])
        {
            for (int j = i + i; j < 31622; j += i)
                isPrime[j] = 0;
            prime[L++] = i;
        }
}

int N, num[30], fac[30];

void getFactor(int x)
{
    N = 0;
    memset(num, 0, sizeof(num));
    for (int i = 0; (long long)prime[i]*prime[i] <= x && i < L; i++)
        if (x % prime[i] == 0)
        {
            while (x % prime[i] == 0)
            {
                x /= prime[i];
                num[N]++;
            }
            fac[N++] = prime[i];
        }
    if (x > 1)
    {
        num[N] = 1;
        fac[N++] = x;
    }
}

const int mm = 100;
int n;
double dp[mm][31622];
int pre[mm][31622];
bool first;

void output(int n,int g)
{
    if (!first)
        printf(" ");
    first = false;
    printf("%d",n*g);
}

void solve(int n,int g)
{
    memset(dp, 0, sizeof(dp));
    memset(pre, -1, sizeof(pre));
    for (int i = 1; i < mm; i++)
    {
        for (int j = 0;j <= n;j++)
            dp[i][j] = dp[i-1][j],pre[i][j] = j;
        for (int j = prime[i-1]; j < n;j *= prime[i-1])
            for (int k = j;k <= n;k++)
                if (dp[i][k] < dp[i-1][k-j]+log(1.0*j))
                {
                    dp[i][k] = dp[i-1][k-j]+log(1.0*j);
                    pre[i][k] = k-j;
                }
    }
    int now = n,pos = mm-1;
    while (true)
    {
        if (pre[pos][now] == -1)
        {
            for (int i = 0;i < now;i++)
                output(1,g);
            break;
        }
        if (pre[pos][now] != now)
            output(now - pre[pos][now],g);
        now = pre[pos][now];
        pos--;
    }
}

int main()
{
    getPrime();
    for (int i = 0;i < L;i++)
        if (prime[i] >= 31622)
        {
            printf("%d %d\n",i,prime[i]);
            break;
        }
    while (scanf("%d", &n) != EOF)
    {
        getFactor(n);
        int g = n / fac[0];
        first = true;
        solve(fac[0],g);
        puts("");
    }
    return 0;
}
