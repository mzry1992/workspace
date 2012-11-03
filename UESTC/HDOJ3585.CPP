#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n,k;
struct graph
{
    int x,y;
}G[55];
int dist[55][55];
bool g[55][55];
int list[55][55],s[55],degree[55],behide[55];
int found,curmax,curobj;

int distanc(graph a,graph b)
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void sortdegree()
{
    for (int i = 1;i <= n;i++)
    {
        int k = i;
        for (int j = i+1;j <= n;j++)
            if (degree[j] < degree[k])
                k = j;
        if (k != i)
        {
            swap(degree[i],degree[k]);
            for (int l = 1;l <= n;l++)
                swap(g[i][l],g[k][l]);
            for (int l = 1;l <= n;l++)
                swap(g[l][i],g[l][k]);
        }
    }
}

void dfs(int d)
{
    if (d-1 > curmax)
    {
        found = 1;
        return;
    }
    for (int i = 1;i < list[d-1][0]-curmax+d;i++)
    if (!found && d+behide[list[d-1][i]+1] > curmax
        && (list[d-1][0] == i || d+behide[list[d-1][i+1]] > curmax))
        {
            list[d][0] = 0;
            for (int j = i+1;j <= list[d-1][0];j++)
            if (g[list[d-1][j]][list[d-1][i]])
                list[d][++list[d][0]] = list[d-1][j];
            if (list[d][0] == 0 || d+behide[list[d][1]] > curmax)
                dfs(d+1);
        }
}

void solve()
{
    sortdegree();
    behide[n+1] = 0;
    behide[n] = 1;
    for (int i = n-1;i > 0;i--)
    {
        curmax = behide[i+1];
        found = list[1][0] = 0;
        for (int j = i+1;j <= n;j++)
        if (g[j][i])
            list[1][++list[1][0]] = j;
        dfs(2);
        behide[i] = curmax+found;
    }
}

int check(int mindist)
{
    memset(g,false,sizeof(g));
    for (int i = 1;i < n;i++)
    for (int j = i+1;j <= n;j++)
        if (dist[i][j] >= mindist)
            g[i][j] = g[j][i] = true;
    for (int i = 1;i <= n;i++)
    {
        degree[i] = 0;
        for (int j = 1;j <= n;j++)
            degree[i] += g[i][j];
    }
    solve();
    return behide[1];
}

int main()
{
    while (scanf("%d%d",&n,&k) != EOF)
    {
        for (int i = 1;i <= n;i++)
            scanf("%d%d",&G[i].x,&G[i].y);
        int l,r,mid;
        r = l = 0;
        for (int i = 1;i < n;i++)
        for (int j = i+1;j <= n;j++)
        {
            dist[i][j] = distanc(G[i],G[j]);
            if (dist[i][j] > r)
                r = dist[i][j];
            dist[j][i] = dist[i][j];
        }
        r++;
        while (l+1 < r)
        {
            mid = (l+r)/2;
            if (check(mid) >= k)
                l = mid;
            else
                r = mid;
        }
        printf("%.2lf\n",sqrt((double)l));
    }
}
