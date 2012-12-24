#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m;
char B[12];
int dp[12][2][12];
bool flag[12][2];

void DP(int pos,int u)
{
    if (pos == 10)
    {
        dp[pos][u][0] = 1;
        flag[pos][u] = true;
        return;
    }

    if (flag[pos][u] == true)
        return;

    int ed = 9;
    if (u == 1)
        ed = B[pos]-'0';

    int add;
    for (int i = 0; i <= ed; i++)
    {
        int npos = pos+1;
        int nu = (u == 1 && i == ed);
        DP(npos,nu);
        if (i == 4 || i == 7)
            add = 1;
        else
            add = 0;
        for (int i = 0; i <= 9; i++)
            dp[pos][u][i+add] += dp[npos][nu][i];
    }
    flag[pos][u] = true;
}

int cnt[10];
const int mod = 1000000007;
long long f[10][7][60];

long long p(int a,int b)
{
    long long res = 1;
    for (int i = a-b+1;i <= a;i++)
        res = res*i%mod;
    return res;
}

int main(int argc,char* argv[])
{
    while (scanf("%d",&m) != EOF)
    {
        sprintf(B,"%010d",m);
        memset(flag,false,sizeof(flag));
        memset(dp,0,sizeof(dp));
        DP(0,1);

        for (int i = 0; i < 10; i++)
            cnt[i] = dp[0][1][i];
        cnt[0]--;

        memset(f,0,sizeof(f));
        for (int i = 0; i <= 6 && i <= cnt[0]; i++)
            f[0][i][0] = p(cnt[0],i);
        for (int i = 1; i < 10; i++)
            for (int x = 0; x <= 6; x++)
                for (int y = 0; y < 60; y++)
                    {
                        f[i][x][y] = (f[i][x][y]+f[i-1][x][y])%mod;
                        for (int k = 1; x+k <= 6 && k <= cnt[i]; k++)
                            f[i][x+k][y+k*i] = (f[i][x+k][y+k*i]+p(cnt[i],k)*f[i-1][x][y]%mod)%mod;
                    }

		long long ans = 0;
		for (int i = 1; i < 10;i++)
			for (int j = 0;j < i;j++)
				ans = (ans+f[9][6][j]*cnt[i])%mod;

		cout << ans << endl;
    }
    return 0;
}

