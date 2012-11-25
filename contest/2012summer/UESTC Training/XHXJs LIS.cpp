#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define nu (((u) == 1) && ((i) == ed))
#define nd (((d) == 1) && ((i) == op))
#define nss (((ss) == 1) && ((i) == 0))

char a[21], b[21];
long long na, nb, dp[21][2][2][1 << 10][2];
bool flag[21][2][2][1 << 10][2];
int k;

long long DP(int pos, int u, int d, int msk,int ss)
{
    if (flag[pos][u][d][msk][ss])
        return dp[pos][u][d][msk][ss];
    long long &res = dp[pos][u][d][msk][ss];
    res = 0;
    int newmsk;
    if (pos == 20)
    {
        int cntbit = 0;
        for (int i = 0; i < 10; i++)
            if (((msk >> i) & 1) == 1)
                cntbit++;
        if (cntbit == k)
            res = 1;
        else
            res = 0;
    }
    else
    {
        int op = 0, ed = 9;
        if (d)
            op = a[pos] - '0';
        if (u)
            ed = b[pos] - '0';
        for (int i = op; i <= ed; i++)
        {
            if (((msk >> i) & 1) == 1 || ((ss == 1) && i == 0))
                res += DP(pos + 1, nu, nd, msk,nss);
            else
            {
                newmsk = msk | (1 << i);
                for (int j = i + 1; j < 10; j++)
                    if (((newmsk >> j) & 1) == 1)
                    {
                        newmsk ^= (1 << j);
                        break;
                    }
                res += DP(pos + 1, nu, nd, newmsk,nss);
            }
        }
    }
    flag[pos][u][d][msk][ss] = true;
    return res;
}

int main()
{
    freopen("data.in", "r", stdin);
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%lld%lld%d", &na, &nb, &k);
        sprintf(a, "%020lld", na);
        sprintf(b, "%020lld", nb);
        memset(flag, false, sizeof(flag));
        printf("Case #%d: %lld\n", cas, DP(0, 1, 1, 0,1));
    }
    return 0;
}
