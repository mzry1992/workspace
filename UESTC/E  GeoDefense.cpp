#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Edge
{
    int to,next;
};

Edge edge[2000];
int head[1000],L;
int ki[1000],pr[1000][1000],po[1000][1000];
int n,m,u,v;

void addedge(int u,int v)
{
    edge[L].to = v;
    edge[L].next = head[u];
    head[u] = L++;
}

int dp[1000][210];
bool visit[1000];

void Gao(int now)
{
    visit[now] = true;

    int f[210],tf[210];
    for (int i = 0; i <= m; i++)
        f[i] = 0;

    bool first = true;

    for (int i = head[now]; i != -1; i = edge[i].next)
        if (visit[edge[i].to] == false)
        {
            Gao(edge[i].to);
            for (int j = 0;j <= m;j++)
                tf[j] = 0;
            if (first == true)
            {
                for (int j = 0;j <= m;j++)
                    tf[j] = dp[edge[i].to][j];
            }
            else
            {
                for (int j = 0; j <= m; j++)
                    for (int k = 0; j+k <= m; k++)
                        tf[j+k] = max(tf[j+k],min(f[j],dp[edge[i].to][k]));
            }
            for (int j = 0;j <= m;j++)
                f[j] = tf[j];
            first = false;
        }

    for (int i = 0; i < ki[now]; i++)
        for (int j = pr[now][i]; j <= m; j++)
            dp[now][j] = max(dp[now][j],f[j-pr[now][i]]+po[now][i]);

}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1; ft <= t; ft++)
    {
        scanf("%d",&n);
        L = 0;
        for (int i = 0; i < n; i++)
            head[i] = -1;
        for (int i = 0; i < n-1; i++)
        {
            scanf("%d%d",&u,&v);
            u--;
            v--;
            addedge(u,v);
            addedge(v,u);
        }
        scanf("%d",&m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&ki[i]);
            for (int j = 0; j < ki[i]; j++)
                scanf("%d%d",&pr[i][j],&po[i][j]);
        }
        memset(visit,false,sizeof(visit));
        memset(dp,0,sizeof(dp));
        Gao(0);
        int res = 0;
        for (int i = 0;i <= m;i++)
            res = max(res,dp[0][i]);
        printf("%d\n",res);
    }
    return 0;
}
