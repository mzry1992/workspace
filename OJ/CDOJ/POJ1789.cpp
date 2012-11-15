#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
char map[2010][10];
struct graph
{
    int u,v,dist;
    bool operator < (const graph &a) const
    {
        return dist < a.dist;
    }
}g[4000000];
int f[2010];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%s",map[i]);
        int tot;
        tot = 0;
        for (int i = 0;i < n;i++)
        for (int j = i+1;j < n;j++)
        {
            g[tot].u = i;
            g[tot].v = j;
            g[tot].dist = 0;
            for (int k = 0;k < 7;k++)
            if (map[i][k] != map[j][k])
                g[tot].dist++;
            tot++;
        }
        sort(g,g+tot);
        for (int i = 0;i < n;i++)
            f[i] = i;
        int cur = -1;
        int res = 0;
        for (int i = 0;i < n-1;i++)
        {
            while (true)
            {
                cur++;
                int fa = findf(g[cur].u);
                int fb = findf(g[cur].v);
                if (fa != fb)
                {
                    res += g[cur].dist;
                    f[fa] = fb;
                    break;
                }
            }
        }
        printf("The highest possible quality is 1/%d.\n",res);
    }
}
