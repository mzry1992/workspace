
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 40007;
bool isprime[MAXN];
int prime[MAXN],tot;
void init() {
	fill(isprime,isprime+40000,true);
	for(int i = 3 ; i <= 200 ; i += 2 ) {
		if(isprime[i]) {
			int t = 40000/i;
			for(int j = 3 ; j <= t ; j += 2 ) {
				isprime[i*j] = false;
			}
		}
	}
	tot = 0;
	prime[tot++] = 2;
	for(int i = 3 ; i <= 39999 ; i += 2 ) {
		if(isprime[i])
			prime[tot++] = i;
	}
}
int solve(int n) {
	int ans = 1,t;
	for(int i = 0 ; prime[i]*prime[i] <= n && i < tot ; i ++ ) {
		t = 0;
		while(!(n % prime[i])) {
			t ++;
			n /= prime[i];
		}
		ans *= 2*t+1;
	}
	if(ans == 1 || n != 1)
		ans *= 3;
	return ans;
}

int main() {
	int t,n,var=0;
	scanf("%d",&t);
	init();
	while(t -- ) {
		scanf("%d",&n);
		int ans = solve(n);
		printf("Scenario #%d:\n",++var);
		if(n == 1) ans = 1;
		printf("%d\n\n",(ans+1)/2);
	}
	return 0;
}
