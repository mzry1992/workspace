#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
using namespace std;

int n, dp[2][27][27][27][4], pre[51][27][27][27][4][4];
char a[100];
int tmp[3], b[4], tb[3];

int calc(int a, int b)
{
    if (a == 0) return b + 'a' - 1;
    return abs(a - b);
}

void update(int i, int j, int k, int q, int l, int pj, int pk, int pq, int pl, int val)
{
    if (dp[i % 2][j][k][q][l] > val)
    {
        dp[i % 2][j][k][q][l] = val;
        pre[i][j][k][q][l][0] = pj;
        pre[i][j][k][q][l][1] = pk;
        pre[i][j][k][q][l][2] = pq;
        pre[i][j][k][q][l][3] = pl;
    }
}

int cur;

void output(int i, int j, int k, int q, int l)
{
    if (i > 0)
        output(i - 1, pre[i][j][k][q][l][0], pre[i][j][k][q][l][1], pre[i][j][k][q][l][2], pre[i][j][k][q][l][3]);

    if (i == 0)
    {
        for (int fi = 0; fi < 4; fi++)
            b[fi] = 0;
        cur = l;
    }
    int move = l - cur;
    if (move < 0)
        for (int fi = 0; fi < -move; fi++)
            putchar('<');
    else
        for (int fi = 0; fi < move; fi++)
            putchar('>');
    cur = l;
    int add = a[i] - b[cur];
    if (add < 0)
        for (int fi = 0; fi < -add; fi++)
            putchar('-');
    else
        for (int fi = 0; fi < add; fi++)
            putchar('+');
    putchar('.');
    b[cur] += add;
}

int main(int argc, char const *argv[])
{
    while (scanf("%s", a) != EOF)
    {
        n = strlen(a);
        memset(dp[0], 63, sizeof(dp[0]));
        int fob = dp[0][0][0][0][0];
        for (int i = 0; i < 4; i++)
            dp[0][0][0][0][i] = (int)a[0];
        for (int i = 0; i < n - 1; i++)
        {
            memset(dp[(i + 1) % 2], 63, sizeof(dp[(i + 1) % 2]));
            for (tmp[0] = 0; tmp[0] < 27; tmp[0]++)
                for (tmp[1] = 0; tmp[1] < 27; tmp[1]++)
                    for (tmp[2] = 0; tmp[2] < 27; tmp[2]++)
                        for (int pos = 0; pos < 4; pos++)
                            if (dp[i % 2][tmp[0]][tmp[1]][tmp[2]][pos] != fob)
                            {
                                int tot = 0;
                                for (int j = 0; j < 4; j++)
                                {
                                    if (tot == pos)
                                        b[tot++] = a[i] - 'a' + 1;
                                    if (j < 3)
                                        b[tot++] = tmp[j];
                                }
                                for (int j = 0; j < 4; j++)
                                {
                                    int cost = abs(j - pos) + calc(b[j], a[i + 1] - 'a' + 1);
                                    tot = 0;
                                    for (int k = 0; k < 4; k++)
                                        if (j != k)
                                            tb[tot++] = b[k];
                                    update(i + 1, tb[0], tb[1], tb[2], j, tmp[0], tmp[1], tmp[2], pos, dp[i % 2][tmp[0]][tmp[1]][tmp[2]][pos] + cost);
                                }
                            }
        }
        int res = dp[(n - 1) % 2][0][0][0][0];
        int resi, resj, resk, resq;
        resi = resj = resk = resq = 0;
        for (int i = 0; i < 27; i++)
            for (int j = 0; j < 27; j++)
                for (int k = 0; k < 27; k++)
                    for (int q = 0; q < 4; q++)
                        if (res > dp[(n - 1) % 2][i][j][k][q])
                        {
                            res = dp[(n - 1) % 2][i][j][k][q];
                            resi = i, resj = j, resk = k, resq = q;
                        }
        output(n - 1, resi, resj, resk, resq);
        puts("");
    }
    return 0;
}