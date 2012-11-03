#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
struct elem
{
    int v,index;
}a[120000];
int d[30][120000];
int s[30][120000];

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
    //cout << depth << ' ' << dl << ' ' << dr << ' ' << fl << ' ' << fr << ' ' << k << endl;
    if (fl == fr)
        return a[d[depth][fl]].v;
    int ls,rs;
    int mid = (dl+dr)/2;
    if (fl == dl)
        ls = 0;
    else
        ls = s[depth][fl-1];
    rs = s[depth][fr];
    if (rs-ls < k)
        return find(depth+1,mid+1,dr,mid+fl-ls,mid+fr-rs,k-(rs-ls));
    else
        return find(depth+1,dl,mid,dl+ls,dl+ls+k-1,k);
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i].v);
            a[i].index = i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i = 1;i <= n;i++)
            d[0][a[i].index] = i;
        build(0,1,n);
        /*for (int i = 0;i <= 10;i++)
        {
            cout << i << " : ";
            for (int j = 1;j <= n;j++)
                cout << a[d[i][j]].v << "  ";
            cout << endl;
            cout << i << " : ";
            for (int j = 1;j <= n;j++)
                cout << s[i][j] << "  ";
            cout << endl;
        }*/
        int l,r,k;
        for (int i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&l,&r,&k);
            printf("%d\n",find(0,1,n,l,r,k));
        }
    }
    return 0;
}

