#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int add[4][4] = {{0,1,1,1},{0,0,2,0},{0,2,0,0},{1,1,1,0}};
const int mod = 100000007;
int dp[1002][4][2001];
int n,k;

int main()
{
	//   0   1   2   3
	//0 00  00  01  01
	//0 00  01  00  01
	//  +0  +1  +1  +1
	//
	//0 00  00  01  01
	//1 10  11  10  11
	//  +0  +0  +2  +0
	//
	//1 10  10  11  11
	//0 00  01  00  01
	//  +0  +2  +0  +0
	//
	//1 10  10  11  11
	//1 10  11  10  11
	//  +1  +1  +1  +0

	dp[1][0][1] = dp[1][1][2] = 1;
	for (int i = 1;i <= 1000;i++)
		for (int j = 0;j < 4;j++)
			for (int k = 0;k <= i*2;k++)
				if (dp[i][j][k] != 0)
					for (int q = 0;q < 4;q++)
						dp[i+1][q][k+add[j][q]] = (dp[i+1][q][k+add[j][q]]+dp[i][j][k])%mod;
	
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		scanf("%d%d",&n,&k);
		int ans = 0;
		for (int i = 0;i < 4;i++)
			ans = (ans+dp[n][i][k])%mod;
		printf("%d\n",ans);
	}
	return 0;
}
