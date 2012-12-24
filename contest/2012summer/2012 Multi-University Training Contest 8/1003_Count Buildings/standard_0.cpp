#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;
const int MAXN = 2110;
const int MOD = 1000000007;
int S1[MAXN + 1][MAXN + 1];
void StirlingS1(int n) {
    S1[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            S1[i][j] = ((long long)(i - 1) * S1[i - 1][j] % MOD + S1[i - 1][j - 1] % MOD) % MOD;
        }
    }
}
int C[MAXN + 1][MAXN + 1];
void Combination(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = C[i][0] = 1; j <= i && j <= MAXN; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}

int main() {
    StirlingS1(MAXN);
    Combination(MAXN);
    int n, x, y;
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &n, &x, &y);
		if (y + x - 1 > n) {
			puts("0");
			continue;
		}
        printf("%d\n", (int)(((long long)S1[n - 1][y + x - 2] * C[y + x - 2][x - 1]) % MOD));
    }
}
