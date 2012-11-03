#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#define P 32000
#define LL long long

int pr[P], pn;
bool notp[P];

void sieve()
{
    for (int i = 2; i < P; ++i) {
        if (!notp[i]) pr[pn++] = i;
        for (int j = 0; j < pn && i * pr[j] < P; ++j) {
            notp[i*pr[j]] = 1;
            if (i%pr[j]==0) break;
        }
    }
}

#define MOD 76543
int hs[MOD], head[MOD], next[MOD], id[MOD], top;

void insert(int x, int y)
{
    int k = x%MOD;
    hs[top] = x, id[top] = y, next[top] = head[k], head[k] = top++;
}

int find(int x)
{
    int k = x%MOD;
    for (int i = head[k]; i; i = next[i]) if (hs[i] == x) return id[i];
    return -1;
}

int BSGS(int a, int b, int n)
{
    memset(head, 0, sizeof(head)); top = 1;
    if (b==1) return 0;
    int m = sqrt(n+.0), j; LL x = 1, p = 1;
    for (int i = 0; i < m; ++i, p = p*a%n) insert(p*b%n, i);
    for (LL i = m; ; i += m) {
        if ((j = find(x=x*p%n)) != -1) return i-j;
        if (i > n) break;
    }
    return -1;
}

int powMod(LL b, LL p, int m)
{
    LL a = 1;
    for (; p; p >>= 1, b = b*b%m) if (p&1) a = a*b%m;
    return a;
}

int pf[10], nf[10], fCnt;

void Factor(int n)
{
    int n2 = sqrt(n+.0); fCnt = 0;
    for (int i = 0; pr[i] <= n2 && n > 1; ++i) if (!(n%pr[i])) {
        for (nf[fCnt] = 1, n/=pr[i]; !(n%pr[i]); n/=pr[i], ++nf[fCnt]);
        pf[fCnt++] = pr[i];
    }
    if (n > 1) nf[fCnt] = 1, pf[fCnt++] = n;
}

int PriRoot(int p)
{
    if (p==2) return 1;
    int phi = p - 1, g, i;
    Factor(phi);
    for (g = 2; g < p; ++g) {
        for (i = 0; i < fCnt; ++i)
            if (powMod(g, phi/pf[i], p) == 1) break;
        if (i == fCnt) break;
    }
    return g;
}

LL ext_gcd(LL a, LL b, LL& x, LL& y)
{
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    LL ret = ext_gcd(b, a%b, y, x);
    y -= a/b*x;
    return ret;
}

int rec[20], md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int y)
{
    return !(y%400) || (y%100 && !(y%4));
}

int Year(int y)
{
    int ret = 365*24*60*60;
    if (leap(y)) ret += 24*60*60;
    if (y%10==5 || y%10==8) ++ret;
    return ret;
}

int Month(int y, int m)
{
    int ret = md[m-1]*24*60*60;
    if (leap(y) && m==2) ret += 24*60*60;
    if ((y%10==5 || y%10==8) && m==12) ++ret;
    return ret;
}

int Day(int y, int m, int d)
{
    int ret = 24*60*60;
    if ((y%10==5 || y%10==8) && m==12 && d==31) ++ret;
    return ret;
}

void outDate(int x)
{
    printf("%d\n",x);
    int year = 2000, month = 1, day = 1, hour = 0, minute = 0, second = 0;
    while (x >= Year(year)) x -= Year(year++);
    while (x >= Month(year, month)) x -= Month(year, month++);
    while (x >= Day(year, month, day)) x -= Day(year, month, day++);
    while (x >= 60*60) x -= 60*60, ++hour;
    while (x >= 60) x -= 60, ++minute;
    second = x;
    if (hour == 24){
        hour = 23;
        minute = 59;
        second = 60;
    }
    printf("%d.%02d.%02d %02d:%02d:%02d\n", year, month, day, hour, minute, second);
}

void solve(int a, int b, int p)
{
    if (!b) {
        outDate(0);
        return;
    }
    int g = PriRoot(p);
    int x = BSGS(g, b, p);
    LL y, t, d = ext_gcd(a, p-1, y, t);
    if (x == -1 || x%d) {
        puts("Transmission error");
        return;
    }
/*    
    y=(y*(x/d))%(p-1);
    d=(p-1)/d;
    int ti = 0;
    for (y=(y%d+d)%d;y<p-1;y+=d)
        rec[ti++] = powMod(g,y,p);
    d = ti;
    */

y %= (p-1)/d;
    if (y < 0) y += (p-1)/d;
    
    for (int i = 0; i < d; ++i) {
        LL ty = y*(x/d)+(p-1)/d*i;
        rec[i] = powMod(g, ty, p);
    }

    std::sort(rec, rec + d);
    for (int i = 0; i < d; ++i) outDate(rec[i]);
}

int main()
{
    sieve();
    int T, cas = 0, a, b, c;
    scanf("%d", &T);
    while (T--) {
//        srand(time(NULL));
//        c = 1000000007;//465455467;//rand() % (pn-1) + 1;
//        a = rand() % 8 + 2, b = (LL)rand()*rand()*rand()%c;//
        scanf("%d%d%d", &c, &a, &b);
        printf("Case #%d:\n", ++cas);
        solve(a, b, c);
    }
    return 0;
}
