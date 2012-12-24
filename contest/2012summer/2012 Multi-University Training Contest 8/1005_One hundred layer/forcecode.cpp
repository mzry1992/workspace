#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <time.h>

using namespace std;

int n,m,X,T,val[109][10009],dp[109][10009];
int sum[10009];

int main()
{
	int i,j,k,l,ss;

	char in[]="data.in", out[]="forcedata.out";
	freopen(in, "r", stdin);
	freopen(out, "w", stdout);
	clock_t clo = clock();
	
	while(scanf("%d %d %d %d",&n,&m,&X,&T) != EOF)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				scanf("%d",&val[i][j]);
				dp[i][j] = -1000000000;
			}
		for(j=1;j<=m;j++) dp[0][j] = -1000000000;
		dp[0][X] = 0;
		
		for(i=1;i<=n;i++)
		{
			sum[0] = 0;
			for(j=1;j<=m;j++) sum[j] = sum[j-1] + val[i][j];
			for(j=1;j<=m;j++)
			{
				k = j-T; if(k < 1) k = 1;
				for(;k<=m && k<=j+T;k++)
				{
					int tmp;
					if(j >= k) tmp = sum[j] - sum[k-1];
					else
						tmp = sum[k] - sum[j-1];

					if(dp[i][j] < dp[i-1][k] + tmp)
						dp[i][j] = dp[i-1][k] + tmp;
				}
			}
		}			
		k = -1000000000;
		for(i=1;i<=m;i++) if(dp[n][i] > k) k = dp[n][i];
		printf("%d\n",k);
	}
	//cout<<clock()-clo<<endl;
	return 0;
}

