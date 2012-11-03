/** ` Micro Mezzo Macro Flation -- Overheated Economy ., **/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define REP(i, n) for (int i=0;i<int(n);++i)
#define FOR(i, a, b) for (int i=int(a);i<int(b);++i)
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define FOR_C(i, a, b) for (int b____=int(b),i=a;i<b____;++i)
#define DO(n) while(n--)
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)
#define Rush int T____; RD(T____); DO(T____)
#pragma comment(linker, "/STACK:36777216")
#pragma GCC optimize ("O2")

template<class T> inline void RD(T &);
template<class T> inline void OT(const T &);
template<class T> inline T &_RD(T &x)
{
    RD(x);
    return x;
}
inline void RS(char *s)
{
    scanf("%s", s);
}
template<class T0, class T1> inline void RD(T0 &x0, T1 &x1)
{
    RD(x0), RD(x1);
}
template<class T0, class T1, class T2> inline void RD(T0 &x0, T1 &x1, T2 &x2)
{
    RD(x0), RD(x1), RD(x2);
}
template<class T> inline void RST(T &A)
{
    memset(A, 0, sizeof(A));
}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3)
{
    RST(A0), RST(A1), RST(A2), RST(A3);
}
template<class T> inline void FLC(T &A, int x)
{
    memset(A, x, sizeof(A));
}
template<class T> inline void CLR(T &A)
{
    A.clear();
}
template<class T> inline void checkMax(T &a, const T b)
{
    if (b > a) a = b;
}
inline int _1(int i)
{
    return 1 << i;
}
template<class T> inline void RD(T &x)
{
    /*char c;
    for (c = getchar(); c < '0'; c = getchar());
    x = c - '0';
    for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';*/
    scanf("%d",&x);
}
template<class T> inline void OT(const T &x)
{
    printf("%d\n", x);
}
template<class T> inline T max(T a, T b, T c)
{
    return max(max(a, b), c);
}
/* .................................................................................................................................. */
const int N = 10001, M = 2 * N;

int l[N], r[N], p[N], w0[N], w1[N]; bool rt[N];
// Link-cut tree
int hd[N], nxt[M], a[M], b[M], w[M], h[M / 2];
// Adjacent list
int splaytime,rotatetime;

int n, ans;

#define lx l[x]
#define rx r[x]

inline void Update(int x)
{
    w1[x] = max(w1[lx], w1[rx], w0[x]);
}

inline void Set(int l[], int y, int x)
{
    l[y] = x, p[x] = y;
}

inline void Rotate(int x)
{
    rotatetime++;
    int y = p[x], z = p[y];

    if (!rt[y]) Set(y == l[z] ? l : r, z, x);
    else p[x] = z;

    if (x == l[y]) Set(l, y, rx), Set(r, x, y);
    else Set(r, y, lx), Set(l, x, y);

    if (rt[y]) rt[y] = false, rt[x] = true; //rt[0] = true;
    Update(y); //Update(x);

}

inline void Splay(int x)
{
    splaytime++;
    while (!rt[x]) Rotate(x);
}

void Access(int x)
{
    int y = 0; do
    {
        Splay(x);
        rt[rx] = true, rt[rx = y] = false, Update(x);
        x = p[y = x];
    }
    while (x);
}

// public:

void Query(int x, int y)
{
    Access(y), y = 0; do
    {
        Splay(x); //if (!p[x]) OT(max(w1[rx], w1[y]));
        rt[rx] = true, rt[rx = y] = false, Update(x);
        x = p[y = x];
    }
    while (x);
}

void Modify(int x, int val)
{
    Splay(x), w0[x] = val;
}

#define v b[i]
#define w w[i]

inline void dfs(int u = 1)
{
    for (int i = hd[u]; i; i = nxt[i]) if (!p[v])
        {
            p[v] = u, w0[v] = w, dfs(h[i >> 1] = v);
        }
}

#undef x
#undef w

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data1.out", "w", stdout);

    Rush
    {
        // Initializing Phase ...
        rotatetime = splaytime = 0;
        FOR_C(i, 2, _RD(n) << 1)
        {
            RD(a[i], b[i], w[i]), a[i | 1] = b[i], b[i | 1] = a[i], w[i | 1] = w[i];
            nxt[i] = hd[a[i]], hd[a[i]] = i; ++i;
            nxt[i] = hd[a[i]], hd[a[i]] = i;
        }

        FLC(rt, true), p[1] = -1, dfs(), p[1] = 0;

        // Interaction Phase ...

        int a, b; char cmd[5];

        while (true)
        {
            RS(cmd); if (cmd[0] == 'C') RD(a, b), Modify(h[a], b);
            else if (cmd[0] == 'Q') RD(a, b), Query(a, b);
            else break;
        }

        // Rececling ....

        printf("splaytime = %d, rotatetime = %d\n",splaytime,rotatetime);
        RST(hd, p, l, r);
    }
}