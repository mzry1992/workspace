#include "iostream"
#include "cstdio"
#include "algorithm"
#include "cstring"
#include "vector"
using namespace std;

const int mod = 1000000007;
int n, a[2000], c[2000], pre[2001], bx[2001], bci[2001];
int num[2000],nci[2000];
int tmp[2001];

void sort(int a[],int l)
{
    for (int i = 1;i <= n;i++)
        tmp[i] = 0;
    for (int i = 0;i < l;i++)
        tmp[a[i]]++;
    int tl = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 0;j < tmp[i];j++)
            a[tl++] = i;
}

pair<int, int> DP(int pos)
{
    if (pos == n - 1)
        return make_pair(0, 0);
    int res = 0, cnt = 0;
    int sa = 0;
    for (int ci = pos; ci < n; ci++)
    {
    	num[ci-pos] = a[ci];
    	nci[ci-pos] = c[ci];
    }
    int l = n-pos;
    sort(num,l);
    sort(nci,l);

    for (int i = 0, j = 0; i < l; i++)
    {
        while (j < l && num[i] >= nci[j])    j++;
        sa += j;
        bx[num[i]] = j;
    }
    sa = ((long long)sa * pre[n - pos - 2]) % mod;
    int ts = 0;
    for (int j = 0; j < l; j++)
        if (num[j] >= c[pos])
            ts++;
    for (int i = pos + 1; i < n; i++)
        if (a[i] > a[pos])
        {
            int xi = a[i], s = ts;
            s += bx[xi];
            s -= (xi >= c[pos]);
            s = ((sa - (long long)s * pre[n - pos - 2] % mod) % mod + mod) % mod;
            res = ((res + s) % mod + (xi >= c[pos]) * pre[n - pos - 1]) % mod;
            cnt = (cnt + pre[n - pos - 1]) % mod;
        }

    pair<int, int> tmp = DP(pos + 1);
    res = ((res + tmp.first) % mod + (a[pos] >= c[pos]) * tmp.second) % mod;
    cnt = (cnt + tmp.second) % mod;

    return make_pair(res, cnt);
}

int main(int argc, char const *argv[])
{
    //freopen("data.in", "r", stdin);
    //freopen("data2.out","w",stdout);
    pre[0] = 1;
    for (int i = 1; i < 2001; ++i)
        pre[i] = (long long)pre[i - 1] * i % mod;
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 1; cas <= totcas; ++cas)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &c[i]);
        printf("Case #%d: %d\n", cas, DP(0).first);
    }
    return 0;
}
