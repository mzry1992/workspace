#include <cstdio>
#include <cstring>
const int MAXL = 300000;
const int MAXN = 20000;
int sa[(MAXL + MAXN)*3], s[(MAXL + MAXN)*3], lent[MAXL + MAXN], height[MAXL + MAXN], rank[MAXL + MAXN];
int totlen;
int tree[MAXL + MAXN << 2], lazy[MAXL + MAXN << 2];
#define F(x) ((x)/3+((x)%3==1?0:tb))
#define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[MAXL + MAXN], wb[MAXL + MAXN], wv[MAXL + MAXN], ws[MAXL + MAXN];
int c0(int *r, int a, int b)
{
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}
int c12(int k, int *r, int a, int b)
{
    if (k == 2) return r[a] < r[b] || r[a] == r[b] && c12(1, r, a + 1, b + 1);
    else return r[a] < r[b] || r[a] == r[b] && wv[a + 1] < wv[b + 1];
}
void sort(int *r, int *a, int *b, int n, int m)
{
    int i;
    for (i = 0; i < n; i++) wv[i] = r[a[i]];
    for (i = 0; i < m; i++) ws[i] = 0;
    for (i = 0; i < n; i++) ws[wv[i]]++;
    for (i = 1; i < m; i++) ws[i] += ws[i - 1];
    for (i = n - 1; i >= 0; i--) b[--ws[wv[i]]] = a[i];
    return;
}
void dc3(int *r, int *sa, int n, int m)
{
    int i, j, *rn = r + n, *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for (i = 0; i < n; i++) if (i % 3 != 0) wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc) dc3(rn, san, tbc, p);
    else for (i = 0; i < tbc; i++) san[rn[i]] = i;
    for (i = 0; i < tbc; i++) if (san[i] < tb) wb[ta++] = san[i] * 3;
    if (n % 3 == 1) wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);
    for (i = 0; i < tbc; i++) wv[wb[i] = G(san[i])] = i;
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for (; i < ta; p++) sa[p] = wa[i++];
    for (; j < tbc; p++) sa[p] = wb[j++];
}

void da(int str[], int sa[], int rank[], int height[], int n, int m)
{
    dc3 (str , sa , n , m);
    int i, j, k;
    for (i = 0; i < n; i++)
        rank [sa[i]] = i;
    for (i = 0, j = 0, k = 0; i < n; height [ rank [i ++]] = k)
        if (rank [i] > 0)
            for (k ? k -- : 0 , j = sa[ rank [i] - 1]; i + k < n && j + k < n &&
                    str [i + k] == str [j + k]; k ++) ;
}
void up(int x)
{
    if (tree[x*2]>tree[x*2+1])
        tree[x]=tree[x*2];
    else
        tree[x]=tree[x*2+1];
}
void down(int x, int l, int r)
{
    if (tree[x]<lazy[x])
        tree[x]=lazy[x];
    if (l < r)
    {
        if (lazy[x*2]<lazy[x])
            lazy[x*2]=lazy[x];
        if (lazy[x*2+1]<lazy[x])
            lazy[x*2+1]=lazy[x];
    }
}
int query(int x, int l, int r, int p)
{
    down(x, l, r);
    if (l == r)
        return tree[x];
    int mid = l + r >> 1;
    if (p <= mid)
        return query(x * 2, l, mid, p);
    else
        return query(x * 2 + 1, mid + 1, r, p);
}
void update(int x, int l, int r, int s, int t, int v)
{
    down(x, l, r);
    if (s <= l && r <= t)
    {
        if (lazy[x]<v)
            lazy[x]=v;
        down(x, l, r);
        return ;
    }
    int mid = l + r >> 1;
    if (s <= mid)
        update(x * 2, l, mid, s, t, v);
    else
        down(x * 2, l, mid);
    if (t > mid)
        update(x * 2 + 1, mid + 1, r, s, t, v);
    else
        down(x * 2 + 1, mid + 1, r);
    up(x);
}
int len[MAXN], st[MAXN], val[MAXN];
int f[MAXL + MAXN << 2];
int belong[MAXL + MAXN];
void build(int x, int l, int r)
{
    if (l < r)
    {
        int mid = l + r >> 1;
        build(x * 2, l, mid);
        build(x * 2 + 1, mid + 1, r);
        if (f[x*2]>f[x*2+1])
            f[x]=f[x*2+1];
        else
            f[x]=f[x*2];
    }
    else
        f[x] = height[l];
}
int query(int x, int l, int r, int s, int t)
{
    /*while (t<l || s>r)
        printf("%d %d %d %d\n",l,r,s,t);
    if (flag)
        printf("%d %d %d %d\n",l,r,s,t);*/
    if (s <= l && r <= t)
        return f[x];
    int mid = l + r >> 1, ret = totlen;
    if (s <= mid)
        ret = query(x * 2, l, mid, s, t);
    if (t > mid)
    {
        int tmp=query(x*2+1,mid+1,r,s,t);
        if (tmp<ret)
            ret=tmp;
    }
    return ret;
}
int lcp(int l, int r)
{
    if (l == r)
        return len[belong[l]] - l + st[belong[l]];
    return query(1, 0, totlen - 1, l + 1, r);
}
struct Inv
{
    int l,r;
};
Inv getInv(int idx, int len)
{
    Inv ret;
    int l = 0, r = idx;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (lcp(mid, idx) >= len)
            r = mid;
        else
            l = mid + 1;
    }
    ret.l = l;
    l = idx;
    r = totlen - 1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (lcp(idx, mid) >= len)
            l = mid;
        else
            r = mid - 1;
    }
    ret.r = l;
    return ret;
}
char t[MAXL+1];
int main(int argc, char const *argv[])
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        int n;
        scanf("%d", &n);
        totlen = 0;
        for (int i = 0; i < n; i++)
        {
            st[i] = totlen;
            scanf("%s%d", t, &val[i]);
            len[i] = strlen(t);
            for (int j = 0; j < len[i]; j++)
            {
                s[totlen + j] = t[j];
                belong[totlen + j] = i;
            }
            s[totlen + len[i]] = '$';
            totlen += len[i] + 1;
        }
        //suffix array
        da(s, sa, rank, height, totlen, 255);
        if (cas == 47)
        {
            for (int i=0;i<totlen;i++)
            {
                printf("%2d: ",i);
                for (int j=sa[i];j<totlen;j++)
                    putchar(s[j]);
                puts("");
            }
            break;
        }
        build(1, 0, totlen - 1);
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = i;
            int lis = 0;
            for (int j = st[x]; j < st[x] + len[x] && j<totlen; j++)
            {
                int ret=query(1, 0, totlen - 1, rank[j]);
                if (ret>lis)
                    lis=ret;
            }
            lis += val[x];
            if (lis>ans)
                ans=lis;
            Inv inv = getInv(rank[st[x]], len[x]);
            update(1, 0, totlen - 1, inv.l, inv.r, lis);
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
