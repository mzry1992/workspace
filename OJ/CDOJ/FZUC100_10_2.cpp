#include <iostream>
#include <cmath>
using namespace std;

const int maxv = 1<<30;
int t,ft;
int n,m,sx,sy,ex,ey;
char map[60][60];
int dp[60][60];
int step[4][2];
int st[60][60];

int comp(int x,int y)
{
    int i,j,ans;
    ans = 0;
    for (i = 1;i <= n;i++)
    for (j = 0;j < m;j++)
    {
        if (map[i][j] == 'A')
        if (st[i][j] == false)
        if (fabs(i-x)+fabs(j-y) <= 2)
        {
                     ans += 1;  st[i][j] = true;
        }
        if (map[i][j] == 'B')
        if (st[i][j] == false)
        if (fabs(i-x)+fabs(j-y) <= 3)
        {
                     ans += 2;  st[i][j] = true;
        }
        if (map[i][j] == 'C')
        if (st[i][j] == false)
        if (fabs(i-x)+fabs(j-y) <= 0)
        {
                     ans += 3;  st[i][j] = true;
        }
        if (map[i][j] == 'D')
        if (st[i][j] == false)
        if (fabs(i-x)+fabs(j-y) <= 2)
        {
                     ans += 4;  st[i][j] = true;
        }
        if (map[i][j] == 'E')
        if (st[i][j] == false)
        if (fabs(i-x)+fabs(j-y) <= 1)
        {
                     ans += 5;  st[i][j] = true;
        }
    }
    return ans;
}

bool can(int x,int y)
{
     if (x > n)    return false;         if (x < 1)    return false;
     if (y >= m)    return false;         if (y < 0)    return false;
     if (map[x][y] == '#')  return false;
     return true;
}

void DFS(int x,int y,int now)
{
     int tx,ty,i,j,k,tnow;
     int temp[60][60];
     if (now >= dp[ex][ey])
        return;
     for (i = 1;i <= n;i++)
     for (j = 0;j < m;j++)
         temp[i][j] = st[i][j];
     tnow = comp(x,y)+now;
     if (tnow < dp[x][y])
        dp[x][y] = tnow;
     else
         return;
     for (k = 1;k <= 4;k++)
     {
         tx = x+step[k][1];
         ty = y+step[k][2];
         if (can(tx,ty))
                        DFS(tx,ty,tnow);
     }
     for (i = 1;i <= n;i++)
     for (j = 0;j < m;j++)
         st[i][j] = temp[i][j];
}

int main()
{
    int i,j;
    step[1][2] = step[2][2] = step[3][1] = step[4][1] = 0;
    step[1][1] = step[3][2] = 1;
    step[2][1] = step[4][2] = -1;
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (i = 1;i <= n;i++)
            scanf("%s",&map[i]);
        for (i = 1;i <= n;i++)
        for (j = 0;j < m;j++)
        {
            if (map[i][j] == '$')  
            {
                          sx = i;  sy = j;
            }
            if (map[i][j] == '!')
            {
                          ex = i;  ey = j;
            }
            dp[i][j] = maxv;
            st[i][j] = false;
        }
        DFS(sx,sy,0);
        if (dp[ex][ey] == maxv)
           dp[ex][ey] = -1;
        printf("Case %d: %d\n",ft,dp[ex][ey]);
    }
    return 0;
}
