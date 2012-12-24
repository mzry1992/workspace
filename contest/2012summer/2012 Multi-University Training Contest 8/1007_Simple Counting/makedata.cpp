#include <stdio.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

struct Query {
	LL a, b, c, d;
	Query(LL a, LL b, LL c, LL d) : a(a), b(b), c(c), d(d) {}
};

vector<Query> vec;
int main() {
	vec.push_back(Query(1, 99, 1, 1));
	vec.push_back(Query(1, 9999, 53, 23));
	vec.push_back(Query(62, 62, 62, 62));
	vec.push_back(Query(50, 70, 62, 72));
	vec.push_back(Query(1, 1000000000000000000, 999999999999999999, 1));
	vec.push_back(Query(43124, 21378374324123323, 787, 21938));
	vec.push_back(Query(999999999999999998, 999999999999999999, 999999999999999999, 999999999999999999));
	vec.push_back(Query(1, 1, 2, 3));
	vec.push_back(Query(1, 1000000000000000000, 9, 5));
	vec.push_back(Query(100, 100, 2, 3));

	srand((unsigned)time(NULL));
	for(int i = 0; i < 40; ++i) {
		LL a = (LL)rand() * rand() * rand() * rand() + (LL)rand() * rand() * rand();
		LL b = (LL)rand() * rand() * rand() * rand() + (LL)rand() * rand() * rand();
		if(a > b) swap(a, b);
		LL c, d;
		if(i <= 30) c = rand(), d = rand();
		else c = (LL)rand() * rand() * rand(), d = (LL)rand() * rand();
		vec.push_back(Query(a, b, c, d));
	}
	int T = 50;
	printf("%d\n", T);
	for(int i = 0; i < T; ++i) {
		LL tc = vec[i].c;
		LL td = vec[i].d;
		LL mod = 1;
		while(tc) {
			if(tc % 10 == 0) vec[i].c += mod;
			mod *= 10;
			tc /= 10;
		}
		mod = 1;
		while(td) {
			if(td % 10 == 0) vec[i].d += mod;
			mod *= 10;
			td /= 10;
		}
		printf("%lld %lld\n%lld %lld\n", vec[i].a, vec[i].b, vec[i].c, vec[i].d);
	}
	return 0;
}
