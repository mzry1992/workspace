#include <cstdio>
struct ele
{
    int s[5];
}tree[80000*4];
int a[80000];
int p;
ele up(ele a,ele b)
{
    ele ret;
    for (int i=0;i<5;i++)
        ret.s[i]=0;
    for (int i=0;i<5;i++)
        for (int j=0;j+i<5;j++)
        {
            ret.s[i+j]+=(long long)a.s[i]*b.s[j]%p;
            if (ret.s[i+j]>=p)
                ret.s[i+j]-=p;
        }
    return ret;
}
void build(int x,int l,int r)
{
    if (l<r)
    {
        int mid=l+r>>1;
        build(x*2,l,mid);
        build(x*2+1,mid+1,r);
        tree[x]=up(tree[x*2],tree[x*2+1]);
    }
    else
    {
        for (int i=2;i<5;i++)
            tree[x].s[i]=0;
        tree[x].s[0]=1;
        tree[x].s[1]=a[l]%p;
    }
}
ele query(int x,int l,int r,int s,int t)
{
    //printf("%d %d %d\n",x,l,r);
    if (s<=l && r<=t)
        return tree[x];
    int mid=l+r>>1;
    if (s<=mid && t>mid)
        return up(query(x*2,l,mid,s,t),query(x*2+1,mid+1,r,s,t));
    else if (t>mid)
        return query(x*2+1,mid+1,r,s,t);
    else if (s<=mid)
        return query(x*2,l,mid,s,t);
}
void update(int x,int l,int r,int pos,int v)
{
    if (l==r)
    {
        tree[x].s[1]+=v;
        tree[x].s[1]=(tree[x].s[1]%p+p)%p;
        return ;
    }
    int mid=l+r>>1;
    if (pos<=mid)
        update(x*2,l,mid,pos,v);
    else
        update(x*2+1,mid+1,r,pos,v);
    tree[x]=up(tree[x*2],tree[x*2+1]);
}
int main()
{
    int n,m;
    scanf("%d%d%d",&n,&m,&p);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    build(1,0,n-1);
    while (m--)
    {
        char c;
        scanf(" %c",&c);
        if (c=='C')
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            ele ret=query(1,0,n-1,l-1,r-1);
            putchar('1');
            for (int i=1;i<=k;i++)
                printf(" %d",ret.s[i]);
            puts("");
        }
        else
        {
            int p,v;
            scanf("%d%d",&p,&v);
            update(1,0,n-1,p-1,v);
        }
    }
    return 0;
}
