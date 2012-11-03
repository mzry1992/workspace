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
int d[35][120000];
int s[35][120000];

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
            d[depth+1][l+tl] = d[depth][i]; tl++;
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
    if (fl == dl)
        ls = 0;
    else
        ls = s[depth][fl-1];
    rs = s[depth][fr];
    if (rs-ls < k)
        return find(depth+1,mid+1,dr,mid+fl-dl-ls+1,mid+fr-dl-rs+1,k-(rs-ls));
    else
        return find(depth+1,dl,mid,dl+ls,dl+rs-1,k);
}

int rank(int val,int tl,int tr)
{
    int l,r,mid;
    l = tl;
    r = tr;
    while (l < r)
    {
        mid = (l+r)/2;
        if (find(0,1,n,tl,tr,mid) < val)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}

struct query
{
    int type;
    int a,b,c;
    int cur;
}q[40000];
int totq;
char query[20];
long long sum1,sum2,sum3;

int main()
{
    freopen("in.txt","r",stdin);
    int ft = 0;
    while (scanf("%d",&m) != EOF)
    {
        totq = 0;
        n = 0;
        for (int i = 1;i <= m;i++)
        {
            scanf("%s",&query);
            if (query[0] == 'I')
            {
                n++;
                scanf("%d",&a[n].v);
                a[n].index = n;
            }
            else if (query[6] == '1')
            {
                totq++;
                scanf("%d%d%d",&q[totq].a,&q[totq].b,&q[totq].c);
                q[totq].type = 1;
                q[totq].cur = n;
            }
            else if (query[6] == '2')
            {
                totq++;
                scanf("%d",&q[totq].a);
                q[totq].type = 2;
                q[totq].cur = n;
            }
            else
            {
                totq++;
                scanf("%d",&q[totq].a);
                q[totq].type = 3;
                q[totq].cur = n;
            }
        }
        sort(a+1,a+n+1,cmp);
        for (int i = 1;i <= n;i++)
            d[0][a[i].index] = i;
        build(0,1,n);
        sum1 = sum2 = sum3 = 0;
        for (int i = 1;i <= totq;i++)
        {
            if (q[i].type == 1)
                sum1 += find(0,1,n,q[i].a,q[i].b,q[i].c);
            else if (q[i].type == 2)
                sum2 += rank(q[i].a,1,q[i].cur);
            else if (q[i].type == 3)
                sum3 += find(0,1,n,1,q[i].cur,q[i].a);
        }
        ft++;
        printf("Case %d:\n%lld\n%lld\n%lld\n",ft,sum1,sum2,sum3);
        /*for (int i = 1;i <= totq;i++)
        {
            if (q[i].type == 1)
                printf("%d\n",find(0,1,n,q[i].a,q[i].b,q[i].c));
            else if (q[i].type == 2)
                printf("%d\n",rank(q[i].a,1,q[i].cur));
            else if (q[i].type == 3)
                printf("%d\n",find(0,1,n,1,q[i].cur,q[i].a));
        }*/
    }
    return 0;
}
