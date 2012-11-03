#include <iostream>
#include <cmath>
using namespace std;

const int maxv = 1<<30;
int t,ft;
int n,m,sx,sy,ex,ey;
char map[60][60];
bool dp[60][60][2][2][2][2][2];
bool flag[5],cane;
int step[4][2];
int ans;

bool can(int x,int y)
{
     if (x > n)    return false;         if (x < 1)    return false;
     if (y >= m)    return false;         if (y < 0)    return false;
     if (map[x][y] == '#')  return false;
     if (map[x][y] == 'A')  return false;
     if (map[x][y] == 'B')  return false;
     if (map[x][y] == 'D')  return false;
     if (map[x][y] == 'E')  return false;
     return true;
}

void DFS(int x,int y,int a,int b,int c,int d,int e)
{
     int tx,ty,k,i,j;
     for (i = 1;i <= n;i++)
     for (j = 0;j < m;j++)
     {
         if (map[i][j] == 'A')
         if (a == 0)
         if (fabs(i-x)+fabs(j-y) <= 2)
                                 a = 1;
         if (map[i][j] == 'B')
         if (b == 0)
         if (fabs(i-x)+fabs(j-y) <= 2)
                                 b = 1;
         if (map[i][j] == 'C')
         if (c == 0)
         if (fabs(i-x)+fabs(j-y) <= 2)
                                 c = 1;
         if (map[i][j] == 'D')
         if (d == 0)
         if (fabs(i-x)+fabs(j-y) <= 2)
                                 d = 1;
         if (map[i][j] == 'E')
         if (e == 0)
         if (fabs(i-x)+fabs(j-y) <= 2)
                                 e = 1;
     }
     if (dp[x][y][a][b][c][d][e] == true)
        return;
     dp[x][y][a][b][c][d][e] = true;
     for (k = 1;k <= 4;k++)
     {
         tx = x+step[k][1];
         ty = y+step[k][2];
         if (can(tx,ty))
            DFS(tx,ty,a,b,c,d,e);
     }
}

int main()
{
    int i,j,k;
    scanf("%d",&t);
    for (ft = 1;ft <= t;ft++)
    {
        step[1][2] = step[2][2] = step[3][1] = step[4][1] = 0;
        step[1][1] = step[3][2] = 1;
        step[2][1] = step[4][2] = -1;
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
        }
        memset(dp,false,sizeof(dp));
        memset(flag,false,sizeof(flag));
        cane = false;
        dp[sx][sy][0][0][0][0][0] = true;
        for (i = 1;i <= 4;i++)
        if (can(sx+step[i][1],sy+step[i][2]))
           DFS(sx+step[i][1],sy+step[i][2],0,0,0,0,0);
        ans = maxv;
        int temp[5];
        for (i = 1;i <= 32;i++)
        {
            k = i;
            for (j = 1;j <= 5;j++)
            {
                temp[j] = k%2;
                k /= 2;
            }
            if (dp[ex][ey][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]] == true)
            if (ans > temp[1]*1+temp[2]*2+temp[3]*3+temp[4]*4+temp[5]*5)
               ans = temp[1]*1+temp[2]*2+temp[3]*3+temp[4]*4+temp[5]*5;
        }
        if (ans == maxv)
           ans = -1;
        printf("Case %d: %d\n",ft,ans);
    }
    return 0;
}
