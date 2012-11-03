#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
//#include <algorithm>
#include <bitset>
#include <list>
#include <set>
#include <map>

using namespace std;


#define REP(I, N) for (int I=0;I<int(N);++I)
#define FOR(I, A, B) for (int I=int(A);I<int(B);++I)
#define DWN(I, B, A) for (int I=int(B-1);I>=int(A);--I)
#define REP_1(I, N) for (int I=1;I<=int(N);++I)
#define FOR_1(I, A, B) for (int I=int(A);I<=int(B);++I)
#define DWN_1(I, B, A) for (int I=int(B);I>=int(A);--I)
#define REP_C(I, N) for (int N____=int(N),I=0;I<N____;++I)
#define FOR_C(I, A, B) for (int B____=int(B),I=A;I<B____;++I)
#define DWN_C(I, B, A) for (int A____=int(A),I=B-1;I>=A____;--I)
#define REP_1_C(I, N) for (int N____=int(N),I=1;I<=N____;++I)
#define FOR_1_C(I, A, B) for (int B____=int(B),I=A;I<=B____;++I)
#define DWN_1_C(I, B, A) for (int A____=int(A),I=B;I>=A____;--I)
#define DO(N) while(N--)
#define DO_C(N) int N____ = N; while(N____--)
#define TO(i, a, b) int s_=a<b?1:-1,b_=b+s_;for(int i=a;i!=b_;i+=s_)
#define TO_1(i, a, b) int s_=a<b?1:-1,b_=b;for(int i=a;i!=b_;i+=s_)
#define SQZ(I, J, A, B) for (int I=int(A),J=int(B)-1;I<J;++I,--J)
#define SQZ_1(I, J, A, B) for (int I=int(A),J=int(B);I<=J;++I,--J)



#define ALL(A) A.begin(), A.end()
#define CLR(A) A.clear()
#define CPY(A, B) memcpy(A, B, sizeof(A))
#define INS(A, P, B) A.insert(A.begin() + P, B)
#define ERS(A, P) A.erase(A.begin() + P)
#define SRT(A) sort(ALL(A))
#define BSC(A, X) find(ALL(A), X) // != A.end()
#define SZ(A) int(A.size())
#define PB push_back
#define MP(A, B) make_pair(A, B)

#define Rush int T____; RD(T____); DO(T____)
#pragma comment(linker, "/STACK:36777216")
#define Ruby system("ruby main.rb")
#define Haskell system("runghc main.hs")
#define Pascal system("fpc main.pas")

typedef long long LL;
typedef double DB;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<LL> VL;
typedef vector<DB> VD;
typedef set<int> SI;
typedef set<string> SS;
typedef set<LL> SL;
typedef set<DB> SD;
typedef map<int, int> MII;
typedef map<string, int> MSI;
typedef map<LL, int> MLI;
typedef map<DB, int> MDI;
typedef pair<int, int> PII;
typedef pair<int, bool> PIB;

template<class T> inline void RD(T &x)
{
    //cin >> x;
    scanf("%d", &x);
    //char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
    //char c; c = getchar(); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';

}

template<class T> inline void OT(const T &x)
{
    cout << x;
    //printf("%d", &x);
}

inline int RD()
{
    int x;
    RD(x);
    return x;
}
template<class T0, class T1> inline void RD(T0 &x0, T1 &x1)
{
    RD(x0), RD(x1);
}
template<class T0, class T1, class T2> inline void RD(T0 &x0, T1 &x1, T2 &x2)
{
    RD(x0), RD(x1), RD(x2);
}
template<class T0, class T1, class T2, class T3> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3)
{
    RD(x0), RD(x1), RD(x2), RD(x3);
}
template<class T0, class T1, class T2, class T3, class T4> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4)
{
    RD(x0), RD(x1), RD(x2), RD(x3), RD(x4);
}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5)
{
    RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5);
}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void RD(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6)
{
    RD(x0), RD(x1), RD(x2), RD(x3), RD(x4), RD(x5), RD(x6);
}
template<class T0, class T1> inline void OT(T0 &x0, T1 &x1)
{
    OT(x0), OT(x1);
}
template<class T0, class T1, class T2> inline void OT(T0 &x0, T1 &x1, T2 &x2)
{
    OT(x0), OT(x1), OT(x2);
}
template<class T0, class T1, class T2, class T3> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3)
{
    OT(x0), OT(x1), OT(x2), OT(x3);
}
template<class T0, class T1, class T2, class T3, class T4> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4)
{
    OT(x0), OT(x1), OT(x2), OT(x3), OT(x4);
}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5)
{
    OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5);
}
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6> inline void OT(T0 &x0, T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5, T6 &x6)
{
    OT(x0), OT(x1), OT(x2), OT(x3), OT(x4), OT(x5), OT(x6);
}


template<class T> inline void RST(T &A)
{
    memset(A, 0, sizeof(A));
}
template<class T0, class T1> inline void RST(T0 &A0, T1 &A1)
{
    RST(A0), RST(A1);
}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2)
{
    RST(A0), RST(A1), RST(A2);
}
template<class T0, class T1, class T2, class T3> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3)
{
    RST(A0), RST(A1), RST(A2), RST(A3);
}
template<class T0, class T1, class T2, class T3, class T4> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4)
{
    RST(A0), RST(A1), RST(A2), RST(A3), RST(A4);
}
template<class T0, class T1, class T2, class T3, class T4, class T5> inline void RST(T0 &A0, T1 &A1, T2 &A2, T3 &A3, T4 &A4, T5 &A5)
{
    RST(A0), RST(A1), RST(A2), RST(A3), RST(A4), RST(A5);
}

//#

template<class T> inline void FLC(T &A, int x)
{
    memset(A, x, sizeof(A));
}
template<class T0, class T1> inline void FLC(T0 &A0, T1 &A1, int x)
{
    FLC(A0, x), FLC(A1, x);
}
template<class T> inline void FLC(T &A0, T &A1, T &A2, int x)
{
    FLC(A0, x), FLC(A1, x), FLC(A2, x);
}
template<class T> inline void FLC(T &A0, T &A1, T &A2, T &A3, int x)
{
    FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x);
}
template<class T> inline void FLC(T &A0, T &A1, T &A2, T &A3, T &A4, int x)
{
    FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x);
}
template<class T> inline void FLC(T &A0, T &A1, T &A2, T &A3, T &A4, T &A5, int x)
{
    FLC(A0, x), FLC(A1, x), FLC(A2, x), FLC(A3, x), FLC(A4, x), FLC(A5, x);
}

//#

template<class T> inline int max(T a, T b, T c)
{
    return max(max(a, b), c);
}
template<class T> inline void checkMin(T &a, T b)
{
    if (b < a) a = b;
}
template<class T> inline void checkMax(T &a, T b)
{
    if (b > a) a = b;
}



const int INF = ~0U >> 3;
const int N = 500003;

int A[N], R[N], l[N], r[N], p[N], ky[N], sz[N], sm[N], ls[N], rs[N], ms[N], bj[N]; char cmd[10];
int n, m, s, t, c, x, y, z, recy, root, total;

#define lx l[x]
#define rx r[x]

inline void Set(int l[], int y, int x)
{
    l[y] = x, p[x] = y;
}

inline void Release(int x)
{

    if (!x) return ;

    if (bj[x] & 1)
    {
        bj[lx] ^= 1, bj[rx] ^= 1;
        swap(l[x], r[x]), swap(ls[x], rs[x]);
    }

    if (bj[x] & 2)
    {
        sm[x] = sz[x] * ky[x], ms[x] = ls[x] = rs[x] = ky[x] < 0 ? ky[x] : sm[x];
        if (lx) bj[lx] |= 2, ky[lx] = ky[x]; if (rx)  bj[rx] |= 2, ky[rx] = ky[x];
    }

    bj[x] = 0;
}


inline void Update(int x)
{

    //if (!x) return;

    Release(x), Release(lx), Release(rx);

    sz[x] = sz[lx] + sz[rx] + 1, sm[x] = sm[lx] + sm[rx] + ky[x];
    ls[x] = max(ls[lx], sm[lx] + ky[x] + max(0, ls[rx]));
    rs[x] = max(rs[rx], sm[rx] + ky[x] + max(0, rs[lx]));
    ms[x] = max(ms[lx], ms[rx], ky[x] + max(0, rs[lx]) + max(0, ls[rx])) ;
}

inline void Update(int x, int y)
{
    Update(x), Update(y);
}

inline void Rotate(int x)
{
    int y = p[x], z = p[y]; Set(y == l[z] ? l : r,  z, x); if (x == l[y])
    {
        Set(l, y, rx), Set(r, x, y);
    }
    else
    {
        Set(r, y, lx), Set(l, x, y);
    }
    Update(y), Update(x);
}
inline void Splay(int x)
{
    while (p[x]) Rotate(x);
    root = x;
}

inline int Select(int k)
{
    int x = root; while (Release(x), sz[lx] != k)
    {
        if (sz[lx] < k) k -= sz[lx] + 1, x = rx;
        else x = lx;
    }

    Splay(x); return x;
}

inline int Select(int a, int b)
{
    return Select(b + 1), l[r[Select(a - 1)]];
}

inline int Build(int a = 1, int b = n)
{
    if (a > b) return 0;

    int x = (recy ? R[recy--] : ++total);

    if (a == b)
    {
        ms[x] = ls[x] = rs[x] = sm[x] = ky[x] = A[a], sz[x] = 1;
    }
    else
    {
        int m = (a + b) >> 1;
        lx = Build(a, m - 1), rx = Build(m + 1, b);
        p[lx] = p[rx] = x, ky[x] = A[m], Update(x);
    }

    return x;
}

void Insert(int x, int p)
{
    y = Select(p), z = Select(p + 1);
    Set(r, y, x), Update(y, z);
}

void Recycle(int x)
{
    if (!x) return;
    Recycle(lx), Recycle(rx);
    l[x] = r[x] = bj[x] = 0, R[++recy] = x;
}

void Inorder(int x = root)
{
    if (x == 0) return; Release(x); Inorder(lx);
    if (ky[x] == -INF || ky[x] == INF) printf("$ ");
    else printf("%d ", ky[x]);
    Inorder(rx);
}


int main()
{

    freopen("N.in", "r", stdin);
    freopen("N2.out", "w", stdout);


    ls[0] = rs[0] = ms[0] = A[1] = A[n = 2] = -INF, root = Build();
    RD(n, m); REP_1(i, n) RD(A[i]); Insert(Build(), 0);

    int cnt = n;

    DO(m)
    {
        scanf("%s", cmd);

        if (cmd[0] == 'I')  // Insert ... .
        {
            RD(s, n); REP_1(i, n) RD(A[i]);
            cnt += n;
            Insert(Build(), s);
        }
        else if (cmd[0] == 'D')  // Delete
        {
            RD(s, t); y = Select(s + t), z = Select(s - 1), x = l[y];
            if (x == l[y]) l[y] = 0; else r[y] = 0;
            Recycle(x), Update(y, z);
        }
        else if (cmd[2] == 'K')  // Make_Same
        {
            RD(s, t, c), y = Select(s + t), z = Select(s - 1), x = l[y];
            bj[x] |= 2, ky[x] = c, Update(y, z);
        }
        else if (cmd[0] == 'R')  // Reverse ..
        {
            RD(s, t), y = Select(s + t), z = Select(s - 1), x = l[y];
            bj[x] ^= 1, Update(y, z);
        }
        else if (cmd[0] == 'G')  // Get_Sum ..
        {
            RD(s, t); printf("%d\n", sm[Select(s , s + t - 1)]);
        }
        else   // Max_Sum ...
        {
            printf("%d\n", ms[root]);
        }

    }
    // Inorder() ...
}