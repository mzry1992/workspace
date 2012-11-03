#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool isPrime[1000000];
int prime[1000000];
int L;

void getPrime()
{
    L = 0;
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i < 1000000; i++)
        if (isPrime[i])
        {
            for (int j = i + i; j < 1000000; j += i)
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

int n;
double dp[100000], tdp[100000];
int pre[100000], tpre[100000];

vector<int> solve(int n)
{
    vector<int> res;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; prime[i] <= n && i < L; i++)
    {
        memset(tdp, 0, sizeof(tdp));
        for (int j = n; j >= 0; j--)
            for (int k = prime[i]; j - k >= 0; k *= prime[i])
                if (dp[j] < dp[j - k] + log(k))
                {
                    dp[j] = dp[j - k] + log(k);
                    pre[j] = k - j;
                }
    }
    int now = n;
    while (now)
    {
        res.push_back(now - pre[now]);
        now = pre[now];
    }
    return res;
}

vector<int> res;

int main()
{
    getPrime();
    while (scanf("%d", &n) != EOF)
    {
        getFactor(n);
        int g = n / fac[0];
        res = solve(fac[0]);
        printf("%d", res[0]*g);
        for (int i = 1; i < res.size(); i++)
            printf(" %d", res[i]*g);
        printf("\n");
    }
    return 0;
}
