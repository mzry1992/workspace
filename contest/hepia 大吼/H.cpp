#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char g[130][12];
int n,m;

int bit[15];
inline int getbit(int sta,int pos)
{
	return sta/bit[pos]%bit[1];
}
inline int setbit(int sta,int pos,int val)
{
	return sta/bit[pos+1]*bit[pos+1]+val*bit[pos]+sta%bit[pos];
}

int a[180000];
int f[180000];
int F(int sta)
{
	if (f[sta] != -1)
		return f[sta];
	int& res = f[sta];
	for (int i = 0;i < m;i++)
		if (getbit(sta,i) == 2)
			return res = F(setbit(sta,i,0))+F(setbit(sta,i,1));
	res = a[sta];
	return res;
}

int dp[180000];
int DP(int sta)
{
	if (dp[sta] != -1)
		return dp[sta];
	int& res = dp[sta];
	res = 0x3f3f3f3f;
	if (F(sta) <= 1)	return res = 0;
	for (int i = 0;i < m;i++)
		if (getbit(sta,i) == 2)
			res = min(res,max(DP(setbit(sta,i,1)),DP(setbit(sta,i,0)))+1);
	return res;
}

int main()
{
	bit[0] = 1;
	for (int i = 1;i < 15;i++)
		bit[i] = bit[i-1]*3;

    while (true)
    {
        scanf("%d%d",&m,&n);
        if (m == 0 && n == 0)	break;

		memset(a,0,sizeof(a));
        for (int i = 0; i < n; i++)
        {
            scanf("%s",g[i]);
			int tmp = 0;
			for (int j = 0;j < m;j++)
				tmp = setbit(tmp,j,g[i][j]-'0');
			a[tmp]++;
        }

		int full = bit[m];

		memset(f,-1,sizeof(f));
		memset(dp,-1,sizeof(dp));
		printf("%d\n",DP(full-1));
    }
    return 0;
}

