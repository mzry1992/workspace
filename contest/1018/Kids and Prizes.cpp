#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long dp[100][100];
int n,m;
double res;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        res = 1.0;
        for (int i = 1;i < m;i++)
            res = res*(n-1)/n+1;
        printf("%.9f\n",res);
    }
    /*for (n = 1;n < 10;n++,puts(""))
        for (m = 1;m < 10;m++)
    {
        memset(dp,0,sizeof(dp));
        for (int i = 1;i < 10;i++)
            for (int j = 1;j < 10;j++)
                dp[i][j] = (dp[i-1][j-1]+1)*i+dp[i][j-1]*(n-i);
        printf("%8lld ",dp[n][m]/n);//-(n*n*m-n*n+n));
        //printf("n = %d m = %d %.9f\n",n,m,dp[n][m]);
    }*/
    return 0;
}
