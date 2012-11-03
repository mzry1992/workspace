#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Trie
{
    int next[100000][26], L;
    vector<int> end[100000];

    int newNode()
    {
        for (int i = 0; i < 26; i++)
            next[L][i] = -1;
        end[L].clear();
        return L++;
    }
    void init()
    {
        L = 0;
        newNode();
    }
    void insert(char buf[], int id)
    {
        int now = 0;
        for (int i = 0; buf[i]; i++)
        {
            if (next[now][buf[i] - 'a'] == -1)
                next[now][buf[i] - 'a'] = newNode();
            now = next[now][buf[i] - 'a'];
        }
        end[now].push_back(id);
    }
    void getdicrank(int dicrank[])
    {
        int tot = 0;
        queue<int> Q;
        Q.push(0);
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            if (end[now].size() > 0)
            {
                sort(end[now].begin(), end[now].end());
                for (int i = 0; i < end[now].size(); i++)
                    dicrank[end[now][i]] = tot++;
            }
            for (int i = 0; i < 26; i++)
                if (next[now][i] != -1)
                    Q.push(next[now][i]);
        }
    }
} dic;

const int maxn = 300010;
# define F(x) ((x)/3+((x)%3==1?0:tb))
# define G(x) ((x)<tb?(x)*3+1:((x)-tb)*3+2)
int wa[maxn * 3], wb[maxn * 3], wv[maxn * 3], ws[maxn * 3];
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
    for (int i = n; i < n * 3; i++)
        str[i] = 0;
    dc3 (str , sa , n + 1 , m);
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        sa[i] = sa[i + 1];
        rank[sa[i]] = i;
    }
    for (i = 0, j = 0, k = 0; i < n; height[rank[i ++]] = k)
        if (rank[i] > 0)
            for (k ? k-- : 0 , j = sa[rank[i] - 1]; i + k < n && j + k < n &&
                    str[i + k] == str[j + k]; k ++) ;
}

int n, m, l;
char buf[100010];
int dicrank[20000];
int s[maxn * 3], sa[maxn * 3], rank[maxn], height[maxn], id[maxn], len[maxn];

int lent[maxn];
int rmqh[maxn][20];
vector<int> rmqr[maxn][20];

void initlent()
{
    int k = 1, l = 0;
    for (int i = 0; i < maxn; i++)
    {
        if (i + 1 > k * 2)
        {
            k *= 2;
            l++;
        }
        lent[i + 1] = l;
    }
}

vector<int> merge(vector<int> a, vector<int> b)
{
    int pa = 0, pb = 0;
    vector<int> res;
    while (res.size() < 10 && (pa < a.size() || pb < b.size()))
    {
        if (pa == a.size())
            res.push_back(b[pb++]);
        else if (pb == b.size())
            res.push_back(a[pa++]);
        else if (dicrank[a[pa]] < dicrank[b[pb]])
            res.push_back(a[pa++]);
        else if (dicrank[a[pa]] > dicrank[b[pb]])
            res.push_back(b[pb++]);
        else
            res.push_back(a[pa++]), pb++;
    }
    return res;
}

void initrankrmq()
{
    for (int i = 0; i < l; i++)
    {
        rmqr[i][0].clear();
        if (id[sa[i]] >= 0 && id[sa[i]] < n)
            rmqr[i][0].push_back(id[sa[i]]);
    }
    for (int j = 1; (1 << j) - 1 < l; j++)
        for (int i = 0; i + (1 << j) - 1 < l; i++)
            rmqr[i][j] = merge(rmqr[i][j - 1], rmqr[i + (1 << (j - 1))][j - 1]);
}

vector<int> queryrankrmq(int l, int r)
{
    int k = lent[r - l + 1];
    return merge(rmqr[l][k], rmqr[r - (1 << k) + 1][k]);
}

void initheightrmq()
{
    for (int i = 0; i < l; i++)
        rmqh[i][0] = height[i];
    for (int j = 1; (1 << j) - 1 < l; j++)
        for (int i = 0; i + (1 << j) - 1 < l; i++)
            rmqh[i][j] = min(rmqh[i][j - 1], rmqh[i + (1 << (j - 1))][j - 1]);
}

int queryheightrmq(int l, int r)
{
    int k = lent[r - l + 1];
    return min(rmqh[l][k], rmqh[r - (1 << k) + 1][k]);
}

void add(char buf[], int bufid)
{
    len[l] = strlen(buf);
    for (int i = 0; buf[i]; i++)
    {
        id[l] = bufid;
        s[l++] = buf[i];
    }
    id[l] = -1;
    s[l++] = '$';
}

int pos[maxn];

int main(int argc, char const *argv[])
{
    freopen("data.in", "r", stdin);
    //freopen("data.out","w",stdout);
    scanf("%d", &n);
    dic.init();
    l = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", buf);
        dic.insert(buf, i);
        add(buf, i);
    }
    dic.getdicrank(dicrank);
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%s", buf);
        add(buf, n + i);
    }
    s[l] = 0;
    da(s, sa, rank, height, l, 128);
    initlent();
    initrankrmq();
    initheightrmq();
    for (int i = 0; i < l; i++)
        if (id[sa[i]] >= n && len[sa[i]] > 0)
            pos[id[sa[i]] - n] = i;
    for (int pi = 0; pi < m; pi++)
    {
        int i = pos[pi];
        int pl, pr, ml, mr, mid;
        ml = 0, mr = i - 1;
        while (ml < mr)
        {
            mid = (ml + mr) >> 1;
            if (queryheightrmq(mid + 1, i) < len[sa[i]])
                ml = mid + 1;
            else
                mr = mid;
        }
        if (queryheightrmq(ml + 1, i) < len[sa[i]])
            ml = i;
        pl = ml;

        ml = i + 1, mr = l - 1;
        while (ml < mr)
        {
            mid = (ml + mr + 1) >> 1;
            if (queryheightrmq(i + 1, mid) < len[sa[i]])
                mr = mid - 1;
            else
                ml = mid;
        }
        if (queryheightrmq(i + 1, ml) < len[sa[i]])
            ml = i;
        pr = ml;

        vector<int> res = queryrankrmq(pl, pr);
        if (res.size() == 0)
            puts("-1");
        else
        {
            printf("%d", res[0] + 1);
            for (int i = 1; i < res.size(); i++)
                printf(" %d", res[i] + 1);
            puts("");
        }

        // printf("%d %d %d %d\n", i, len[sa[i]], pl, pr);

        // for (int j = sa[i]; j < l; j++)
        //     putchar(s[j]);
        // puts("");
    }
    // for (int i = 0; i < l; i++)
    // {
    //     printf("%d height = %d id = %d: ", i, height[i], id[sa[i]]);
    //     for (int j = sa[i]; j < l; j++)
    //         putchar(s[j]);
    //     puts("");
    // }
    return 0;
}
