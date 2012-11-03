/*
ID: muziriy3
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <deque>
#define MAX(X,Y) ((X>Y)?X:Y)
using namespace std;

int r;
int a;
int dp[1200][1200];

int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    scanf("%d",&r);
    memset(dp,0,sizeof(dp));
    for (int i = 1;i <= r;i++)
    for (int j = 1;j <= i;j++)
    {
        scanf("%d",&a);
        dp[i][j] = MAX(dp[i-1][j-1],dp[i-1][j])+a;
    }
    int res = 0;
    for (int i = 1;i <= r;i++)
    if (dp[r][i] > res) res = dp[r][i];
    printf("%d\n",res);
}
