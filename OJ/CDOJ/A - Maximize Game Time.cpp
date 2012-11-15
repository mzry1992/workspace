#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int T[1010],P[1010];
int dp[1010],dp2[1010];
int sum[1010],sum1[1010];
struct graph
{
    int next,to;
}buf[20010];
int totn;

void addEdge(int u,int v)
{
    buf[totn].to = v;
    buf[totn].next = buf[u].next;
    buf[u].next = totn;
    totn++;
}

void getsum(int root)
{
    int v;
    sum[root] = T[root];
    for (int i = buf[root].next;i != -1;i = buf[i].next)
    {
        v = buf[i].to;
        getsum(v);
        sum[root] += sum[v];
    }
}

void treedp2(int root)
{
    int u,v;
    dp2[root] = 0;
    sum1[root] = 0;
    if (buf[root].next == -1)   return;
    for (int i = buf[root].next;i != -1;i = buf[i].next)
        treedp2(buf[i].to);
    for (int i = buf[root].next;i != -1;i = buf[i].next)
    {
        u = buf[i].to;
        int tres = sum[u];
        for (int j = buf[root].next;j != -1;j = buf[j].next)
        {
            v = buf[j].to;
            if (u == v) continue;
            tres += dp2[v];
        }
        sum1[root] += dp2[u];
        dp2[root] = max(dp2[root],tres);
    }
}

void treedp(int root)
{
    int u,v;
    dp[root] = T[root];
    if (buf[root].next == -1)   return;
    for (int i = buf[root].next;i != -1;i = buf[i].next)
        treedp(buf[i].to);
    bool hastwo = false;
    for (int i = buf[root].next;i != -1;i = buf[i].next)
    {
        u = buf[i].to;
        for (int j = buf[root].next;j != -1;j = buf[j].next)
        {
            v = buf[j].to;
            if (u == v) continue;
            int tres = sum1[root]-dp2[u]-dp2[v];
            hastwo = true;
            dp[root] = max(dp[root],tres+sum[u]+dp[v]+T[root]);
        }
    }
    if (hastwo == false)
        dp[root] = sum[buf[buf[root].next].to]+T[root];
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%d",&T[i]);
        for (int i = 0;i < n;i++)
            buf[i].next = -1;
        totn = n;
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&P[i]);
            if (P[i]!=-1)
                addEdge(P[i],i);
        }
        memset(sum,0,sizeof(sum));
        for (int i = 0;i < n;i++)
        if (P[i] == -1)
            getsum(i);
        memset(dp,0,sizeof(dp));
        treedp2(n-1);
        treedp(n-1);
        for (int i = 0;i < n-1;i++)
        if (P[i] == -1)
            dp[n-1] += sum[i];
        printf("%d\n",dp[n-1]);
    }
}
