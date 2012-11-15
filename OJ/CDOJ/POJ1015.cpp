#include <iostream>
#include <cstdio>
#include <cstring>
#define MIN(X,Y) (((X)>(Y))?(Y):(X))
#define ABS(X) (((X)>0)?(X):(-(X)))
#define MAX(X,Y) (((X)<(Y))?(Y):(X))
using namespace std;

int n,m;
int d[210],p[210];
int dp[210][25][1100];
int from[210][25][1100];

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        int ttot;
        ttot = 0;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d%d",&d[i],&p[i]);
            ttot += MAX(d[i],p[i]);
        }
        for (int i = 0;i <= n;i++)
        for (int j = 0;j <= m;j++)
        for (int k = MAX(0,500-ttot);k <= MIN(1000,500+ttot);k++)
            dp[i][j][k] = from[i][j][k] = -1;
        for (int i = 0;i <= n;i++)
            dp[i][0][500] = 0;
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= MIN(m,i);j++)
        for (int k = MAX(0,500-ttot);k <= MIN(1000,500+ttot);k++)
        {
            dp[i][j][k] = dp[i-1][j][k];
            from[i][j][k] = from[i-1][j][k];
            if (k+d[i]-p[i] >= 0 && k+d[i]-p[i] <= 1000)
            if (dp[i-1][j-1][k+d[i]-p[i]] != -1)
            {
                if (dp[i-1][j-1][k+d[i]-p[i]]+d[i]+p[i] > dp[i][j][k])
                {
                    dp[i][j][k] = dp[i-1][j-1][k+d[i]-p[i]]+d[i]+p[i];
                    from[i][j][k] = i;
                }
            }
        }
        int maxres = -1;
        int maxpos = 500-ttot;
        for (int i = MAX(0,500-ttot);i <= MIN(1000,500+ttot);i++)
        if (ABS(i-500) < ABS(maxpos-500) && dp[n][m][i] > 0)
        {
            maxres = dp[n][m][i];
            maxpos = i;
        }
        else if (ABS(i-500) == ABS(maxpos-500) && dp[n][m][i] > maxres)
        {
            maxres = dp[n][m][i];
            maxpos = i;
        }
        int totd,totp;
        totd = totp = 0;
        int res[100];
        int cur;
        cur = from[n][m][maxpos];
        for (int i = m;i >= 1;i--)
        {
            totd += d[cur];
            totp += p[cur];
            res[i] = cur;
            maxpos += (d[cur]-p[cur]);
            cur = from[cur-1][i-1][maxpos];
        }
        ft++;
        printf("Jury #%d\n",ft);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",totd,totp);
        for (int i = 1;i <= m;i++)
            printf(" %d",res[i]);
        printf("\n\n");
    }
}
