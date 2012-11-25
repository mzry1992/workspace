#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int k,n,m,per[10];

int calc(int k,int n)
{
	int p1 = (100*k)/n;
	int p2 = (100*k)%n;
	if (p2*2 == n)
		return p1+p1%2;
	return p1+(p2*2 > n);
}

int dp[11][101][101];
int pre[11][101][101][2];

void output(int pos,int n,int k)
{
	if (pos == 0)	return;
	output(pos-1,pre[pos][n][k][0],pre[pos][n][k][1]);
	int ni = n-pre[pos][n][k][0];
	int ki = k-pre[pos][n][k][1];
	printf("%d %d\n",ni-ki,ni);
}

int DP(int minn)
{
	memset(dp,-1,sizeof(dp));
	dp[0][0][0] = 0;
	for (int i = 1;i <= m;i++)
	{
		for (int ni = minn;ni <= n;ni++)
			for (int ki = 0;ki <= ni;ki++)
				if (calc(ki,ni) == per[i])
				{
					for (int tn = 0;tn <= n-ni;tn++)
						for (int tk = 0;tk <= k-ki;tk++)
							if (dp[i-1][tn][tk] >= 0)
							{
								int nowgap = max(ni-minn,dp[i-1][tn][tk]);
								if (dp[i][tn+ni][tk+ki] == -1 || dp[i][tn+ni][tk+ki] > nowgap)
								{
									dp[i][tn+ni][tk+ki] = nowgap;
									pre[i][tn+ni][tk+ki][0] = tn;
									pre[i][tn+ni][tk+ki][1] = tk; 
								}
							}
				}
	}
	return dp[m][n][k];
}

int main()
{
	while (scanf("%d%d%d",&k,&n,&m) != EOF)
	{
		for (int i = 1;i <= m;i++)
			scanf("%d",&per[i]);
		int mingap = 100,minn;
		for (int mn = 1;mn*m <= n;mn++)
		{
			int gap = DP(mn);
			if (gap >= 0)
				if (gap < mingap)
				{
					mingap = gap;
					minn = mn;
				}
		}
		DP(minn);
		output(m,n,k);
	}
	return 0;
}
