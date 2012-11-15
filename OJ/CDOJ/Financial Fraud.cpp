#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct elem
{
    int v,index;
}b[50001];
int d[30][50001];
int s[30][50001];
int a[50001];
int n;

bool cmp(elem a,elem b)
{
    if (a.v == b.v)
        return a.index <= b.index;
    return a.v < b.v;
}

void build(int depth,int l,int r)
{
    if (l == r) return;
    int mid = (l+r)>>1;
    int tl,tr;
    tl = tr = 0;
    for (int i = l;i <= r;i++)
    {
        if (cmp(b[d[depth][i]],b[mid]))
        {
            d[depth+1][l+tl] = d[depth][i];
            tl++;
        }
        else
        {
            d[depth+1][mid+1+tr] = d[depth][i];
            tr++;
        }
        s[depth][i] = tl;
    }
    build(depth+1,l,mid);
    build(depth+1,mid+1,r);
}

int _find(int depth,int dl,int dr,int fl,int fr,int k)
{
    if (fl == fr)   return b[d[depth][fl]].v;
    int ls,rs;
    int mid = (dl+dr)>>1;
    ls = (fl == dl)?0:s[depth][fl-1];
    rs = s[depth][fr];
    return (rs-ls < k)?
        _find(depth+1,mid+1,dr,mid+fl-dl-ls+1,mid+fr-dl-rs+1,k-(rs-ls)):
        _find(depth+1,dl,mid,dl+ls,dl+rs-1,k);
}

int find(int l,int r,int k)
{
    return _find(0,1,n,l,r,k);
}

int rank(int l,int r,int v)
{

}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i]);
            b[i].v = a[i];
            b[i].index = i;
        }
        sort(b+1,b+n+1,cmp);
        for (int i = 1;i <= n;i++)
            d[0][b[i].index] = i;
        build(0,1,n);
    }
    return 0;
}
