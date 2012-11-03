#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

pair<long long,long long>
long long n,a[1000000];
int fac[1000],cnt[1000],tot,q,totfac;

void Gao(int now,long long mut,int leav)
{
    if (now == tot)
    {
        long long a = n/mut;
        long long b = 1LL<<leav;
        b--;
        a = a-b;
        return;
    }
    for (int i = 0;i <= cnt[now];i++)
    {
        Gao(now+1,mut,leav-i);
        mut *= fac[now];
    }
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%lld%d",&n,&q);
        for (int i = 2;i*i <= n;i++)
            if (n%i == 0)
            {
                fac[tot] = i;
                cnt[tot] = 0;
                while (n%i == 0)
                {
                    n /= i;
                    cnt[tot]++;
                }
                tot++;
            }
        if (n != 1)
        {
            fac[tot] = n;
            cnt[tot++] = 1;
        }
        totfac = 0;
        for (int i = 0;i < tot;i++)
            totfac += cnt[i];
        Gao(0,1,totfac);
        for (int i = 0;i < q;i++)
            scanf("%lld",&a[i]);
    }
	return 0;
}
