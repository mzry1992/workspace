#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,f[10000001],sum[10000001],a,b,res,fa,fb;

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= 10000000;i++)
        {
            f[i] = i;
            sum[i] = 1;
        }
        res = 1;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&a,&b);
            fa = findf(a);
            fb = findf(b);
            if (fa != fb)
            {
                res = max(res,sum[fa]+sum[fb]);
                f[fb] = fa;
                sum[fa] = sum[fa]+sum[fb];
            }
        }
        printf("%d\n",res);
    }
}
