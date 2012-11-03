#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
char a[120],b[120];
int dp[120][120];
const int map[5][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};

int getindex(char ch)
{
    if (ch == 'A')  return 0;
    if (ch == 'C')  return 1;
    if (ch == 'G')  return 2;
    if (ch == 'T')  return 3;
    return 4;
}

int MAX(int a,int b)
{
    if (a > b)  return a;
    return b;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%s",&n,a);
        scanf("%d%s",&m,b);
        for (int i = 0;i <= n;i++)
            for (int j = 0;j <= m;j++)
                dp[i][j] = -19921005;
        dp[0][0] = 0;
        for (int i = 0;i <= n;i++)
            for (int j = 0;j <= m;j++)
            {
                if (i > 0 && j > 0)
                    if (dp[i-1][j-1] != -19921005)
                        dp[i][j] = MAX(dp[i][j],dp[i-1][j-1]+map[getindex(a[i-1])][getindex(b[j-1])]);
                if (i > 0)
                    if (dp[i-1][j] != -19921005)
                        dp[i][j] = MAX(dp[i][j],dp[i-1][j]+map[getindex(a[i-1])][getindex('-')]);
                if (j > 0)
                    if (dp[i][j-1] != -19921005)
                        dp[i][j] = MAX(dp[i][j],dp[i][j-1]+map[getindex('-')][getindex(b[j-1])]);
            }
        printf("%d\n",dp[n][m]);
    }
}
