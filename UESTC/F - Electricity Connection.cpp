#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char map[10][10];
int pl,pw;
int dis[100][100];
int xy[10][10];
struct graph
{
    int u,v;
    int cost;
    bool operator < (const graph &a) const
    {
        return cost < a.cost;
    }
}g[10000];
int totg;
int f[100];
int gx,gy;

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        scanf("%d%d",&pl,&pw);
        for (int i = 0;i < 8;i++)
            scanf("%s",map[i]);
        for (int i = 1;i <= 64;i++)
        for (int j = 1;j <= 64;j++)
            dis[i][j] = 19921005;
        for (int i = 0;i < 8;i++)
        for (int j = 0;j < 8;j++)
        {
            if (map[i][j] == 'G')
            {
                gx = i;
                gy = j;
            }
            xy[i][j] = i*8+j+1;
            if (map[i][j] == '.')   dis[xy[i][j]][xy[i][j]] = pl;
            else if (map[i][j] == 'W') dis[xy[i][j]][xy[i][j]] = pw;
            else dis[xy[i][j]][xy[i][j]] = 0;
        }
        for (int i = 0;i < 8;i++)
        for (int j = 0;j < 8;j++)
        for (int k = j+1;k < 8;k++)
        {
            bool flag = true;
            for (int q = j+1;q <= k;q++)
            if (map[i][q] == 'H' || map[i][q] == 'G')
                flag = false;
            if (flag == true)
            {
                int cost = k-j;
                for (int q = j+1;q <= k;q++)
                if (map[i][q] == '.')
                    cost += pl;
                else
                    cost += pw;
                dis[xy[i][j]][xy[i][k]] = dis[xy[i][k]][xy[i][j]] = cost;
            }
            flag = true;
            for (int q = j+1;q <= k;q++)
            if (map[q][i] == 'H' || map[q][i] == 'G')
                flag = false;
            if (flag == true)
            {
                int cost = k-j;
                for (int q = j+1;q <= k;q++)
                if (map[q][i] == '.')
                    cost += pl;
                else
                    cost += pw;
                dis[xy[j][i]][xy[k][i]] = dis[xy[k][i]][xy[j][i]] = cost;
            }
        }
        totg = 0;
        for (int i = 1;i <= 64;i++)
        for (int j = 1;j <= 64;j++)
        if (dis[i][j] != 19921005)
        {
            totg++;
            g[totg].u = i;
            g[totg].v = j;
            g[totg].cost = dis[i][j];
        }
        sort(g+1,g+1+totg);
        int res = 19921005;
        for (int l = 1;l <= totg;l++)
        {
            cout << l << endl;
            for (int i = 1;i <= 64;i++)
                f[i] = i;
            int cur = 0;
            int tres = 0;
            bool isres = true;
            for (int k = 1;k <= l;k++)
            {
                if (isres == false) break;
                while (true)
                {
                    cur++;
                    if (cur > totg)
                    {
                        isres = false;
                        break;
                    }
                    int fa = findf(g[cur].u);
                    int fb = findf(g[cur].v);
                    if (fa != fb)
                    {
                        f[fa] = fb;
                        tres += g[cur].cost;
                        break;
                    }
                }
            }
            if (isres == false) continue;
            bool flag = true;
            for (int i = 0;i < 8;i++)
            for (int j = 0;j < 8;j++)
            if (map[i][j] == 'H')
            if (findf(f[xy[i][j]]) != findf(f[xy[gx][gy]]))
                flag = false;
            if (flag == true)
            if (tres < res)
                res = tres;
        }
        printf("%d\n",res);
    }
}
