#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;
int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    const int cas = 30;
    int len[cas];
    len[0] = len[1] = 1;
    for (int i = 2; i < 25; i++) {
        len[i] = (len[i - 1] + len[i - 2]) % 100000 + 1;
    }
    for (int i = 25; i < cas; i++) {
        len[i] = 100000;
    }
    int n[cas];
    for (int i = 0; i < cas; i++) {
        n[i] = (long long)rand() * rand() % 1000000 + 1;
    }
    n[cas - 2] = 500000;
    n[cas - 1] = 1000000;
    int k[cas];
    for (int i = 0; i < cas; i++) {
        k[i] = min(len[i], rand() % 15 + 1);
    }
    k[cas - 2] = 15;
    k[cas - 1] = 15;
    printf("%d\n", cas);
    for (int T = 0; T < cas; T++) {
        printf("%d %d\n", n[T], len[T]);
        printf("%d", k[T]);
        map<int, int> mp;
        mp[0] = 1;
        for (int i = 1; i < k[T]; i++) {
            int pos = rand() % len[T];
            while (mp.count(pos)) {
                pos = rand() % len[T];
            }
            mp[pos] = 1;
        }
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            printf(" %d", it->first);
        }
        puts("");
    }
}
