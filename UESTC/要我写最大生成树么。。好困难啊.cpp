#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct graph
{
    int a,b;
    long long cost;
    int index;
}g[120000];
int n,m;
long long s;
int f[51000];
int flag[51000];

bool cmp(graph a,graph b)
{
    return a.cost > b.cost;
}

bool cmp2(graph a,graph b)
{
    return a.cost < b.cost;
}

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    bool first = true;
    while (scanf("%d%d%lld",&n,&m,&s) != EOF)
    {
        if (!first)
            printf("\n");
        first = false;
        for (int i = 1;i <= m;i++)
            scanf("%d%d%lld",&g[i].a,&g[i].b,&g[i].cost);
        for (int i = 1;i <= m;i++)
            g[i].index = i;
        for (int i = 1;i <= n;i++)
            f[i] = i;
        sort(g+1,g+m+1,cmp);
        int tot = 0;
        memset(flag,false,sizeof(flag));
        for (int now = 1;now <= m;now++)
        {
            int ta,tb;
            ta = g[now].a;
            tb = g[now].b;
            int fa = findf(ta);
            int fb = findf(tb);
            if (fa != fb)
            {
                tot++;
                f[fa] = fb;
                g[now].cost = 11000000000000LL;
            }
            if (tot == n-1)
                break;
        }
        sort(g+1,g+m+1,cmp2);
        int ans[110000];
        tot = 0;
        for (int i = 1;i <= m;i++)
        if (g[i].cost != 11000000000000LL)
        if (g[i].cost <= s)
        {
            s -= g[i].cost;
            tot++;
            ans[tot] = g[i].index;
        }
        sort(ans+1,ans+1+tot);
        printf("%d\n",tot);
        for (int i = 1;i <= tot;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
}
