#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool isPrime[1000000];
int prime[1000000],L;
int n;

void getPrime()
{
    L = 0;
    memset(isPrime,true,sizeof(isPrime));
    for (int i = 2;i < 1000000;i++)
        if (isPrime[i])
        {
            for (int j = i+i;j < 1000000;j += i)
                isPrime[j] = 0;
            prime[L++] = i;
        }
}

vector<pair<int,int> > fac;

void getFac(int v)
{
    for (int i = 0;(long long)prime[i]*prime[i] <= v && i < L;i++)
        if (v%prime[i] == 0)
        {
            pair<int,int> tmp = make_pair(prime[i],0);
            while (v%prime[i] == 0)
            {
                tmp.second++;
                v /= prime[i];
            }
            fac.push_back(tmp);
        }
    if (v > 1)
        fac.push_back(make_pair(v,1));
}

int cnt;

const int mod = 1000000007;

int c[2000][2000];
int f[25];

int main()
{
    c[0][0] = 1;
    for (int i = 1;i < 2000;i++)
    {
        c[i][0] = 1;
        for (int j = 1;j <= i;j++)
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%mod;
    }
    getPrime();
    while (scanf("%d",&n) != EOF)
    {
        fac.clear();
        for (int i = 0;i < n;i++)
        {
            int v;
            scanf("%d",&v);
            getFac(v);
        }
        sort(fac.begin(),fac.end());
        cnt = 1;
        for (int i = 1;i < fac.size();i++)
            if (fac[i].first == fac[cnt-1].first)
                fac[cnt-1].second += fac[i].second;
            else
                fac[cnt++] = fac[i];
        while (fac.size() > cnt)
            fac.pop_back();

        for (int i = 1;i <= n;i++)
        {
            f[i] = 1;
            for (int j = 0;j < fac.size();j++)
                f[i] = (long long)f[i]*c[i+fac[j].second-1][i-1]%mod;
        }

        int res = 0;
        for (int i = 1;i <= n;i++)
            if ((n-i)&1)
                res = ((res-(long long)c[n][i]*f[i]%mod)%mod+mod)%mod;
            else
                res = (res+(long long)c[n][i]*f[i]%mod)%mod;

        printf("%d\n",res);
    }
	return 0;
}
