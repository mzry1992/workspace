#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <time.h>

using namespace std;

int n,m,X,T,val[109][10009],dp[109][10009];
int op,cl,p[100009],sum[10009],q[10009];

int main()
{
	int i,j,k,l,ss;

	char in[]="data.in", out[]="data.out";
//	freopen(in, "r", stdin);
//	freopen(out, "w", stdout);
	
	clock_t clo = clock();

    while(scanf("%d %d %d %d",&n,&m,&X,&T) != EOF)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++) scanf("%d", &val[i][j]);
		
		for(i=0;i<=m;i++) dp[0][i] = -1000000000;
		dp[0][X] = 0;
		
		for(i=1;i<=n;i++)
		{
			op = 0; cl = 1; p[0] = 1;
			dp[i][1] = dp[i-1][1]+val[i][1]; q[0] = dp[i-1][1];
		
			ss = val[i][1];
			for(j=2;j<=m;j++)
			{
				while(op < cl && j-T > p[op]) op++;
				l = dp[i-1][j] - ss;
				while(op < cl && q[cl-1] <= l) cl--;
				ss += val[i][j];
				p[cl] = j; q[cl++] = l;
				dp[i][j] = ss + q[op];
			}
			
			op = 0; cl = 1; p[0] = m; 
			if(dp[i][m] < dp[i-1][m] + val[i][m]) dp[i][m] = dp[i-1][m] + val[i][m];
			q[0] = dp[i-1][m];
			
			ss = val[i][m];
			for(j=m-1;j>0;j--)
			{
				while(op < cl && j+T < p[op]) op++;
				l = dp[i-1][j] - ss;
				while(op < cl && q[cl-1] <= l) cl--;
				ss += val[i][j];
				p[cl] = j; q[cl++] = l;
				if(dp[i][j] <  ss + q[op])
					dp[i][j] = ss + q[op];
			}
		}
		k = -1000000000;
		for(i=1;i<=m;i++) if(dp[n][i] > k) k = dp[n][i];
		printf("%d\n",k);
	}
	//cout<<clock()-clo<<endl;
	return 0;
}

