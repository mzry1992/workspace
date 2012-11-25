#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int a,b,c,x;
    bool operator < (const Edge& ttt) const
    {
        return c < ttt.c;
    }
};

int n,m,w,f[50000],res;
Edge e[100000];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int check(int val)
{
    for (int i = 0;i < n;i++)
        f[i] = i;
    for (int i = 0;i < n;i++)
        e[i].c += e[i].x*val;
    sort(e,e+m);
    int totb = 0;
    res = 0;
    for (int i = 0,j = 0;i < m;i++)
    {
        int fa = findf(e[i].a);
        int fb = findf(e[i].b);
        if (fa != fb)
        {
            f[fa] = fb;
            j++;
            totb += e[i].x;
            res += e[i].c-e[i].x*val;
            if (j == n-1)   break;
        }
    }
    for (int i = 0;i < n;i++)
        e[i].c -= e[i].x*val;
    return n-1-totb;
}

int main()
{
    int cas = 0;
    while (scanf("%d%d%d",&n,&m,&w) != EOF)
    {
        for (int i = 0; i < m; i++)
            scanf("%d%d%d%d",&e[i].a,&e[i].b,&e[i].c,&e[i].x);
        int l,r,mid;
        l = -1000;
        r = 1000;
        for (int i = 0;i < 50;i++)
        {
            mid = (l+r)>>1;
            if (check(mid) < w)
                l = mid;
            else
                r = mid;
        }
        printf("Case %d: %d\n",++cas,res);
    }
    return 0;
}
