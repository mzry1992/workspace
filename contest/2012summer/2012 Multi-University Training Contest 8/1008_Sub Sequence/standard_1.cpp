#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;


int main() {
	int T;
	scanf("%d",&T);
	while (T --) {
		int n;
		scanf("%d",&n);
		int m = 1;
		while (m * m < n) {
			m ++;
		}
		vector<int> out;
		int s = 0;
		if (n <= m * (m - 1)) {
			out.push_back(1);
			s = 1;
		}
		int e = (n - 1) % m + 1;
		for (int i = e ; i > s ; i --) {
			out.push_back(i);
		}
		while ((e += m) <= n) {
			s = e - m;
			for (int i = e ; i > s ; i --) {
				out.push_back(i);
			}
		}
		for (int i = 0 ; i < out.size() ; i ++) {
			printf("%d%c",out[i] , (i == out.size() - 1) ? '\n' :' ');
		}
	}
	return 0;
}
