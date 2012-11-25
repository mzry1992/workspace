#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int dp[2][10000],sum[10000];
int a[20];

int main()
{
    scanf("%d%d",&n,&m);
    if (n == 1)
    {
        printf("%d\n",1%m);
        return 0;
    }
    if (m<3)
    {
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;
    bool flag = 0;
    for (int i = 1; i < n; i++,flag = !flag)
        if (i&1)
        {
            sum[n-i+1] = 0;
            for (int j = n-i; j >= 0; j--)
                sum[j] = (sum[j+1]+dp[flag][j])%m;
            for (int j = 0; j < n; j++)
                dp[!flag][j] = sum[j+1];
        }
        else
        {
            sum[0] = dp[flag][0];
            for (int j = 1; j < n; j++)
                sum[j] = (sum[j-1]+dp[flag][j])%m;
            for (int j = 0; j < n; j++)
                dp[!flag][j] = sum[j];
        }
    printf("%d\n",(dp[flag][0]*2)%m);
    return 0;
}
