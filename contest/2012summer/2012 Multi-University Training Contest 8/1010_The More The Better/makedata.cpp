#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

typedef long long LL;

inline int myrand(int mod) {
	return (((LL)rand() << 30) + (rand() << 15) + rand()) % mod;
}

int main() {
	srand((long)time(NULL));
	puts("1 2000000000 999999998 1 1000000000");
	for (int cas = 1; cas <= 100; ++cas)
		printf("%d %d %d %d %d\n", myrand(1000) + 1, myrand(2000000000) + 1, myrand(1000000000) + 1, myrand(1000000000) + 1, myrand(1000000000) + 1);
	for (int cas = 1; cas <= 10; ++cas)
		printf("%d %d %d %d %d\n", myrand(20000000) + 1, myrand(2000000000) + 1, myrand(1000000000) + 1, myrand(1000000000) + 1, myrand(1000000000) + 1);
	printf("%d %d %d %d %d\n", 20000000, myrand(2000000000) + 1, myrand(1000000000) + 1, myrand(1000000000) + 1, myrand(1000000000) + 1);
	return 0;
}
