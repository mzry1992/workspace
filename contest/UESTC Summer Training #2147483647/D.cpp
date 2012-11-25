#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool g[100][100];
long long mp[100][100];
int n,m;
int f[100];

int findf(int x)
{
    if (x != f[x])  f[x] = findf(f[x]);
    return f[x];
}

bool vis[100];
int a[100],tot,ans[110],len;
bool DFS(int now,int from)
{
    a[tot++] = now;
    if (vis[now] == true)
    {
        len = 0;
        ans[len++] = a[--tot];
        while (true)
        {
            ans[len++] = a[--tot];
            if (ans[len-1] == now)
                break;
        }
        return true;
    }
    vis[now] = true;

    for (int i = 0; i < n; i++)
        if (i != from && g[now][i])
            if (DFS(i,now)) return true;

    tot--;
    vis[now] = false;
    return false;
}

long long cost[110];

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++)
            f[i] = i;
        memset(g,false,sizeof(g));
        long long cntng = 0;
        for (int i = 0; i < m; i++)
        {
            int u,v;
            long long c;
            scanf("%d%d%lld",&u,&v,&c);

            if (c <= 0)
                cntng += c;
            else
            {
                mp[u][v] = mp[v][u] = c;
                g[u][v] = g[v][u] = true;

                f[findf(u)] = findf(v);
            }
        }

        bool flag = true;
        for (int i = 0; i < n && flag; i++)
            if (findf(i) != findf(0))
                flag = false;
        if (!flag)
        {
            printf("%lld\n",cntng);
            continue;
        }

        tot = 0;
        memset(vis,false,sizeof(vis));
        long long minedg = 0x7fffffffffffffff;

        if (DFS(0,-1))
        {
            for (int i = 1; i < len; i++)
            {
                cost[i-1] = mp[ans[i-1]][ans[i]];
                g[ans[i-1]][ans[i]] = g[ans[i]][ans[i-1]] = false;
            }
            sort(cost,cost+len-1);
            minedg = cost[0]+cost[1];
        }

        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                if (g[i][j])
                    minedg = min(minedg,mp[i][j]);
        printf("%lld\n",cntng+minedg);
    }
    return 0;
}
