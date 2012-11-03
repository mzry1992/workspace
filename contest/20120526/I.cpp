#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char a[110],b[110],c[310];
int dp[310][110][110];
bool flag[310][110][110];
int la,lb,lc;

int calc(int i,int j,int k)
{
    if (flag[i][j][k] == true)  return dp[i][j][k];
    flag[i][j][k] = true;
    int& ret = dp[i][j][k];
    if (i == 0)
        return ret = (j == 0 && k == 0);
    ret = calc(i-1,j,k);
    if (c[i-1] == a[j-1] && c[i-1])
    if (c[i-1] == a[j-1])
        ret += calc(i-1,j-1,k);
    return ret;
}

int main()
{
    int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%s%s%s",a,b,c);
        la = strlen(a);
        lb = strlen(b);
        lc = strlen(c);
        memset(dp,-1,sizeof(dp));
        dp[0][0][0] = 0;
        //memset(flag,false,sizeof(flag));
        //printf("%d\n",calc(lc,la,lb));
	}
	return 0;
}
