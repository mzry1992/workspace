#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<set>
#define int_max 0x7fffffff
#define ll_max 0x7fffffffffffffffLL
#define fr first
#define se second
typedef long long ll;
typedef unsigned long long llu;
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
char s[55];
int a[55];
int dp[51][4][27][27][27], pre[51][4][27][27][27];
int Nxt[51];
int l;
int dfs(int n, int po, int x, int y, int z, int w)
{
    if (n == l)return 0;
    int u, d, k;
    if (po == 0)u = y - 'a' + 1, d = z - 'a' + 1, k = w - 'a' + 1;
    if (po == 1)u = x - 'a' + 1, d = z - 'a' + 1, k = w - 'a' + 1;
    if (po == 2)u = x - 'a' + 1, d = y - 'a' + 1, k = w - 'a' + 1;
    if (po == 3)u = x - 'a' + 1, d = y - 'a' + 1, k = z - 'a' + 1;
    u = max(u, 0);
    d = max(d, 0);
    k = max(k, 0);
    int &ans = dp[n][po][u][d][k], tmp, &pr = pre[n][po][u][d][k];
    if (ans != -1)return ans;
    ans = int_max;
    tmp = dfs(n + 1, 0, a[n + 1], y, z, w) + abs(po - 0) + abs(a[n + 1] - x);
    if (tmp < ans)ans = tmp, pr = 0;
    tmp = dfs(n + 1, 1, x, a[n + 1], z, w) + abs(po - 1) + abs(a[n + 1] - y);
    if (tmp < ans)ans = tmp, pr = 1;
    tmp = dfs(n + 1, 2, x, y, a[n + 1], w) + abs(po - 2) + abs(a[n + 1] - z);
    if (tmp < ans)ans = tmp, pr = 2;
    tmp = dfs(n + 1, 3, x, y, z, a[n + 1]) + abs(po - 3) + abs(a[n + 1] - w);
    if (tmp < ans)ans = tmp, pr = 3;
    return ans;
}
int pool[4];
int main()
{
    freopen("A.in", "r", stdin);
    freopen("A2.out","w",stdout);
    //freopen("C:\\Users\\pyxf\\Desktop\\out1.txt", "w", stdout);
    while (scanf("%s", s) != EOF)
    {
        l = strlen(s);
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < l; i++)a[i + 1] = s[i];
        a[0] = 0;


        int st = 0;
        if (dfs(0, 0, 0, 0, 0, 0) > dfs(0, 1, 0, 0, 0, 0))
            st = 1;
        printf("%d\n", min(dfs(0, 0, 0, 0, 0, 0), dfs(0, 1, 0, 0, 0, 0)));
        /*int u, d, k;
        for (int i = 0; i < l; i++)
        {
            //printf("%d\n",Nxt[i]);
            if (st == 0)u = pool[1] - 'a' + 1, d = pool[2] - 'a' + 1, k = pool[3] - 'a' + 1;
            if (st == 1)u = pool[0] - 'a' + 1, d = pool[2] - 'a' + 1, k = pool[3] - 'a' + 1;
            if (st == 2)u = pool[0] - 'a' + 1, d = pool[1] - 'a' + 1, k = pool[3] - 'a' + 1;
            if (st == 3)u = pool[0] - 'a' + 1, d = pool[1] - 'a' + 1, k = pool[2] - 'a' + 1;
            u = max(u, 0);
            d = max(d, 0);
            k = max(k, 0);
            int pr = pre[i][st][u][d][k];
            //printf("%d %d\n",pool[pr],a[i+1]);
            if (pr == st)
            {
                if (pool[pr] <= a[i + 1])
                {
                    for (int j = pool[pr]; j < a[i + 1]; j++)
                        putchar('+');
                    putchar('.');
                    pool[pr] = a[i + 1];
                }
                else if (pool[pr] > a[i + 1])
                {
                    for (int j = pool[pr]; j > a[i + 1]; j--)
                        putchar('-');
                    putchar('.');
                    pool[pr] = a[i + 1];
                }
            }
            else if (pr > st)
            {
                for (int j = st; j < pr; j++)
                    putchar('>');
                if (pool[pr] <= a[i + 1])
                {
                    for (int j = pool[pr]; j < a[i + 1]; j++)
                        putchar('+');
                    putchar('.');
                    pool[pr] = a[i + 1];
                }
                else if (pool[pr] > a[i + 1])
                {
                    for (int j = pool[pr]; j > a[i + 1]; j--)
                        putchar('-');
                    putchar('.');
                    pool[pr] = a[i + 1];
                }
            }
            else
            {
                for (int j = st; j > pr; j--)
                    putchar('<');
                if (pool[pr] <= a[i + 1])
                {
                    for (int j = pool[pr]; j < a[i + 1]; j++)
                        putchar('+');
                    putchar('.');
                    pool[pr] = a[i + 1];
                }
                else if (pool[pr] > a[i + 1])
                {
                    for (int j = pool[pr]; j > a[i + 1]; j--)
                        putchar('-');
                    putchar('.');
                    pool[pr] = a[i + 1];
                }

            }
            st = pr;
        }
        puts("");*/
    }
    return 0;
}