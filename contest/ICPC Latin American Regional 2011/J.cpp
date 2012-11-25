#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int b,mod,a[100001],n,q,tree[100001],l,r,bj[100000],inv[100000];
char com;

int read(int k)
{
    int sum = 0;
    for (; k; k^=k&-k)
        sum = (sum+tree[k])%mod;
    return sum;
}

void update(int k,int v)
{
    for (; k <= n; k += k&-k)
        tree[k] = (tree[k]+v)%mod;
}

int power(int x,int y)
{
    long long ret=1;
    for (long long a=x%mod; y; y>>=1,a=a*a%mod)
        if (y&1)
            ret=ret*a%mod;
    return ret;
}

int getInv(int x)//mod 为素数
{
    return power(x,mod-2);
}

int read(int l,int r)
{
    long long ret = (read(r)-read(l-1)+mod)%mod;
    ret = ret*inv[n-r]%mod;
    return ret;
}

int main()
{
    while (true)
    {
        scanf("%d%d%d%d",&b,&mod,&n,&q);
        bj[0] = 1;
        for (int i = 1;i < n;i++)
            bj[i] = (long long)bj[i-1]*b%mod;
        for (int i = 0;i < n;i++)
            inv[i] = getInv(bj[i]);
        if (b == 0 && mod == 0 && n == 0 && q == 0) break;
        for (int i = 0; i <= n; i++)
            a[i] = tree[i] = 0;
        for (int i = 0; i < q; i++)
        {
            scanf(" %c%d%d",&com,&l,&r);
            if (com == 'E')
            {
                int now = read(l,l);
                update(l,(long long)((r-now+mod)%mod)*bj[n-l]%mod);
            }
            else
                printf("%d\n",read(l,r));
        }
        printf("-\n");
    }
    return 0;
}
