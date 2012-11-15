#include<map>
#include<set>
#include<vector>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define arr       1010
#define brr       1000000
#define inf       -1u>>1

int n,m,root = 1,g[arr][arr];
int eu[brr],ev[brr], ew[brr];
vector<int>e[arr], f[arr];

typedef vector<int>::iterator vit;
bool flg[arr], use[arr];
int pi[arr],di[arr];

void dfs (int x)
{
    flg[x] = true;
    for ( vit it = e[x].begin(); it !=e[x].end(); it++ )
    {
        if ( !flg[ ev[*it ] ] )dfs(ev[*it]);
    }
}

int mstree ()
{
    int res = 0;
    fill(flg + 1, flg + n + 1, false);
    while ( true )
    {
        for ( int i = 1; i <= n; i++ )
        {
            pi[i] = i, di[i] = inf;
            if ( i == root || flg[i] )continue;
            for ( vit it = f[i].begin(); it != f[i].end(); it++ )
            {
                if ( flg[ eu[*it] ] )continue;
                if ( di[i] > ew[*it])
                {
                    di[i] = ew[*it];
                    pi[i] = eu[*it];
                }
            }
        }
        int end = 0, idx;
        for ( int i = 1; i <= n; i++ )
        {
            if ( i == root || flg[i] )continue;
            fill(use + 1, use + n + 1,false);
            for ( int &j = idx = i; j!= root && !use[j]; j = pi[j] )
            {
                use[j] = 1;
            }
            if ( idx == root ) continue;
            res += di[idx], flg[idx] = 1;
            for ( int j = pi[idx]; j !=idx; j = pi[j] )
            {
                res += di[j], flg[j] =1;
            }
            for (vit it = f[idx].begin(); it != f[idx].end(); it++)
            {
                if (!flg[eu[*it]])
                {
                    ew[*it] -=di[idx];
                }
            }
            for ( int j = pi[idx]; j !=idx; j = pi[j] )
            {
                for (vit it =f[j].begin(); it != f[j].end(); it++)
                {
                    if(!flg[eu[*it]])
                    {
                        ev[*it] =idx;
                        ew[*it] -=di[j];
                        f[idx].push_back(*it);
                    }
                }
                for (vit it =e[j].begin(); it != e[j].end(); it++)
                {
                    if (!flg[ev[*it]])
                    {
                        eu[*it] =idx;
                        e[idx].push_back(*it);
                    }
                }
            }
            flg[idx] = 0;
            end = 1;
        }
        if (end == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (!flg[i] &&i != root)
                {
                    res += di[i];
                }
            }
            break;
        }
    }
    return res;
}

struct Point
{
    int x,y,z;
};

Point p[1010];
int X,Y,Z;

int DIS(Point a,Point b)
{
    return abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
}

int main ()
{
    while (true)
    {
        scanf("%d%d%d%d",&n,&X,&Y,&Z);
        if (n == 0 && X == 0 && Y == 0 && Z == 0)   break;
        for (int i = 1; i <= n; i++)
            scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
        for ( int i = 1; i <= n+1; i++ )
        {
            e[i].clear(), f[i].clear();
            fill(g[i] + 1, g[i] + n + 2,inf);
        }
        for (int i = 1; i <= n; i++)
            g[1][i+1] = min(g[1][i+1],p[i].z*X);
        for (int i = 1; i <= n; i++)
        {
            int k,to;
            scanf("%d",&k);
            for (int j = 0; j < k; j++)
            {
                //to = readint();
                scanf("%d",&to);
                if (i == to)    continue;
                if (p[i].z >= p[to].z)
                    g[i+1][to+1] = min(g[i+1][to+1],DIS(p[i],p[to])*Y);
                else
                    g[i+1][to+1] = min(g[i+1][to+1],DIS(p[i],p[to])*Y+Z);
            }
        }
        n++;
        m = 0;
        for ( int i = 1; i <= n; i++ )
        {
            for ( int j = 1; j <= n; j++ )
            {
                if ( j != i &&j != root && g[i][j] != inf )
                {
                    eu[m] = i, ev[m] = j, ew[m] = g[i][j];
                    e[i].push_back(m), f[j].push_back(m);
                    ++m;
                }
            }
        }
        fill(flg + 1, flg + n + 1, false);
        dfs(root);
        int ans = 0;
        for ( int i = 1; i <= n&& ans != -1; i++ )
        {
            if ( !flg[i] ) ans = -1;
        }
        if ( ans == 0 ) ans = mstree();
        printf(ans == -1 ? "impossible\n": "%d\n", ans);
    }
    return 0;
}
