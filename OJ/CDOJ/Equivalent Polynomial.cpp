#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct poly
{
    long long a[500];
    int len;
}pa,pb;
int n,t;

poly add(poly a,poly b)
{
    int la = a.len;
    int lb = b.len;
    poly res;
    memset(res.a,0,sizeof(res.a));
    res.len = max(la,lb);
    for (int i = 0;i <= res.len;i++)
        res.a[i] = a.a[i]+b.a[i];
    return res;
}

poly mult(poly a,poly b)
{
    int la = a.len;
    int lb = b.len;
    poly res;
    res.len = la+lb;
    memset(res.a,0,sizeof(res.a));
    for (int i = 0;i <= la;i++)
    for (int j = 0;j <= lb;j++)
        res.a[i+j] += a.a[i]*b.a[j];
    return res;
}

poly cons(int val)
{
    poly res;
    memset(res.a,0,sizeof(res.a));
    res.len = 0;
    res.a[0] = val;
    return res;
}

int main()
{
    while (scanf("%d%d",&n,&t) != EOF)
    {
        memset(pa.a,0,sizeof(pa.a));
        for (int i = 0;i <= n;i++)
            scanf("%d",&pa.a[i]);
        pa.len = n;
        poly xt;
        memset(xt.a,0,sizeof(xt.a));
        xt.len = 1;
        xt.a[0] = t;
        xt.a[1] = 1;
        poly xk;
        memset(xk.a,0,sizeof(xk.a));
        xk.len = 0;
        xk.a[0] = 1;
        memset(pb.a,0,sizeof(pb.a));
        pb.len = 0;
        for (int i = 0;i <= n;i++)
        {
            if (pa.a[i] != 0)
                pb = add(pb,mult(xk,cons(pa.a[i])));
            xk = mult(xk,xt);
        }
        for (int i = 0;i < n;i++)
            printf("%I64d ",pb.a[i]);
        printf("%I64d\n",pb.a[n]);
    }
}
