#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n,m;
int map[20][20];
int va[20];
struct graph
{
    int a,b,cost;
}g[400];
int totg = 0;
int f[20];
int mina,minb,ans;

bool cmp(graph a,graph b)
{
    return a.cost < b.cost;
}

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

void updata(int sta)
{
    int sumn,sume;
    sumn = sume = 0;
    for (int i = 1;i <= n;i++)
    if ((sta>>(i-1))&1)
        sumn += va[i];
    totg = 0;
    for (int i = 1;i <= n;i++)
    if ((sta>>(i-1))&1)
    for (int j = 1;j <= n;j++)
    if ((sta>>(j-1))&1)
    {
        totg++;
        g[totg].a = i;
        g[totg].b = j;
        g[totg].cost = map[i][j];
    }
    sort(g+1,g+1+totg,cmp);
    for (int i = 1;i <= n;i++)
        f[i] = i;
    int sum = 0;
    for (int i = 1;i <= totg;i++)
    {
        int fa,fb;
        fa = findf(g[i].a);
        fb = findf(g[i].b);
        if (fa != fb)
        {
            sum++;
            sume += g[i].cost;
            f[fa] = fb;
        }
        if (sum == m)
            break;
    }
    //cout << sta << ' ' << sume << ' ' << sumn << ' ' << (double)sume/(double)sumn << ' ' << (double)mina/(double)minb << endl;
    if (sume*minb < sumn*mina)
    {
        mina = sume;
        minb = sumn;
        ans = sta;
    }
    else if (sume*minb == sumn*mina)
    {
        if (ans > sta)
            ans = sta;
    }
}

void DFS(int now,int tot,int sta)
{
    if (now == n+1)
        return;
    if (n-now < m-tot)
        return;
    if (tot == m)
    {
        DFS(now+1,tot,(sta<<1));
        updata(sta);
        return;
    }
    DFS(now+1,tot+1,(sta<<1)+1);
    DFS(now+1,tot,(sta<<1));
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)
            break;
        for (int i = 1;i <= n;i++)
            scanf("%d",&va[i]);
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            scanf("%d",&map[i][j]);
        mina = 1;
        minb = 0;
        ans = 0;
        DFS(1,0,0);
        DFS(1,1,1);
        int sumo = 0;
        for (int i = 1;i <= n;i++)
        if ((ans>>(i-1))&1)
        {
            sumo++;
            printf("%d",i);
            if (sumo < m)
                printf(" ");
        }
        printf("\n");
    }
}
