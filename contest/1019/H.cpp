#include<cstdio>
#include<algorithm>
using namespace std;
pair<int,int> tree[400000];
int lazy[400000];
int a[100000],h[100000],b[100000];
void build(int x,int l,int r)
{
    lazy[x]=0;
    if (l<r)
    {
        int mid=l+r>>1;
        build(x*2,l,mid);
        build(x*2+1,mid+1,r);
        tree[x]=max(tree[x*2],tree[x*2+1]);
    }
    else
        tree[x]=make_pair(h[l],l);
}
void clear(int x,int l,int r)
{
    tree[x].first+=lazy[x];
    if (l<r)
    {
        lazy[x*2]+=lazy[x];
        lazy[x*2+1]+=lazy[x];
    }
    lazy[x]=0;
}
pair<int,int> read(int x,int l,int r,int k)
{
    clear(x,l,r);
    if (tree[x].first<k)
        return make_pair(-1,0);
    if (l==r)
        return tree[x];
    int mid=l+r>>1;
    clear(x*2+1,mid+1,r);
    if (tree[x*2+1].first<k)
        return read(x*2,l,mid,k);
    else
        return read(x*2+1,mid+1,r,k);
}
void change(int x,int l,int r,int p)
{
    clear(x,l,r);
    if (l==r)
    {
        tree[x].first=1;
        return ;
    }
    int mid=l+r>>1;
    if (p>mid)
    {
        change(x*2+1,mid+1,r,p);
        clear(x*2,l,mid);
    }
    else
    {
        change(x*2,l,mid,p);
        clear(x*2+1,mid+1,r);
    }
    tree[x]=max(tree[x*2],tree[x*2+1]);
}
void update(int x,int l,int r,int s,int t)
{
    clear(x,l,r);
    if (s<=l && r<=t)
    {
        lazy[x]++;
        clear(x,l,r);
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        update(x*2,l,mid,s,t);
    else
        clear(x*2,l,mid);
    if (t>mid)
        update(x*2+1,mid+1,r,s,t);
    else
        clear(x*2+1,mid+1,r);
    tree[x]=max(tree[x*2],tree[x*2+1]);
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d%d%d",&h[i],&a[i],&b[i]);
        int m;
        scanf("%d",&m);
        build(1,0,n-1);
        for (int i=0;i<m;i++)
        {
            int k;
            scanf("%d",&k);
            pair<int,int> ret=read(1,0,n-1,k);
            if (ret.second==-1)
            {
                update(1,0,n-1,0,n-1);
                continue;
            }
            change(1,0,n-1,ret.second);
            update(1,0,n-1,a[ret.second]-1,b[ret.second]-1);
        }
        clear(1,0,n-1);
        printf("%d\n",tree[1].first);
    }
    return 0;
}
