#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;

const int MAXN = 301;
const int MOD = 1000000007;
int dp[MAXN][MAXN][MAXN];

int main() {
    int n, x, y;
    dp[1][1][1] = 1;
    for (int i = 2; i < MAXN; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                dp[i][j][k] = (long long)(i - 2) * dp[i - 1][j][k] % MOD;
                if (k) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
                if (j) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k]) % MOD;
            }
        }
    }
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &n, &x, &y);
        printf("%d\n", dp[n][x][y]);
    }
}
