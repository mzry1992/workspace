#include <stdio.h>
#define MAX_N 1001
int N;
int DP[MAX_N][MAX_N], X[MAX_N][MAX_N];
int main()
{
    int i, j;
    scanf("%d",&N);
    for(i=1; i<=N; i++)
    {
        DP[1][i] = i;
        DP[2][i] = i*i;
    }
    for(i=3; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            if(j-2 >= 0) X[i][j] = X[i][j-1]+DP[i-2][j-2];
            DP[i][j] = DP[i][j-1]+DP[i-1][j-1]+DP[i-2][j-1]+X[i][j];
        }
    }
    printf("%d\n",DP[N][N]);
    return 0;
}
