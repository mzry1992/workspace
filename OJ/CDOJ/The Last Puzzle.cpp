#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[200],b[200],dp[200][200][2],nxt[200][200][2];
bool vis[200][200][2];

int DP(int l,int r,int s)
{
    if (vis[l][r][s] == true)   return dp[l][r][s];
    if (l == r)
        return 0;
    int best = -1;
    if (s == 0)
    {
        if (DP(l+1,r,0) != -1)
        {
            best = b[l+1]-b[l]+DP(l+1,r,0);
            nxt[l][r][s] = 0;
        }
        if (DP(l+1,r,1) != -1)
        {
            int now = b[r]-b[l]+DP(l+1,r,1);
            if (best == -1 || best > now)
            {
                best = now;
                nxt[l][r][s] = 1;
            }
        }
        if (best == -1 || a[l] <= best)
            best = -1;
    }
    else
    {
        if (DP(l,r-1,0) != -1)
        {
            best = b[r]-b[l]+DP(l,r-1,0);
            nxt[l][r][s] = 0;
        }
        if (DP(l,r-1,1) != -1)
        {
            int now = b[r]-b[r-1]+DP(l,r-1,1);
            if (best == -1 || best > now)
            {
                best = now;
                nxt[l][r][s] = 1;
            }
        }
        if (best == -1 || a[r] <= best)
            best = -1;
    }
    vis[l][r][s] = true;
    dp[l][r][s] = best;
    return dp[l][r][s];
}

void output(int l,int r,int s)
{
    if (l == r)
    {
        printf("%d\n",l+1);
        return;
    }
    if (s == 0)
    {
        printf("%d ",l+1);
        output(l+1,r,nxt[l][r][s]);
    }
    else
    {
        printf("%d ",r+1);
        output(l,r-1,nxt[l][r][s]);
    }
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d",&b[i]);
        memset(vis,false,sizeof(vis));
        int best = -1,from;
        best = DP(0,n-1,0);
        from = 0;
        if (best == -1 || (DP(0,n-1,1) != -1 && best > DP(0,n-1,1)))
        {
            best = DP(0,n-1,1);
            from = 1;
        }
        if (best == -1)
            printf("Mission Impossible\n");
        else
            output(0,n-1,from);
    }
    return 0;
}
