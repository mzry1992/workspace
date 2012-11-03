#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node
{
    int l,r;
    bool odd;
}q[6000];
int ls[12000];
int f[12000];
bool d[12000];
int len,totq;
char typ[10];

int findf(int x)
{
    if (f[x] != x)
    {
        int newf = findf(f[x]);
        d[x] = d[x]^d[f[x]];
        f[x] = newf;
    }
    return f[x];
}

int main()
{
    scanf("%d%d",&len,&totq);
    for (int i = 1;i <= totq;i++)
    {
        scanf("%d%d%s",&q[i].l,&q[i].r,typ);
        if (strcmp(typ,"odd") == 0) q[i].odd = true;
        else q[i].odd = false;
        ls[i*2-1] = q[i].l;
        ls[i*2] = q[i].r;
    }
    sort(ls+1,ls+totq*2+1);
    ls[0] = ls[1]-1;
    int ttot = 0;
    for (int i = 1;i <= totq*2;i++)
    if (ls[i] != ls[i-1])
    {
        ttot++;
        ls[ttot] = ls[i];
    }
    for (int i = 1;i <= totq;i++)
    {
        int *pos = lower_bound(ls+1,ls+ttot+1,q[i].l);
        q[i].l = (int)(pos-ls);
        pos = lower_bound(ls+1,ls+ttot+1,q[i].r);
        q[i].r = (int)(pos-ls);
    }
    for (int i = 1;i <= ttot+1;i++)
        f[i] = i;
    for (int i = 1;i <= totq+1;i++)
    {
        if (i == totq+1)
        {
            printf("%d\n",i-1);
            break;
        }
        int fx = findf(q[i].l);
        int fy = findf(q[i].r+1);
        if (fx != fy)
        {
            f[fy] = fx;
            d[fy] = d[q[i].l]^d[q[i].r+1]^q[i].odd;
        }
        else
        {
            if (d[q[i].l]^d[q[i].r+1] != q[i].odd)
            {
                printf("%d\n",i-1);
                break;
            }
        }
    }
}
