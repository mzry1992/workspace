#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
bool map[15][2100][2100];
bool bit[2][15];
long long dp[15][2100];

void DFS(int w,int s,int y)
{
    if (y == w)
    {
        int temp = 0;
        int base = 1;
        for (int i = 0;i < w;i++)
        {
            temp += base*bit[1][i];
            base *= 2;
        }
        map[w][s][temp] = true;
        return;
    }
    DFS(w,s,y+1);
    if (y <= w-2)
    {
        if (bit[1][y] == 0 && bit[1][y+1] == 0)
        {
            bit[1][y] = bit[1][y+1] = 1;
            DFS(w,s,y+2);
            bit[1][y] = bit[1][y+1] = 0;
        }
    }
}

void solve(int w,int s)
{
    memset(bit,false,sizeof(bit));
    for (int i = 0;i < w;i++)
    {
        bit[0][i] = (s>>i)&1;
        if (bit[0][i] == 0)
            bit[0][i] = bit[1][i] = 1;
    }
    DFS(w,s,0);
}

int main()
{
    memset(map,false,sizeof(map));
    for (int i = 1;i <= 11;i++)
    for (int j = 0;j < (1<<i);j++)
        solve(i,j);
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        memset(dp,0,sizeof(dp));
        dp[0][(1<<m)-1] = 1;
        for (int i = 1;i <= n;i++)
        for (int j = 0;j < (1<<m);j++)
        for (int k = 0;k < (1<<m);k++)
        if (map[m][k][j] == true)
            dp[i][j] += dp[i-1][k];
        printf("%lld\n",dp[n][(1<<m)-1]);
    }
}
