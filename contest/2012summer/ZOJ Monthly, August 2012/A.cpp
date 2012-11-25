#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int tree[2000000];
int a[500000];
int out[50000];
struct Event
{
    int id,l,r;
    Event(){}
    Event(int _id,int _l,int _r)
    {
        id=_id;
        l=_l;
        r=_r;
    }
    bool operator<(const Event &a)const
    {
        if (r!=a.r)
            return r<a.r;
        else
            return id<a.id;
    }
}event[550000];
int query(int x,int l,int r,int p)
{
    if (l==r)
        return tree[x];
    int mid=l+r>>1;
    if (p<=mid)
        return max(query(x*2,l,mid,p),tree[x*2+1]);
    else
        return query(x*2+1,mid+1,r,p);
}
void update(int x,int l,int r,int p)
{
    if (l==r)
    {
        tree[x]=p;
        return ;
    }
    int mid=l+r>>1;
    if (p<=mid)
        update(x*2,l,mid,p);
    else
        update(x*2+1,mid+1,r,p);
    tree[x]=max(tree[x*2],tree[x*2+1]);
}
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        map<int,int> pre;
        int m=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (pre.find(a[i])!=pre.end())
                event[m++]=Event(0,pre[a[i]],i);
            pre[a[i]]=i;
        }
        int q;
        scanf("%d",&q);
        for (int i=0;i<q;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            event[m++]=Event(i+1,u-1,v-1);
        }
        sort(event,event+m);
        memset(tree,-1,sizeof(tree));
        for (int i=0;i<m;i++)
            if (event[i].id)
                out[event[i].id-1]=query(1,0,n-1,event[i].l);
            else
                update(1,0,n-1,event[i].l);
        for (int i=0;i<q;i++)
            if (out[i]!=-1)
                printf("%d\n",a[out[i]]);
            else
                puts("OK");
        puts("");
    }
	return 0;
}
