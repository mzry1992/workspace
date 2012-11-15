#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,dp[101][101][101][2];
bool u[101][101][101][2];

int DP(int tot,int use,int nowuse,int black,int row)
{
    if (u[use][nowuse][black][row] == true) return dp[use][nowuse][black][row];
    u[use][nowuse][black][row] = true;
    if (use == tot)
    {
        dp[use][nowuse][black][row] = (black*2 == tot)?1:0;
        return dp[use][nowuse][black][row];
    }
    dp[use][nowuse][black][row] = 0;
    for (int i = nowuse;i >= 1;i--)
        if (use+i <= tot)
            dp[use][nowuse][black][row] += DP(tot,use+i,i,black+((row==0)?((i%2==0)?(i/2):((i-1)/2)):((i%2==0)?(i/2):((i+1)/2))),row^1);
    return dp[use][nowuse][black][row];
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        memset(u,false,sizeof(u));
        printf("%d\n",DP(n,0,n+1,0,0));
    }
}
