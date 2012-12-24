#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n, l, a, b, mod;
	while (scanf("%d%d%d%d%d", &n, &l, &a, &b, &mod) != EOF) {
		a %= mod; b %= mod;
		int ans = 0;
		int le = l, ri = 0;
		int sum = b; int y = l / 2;
		for (int i = 1; i <= n; ++i) {
			sum += a;
			if (sum >= mod) sum -= mod;
			if (sum <= y) {
				++ans;
				if (sum > ri) ri = sum;
			} else {
				if (sum < le) le = sum;
			}
		}
		printf("%d\n", ans + (le + (long long)ri <= l));
	}
	return 0;
}
