#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct Matrix
{
    int a[52];
    Matrix operator * (const Matrix &b)const
    {
        Matrix res;
        for (int i = 0;i < 52;i++)
            res.a[i] = b.a[a[i]];
        return res;
    }
    Matrix operator ^ (int y)const
    {
        Matrix res, x;
        for (int i = 0; i < 52; i++)
            res.a[i] = i, x.a[i] = a[i];
        for (; y; y >>= 1, x = x * x)
            if (y & 1)
                res = res * x;
        return res;
    }
};

int card[52], index[52];
int n, l, r;
Matrix base;

int main()
{
    int totcas;
    scanf("%d", &totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        for (int i = 0; i < 52; i++)
            scanf("%d", &card[i]);
        scanf("%d%d%d", &n, &l, &r);
        l--;
        r--;
        int cnt = 0;
        for (int i = l; i <= r; i++)
            index[cnt++] = i;
        for (int i = 0; i < l; i++)
            index[cnt++] = i;
        for (int i = r + 1; i < 52; i++)
            index[cnt++] = i;
        for (int i = 0; i < 52; i++)
            base.a[i] = index[i];
        base = base ^ n;
        printf("Case #%d:", cas);
        for (int i = 0; i < 52; i++)
            printf(" %d", card[base.a[i]]);
        printf("\n");
    }
    return 0;
}
