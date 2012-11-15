#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[1000];
int n;

int getval(char ch)
{
    if (ch == 'F') return 0;
    if (ch == 'T') return 10;
    if (ch == 'J') return 10;
    if (ch == 'Q') return 10;
    if (ch == 'K') return 10;
    if (ch == 'A') return 1;
    return ch-'0';
}

int dp[200][30][30][30];

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        gets(buf);
        gets(buf);
        memset(dp,255,sizeof(dp));
        dp[0][0][0][0] = 0;
        for (int i = 1;i <= n;i++)
        {
            int val = getval(buf[(i-1)*2]);
            for (int j = 0;j <= 21;j++)
            for (int k = 0;k <= 21;k++)
            for (int l = 0;l <= 21;l++)
            if (dp[i-1][j][k][l] >= 0)
            {
                if (val == 0)
                {
                    if (j < 21)
                        dp[i][0][k][l] = max(dp[i][0][k][l],dp[i-1][j][k][l]+150);
                    if (k < 21)
                        dp[i][j][0][l] = max(dp[i][j][0][l],dp[i-1][j][k][l]+250);
                    if (l < 21)
                        dp[i][j][k][0] = max(dp[i][j][k][0],dp[i-1][j][k][l]+350);
                }
                else
                {
                    if (j < 21){
                    if (j+val == 21)
                        dp[i][0][k][l] = max(dp[i][0][k][l],dp[i-1][j][k][l]+150);
                    else
                        dp[i][(j+val>21)?(21):(j+val)][k][l] = max(dp[i][(j+val>21)?(21):(j+val)][k][l],dp[i-1][j][k][l]+50);}
                    if (k < 21){
                    if (k+val == 21)
                        dp[i][j][0][l] = max(dp[i][j][0][l],dp[i-1][j][k][l]+250);
                    else
                        dp[i][j][(k+val>21)?(21):(k+val)][l] = max(dp[i][j][(k+val>21)?(21):(k+val)][l],dp[i-1][j][k][l]+50);}
                    if (l < 21){
                    if (l+val == 21)
                        dp[i][j][k][0] = max(dp[i][j][k][0],dp[i-1][j][k][l]+350);
                    else
                        dp[i][j][k][(l+val>21)?(21):(l+val)] = max(dp[i][j][k][(l+val>21)?(21):(l+val)],dp[i-1][j][k][l]+50);}
                }
            }
        }
        int ans = 0;
        int tn = n;
        while (true)
        {
            bool flag = false;
            for (int i = 0;i <= 21;i++)
            for (int j = 0;j <= 21;j++)
            for (int k = 0;k <= 21;k++)
            if (dp[tn][i][j][k] >= 0)
                flag = true;
            if (flag == true)
                break;
            tn--;
        }
        for (int i = 0;i <= 21;i++)
        for (int j = 0;j <= 21;j++)
        for (int k = 0;k <= 21;k++)
        if (dp[tn][i][j][k] > ans)
            ans = dp[tn][i][j][k];
        printf("%d\n",ans);
    }
}
