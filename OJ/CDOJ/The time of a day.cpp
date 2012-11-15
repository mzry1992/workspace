#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


long long gcd(long long a,long long b)
{
    return (b == 0)?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}

map<long long,long long> dp[41];
map<long long,long long>::iterator it;

int main()
{
    dp[0].clear();
    dp[0][1] = 1;
    for (int i = 1;i <= 40;i++)
        for (it = dp[i-1].begin();it != dp[i-1].end();it++)
        {
            dp[i][lcm(it->first,i)] += it->second;
            dp[i][it->first] += it->second;
        }
    int t,n;
    long long m;
    long long res;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%I64d",&n,&m);
        if (m==1)
        {
            printf("Case #%d: %I64d\n",ft,(1LL<<n)-1);
            continue;
        }
        res = 0;
        for (it = dp[n].begin();it != dp[n].end();it++)
            if (it->first >= m)
                res += it->second;
        printf("Case #%d: %I64d\n",ft,res);
    }
    return 0;
}
