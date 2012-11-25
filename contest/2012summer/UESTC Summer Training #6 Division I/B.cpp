#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct edge
{
    int a,b,cost;
    bool operator < (const edge& b)const
    {
        return cost < b.cost;
    }
};

edge e[500*500];
int n,m,f[500];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    while (totcas--)
    {
        scanf("%d%d",&n,&m);
        for (int i = 0;i < m;i++)
            scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].cost);
        sort(e,e+m);
        for (int i = 0;i < n;i++)
            f[i] = i;
        int res = 0;
        for (int i = 0;i < m;i++)
        {
            int fa = findf(e[i].a);
            int fb = findf(e[i].b);
            if (fa != fb)
            {
                res += e[i].cost;
                f[fa] = fb;
            }
        }
        printf("%d\n",res);
    }
	return 0;
}
