#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

typedef long long LL;

const int mod = 1e9+7;
const int N = 301;

int dp[N][N][N];
int cansee[N][N];
int C[N][N];

int main(){
	C[0][0] = 1;
	for(int i=1; i<N; i++){
		C[i][0] = 1;
		for(int j=1; j<=i; j++)
			C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
	}
	cansee[0][0] = 1;
	cansee[1][1] = 1;
	dp[0][0][0] = 1;
	dp[1][1][1] = 1;
	int tot = 0;
	for(int i=2; i<N; i++)
	{
		for(int l = 0; l<i; l++){
			int r = i - l - 1;
			for(int k=0; k<=l; k++)
				for(int t=0; t<=r; t++){
					dp[i][k+1][t+1] = (dp[i][k+1][t+1] + (C[i-1][l] * (LL)cansee[l][k] % mod) * (LL)cansee[r][t] )%mod;
					tot ++;
				}
		}
		for(int s = 0; s<=i; s++){
			for(int j=0; j<=i; j++)
				cansee[i][s] = (cansee[i][s] + dp[i][s][j])%mod;
		}
	}
    int T;
    scanf("%d", &T);
    for(int cas=1;cas<=T; cas++)
    {
        int n,a,b;
        scanf("%d%d%d",&n,&a,&b);
        printf("%d\n", dp[n][a][b]);
    }
	return 0;
}
