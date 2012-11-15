#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int step[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int res,n,m,a[100][100],dp[100][100];

bool check(int x,int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)    return true;
    return false;
}

int DP(int x,int y)
{
    if (dp[x][y] != 0)  return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0;i < 4;i++)
        if (check(x+step[i][0],y+step[i][1]) == true)
            if (a[x][y] < a[x+step[i][0]][y+step[i][1]])
                dp[x][y] = max(dp[x][y],DP(x+step[i][0],y+step[i][1])+1);
    return dp[x][y];
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            scanf("%d",&a[i][j]);
    res = 0;
    memset(dp,0,sizeof(dp));
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            res = max(res,DP(i,j));
    printf("%d\n",res);
}
