#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
struct node
{
    long long w,c;
}g[60];
long long w,lasw[60],lasc[60],res;

bool cmp(node a,node b)
{
    if (a.w == b.w) return a.c > b.c;
    return a.w > b.w;
}

void DFS(int deep,long long noww,long long nowc,long long lasno)
{
    if (noww > w)   return;
    res = max(res,nowc);
    if (deep > n)   return;
    if (g[deep].w == lasno)
    {
        DFS(deep+1,noww,nowc,lasno);
        return;
    }
    if (nowc+lasc[deep] <= res) return;
    if (noww+lasw[deep] <= w)
    {
        res = max(res,nowc+lasc[deep]);
        return;
    }
    DFS(deep+1,noww+g[deep].w,nowc+g[deep].c,lasno);
    DFS(deep+1,noww,nowc,g[deep].w);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%lld",&n,&w);
        for (int i = 1;i <= n;i++)
            scanf("%lld%lld",&g[i].w,&g[i].c);
        sort(g+1,g+1+n,cmp);
        lasw[n+1] = lasc[n+1] = 0;
        for (int i = n;i >= 1;i--)
        {
            lasw[i] = lasw[i+1]+g[i].w;
            lasc[i] = lasc[i+1]+g[i].c;
        }
        res = 0;
        DFS(1,0,0,-1);
        printf("Case %d: %lld\n",ft,res);
    }
}
