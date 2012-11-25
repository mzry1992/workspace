#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[105];
int mp[105];
int n,m;
int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}
bool res[105],vis[105];
int g[105][105];
bool dfs(int now,int fa,int root)
{
    if (root != fa && g[now][root] >0)  return true;
    vis[now] = true;
    for (int i = 0;i < n;i++)
        if (i != fa && g[now][i]>0 && vis[i] == false)
            if (dfs(i,now,root))
                return true;
    return false;
}
int main()
{
    while (scanf("%d%d",&n,&m) == 2)
    {
        memset(g,0,sizeof(g));
        for (int i = 0;i < n;i++)
        {
            res[i] = false;
            f[i] = i;
            mp[i] = 0;
        }
        for (int i = 0;i < m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;

            g[u][v]++;g[v][u]++;

            if (findf(u) != findf(v))
                f[findf(u)] = findf(v);

            if (u == 0)
                mp[v]++;
        }
        int cnt = 0,sum = 0;
        for (int i = 1;i < n;i++)
        {
            sum += mp[i];
            if (mp[i] > 1)
            {
                if(mp[i]%2 == 0)
                    res[0]=true;
                cnt++;
            }
        }
        if(sum == 0)
            res[0]=true;
        for (int i = 1;i < n;i++)
            if (findf(0) == findf(i))
                res[i] = true;
        memset(vis,false,sizeof(vis));
        bool tmp=dfs(0,-1,0);
        if(!res[0])
            res[0]=tmp;
        if (cnt == 1)
        {
            for (int i = 1;i < n;i++)
                if (mp[i] > 1 && mp[i]%2 == 0 && !tmp)
                {
                    res[i]=false;
                    for(int j = 1;j < n;j++)
                        if(g[i][j]>1)
                            res[i]=true;
                    if(!res[i])
                    {
                        g[0][i]--;g[i][0]--;
                        memset(vis,false,sizeof(vis));
                        res[i]=dfs(i,-1,i);
                    }
                    break;
                }
        }
        bool first = true;
        for (int i = 0;i < n;i++)
            if (res[i] == true)
            {
                if (!first)
                    printf(" ");
                first = false;
                printf("%d",i+1);
            }
        printf("\n");
    }
    return 0;
}

