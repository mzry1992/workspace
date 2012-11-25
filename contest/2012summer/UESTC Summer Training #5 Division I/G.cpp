#include<cstdio>
#include<algorithm>
using namespace std;
const long long inf=0x7fffffffffffffffLL;
struct trees
{
    long long sum,sum2,add,min,max,over;
}tree[4000000];
long long a[1000000];
void up(int x)
{
    tree[x].max=max(tree[x*2].max,tree[x*2+1].max);
    tree[x].min=min(tree[x*2].min,tree[x*2+1].min);
    tree[x].sum=tree[x*2].sum+tree[x*2+1].sum;
    tree[x].sum2=tree[x*2].sum2+tree[x*2+1].sum2;
}
void build(int x,int l,int r)
{
    tree[x].add=0;
    tree[x].over=1001;
    if (l==r)
    {
        tree[x].sum=tree[x].max=tree[x].min=a[l];
        tree[x].sum2=a[l]*a[l];
    }
    else
    {
        int mid=l+r>>1;
        build(x*2,l,mid);
        build(x*2+1,mid+1,r);
        up(x);
    }
}
void down(int x,int l,int r)
{
    if (tree[x].over<1001)
    {
        tree[x].over+=tree[x].add;
        tree[x].add=tree[x*2].add=tree[x*2+1].add=0;
        tree[x*2].over=tree[x*2+1].over=tree[x].max=tree[x].min=tree[x].over;
        tree[x].sum=tree[x].over*(r-l+1);
        tree[x].sum2=tree[x].over*tree[x].over*(r-l+1);
        tree[x].over=1001;
    }
    else
    {
        tree[x].max+=tree[x].add;
        tree[x].min+=tree[x].add;
        tree[x*2].add+=tree[x].add;
        tree[x*2+1].add+=tree[x].add;
        tree[x].sum2+=2*tree[x].sum*tree[x].add+tree[x].add*tree[x].add*(r-l+1);
        tree[x].sum+=tree[x].add*(r-l+1);
        tree[x].add=0;
    }
}
long long querymax(int x,int l,int r,int s,int t)
{
    down(x,l,r);
    if (s<=l && r<=t)
        return tree[x].max;
    int mid=l+r>>1;
    long long ret=-inf;
    if (s<=mid)
        ret=querymax(x*2,l,mid,s,t);
    if (t>mid)
        ret=max(querymax(x*2+1,mid+1,r,s,t),ret);
    return ret;
}
long long querymin(int x,int l,int r,int s,int t)
{
    down(x,l,r);
    if (s<=l && r<=t)
        return tree[x].min;
    int mid=l+r>>1;
    long long ret=inf;
    if (s<=mid)
        ret=querymin(x*2,l,mid,s,t);
    if (t>mid)
        ret=min(querymin(x*2+1,mid+1,r,s,t),ret);
    return ret;
}
long long querysum(int x,int l,int r,int s,int t)
{
    down(x,l,r);
    if (s<=l && r<=t)
        return tree[x].sum;
    int mid=l+r>>1;
    long long ret=0;
    if (s<=mid)
        ret=querysum(x*2,l,mid,s,t);
    if (t>mid)
        ret+=querysum(x*2+1,mid+1,r,s,t);
    return ret;
}
long long querysum2(int x,int l,int r,int s,int t)
{
    down(x,l,r);
    if (s<=l && r<=t)
        return tree[x].sum2;
    int mid=l+r>>1;
    long long ret=0;
    if (s<=mid)
        ret=querysum2(x*2,l,mid,s,t);
    if (t>mid)
        ret+=querysum2(x*2+1,mid+1,r,s,t);
    return ret;
}
void adds(int x,int l,int r,int s,int t,int v)
{
    down(x,l,r);
    if (s<=l && r<=t)
    {
        tree[x].add=v;
        down(x,l,r);
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        adds(x*2,l,mid,s,t,v);
    else
        down(x*2,l,mid);
    if (t>mid)
        adds(x*2+1,mid+1,r,s,t,v);
    else
        down(x*2+1,mid+1,r);
    up(x);
}
void change(int x,int l,int r,int s,int t,int v)
{
    down(x,l,r);
    if (s<=l && r<=t)
    {
        tree[x].over=v;
        down(x,l,r);
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        change(x*2,l,mid,s,t,v);
    else
        down(x*2,l,mid);
    if (t>mid)
        change(x*2+1,mid+1,r,s,t,v);
    else
        down(x*2+1,mid+1,r);
    up(x);
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        printf("Case %d:\n",cas);
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        build(1,0,n-1);
        for (int i=0;i<m;i++)
        {
            int typ,l,r;
            scanf("%d%d%d",&typ,&l,&r);
            l--;r--;
            if (typ==2)
            {
                long long rmax=querymax(1,0,n-1,l,r),rmin=querymin(1,0,n-1,l,r),sum=querysum(1,0,n-1,l,r),sum2=querysum2(1,0,n-1,l,r);
                sum=sum2*(r-l+1)-sum*sum;
                long long g=__gcd(sum,(long long)(r-l+1)*(r-l+1));
                printf("%lld/%lld %lld\n",sum/g,(long long)(r-l+1)*(r-l+1)/g,rmax-rmin);
            }
            else if (typ)
            {
                long long x;
                scanf("%lld",&x);
                adds(1,0,n-1,l,r,x);
            }
            else
            {
                long long x;
                scanf("%lld",&x);
                change(1,0,n-1,l,r,x);
            }
        }
    }
}
