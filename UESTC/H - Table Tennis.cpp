#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char now[110];
double p1,p2,res,dp[500][22][22];
int pa,pb,len;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        gets(now);
        gets(now);
        scanf("%lf%lf",&p1,&p2);
        pa = pb = 0;
        len = strlen(now);
        bool flag = false;
        for (int i = 0;i < len;i++)
        {
            if (i%10 < 5 && now[i] == 'W' && p1 == 0.0) flag = true;
            if (i%10 < 5 && now[i] == 'L' && p1 == 1.0) flag = true;
            if (i%10 >= 5 && now[i] == 'W' && p2 == 0.0) flag = true;
            if (i%10 >= 5 && now[i] == 'L' && p2 == 1.0) flag = true;
            if (now[i] == 'W')
                pa++;
            else
                pb++;
            if (pa == 20 && pb == 20)
                pa = pb = 15;
        }
        printf("Case %d: ",ft);
        if (pa > 21 || pb > 21 || (pa == 21 && pb == 21) || flag == true)
        {
            res = -1.0;
            printf("%.6f\n",res);
            continue;
        }
        if (pa == 21 && pb < 21)
        {
            res = 1.0;
            printf("%.6f\n",res);
            continue;
        }
        if (pb == 21 && pa < 21)
        {
            res = 0.0;
            printf("%.6f\n",res);
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[len][pa][pb] = 1.0;
        for (int i = len+1;i <= len+(21-pa)+(21-pb);i++)
            for (int j = pa;j <= 21;j++)
                for (int k = pb;k <= 21;k++)
                    if (j != 21 || k != 21)
                    {
                        if (!(j-1 == 20 && k == 20) && k != 21)
                            dp[i][j][k] += dp[i-1][j-1][k]*((i-1)%10 < 5 ? p1:p2);
                        if (!(j == 20 && k-1 == 20) && j != 21)
                            dp[i][j][k] += dp[i-1][j][k-1]*((i-1)%10 < 5 ? (1-p1) : (1-p2));
                    }
        double res1,res2,res3,res4;
        res1 = res2 = res3 = 0.0;
        for (int i = pb;i <= 21;i++)
            res1 += dp[len+(21-pa)+(i-pb)][21][i];
        res2 = dp[len+(20-pa)+(20-pb)][20][20];
        memset(dp,0,sizeof(dp));
        dp[len+(20-pa)+(20-pb)][15][15] = 1.0;
        for (int i = len+(20-pa)+(20-pb)+1;i <= len+(20-pa)+(20-pb)+(21-15)+(21-15);i++)
            for (int j = 15;j <= 21;j++)
                for (int k = 15;k <= 21;k++)
                    if (j != 21 || k != 21)
                    {
                        if (!(j-1 == 20 && k == 20) && k != 21)
                            dp[i][j][k] += dp[i-1][j-1][k]*((i-1)%10 < 5 ? p1:p2);
                        if (!(j == 20 && k-1 == 20) && j != 21)
                            dp[i][j][k] += dp[i-1][j][k-1]*((i-1)%10 < 5 ? (1-p1) : (1-p2));
                    }
        for (int i = 15;i <= 21;i++)
            res3 += dp[len+(20-pa)+(20-pb)+(21-15)+(i-15)][21][i];
        res4 = dp[len+(20-pa)+(20-pb)+(20-15)+(20-15)][20][20];
        //cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res4 << endl;
        if (1.0-res4 != 0.0)
            res = res1+(res2*res3)/(1-res4);
        else
            res = res1;
        printf("%.6f\n",res);
    }
}
