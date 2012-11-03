/*
ID: muziriy3
PROG: subset
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

int n;
long long dp[50][3000];
int sum;
long long tot;

int main()
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    scanf("%d",&n);
    sum = n*(n+1)/2;
    if (sum%2 == 1)
        printf("0\n");
    else
    {
        memset(dp,0,sizeof(dp));
        for (int i = 0;i <= n;i++)
            dp[i][0] = 1;
        for (int i = 1;i <= n;i++)
        for (int j = 1;j <= sum;j++)
        {
            if (j-i >= 0)
                dp[i][j] = dp[i-1][j-i]+dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
        tot = dp[n][sum/2]/2;
        printf("%d\n",tot);
    }
}
