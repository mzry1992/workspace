//C(n,m) % MOD n, m<=10^6
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const int MAXN = 2000001;
const int MAXP = 150000;
const int MOD = 364875103;
int n, m, num, prime[MAXP];
bool isprime[MAXN + 1];

int sieve(int n) {
    int p = 0;
    memset(isprime, 1, sizeof(isprime));
    for (int i = 2; i <= n; i++) {
        if (isprime[i])
            prime[p++] = i;
        for (int j = 0; j < p && i * prime[j] <= n; j++) {
            isprime[i * prime[j]] = 0;
            if (i % prime[j] == 0)
                break;
        }
    }
    isprime[0] = isprime[1] = 0;
    return p;
}

LL mul(LL a, LL b, LL c) { // a*b % c
    LL ret = 0, tmp = a % c;
    for (; b; b >>= 1) {
        if (b & 1)
            if((ret += tmp) >= c)
                ret -= c;
        if ((tmp <<= 1) >= c)
            tmp -= c;
    }
    return ret;
}

LL power(LL a, LL b, LL c) { // a^b % c
    LL res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = mul(res, a, c);
        a = mul(a, a, c);
    }
    return res;
}

int addfact(int n, int cnt[], int d) {
    int i;
    for (i = 0; i < num && prime[i] <= n; i++) {
        int x = n;
        while (x) {
            cnt[i] += d * (x / prime[i]);
            x /= prime[i];
        }
    }
    return i;
}
LL C(int n, int m) {
    int p, cnt[MAXP] = {0};
    p = addfact(n, cnt, 1);//分子n!
    addfact(m, cnt, -1);//分母m!
    addfact(n - m, cnt, -1);//分母(n-m)!
    LL ret = 1;
    for (int i = 0; i < p; i++)
        ret = mul(ret, power(prime[i], cnt[i], MOD), MOD);//mul(ret * power(prime[i],cnt[i],MOD)) % MOD;
    return ret % MOD;
}

int id[16];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    num = sieve(MAXN);
    //cout << num << endl;
    /*while (scanf("%d%d", &n, &m) != EOF) {
        printf("%I64d\n", C(n, m));
    }*/
    int cas, n, m;
    scanf("%d", &cas);
    for (int T = 1; T <= cas; T++) {
        scanf("%d%d", &n, &m);
        int k;
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%d", &id[i]);
        }
        id[k] = m;
        int cnt;
        long long ans = 1;
        for (int i = 1; i <= k; i++) {
            cnt = id[i] - id[i - 1];
            ans = (ans * C(n + cnt - 1, cnt)) % MOD;
        }
        printf("Case #%d: %I64d\n", T, ans);
    }
}
