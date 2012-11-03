#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN=100000,MAXM=100000;

struct node
{
    node *l,*r;
    int sum;
}tree[MAXN*4+MAXM*20];

int N;
node *newnode()
{
    tree[N].l=tree[N].r=NULL;
    tree[N].sum=0;
    return &tree[N++];
}
node *newnode(node *x)
{
    tree[N].l=x->l;
    tree[N].r=x->r;
    tree[N].sum=x->sum;
    return &tree[N++];
}
node *build(int l,int r)
{
    node *x=newnode();
    if (l<r)
    {
        int mid=l+r>>1;
        x->l=build(l,mid);
        x->r=build(mid+1,r);
        x->sum=x->l->sum+x->r->sum;
    }
    else
        x->sum=0;
    return x;
}
node *update(node *x,int l,int r,int p,int v)
{
    if (l<r)
    {
        int mid=l+r>>1;
        node *nx=newnode(x);
        if (p<=mid)
        {
            node *ret=update(x->l,l,mid,p,v);
            nx->l=ret;
        }
        else
        {
            node *ret=update(x->r,mid+1,r,p,v);
            nx->r=ret;
        }
        nx->sum=nx->l->sum+nx->r->sum;
        return nx;
    }
    else
    {
        node *nx=newnode(x);
        nx->sum+=v;
        return nx;
    }
}
int query(node *x1,node *x2,int l,int r,int k)
{
    if (l<r)
    {
        int mid=l+r>>1;
        int lsum=x2->l->sum-x1->l->sum;
        if (lsum>=k)
            return query(x1->l,x2->l,l,mid,k);
        else
            return query(x1->r,x2->r,mid+1,r,k-lsum);
    }
    else
        return l;
}
char s[10];
node *root[MAXM+1];
int a[MAXN],b[MAXN];
int init(int n)
{
    for (int i=0;i<n;i++)
        b[i]=a[i];
    sort(b,b+n);
    int tn=unique(b,b+n)-b;
    for (int i=0;i<n;i++)
    {
        int l=0,r=tn-1;
        while (l<r)
        {
            int mid=l+r>>1;
            if (b[mid]>=a[i])
                r=mid;
            else
                l=mid+1;
        }
        a[i]=l;
    }
    return tn;
}
int main()
{
    int cas=1,n;
    while (scanf("%d",&n)!=EOF)
    {
        printf("Case %d:\n",cas++);
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int tn=init(n);
        N=0;
        root[0]=build(0,tn-1);
        for (int i=1;i<=n;i++)
            root[i]=update(root[i-1],0,tn-1,a[i-1],1);
        int m;
        scanf("%d",&m);
        for (int i=0;i<m;i++)
        {
            int s,t;
            scanf("%d%d",&s,&t);
            printf("%d\n",b[query(root[s-1],root[t],0,tn-1,t-s+2>>1)]);
        }
    }
    return 0;
}
