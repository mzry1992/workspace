#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX = 20500;
const int oo = 0x3f3f3f3f;

struct Edge
{
    int id, to, w;
    bool solid;
    Edge *next;
} e[MAX], *cur, *g[MAX], *valid[MAX], *solid[MAX], *pree[MAX];
bool vst[MAX];
int d[MAX], cnt[MAX], p[MAX], pos[MAX];
int dp[20][MAX], lcaidx[MAX], n, K, top;
int seg[MAX << 2], head[MAX], q[MAX];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        g[i] = NULL;
        valid[i] = NULL;
        solid[i] = NULL;
        vst[i] = false;
    }
    cur = e;
    K = 0;
    top = 0;
}

void add(int id, int u, int v, int w)
{
    cur->id = id;
    cur->to = v;
    cur->w = w;
    cur->solid = false;
    cur->next = g[u];
    g[u] = cur++;
    cur->id = id;
    cur->to = u;
    cur->w = w;
    cur->solid = false;
    cur->next = g[v];
    g[v] = cur++;
}

void dfs(int dep, int u, int pre)
{
    vst[u] = true;
    d[u] = dep;
    p[u] = pre;
    cnt[u] = 1;
    lcaidx[u] = K;
    dp[0][K++] = u;
    for (Edge *it = g[u]; it; it = it->next)
    {
        int v = it->to;
        if (!vst[v])
        {
            dfs(dep + 1, v, u);
            pree[v] = it;
            dp[0][K++] = u;
            cnt[u] += cnt[v];
            valid[it->id] = it;
            if (solid[u] == NULL || cnt[solid[u]->to] < cnt[v])
            {
                solid[u] = it;
            }
        }
    }
    if (solid[u])
        solid[u]->solid = true;
}

void dfs(int u, int h)
{
    vst[u] = true;
    head[u] = h;
    if (solid[u])
    {
        pos[u] = top;
        q[top++] = u;
        dfs(solid[u]->to, h);
        for (Edge *it = g[u]; it; it = it->next)
        {
            int v = it->to;
            if (!vst[v])
            {
                dfs(v, v);
            }
        }
    }
}

void rmq()
{
    int st = 1;
    for (int i = 1; i < 20; i++)
    {
        for (int j = 0; j + st < K; j++)
        {
            dp[i][j] = d[dp[i - 1][j]] < d[dp[i - 1][j + st]] ? dp[i - 1][j]
                       : dp[i - 1][j + st];
        }
        if (st >= K)
            break;
        st <<= 1;
    }
}

int rmq(int l, int r)
{
    int st = 1, dep = -1;
    while (st <= r - l + 1)
    {
        st <<= 1;
        dep++;
    }
    st >>= 1;
    return d[dp[dep][l]] < d[dp[dep][r - st + 1]] ? dp[dep][l] : dp[dep][r - st
            + 1];
}

int lca(int u, int v)
{
    if (lcaidx[u] <= lcaidx[v])
        return rmq(lcaidx[u], lcaidx[v]);
    else
        return rmq(lcaidx[v], lcaidx[u]);
}

void init(int k, int l, int r)
{
    if (l == r)
    {
        seg[k] = solid[q[l]]->w;
        return;
    }
    int mid = l + r >> 1;
    init(k << 1, l, mid);
    init(k << 1 | 1, mid + 1, r);
    seg[k] = max(seg[k << 1], seg[k << 1 | 1]);
}

void update(int k, int l, int r, int idx, int v)
{
    if (l == r)
    {
        seg[k] = v;
        return;
    }
    int mid = l + r >> 1;
    if (idx <= mid)
        update(k << 1, l, mid, idx, v);
    else
        update(k << 1 | 1, mid + 1, r, idx, v);
    seg[k] = max(seg[k << 1], seg[k << 1 | 1]);
}

int read(int k, int l, int r, int ll, int rr)
{
    if (l > rr || r < ll)
        return -oo;
    if (l >= ll && r <= rr)
        return seg[k];
    int mid = l + r >> 1;
    return max(read(k << 1, l, mid, ll, rr),
               read(k << 1 | 1, mid + 1, r, ll, rr));
}

int getPr(int pr, int u)
{
    int ret = -oo;
    int ptr = u;

    while (ptr != pr)
    {
        if (pree[ptr]->solid)
        {
            int tmp = head[ptr];
            if (d[tmp] < d[pr])
                tmp = pr;
            ret = max(ret, read(1, 0, top - 1, pos[tmp], pos[p[ptr]]));
            ptr = tmp;
        }
        else
        {
            ret = max(ret, pree[ptr]->w);
            ptr = p[ptr];
        }
    }

    return ret;
}

int query(int u, int v)
{
    if (u == v)
        return 0;
    int p = lca(u, v);

    return max(getPr(p, u), getPr(p, v));
}

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data1.out", "w", stdout);
    int T;
    int u, v, val;
    char op[20];

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        init();
        for (int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &u, &v, &val);
            add(i, u, v, val);
        }
        dfs(0, 1, -1);
        rmq();
        for (int i = 1; i <= n; i++)
        {
            vst[i] = false;
        }
        dfs(1, 1);
        init(1, 0, top - 1);
        while (scanf("%s", op), op[0] != 'D')
        {
            scanf("%d%d", &u, &v);
            if (op[0] == 'Q')
            {
                printf("%d\n", query(u, v));
            }
            else
            {
                Edge *it = valid[u];
                if (it->solid)
                {
                    it->w = v;
                    update(1, 0, top - 1, pos[p[it->to]], v);
                }
                else
                {
                    it->w = v;
                }
            }
        }
    }

    return 0;
}