#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int a[10];
long long res1,res2;

void Gao(int now,int used,int na,int nb)
{
    if (now == n)
    {
        res2++;
        return;
    }
    int ta,tb;
    for (int i = 0;i < n;i++)
        if (((used>>i)&1) != 1)
        {
            ta = na-(1<<i);
            tb = nb;
            if (ta >= tb)
                Gao(now+1,used|(1<<i),ta,tb);
            ta = na;
            tb = nb-(1<<i);
            if (ta >= tb)
                Gao(now+1,used|(1<<i),ta,tb);
        }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            a[i] = i;
        res1 = res2 = 0;
        Gao(0,0,1<<n,1<<n);
        res1 = 1;
        for (int i = 1;i <= n;i++)
            res1 = res1*2*i;
        cout << res1 << ' ' << res2 << endl;
    }
    return 0;
}
