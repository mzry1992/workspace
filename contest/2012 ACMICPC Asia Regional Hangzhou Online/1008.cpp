#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100000],b[100000];
int ans[100000];
struct EV
{
    int pos,id,val;
    EV(){}
    EV(int _pos,int _val,int _id)
    {
        pos=_pos;
        val=_val;
        id=_id;
    }
    bool operator<(const EV &a) const
    {
        return pos<a.pos;
    }
}ev[200000];
int tree[400000];
void update(int x,int l,int r,int p)
{
    if (l==r)
    {
        tree[x]++;
        return ;
    }
    int mid=l+r>>1;
    if (p<=mid)
        update(x*2,l,mid,p);
    else
        update(x*2+1,mid+1,r,p);
    tree[x]=tree[x*2]+tree[x*2+1];
}
int query(int x,int l,int r,int p)
{
    if (r<=p)
        return tree[x];
    int mid=l+r>>1,ret=query(x*2,l,mid,p);
    if (p>mid)
        ret+=query(x*2+1,mid+1,r,p);
    return ret;
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
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        int tn=unique(b,b+n)-b;
        for (int i=0;i<n;i++)
            a[i]=lower_bound(b,b+tn,a[i])-b;
        for (int i=0;i<m;i++)
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            int p=upper_bound(b,b+tn,x)-b-1;
            ev[i*2]=EV(l-1,p,i*2);
            ev[i*2+1]=EV(r,p,i*2+1);
            ans[i] = 0;
        }
        sort(ev,ev+m*2);
        memset(tree,0,sizeof(tree));
        int now=0;
        for (int i=0;i<m*2;i++)
            if (ev[i].pos!=-1 && ev[i].val!=-1)
            {
                while (ev[i].pos>=now)
                    update(1,0,tn-1,a[now++]);
                if (ev[i].id&1)
                    ans[ev[i].id/2]+=query(1,0,tn-1,ev[i].val);
                else
                    ans[ev[i].id/2]-=query(1,0,tn-1,ev[i].val);
            }
        for (int i=0;i<m;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
