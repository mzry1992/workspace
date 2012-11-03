#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[100010],c[100010];
int n,m,k;
int f[100010],b[100010],w[100010];
int totb,totw,tot;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        totb = totw = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&c[i]);
            if (c[i] == 0)  totw++;
            else totb++;
        }
        tot = 0;
        memset(b,0,sizeof(b));
        memset(w,0,sizeof(w));
        a[0] = k-1;
        for (int i = 1;i <= n;i++)
            if (a[i] >= k)
            {
                if (a[i-1] < k) tot++;
                f[i] = tot;
                if (c[i] == 0)  w[f[i]]++;
                else b[f[i]]++;
            }
            else
                f[i] = -1;
        long long res = (long long)n*(long long)(n-1)/2LL;
        long long part3 = 0;
        for (int i = 1;i <= tot;i++)
            part3 += (long long)b[i]*(long long)w[i];
        for (int i = 0;i < m;i++)
        {
            int u,v;
            scanf("%d",&u);
            if (u == 0)
            {
                scanf("%d",&v);
                if (c[v] == 0)
                {
                    totw--;
                    totb++;
                    c[v] = 1;
                    if (f[v] != -1)
                    {
                        part3 -= (long long)b[f[v]]*(long long)w[f[v]];
                        b[f[v]]++;
                        w[f[v]]--;
                        part3 += (long long)b[f[v]]*(long long)w[f[v]];
                    }
                }
                else
                {
                    totw++;
                    totb--;
                    c[v] = 0;
                    if (f[v] != -1)
                    {
                        part3 -= (long long)b[f[v]]*(long long)w[f[v]];
                        b[f[v]]--;
                        w[f[v]]++;
                        part3 += (long long)b[f[v]]*(long long)w[f[v]];
                    }
                }
            }
            else
            {
                long long tres = res-part3;
                tres -= (long long)totb*(long long)(totb-1)/2LL;
                tres -= (long long)totw*(long long)(totw-1)/2LL;
                printf("%lld\n",tres);
            }
        }
    }
}
