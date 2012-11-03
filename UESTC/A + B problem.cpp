#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,tn;
long long a[16];
int len[16][16];
long long val[16][16];

void Gao(int x, int y)
{
    long long tmpa,tmpb;
    tmpa = a[x];
    tmpb = a[y];
    int lena,lenb;
    lena = tmpa.bitLength();
    lenb = tmpb.bitLength();
    for (int i = 1;i < lenb;i++)
    {
        long long tb = tmpb>>i;
        long long ta = tmpa;
        for (int j = lenb-i;j < lena;j++)
            ta = ta.clearBit(j);
        if (tb.compareTo(ta) == 0)
        {
            len[x][y] = i;
            tb = tmpb;
            for (int j = i;j < lenb;j++)
                tb = tb.clearBit(j);
            val[x][y] = tb;
            return;
        }
    }
    len[x][y] = lenb;
    val[x][y] = tmpb;
}

bool ainb(long long a, long long b)
{
    for (int i = 0;i <= b.bitLength()-a.bitLength();i++)
    {
        BigInteger tmpb = b.shiftRight(b.bitLength()-a.bitLength()-i);
        for (int j = a.bitLength();j < tmpb.bitLength();j++)
            tmpb = tmpb.clearBit(j);
        if (tmpb.compareTo(a) == 0)	return true;
    }
    return false;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        n = tn;
        for (int i = 0;i < tn;i++)
            scanf("%lld",&a[i]);
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                if (ainb(a[j],a[i]) == true)
                {
                    swap(a[j],a[n-1]);
                    n--;
                }
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (i != j)
                    Gao(i,j);
    }
}
