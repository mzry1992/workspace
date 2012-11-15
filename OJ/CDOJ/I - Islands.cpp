#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m,q,tot,cur,map[1200][1200],h[120000],res[120000];
struct node
{
    int x,y,h;
}g[1200000];
int f[1200000];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

bool cmp(node a,node b)
{
    return a.h > b.h;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
            {
                scanf("%d",&map[i][j]);
                g[(i-1)*m+j].x = i;
                g[(i-1)*m+j].y = j;
                g[(i-1)*m+j].h = map[i][j];
                f[(i-1)*m+j] = (i-1)*m+j;
            }
        sort(g+1,g+1+n*m,cmp);
        scanf("%d",&q);
        for (int i = 1;i <= q;i++)
            scanf("%d",&h[i]);
        tot = 0;
        cur = 1;
        for (int i = q;i >= 1;i--)
        {
            for (;g[cur].h > h[i] && cur <= n*m;cur++)
            {
                int x,y,tx,ty;
                x = g[cur].x;
                y = g[cur].y;
                tot++;
                for (int j = 0;j < 4;j++)
                {
                    tx = x+step[j][0];
                    ty = y+step[j][1];
                    if (tx >= 1 && tx <= n && ty >= 1 && ty <= m)
                        if (map[tx][ty] > h[i])
                            if (findf((tx-1)*m+ty) != findf((x-1)*m+y))
                            {
                                f[findf((tx-1)*m+ty)] = findf((x-1)*m+y);
                                tot--;
                            }
                }
            }
            res[i] = tot;
        }
        for (int i = 1;i <= q;i++)
            printf("%d ",res[i]);
        printf("\n",res[q]);
    }
}
