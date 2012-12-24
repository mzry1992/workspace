#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int main() {
    int n, L, A, B, mod;
    while (scanf("%d%d%d%d%d", &n, &L, &A, &B, &mod) != EOF) {
        int last = B, now, minv = L, maxv = 0, cnt = 0;
        for (int i = 1; i <= n; ++i) {
            now = last + A;
            while (now >= mod) now -= mod;
            last = now;
            if (now > L / 2) {
                minv = min(minv, now);
            } else {
                maxv = max(maxv, now);
                cnt++;
            }
        }
        if (minv + (long long)maxv <= L)
            cnt++;
        printf("%d\n", cnt);
    }
}
