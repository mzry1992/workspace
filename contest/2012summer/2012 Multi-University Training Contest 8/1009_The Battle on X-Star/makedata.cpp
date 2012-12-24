#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 10000

inline int myrand(int a, int b) {
	int r = b - a + 1;
	return ((rand() << 15) + rand()) % r + a;
}

typedef long long LL;

inline double dis_rand() {
	return (((LL)rand() << 30) + (rand() << 15) + rand()) / 10000.0;
}

pair<int, int> v[MAXN];
char buf[10000];

int main() {
	FILE* in = fopen("man_made.in", "r");
	while (fgets(buf, sizeof buf, in))
		puts(buf);
	fclose(in);
	srand((long)time(NULL));
	for (int cas = 1; cas <= 10; ++cas) {
		int n = myrand(1, 10000);
		for (int i = 0; i < n; ++i)
			v[i].first = myrand(-90000, 90000),
			v[i].second = myrand(-180000, 180000);
		sort(v, v + n);
		n = unique(v, v + n) - v;
		int m = myrand(1, 1000);
		printf("%d %d %.3f\n", n, m, dis_rand());
		for (int i = 0; i < n; ++i)
			printf("%.3f %.3f\n", v[i].first / 1000.0, v[i].second / 1000.0);
		for (int i = 0; i < m; ++i) {
			int a, b;
			a = myrand(0, n - 1);
			while ((b = myrand(0, n - 1)) == a)
				;
			printf("%d %d\n", a, b);
			printf("%.3f %.3f\n", myrand(-90000, 90000) / 1000.0, myrand(-180000, 180000) / 1000.0);
			printf("%.3f %.3f\n", myrand(0, 5000) / 1000.0, myrand(0, 5000) / 1000.0);
		}
		puts("");
	}
	return 0;
}
