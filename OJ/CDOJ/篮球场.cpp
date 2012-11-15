#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a,b,n,mp[101][101],x,y;
int sum[101][101],dp[101][101];

int CalcSum(int x1,int y1,int x2,int y2)
{
    if (x1 <= x2 && y1 <= y2)
        return sum[x2][y2]-(sum[x1-1][y2]+sum[x2][y1-1]-sum[x1-1][y1-1]);
    return 19921005;
}

int main()
{
    while (true)
    {
        scanf("%d%d",&a,&b);
        if (a == 0 && b == 0)   break;
        scanf("%d",&n);
        memset(mp,0,sizeof(mp));
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&x,&y);
            mp[x][y] = true;
        }
        memset(sum,0,sizeof(sum));
        for (int i = 1;i <= a;i++)
            for (int j = 1;j <= b;j++)
                sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mp[i][j];
        for (int i = 0;i <= a;i++)
            for (int j = 0;j <= b;j++)
            {
                dp[i][j] = 19921005;
                if (i >= 27 && j >= 14)
                    dp[i][j] = min(dp[i][j],CalcSum(i-27,j-14,i,j));
                if (i >= 14 && j >= 27)
                    dp[i][j] = min(dp[i][j],CalcSum(i-14,j-27,i,j));
                if ((i >= 27 && j >= 14) || (i >= 14 && j >= 27))
                {
                    dp[i][j] = min(dp[i][j],dp[i-1][j]);
                    dp[i][j] = min(dp[i][j],dp[i][j-1]);
                }
            }
        int res = 19921005;
        for (int i = 1;i <= a;i++)
            for (int j = 1;j <= b;j++)
            {
                int tres;
                if (i >= 14 && j >= 27)
                {
                    tres = CalcSum(i-14,j-27,i,j)+min(dp[i-14][b],dp[a][j-27]);
                    if (tres < res) res = tres;
                }
                if (i >= 27 && j >= 14)
                {
                    tres = CalcSum(i-27,j-14,i,j)+min(dp[i-27][b],dp[a][j-14]);
                    if (tres < res) res = tres;
                }
            }
        printf("%d\n",res);
    }
}
