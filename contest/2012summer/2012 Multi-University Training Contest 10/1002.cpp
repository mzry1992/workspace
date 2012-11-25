#include <cstdio>
#include <map>
using namespace std;
struct Tree
{
    int lazy;
    map<int,int> color;
}tree[400000];
int a[100000];
void down(int x,int l,int r)
{
    if (tree[x].lazy==-1)
        return ;
    tree[x].color.clear();
    tree[x].color[tree[x].lazy]=r-l+1;
    if (l<r)
        tree[x*2].lazy=tree[x*2+1].lazy=tree[x].lazy;
    tree[x].lazy=-1;
}
void up(int x)
{
    tree[x].color.clear();
    for (map<int,int> ::iterator it=tree[x*2].color.begin();it!=tree[x*2].color.end();it++)
        tree[x].color.insert(*it);
    for (map<int,int> ::iterator it=tree[x*2+1].color.begin();it!=tree[x*2+1].color.end();it++)
        tree[x].color[it->first]+=it->second;
}
void build(int x,int l,int r)
{
    tree[x].lazy=-1;
    tree[x].color.clear();
    if (l<r)
    {
        int mid=l+r>>1;
        build(x*2,l,mid);
        build(x*2+1,mid+1,r);
        up(x);
    }
    else
        tree[x].color[a[l]]=1;
}
void update(int x,int l,int r,int s,int t,int z)
{
    down(x,l,r);
    if (s<=l && r<=t)
    {
        tree[x].lazy=z;
        down(x,l,r);
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        update(x*2,l,mid,s,t,z);
    else
        down(x*2,l,mid);
    if (t>mid)
        update(x*2+1,mid+1,r,s,t,z);
    else
        down(x*2+1,mid+1,r);
    up(x);
}
int query(int x,int l,int r,int s,int t,int z)
{
    down(x,l,r);
    if (s<=l && r<=t)
        return tree[x].color[z];
    int mid=l+r>>1,ret=0;
    if (s<=mid)
        ret=query(x*2,l,mid,s,t,z);
    if (t>mid)
        ret+=query(x*2+1,mid+1,r,s,t,z);
    return ret;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        build(1,0,n-1);
        for (int i=0;i<m;i++)
        {
            int typ,l,r,z;
            scanf("%d%d%d%d",&typ,&l,&r,&z);
            if (typ==1)
                update(1,0,n-1,l,r,z);
            else
                printf("%d\n",query(1,0,n-1,l,r,z));
        }
    }
}
