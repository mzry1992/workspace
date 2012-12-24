#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n = 3;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = j; k < n; k++) {
                for (int kk = k; kk < n; kk++) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}
//C(N+M-1, M)=C(3+4-1,4)=C(6,4)=C(6,2)=
