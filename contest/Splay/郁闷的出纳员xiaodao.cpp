/* .................................................................................................................................. */

/** Header **/

#include <cstdio>
#include <cstring>
#define DO(N) while(N--)

template<class T> inline void RD(T &x)  // ... :" I am I/O Accelerator ... Use me at your own risk ;) ... " ..
{
    //scanf("%d", &x);
    char c;
    c = getchar();
    x = c - '0';
    for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';
}
template<class T> inline void RD(T &x0, T &x1)
{
    RD(x0), RD(x1);
}
template<class T> inline void RST(T &A)
{
    memset(A, 0, sizeof(A));
}
template<class T> inline void RST(T &A0, T &A1)
{
    RST(A0), RST(A1);
}
template<class T> inline void RST(T &A0, T &A1, T &A2)
{
    RST(A0), RST(A1), RST(A2);
}
template<class T> inline void checkMin(T &a, T b)
{
    if (b<a) a=b;
}

const int INF = 0x7fffffff;
const int N = 100001;

int l[N], r[N], p[N], ky[N], sz[N];
int root, total;
int n, b, d, ans;


inline void Rotate(int x)
{
    int y = p[x], z = p[y], lc = l[x], rc = r[x];
    if (y == l[z]) l[z] = x;
    else r[z] = x;
    if (x == l[y])
    {
        p[p[p[rc] = y] = x] = z, l[r[x] = y] = rc;
        sz[x] = sz[y], sz[y] -= sz[lc] + 1;
    }
    else
    {
        p[p[p[lc] = y] = x] = z, r[l[x] = y] = lc;
        sz[x] = sz[y], sz[y] -= sz[rc] + 1;
    }
}

inline void Splay(int x)
{
    while (p[x]) Rotate(x);
    root = x;
}

void Insert(int val)
{
    val -= b - d;
    if (val < d) return;
    int x = root, y = 0;
    while (x != 0)
    {
        ++sz[y = x];
        if (val < ky[x]) x = l[x];
        else x = r[x];
    }

    x = ++total, ky[x] = val, sz[x] = 1, p[x] = y;
    if (val < ky[y]) l[y] = x;
    else r[y] = x;

    Splay(x);
}

int Search()
{
    int val = d, res = 0, x = root;
    while (x != 0)
    {
        if (val > ky[x]) x = r[x];
        else
        {
            if (ky[x] <= ky[res]) res = x;
            x = l[x];
        }
    }
    return res;
}

int Select(int k)
{
    printf("%d\n",k);
    int x = root;
    while (sz[l[x]] + 1 != k)
    {
        if (sz[l[x]] + 1 < k) k -= sz[l[x]] + 1, x = r[x];
        else x = l[x];
    }
    Splay(x);
    return x;
}

int main()
{

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

#define gc getchar()

    while (scanf("%d %d", &n, &b)  != EOF)
    {

        gc;
        RST(p, l, r);
        RST(ky, sz);
        root = total = ans = d = 0;
        Insert(INF), ky[0] = INF;
        int t;
        DO(n)
        {

            char cmd = gc;
            gc; //scanf(" %c", &cmd);
            RD(t);
            switch (cmd)
            {
            case 'I':
                Insert(t);
                break;
            case 'A':
                d -= t;
                break;
            case 'S':
                d += t, Splay(Search());
                ans += sz[l[root]], sz[root] -= sz[l[root]], l[root] = 0;
                break;
            default:
                if (t >= sz[root]) puts("-1");
                else printf("%d\n", ky[Select(sz[root] - t)] + b - d);
            }
        }
        printf("%d\n", ans);
    }
}
