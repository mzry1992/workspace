#include <iostream>
#include <cstdio>
#define MAXN 30000
#define _cp(a,b) ((a) < (b))
using namespace std;

typedef int elem_t;

struct heap
{
    elem_t h[MAXN];
    int n,p,c;
    void init(){n = 0;}
    void ins(elem_t e)
    {
        for (p = ++n;p > 1 && _cp(e,h[p>>1]);h[p] = h[p>>1],p>>=1);
        h[p] = e;
    }
    int del(elem_t &e)
    {
        if (!n) return 0;
        for (e = h[p=1],c = 2;c < n && _cp(h[c += (c < n-1 && _cp(h[c+1],h[c]))],h[n]);h[p] = h[c],p = c,c <<= 1);
        h[p] = h[n--];
        return 1;
    }
}Q;

int main()
{
    int n;
    scanf("%d",&n);
    Q.init();
    for (int i = 1;i <= n;i++)
    {
        int temp;
        scanf("%d",&temp);
        Q.ins(temp);
    }
    int res = 0;
    for (int i = 1;i <= n-1;i++)
    {
        int a,b;
        Q.del(a);
        Q.del(b);
        res += a+b;
        Q.ins(a+b);
    }
    printf("%d\n",res);
}
