#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long n,m;
long long T[60],G[60],K[60],E[60][60],allget[60],nextget[60];
bool visit[60],g[60][60],dag[60][60];
int f[60],ind[60],pass[60],totpass,sc[60][60],totsc[60];
long long minres;
struct node
{
    int ti,gi;
}goods[60];
int totgoods;

bool cmp(node a,node b)
{
    if (a.gi == b.gi)   return a.ti < b.ti;
    return a.gi > b.gi;
}

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

void DFS(int now,long long sumt,long long sumg)
{
    if (sumt >= minres) return;
    if (sumg+nextget[now+1] < m)    return;
    if (sumg >= m)
    {
        minres = sumt;
        return;
    }
    DFS(now+1,sumt+goods[now+1].ti,sumg+goods[now+1].gi);
    DFS(now+1,sumt,sumg);
}

void DFSPath(int now)
{
    bool hasnext = false;
    totpass++;
    pass[totpass] = now;
    for (int i = 1;i <= n;i++)
        if (dag[now][i] == true)
        {
            DFSPath(i);
            hasnext = true;
        }
    if (hasnext == false)
    {
        totgoods = 0;
        for (int i = 1;i <= totpass;i++)
            for (int j = 1;j <= totsc[pass[i]];j++)
            {
                totgoods++;
                goods[totgoods].ti = T[sc[pass[i]][j]];
                goods[totgoods].gi = G[sc[pass[i]][j]];
            }
        sort(goods+1,goods+1+totgoods,cmp);
        memset(nextget,0,sizeof(nextget));
        for (int i = totgoods;i >= 1;i--)
            nextget[i] = nextget[i+1]+goods[i].gi;
        DFS(1,0,0);
        DFS(1,goods[1].ti,goods[1].gi);
        totpass--;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%lld%lld",&n,&m);
        memset(g,false,sizeof(g));
        for (int i = 1;i <= n;i++)
        {
            scanf("%lld%lld%lld",&T[i],&G[i],&K[i]);
            for (int j = 1;j <= K[i];j++)
            {
                scanf("%lld",&E[i][j]);
                g[i][E[i][j]] = true;
            }
        }
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                    if (g[i][k] == true && g[k][j] == true)
                        g[i][j] = true;
        for (int i = 1;i <= n;i++)
            f[i] = i;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (g[i][j] == true && g[j][i] == true)
                    f[findf(j)] = findf(i);
        memset(dag,false,sizeof(dag));
        memset(ind,0,sizeof(ind));
        memset(totsc,0,sizeof(totsc));
        for (int i = 1;i <= n;i++)
        {
            totsc[findf(i)]++;
            sc[findf(i)][totsc[findf(i)]] = i;
        }
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (findf(i) != findf(j))
                    if (g[i][j] == true)
                    {
                        dag[findf(i)][findf(j)] = true;
                        ind[findf(j)]++;
                    }
        minres = 510000000;
        for (int i = 1;i <= n;i++)
            if (findf(i) == i)
                if (ind[findf(i)] == 0)
                {
                    totpass = 0;
                    DFSPath(findf(i));
                }
        if (minres == 510000000)
            printf("Case %d: Poor Magina, you can't save the world all the time!\n",ft);
        else
            printf("Case %d: %lld\n",ft,minres);
    }
}
