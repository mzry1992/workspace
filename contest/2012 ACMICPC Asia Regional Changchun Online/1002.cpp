#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Event
{
    int x,y;
    bool typ;
    Event(){}
    Event(int _x,int _y,bool _typ)
    {
        x=_x;
        y=_y;
        typ=_typ;
    }
    bool operator<(const Event &a)const
    {
        if (x!=a.x)
            return x<a.x;
        if (y!=a.y)
            return y<a.y;
        return typ>a.typ;
    }
}ev[200000];
int tree[800000];
void update(int x,int l,int r,int p,int v)
{
    if (l==r)
    {
        tree[x]+=v;
        return ;
    }
    int mid=l+r>>1;
    if (p<=mid)
        update(x*2,l,mid,p,v);
    else
        update(x*2+1,mid+1,r,p,v);
    tree[x]=tree[x*2]+tree[x*2+1];
}
int query(int x,int l,int r,int p)
{
    if (!tree[x])
        return -1;
    if (l==r)
        return l;
    int mid=l+r>>1;
    if (p<=mid)
        return query(x*2,l,mid,p);
    else
    {
        int ret=query(x*2+1,mid+1,r,p);
        if (ret!=-1)
            return ret;
        else
            return query(x*2,l,mid,p);
    }
}
int ty[200000],tn;
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ev[i]=Event(x,y,0);
        }
        for (int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ev[i+n]=Event(x,y,1);
        }
        for (int i = 0;i < n*2;i++)
            ty[i] = ev[i].y;
        memset(tree,0,sizeof(tree));
        sort(ty,ty+n*2);
        tn = unique(ty,ty+n*2)-ty;
        for (int i = 0;i < n*2;i++)
            ev[i].y = lower_bound(ty,ty+tn,ev[i].y)-ty;
        sort(ev,ev+n*2);
        int ans=0;
        for (int i=0;i<n*2;i++)
            if (ev[i].typ)
                update(1,0,tn-1,ev[i].y,1);
            else
            {
                int p=query(1,0,tn-1,ev[i].y);
                if (p==-1)
                    continue;
                ans++;
                update(1,0,tn-1,p,-1);
            }
        printf("%d\n",ans);
    }
}
