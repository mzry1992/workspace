#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long n,m;
long long d[10000];

long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

bool hasans;

long long celling(double x)
{
    if (x-(double)((long long)x) < 1e-8)  return (long long)x;
    return (long long)x+1;
}

void DFS(int deep,long long x,long long y)
{
    if (y >= 1000000LL) return;
    if (hasans == true) return;
    if (x == 1)
    {
        d[deep] = y;
        if (y >= 1000000LL) return;
        hasans = true;
        bool first = true;
        for (int i = 1;i <= deep;i++)
        {
            if (first == false) printf(" ");
            first = false;
            printf("%lld",d[i]);
        }
        puts("");
        return;
    }
    d[deep] = max(celling((double)y/(double)x),d[deep-1]);
    while (d[deep] < 1000000LL)
    {
        long long tx,ty;
        tx = x*d[deep]-y;
        ty = y*d[deep];
        long long tgcd = gcd(tx,ty);
        tx /= tgcd;
        ty /= tgcd;
        DFS(deep+1,tx,ty);
        if (hasans == true) return;
        d[deep]++;
    }
}

int main()
{
    while (true)
    {
        scanf("%lld%lld",&n,&m);
        if (n == 0 && m == 0)   break;
        hasans = false;
        long long tgcd = gcd(n,m);
        d[0] = 0;
        DFS(1,n/tgcd,m/tgcd);
    }
}
