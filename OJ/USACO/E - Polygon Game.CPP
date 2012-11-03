#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX(X,Y) (((X)<(Y))?(Y):(X))
#define MIN(X,Y) (((X)>(Y))?(Y):(X))
using namespace std;

int n;
int num[200];
char op[200];
long long dp[2][200][200];
bool use[200][200];

long long calc(long long a,char op,long long b)
{
    if (op == '+')  return (long long)(a+b);
    return (long long)(a*b);
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 1;i <= n;i++)
        {
            scanf(" %c",&op[i]);
            scanf("%d",&num[i]);
            op[i+n] = op[i];
            num[i+n] = num[i];
        }
        memset(use,false,sizeof(use));
        memset(dp,0,sizeof(dp));
        for (int i = 1;i <= 2*n;i++)
        {
            dp[0][i][i] = dp[1][i][i] = num[i];
            use[i][i] = true;
        }
        long long res = -((long long)1<<63);
        for (int s = 1;s <= n;s++)
        {
            for (int l = 2;l <= n;l++)
            for (int i = s+1-1;i <= s+n-1;i++)
            {
                int j = i+l-1;
                if (j > s+n)    break;
                if (use[i][j] == false)
                {
                    dp[0][i][j] = -((long long)1<<63);
                    dp[1][i][j] = ((long long)1<<63)-1;
                    for (int k = i+1;k <= j;k++)
                    {
                        long long tmax = -((long long)1<<63);
                        for (int x = 0;x <= 1;x++)
                        for (int y = 0;y <= 1;y++)
                            tmax = MAX(tmax,calc(dp[x][i][k-1],op[k],dp[y][k][j]));
                        dp[0][i][j] = MAX(dp[0][i][j],tmax);
                        long long tmin = ((long long)1<<63)-1;
                        for (int x = 0;x <= 1;x++)
                        for (int y = 0;y <= 1;y++)
                            tmin = MIN(tmin,calc(dp[x][i][k-1],op[k],dp[y][k][j]));
                        dp[1][i][j] = MIN(dp[1][i][j],tmin);
                    }
                    use[i][j] = true;
                    //if (s == 3)
                    //cout << i << ' ' << j << ' ' << dp[0][i][j] << ' ' << dp[1][i][j] << endl;
                }
            }
            res = MAX(res,MAX(dp[0][s][s+n-1],dp[1][s][s+n-1]));
            /*
            cout << dp[0][s][s+n-1] << endl;
            for (int i = s;i <= s+n-1;i++)
                cout << op[i] << ' ' << num[i] << ' ';
            cout << endl;
            */
        }
        cout << res << endl;
    }
}
