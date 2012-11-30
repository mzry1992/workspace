#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

struct Edge
{
    int to,next,col;
} edge[600000];
int head[300000],L;
int w[300000],n;

void addedge(int u,int v,int col)
{
    edge[L].to = v;
    edge[L].col = col;
    edge[L].next = head[u];
    head[u] = L++;
}

long long dp[300000];
int num[300000];
long long ans;
//dp[i] -> 和父节点相连
void DP(int u,int fa,int col)
{
    dp[u] = 0;
    num[u] = 1;

    map<int,long long> cols;
    map<int,int> cntcols;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)	continue;

        DP(v,u,edge[i].col);

        if (edge[i].col != col)
        {
            dp[u] += dp[v];
            num[u] += num[v];
        }
		ans += dp[v]+(long long)num[v]*w[u];
        cols[edge[i].col] += dp[v];
        cntcols[edge[i].col] += num[v];
    }
    dp[u] += (long long)num[u]*w[u];

    if (cols.size() != 1)
    {
        long long tans = 0,sumcol = 0,sumnum = 0;

        for (map<int,long long>::iterator it = cols.begin(); it != cols.end(); it++)
        {
            int colj = it->first;
			sumcol += cols[colj];
			sumnum += cntcols[colj];
        }
        for (map<int,long long>::iterator it = cols.begin(); it != cols.end(); it++)
        {
            int coli = it->first;
			tans += cols[coli]*(sumnum-cntcols[coli])+cntcols[coli]*(sumcol-cols[coli]+(sumnum-cntcols[coli])*w[u]);
        }
        ans += tans/2;
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&w[i]);
            head[i] = -1;
        }
        L = 0;
        for (int i = 0; i < n-1; i++)
        {
            int u,v,col;
            scanf("%d%d%d",&u,&v,&col);
            u--;
            v--;
            addedge(u,v,col);
            addedge(v,u,col);
        }
        ans = 0;
        DP(0,-1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}
