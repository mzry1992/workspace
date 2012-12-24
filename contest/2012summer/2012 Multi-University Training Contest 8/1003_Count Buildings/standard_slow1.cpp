#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define Mod 1000000007

typedef long long LL;

int f[2001][2001], c[2001][2001];
int p[2001], vp[2001];

int mypow(int a, int p) {
	int r = 1;
	while (p) {
		if (p & 1)
			r = r * (LL)a % Mod;
		a = a * (LL)a % Mod;
		p >>= 1;
	}
	return r;
}

int main() {
	p[0] = 1; vp[0] = 1;
	for (int i = 1; i <= 2000; ++i) {
		p[i] = p[i - 1] * (LL)i % Mod;
		vp[i] = mypow(p[i], Mod - 2);
	}
	f[1][1] = 1;
	for (int i = 2; i <= 2000; ++i)
		for (int j = 2; j <= i; ++j) {
			f[i][j] = f[i - 1][j] * (LL)(i - 2) % Mod;
			f[i][j] = (f[i][j] + f[i - 1][j - 1]) % Mod;
		}
	for (int i = 0; i <= 2000; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % Mod;
	}
	int test;
	scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		int n, a, b;
		scanf("%d%d%d", &n, &a, &b);
		int ans = 0;
		for (int i = a; i <= n - b + 1; ++i)
			ans = (ans + f[i][a] * (LL)f[n - i + 1][b]
				% Mod * (LL)c[n - 1][i - 1]) % Mod;
		printf("%d\n", ans);
	}
	return 0;
}
