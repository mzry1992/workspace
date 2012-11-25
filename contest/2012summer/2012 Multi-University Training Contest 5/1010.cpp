#include <cstdio>
struct node
{
    node *l,*r;
    int sum,lazy;
} tree[1000000*4+1000000*20];
int N;
node *newnode()
{
    tree[N].sum=0;
    tree[N].l=tree[N].r=NULL;
    tree[N].lazy=-1;
    return &tree[N++];
}
node *newnode(node *x)
{
    tree[N].l=x->l;
    tree[N].r=x->r;
    tree[N].sum=x->sum;
    tree[N].lazy=x->lazy;
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
        x->sum=1;
    return x;
}
node *down(node *x,int l,int r)
{
    if (x->lazy==-1)
        return x;
    node *ret=newnode(x);
    if (l<r)
        ret->l->lazy=ret->r->lazy=ret->lazy;
    ret->sum=(r-l+1)*ret->lazy;
    ret->lazy=-1;
}
node *update(node *x,int l,int r,int s,int t,int v)
{
    node *nx=down(x,l,r);
    x=nx;
    if (s<=l && r<=t)
    {
        x->lazy=v;
        return down(x,l,r);
    }
    int mid=l+r>>1;
    node *nl,*nr,*ret=newnode(x);
    if (s<=mid)
        nl=update(x->l,l,mid,s,t,v);
    else
        nl=down(x->l,l,mid);
    if (t>mid)
        nr=update(x->r,mid+1,r,s,t,v);
    else
        nr=down(x->r,mid+1,r);
    ret->l=nl;
    ret->r=nr;
    ret->sum=ret->l->sum+ret->r->sum;
    return ret;
}
int query(node *x,int l,int r,int s,int t)
{
    node *nx=down(x,l,r);
    x=nx;
    if (s<=l && r<=t)
        return x->sum;
    int mid=l+r>>1;
    int ret=0;
    if (s<=mid)
        ret+=query(x->l,l,mid,s,t);
    if (t>mid)
        ret+=query(x->r,mid+1,r,s,t);
    return ret;
}
char s[10];
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        int n;
        N=0;
        scanf("%d",&n);
        node *root=build(0,n-1);
        int m;
        scanf("%d",&m);
        while (m--)
        {
            int s,t,v;
            scanf("%d%d%d",&s,&t,&v);
            root=update(root,0,n-1,s-1,t-1,v);
        }
    }
    return 0;
}
