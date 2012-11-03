#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long m,maxres,nextget[60];
struct node
{
    long long w,c;
}g[60];

bool cmp(node a,node b)
{
    if (a.w == b.w) return a.c > b.c;
    return a.w > b.w;
}

void DFS(int now,long long totw,long long totc,int lastno)
{
    if (totw > m)   return;
    if (totc+nextget[now+1] <= maxres)   return;
    if (totc > maxres)  maxres = totc;
    if (g[now+1].c != g[lastno].c || lastno == 0)
        DFS(now+1,totw+g[now+1].w,totc+g[now+1].c,lastno);
    DFS(now+1,totw,totc,now+1);
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%lld",&n,&m);
        long long sumw,sumc;
        sumw = sumc = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%lld%lld",&g[i].w,&g[i].c);
            sumw += g[i].w;
            sumc += g[i].c;
        }
        sort(g+1,g+1+n,cmp);
        memset(nextget,0,sizeof(nextget));
        for (int i = n;i >= 1;i--)
            nextget[i] = nextget[i+1]+g[i].c;
        maxres = 0;
        DFS(0,0,0,0);
        printf("Case %d: %lld\n",ft,maxres);
    }
}
