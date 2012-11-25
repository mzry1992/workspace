#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[1000],s[1000][1000],top[1000];
int f[1000],cnt[1000];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

long long gcd(long long a,long long b)
{
    if (b == 0) return a;
    return gcd(b,a%b);
}

long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        if (n == 0 && m == 0)   break;
        for (int i = 0; i < n; i++)
            a[i] = i;
        for (int i = 0; i < m; i++)
            top[i] = 0;
        for (int i = 0; i < n; i++)
            s[i%m][top[i%m]++] = a[i];
        int tt = 0;
        for (int i = 0; i < m; i++)
            for (int j = top[i]-1; j >= 0; j--)
                a[tt++] = s[i][j];

        //for (int i = 0; i < n; i++)
        //    printf("%d --> %d\n",i,a[i]);

        for (int i = 0;i < n;i++)
        {
            cnt[i] = 0;
            f[i] = i;
        }
        for (int i = 0;i < n;i++)
        {
            int fa = findf(i);
            int fb = findf(f[a[i]]);
            if (fa != fb)
                f[fa] = fb;
        }

        for (int i = 0;i < n;i++)
            cnt[findf(i)]++;

        long long res = 1;
        for (int i = 0;i < n;i++)
            if (cnt[i] > 0)
                res = lcm(res,cnt[i]);
        printf("%I64d\n",res);

    }
    return 0;
}
