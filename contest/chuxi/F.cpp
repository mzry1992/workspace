#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Edge
{
    int u,v,w,tw;
    friend bool operator < (const Edge &a,const Edge &b)
    {
        return a.tw < b.tw;
    }
};

Edge edge[1000];
int n,m,f[50];

int findf(int x)
{
    if (x != f[x])  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
            edge[i].u--;
            edge[i].v--;
            edge[i].tw = (n-1)*edge[i].w*edge[i].w-edge[i].w;
        }
        sort(edge,edge+n);
        for (int i = 0;i < n;i++)
            f[i] = i;
        int fa,fb,resa,resb;
        resa = resb = 0;
        for (int i = 0;i < m;i++)
        {
            fa = findf(edge[i].u);
            fb = findf(edge[i].v);
            if (fa == fb)   continue;
            f[fa] = fb;
            resa += edge[i].w*edge[i].w;
            resb += edge[i].w;
        }
        resa *= n-1;
        int res = resa-resb*resb;
        double ans = (double)res/(double)((n-1)*(n-1));
        printf("Case %d: %.2f\n",++ft,ans);
    }
    return 0;
}
