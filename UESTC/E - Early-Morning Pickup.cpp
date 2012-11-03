#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,g[600][600];
int S[600],T[600],C[600],M[600],tR,tC,tM;
int map[600][600],matchy[600],lx[600],ly[600];
bool visx[600],visy[600];
int lack;

bool find(int x)
{
    visx[x] = true;
    int t;
    for (int y = 1;y <= tR;y++)
    {
        if (!visy[y])
        {
            t = lx[x]+ly[y]-map[x][y];
            if (t == 0)
            {
                visy[y] = true;
                if (matchy[y] == -1 || find(matchy[y]))
                {
                    matchy[y] = x;
                    return true;
                }
            }
            else if (lack > t)  lack = t;
        }
    }
    return false;
}

int KM()
{
    memset(lx,0,sizeof(lx));
    memset(ly,0,sizeof(ly));
    memset(matchy,-1,sizeof(matchy));
    for (int i = 1;i <= tR;i++)
        for (int j = 1;j <= tR;j++)
            if (map[i][j] > lx[i])
                lx[i] = map[i][j];
    for (int x = 1;x <= tR;x++)
    {
        while (true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            lack = 1992100500;
            if (find(x))    break;
            for (int i = 1;i <= tR;i++)
            {
                if (visx[i])    lx[i] -= lack;
                if (visy[i])    ly[i] += lack;
            }
        }
    }
    int cost = 0;
    for (int i = 1;i <= tR;i++)
        cost += map[matchy[i]][i];
    return cost;
}

int uper(int x,int y)
{
    if (x%y == 0)   return x/y;
    return (x/y)+1;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                g[i][j] = 19921005;
        for (int i = 1;i <= m;i++)
        {
            int u,v,cost;
            scanf("%d%d%d",&u,&v,&cost);
            g[u][v] = g[v][u] = min(g[u][v],cost);
        }
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                    if (g[i][j] > g[i][k]+g[k][j])
                        g[i][j] = g[i][k]+g[k][j];
        scanf("%d",&tR);
        for (int i = 1;i <= tR;i++) scanf("%d%d",&S[i],&T[i]);
        scanf("%d",&tC);
        for (int i = 1;i <= tC;i++) scanf("%d",&C[i]);
        scanf("%d",&tM);
        for (int i = 1;i <= tM;i++) scanf("%d",&M[i]);
        for (int i = 1;i <= tR;i++)
        {
            for (int j = 1;j <= tC;j++)
            {
                map[i][j] = 19921005;
                for (int k = 1;k <= tM;k++)
                    if (map[i][j] > g[S[i]][C[j]]+g[C[j]][M[k]]+g[M[k]][T[i]])
                        map[i][j] = g[S[i]][C[j]]+g[C[j]][M[k]]+g[M[k]][T[i]];
            }
            for (int j = tC+1;j <= tR;j++)
                map[i][j] = g[S[i]][T[i]];
        }
        for (int i = 1;i <= tR;i++)
            for (int j = 1;j <= tR;j++)
                map[i][j] = -map[i][j];
        int mincost = uper(-KM(),tR);
        int nh,nm;
        nh = 8;
        nm = 0;
        nm = mincost%60;
        nh += mincost/60;
        printf("%02d:%02d\n",nh,nm);
    }
}
