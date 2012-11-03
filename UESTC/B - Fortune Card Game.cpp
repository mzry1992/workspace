#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char spell[200];
char symbol[900][3];
int add[900],next[900];
int dp[160][900];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%d%s%d",&add[i],symbol[i],&next[i]);
        scanf("%s",spell);
        int len = strlen(spell);
        for (int i = 0;i <= len;i++)
            for (int j = 1;j <= 800;j++)
                dp[i][j] = -1;
        dp[0][1] = 0;
        for (int i = 1;i <= len;i++)
            for (int j = 1;j <= n;j++)
                if (symbol[j][0] == spell[i-1])
                    if (dp[i-1][add[j]] != -1)
                        if (dp[i][next[j]] < dp[i-1][add[j]]+next[j])
                            dp[i][next[j]] = dp[i-1][add[j]]+next[j];
        int maxres = 0;
        for (int i = len;i <= len;i++)
            for (int j = 1;j <= 800;j++)
                if (dp[i][j] > maxres)
                    maxres = dp[i][j];
        printf("%d\n",maxres);
    }
}
