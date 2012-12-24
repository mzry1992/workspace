#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
#define MAXN 100000

int s[MAXN], cnt, num[500];

int main() {
	//clock_t start = clock();
	for (int i = 0; i * i <= MAXN; ++i)
		s[cnt++] = i * i;
	int test;
	scanf("%d", &test);
	for (int cas = 1; cas <= test; ++cas) {
		int n;
		scanf("%d", &n);
		int p = lower_bound(s, s + cnt, n) - s;
		int st, pst = 0, th;
		bool flag = false;
		if (n == p * p) {
			st = p;
			th = p + 1;
		} else {
			--p;
			st = n - p * p;
			if (st > p) {
				st -= p;
				++p;
				th = p + 1;
			} else {
				th = p - 1;
				int sum = 0;
				for (int i = p; i > 1; --i) {
					num[i] = p + 1;
					sum += num[i];
				}
				num[1] = n - sum - 1;
				num[0] = 1;
				sum = 0;
				for (int i = 0; i <= p; ++i) {
					for (int j = num[i]; j > 0; --j)
						if (flag)
							printf(" %d", j + sum);
						else {
							printf("%d", j + sum);
							flag = true;
						}
					sum += num[i];
				}
				putchar('\n');
				continue;
			}
		}
		while (st <= n) {
			for (int i = st; i > pst; --i)
				if (flag)
					printf(" %d", i);
				else {
					printf("%d", i);
					flag = true;
				}
			pst = st;
			st += p;
		}
		putchar('\n');
	}
	//printf("%lf\n", (clock() - start) / (double)CLOCKS_PER_SEC);
	return 0;
}
