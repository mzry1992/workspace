#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define M1 97
#define M2 3761599

typedef long long LL;
int n, m, k;
int a[100000];
int p1[M1], p2[M2];

int mypow(int a, int p, int mod) {
	int r = 1;
	while (p) {
		if (p & 1) r = r * (LL)a % mod;
		a = a * (LL)a % mod;
		p >>= 1;
	}
	return r;
}

int C(int n, int k, int mod, int *p) {
	if (n < k) return 0;
	int ret = p[n] * (LL)mypow(p[k], mod - 2, mod) % mod;
	return ret * (LL)mypow(p[n - k], mod - 2, mod) % mod;
}

int lucas(int n, int k, int mod, int *p) {
    int res = 1;
    while (n && k && res) {
        res = res * (LL)C(n % mod, k % mod, mod, p) % mod;
        n /= mod, k /= mod;
    }
    return res;
}


int main() {
	p1[0] = p2[0] = 1;
	for (int i = 1; i < M1; ++i)
		p1[i] = p1[i - 1] * i % M1;
	for (int i = 1; i < M2; ++i)
		p2[i] = p2[i - 1] * (LL)i % M2;
	int c1 = M2 * mypow(M2, M1 - 2, M1);
	int c2 = M1 * mypow(M1, M2 - 2, M2);
	int test;
	scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < k; ++i)
			scanf("%d", a + i);
		a[k++] = m;
		sort(a, a + k);
		int ret = 1;
		for (int i = 1; i < k; ++i) {
			int a1 = lucas(a[i] - a[i - 1] + n - 1, a[i] - a[i - 1], M1, p1);
			int a2 = lucas(a[i] - a[i - 1] + n - 1, a[i] - a[i - 1], M2, p2);
			//printf("%d %d\n", a1, a2);
			int r = (a1 * (LL)c1 + a2 * (LL)c2) % (M1 * M2);
			ret = ret * (LL)r % (M1 * M2);
		}
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}