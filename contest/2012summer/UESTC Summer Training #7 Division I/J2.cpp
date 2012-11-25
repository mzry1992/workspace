#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MaxN = 10005;
const int DIGIT_COUNT = 1000000000;
char s[MaxN];
int sn;
int ax[MaxN];
int vst[MaxN][2][2], T;
int n,K;
#define __FISH__

struct BigInt {
    LL d[500];
    int len;
    inline BigInt& operator=(const LL& x) {
        d[0] = x;
        len = 1;
        fix();
        return *this;
    }
    inline BigInt operator*(const LL& x) {
        BigInt ret = *this;
        for (int i = 0; i < len; i++) {
            ret.d[i] *= x;
        }
        ret.fix();
        return ret;
    }
    inline void fix() {
        d[len] = 0;
        while (len > 1 && !d[len - 1]) len--;
        for (int i = 0; i < len; i++) {
            d[i + 1] += d[i] / DIGIT_COUNT;
            d[i] %= DIGIT_COUNT;
        }   
        while (d[len]) {
            d[len + 1] = d[len] / DIGIT_COUNT;
            d[len] %= DIGIT_COUNT;
            len++;
        }
    }
    inline BigInt& operator=(const BigInt& big) {
        len = big.len;
        for (int i = 0; i < len; i++) {
            d[i] = big.d[i];
        }
        d[len] = 0;
        return *this;
    }
    inline BigInt operator+(const BigInt& big) const {
        BigInt ret;
        ret.len = max(len, big.len);
        for (int i = 0; i < ret.len; i++) {
            ret.d[i] = 0;
            if (i < len) ret.d[i] += d[i];
            if (i < big.len) ret.d[i] += big.d[i];
        }
        ret.fix();
        return ret;
    }
    inline void show() const {
#ifdef __FISH__
    	printf("%lld", d[len - 1]);
#else
        printf("%I64d", d[len - 1]);
#endif
        for (int i = len - 2; i >= 0; i--)
#ifdef __FISH__
        	printf("%09lld", d[i]);
#else
            printf("%09I64d", d[i]);
#endif
        puts("");
    }
} dp[MaxN][2][2];

inline BigInt& sol(int dep, int u, int d)
{
    if (vst[dep][u][d] == T) return dp[dep][u][d];
    vst[dep][u][d] = T;
    BigInt& ret = dp[dep][u][d];
    ret = 0;
    if(dep==(n+1)/2)
    {
        if((n+1)&1)
        {
            if(u*K+ax[dep]-d<0 || (u*K+ax[dep]-d)%2)ret = 0;
            else
            {
                int xx = (u*K+ax[dep]-d)/2;
                if(xx<K)ret = 1;
                else ret = 0;
            }
        }
        else
        {
            if(u==d)ret = 1;
        }
        return ret;
    }
    int i, x, nu, nd;

    i = ax[n - dep] - d;
    x = i < K ? (i + 1) : (K - (i - K + 1));
    if (!dep && i < K) x--;
    if (x > 0) {
    	nu = u * K + ax[dep] - i;
    	if (nu >= 0 && nu <= 1) {
    		nd = (i + d) / K;
        	ret = (ret+sol(dep+1, nu, nd)*x);
    	}
    }

    i = ax[n - dep] - d + K;
    x = i < K ? (i + 1) : (K - (i - K + 1));
    if (!dep && i < K) x--;
    if (x > 0) {
    	nu = u * K + ax[dep] - i;
    	if (nu >= 0 && nu <= 1) {
    		nd = (i + d) / K;
        	ret = (ret+sol(dep+1, nu, nd)*x);
    	}
    }
    return ret;
}

inline void cal()
{
    K = 10;
    n = sn - 1;
    s[n+1] = 0;

    for(int i = 0; i <= n; i++)ax[i] = s[i]-'0';
    T++;
    BigInt& ret = sol(0, 0, 0);
    int st = ax[0];
    for(int i = 0; i < n; i++)ax[i] = ax[i+1];
    n--;
    if(n>=0 && st<=1)
    {
        T++;
        ret = ret + sol(0, st, 0);
    }
    ret.show();
}

char ss[100005];
int main()
{
    freopen("J.in","r",stdin);
    //freopen("J2.out","w",stdout);
	int temp;
    while((s[0] = getchar()) != EOF)
    {
    	temp = 1;
    	sn = s[0] == '0' ? 0 : 1;
    	while ((s[sn] = getchar()) != '\n') {
    		if (sn != 0 || s[sn] != '0') sn++;
    		temp++;
    	}
    	if (sn == 0 && temp == 1) break;
        if (sn == 0) {
        	puts("1");
        	continue;
        }
        int xx;
        cal();
    }
    return 0;
}