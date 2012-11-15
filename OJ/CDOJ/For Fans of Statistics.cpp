#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
struct elem
{
    int v,index;
}a[80000];
int d[30][80000];
int s[30][80000];

bool cmp(elem a,elem b)
{
    if (a.v == b.v)
        return a.index <= b.index;
    return a.v < b.v;
}

void build(int depth,int l,int r)
{
    if (l == r)
        return;
    int mid = (l+r)/2;
    int tl,tr;
    tl = tr = 0;
    for (int i = l;i <= r;i++)
    {
        if (cmp(a[d[depth][i]],a[mid]))
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

int find(int depth,int dl,int dr,int fl,int fr,int k)
{
    if (fl == fr)
        return a[d[depth][fl]].v;
    int ls,rs;
    int mid = (dl+dr)/2;
    ls = (fl == dl)?0:s[depth][fl-1];
    rs = s[depth][fr];
    return (rs-ls < k)?
        find(depth+1,mid+1,dr,mid+fl-dl-ls+1,mid+fr-dl-rs+1,k-(rs-ls)):
        find(depth+1,dl,mid,dl+ls,dl+rs-1,k);
}

int findkth(int l,int r,int k)
{
    return find(0,1,n,l,r,k);
}

int main()
{
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i].v);
        a[i].index = i;
    }
    sort(a+1,a+n+1,cmp);
    for (int i = 1;i <= n;i++)
        d[0][a[i].index] = i;
    build(0,1,n);
    scanf("%d",&m);
    int l,r,v,k;
    for (int i = 1;i <= m;i++)
    {
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",findkth(l,r,k));
    }
    return 0;
}
