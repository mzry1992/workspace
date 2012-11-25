#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
char a[5010],b[5010];
int la,lb,dp[5010][5010];

int main()
{
    scanf("%s%s",a+1,b+1);
    la = strlen(a+1)+1;
    lb = strlen(b+1)+1;
    memset(dp,0,sizeof(dp));
    int res = 0;
    for (int i = 1;i < la;i++)
    {
        for (int j = 1;j < lb;j++)
            if (a[i] == b[j])
            {
                dp[i][j] = (1+dp[i-1][j-1])%mod;
                res = (res+dp[i][j])%mod;
            }
        for (int j = 1;j < lb;j++)
            dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
    }
    printf("%d\n",res);
	return 0;
}
