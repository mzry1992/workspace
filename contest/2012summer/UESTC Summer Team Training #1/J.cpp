#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int inf = 1<<30;
int n,m;
int s[100005];
struct N
{
    int l,r,mid;
    int k;
}node[100005*4];
struct M
{
    int x,y;
}s1[100005],s2[100005];
void init(int p,int l,int r)
{
    node[p].l=l;
    node[p].r=r;
    node[p].mid=(l+r)>>1;
    if(l==r)
        node[p].k=s[l];
    else
    {
        init(p<<1,l,node[p].mid);
        init(p<<1|1,node[p].mid+1,r);
        node[p].k=min(node[p<<1].k,node[p<<1|1].k);
    }
}
int read(int p,int l,int r)
{
    if(node[p].l==l&&node[p].r==r)
        return node[p].k;
    else if(r<=node[p].mid)
        return read(p<<1,l,r);
    else if(l>node[p].mid)
        return read(p<<1|1,l,r);
    else
    {
        int k1,k2;
        k1=read(p<<1,l,node[p].mid);
        k2=read(p<<1|1,node[p].mid+1,r);
        return min(k1,k2);
    }
}
bool cmp(M a,M b)
{
    if(a.y<b.y)
        return true;
    else if(a.y==b.y&&a.x<b.y)
        return true;
    return false;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
	    int i;
	    for(i=0;i<n;i++)
            scanf("%d%d",&s1[i].x,&s1[i].y);
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d%d",&s2[i].x,&s2[i].y);
        sort(s1,s1+n,cmp);
        sort(s2,s2+m,cmp);
        for(i=0;i<m;i++)
            s[i]=abs(s1[0].x-s2[i].x)+abs(s1[0].y-s2[i].y);
        init(1,0,m-1);
        int l,r,mid;
        l=0;r=m-1;mid=(l+r)>>1;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(s2[mid].y>s1[0].y)
                r=mid;
            else
                l=mid+1;
        }
        bool flag=true;
        if(s2[r].y<s1[0].y)
            flag=false;
        int st=r,now=r+1;
        int k1,k2,k3;
        int ans=node[1].k;
        if(st-1>=0)
            k1=read(1,0,st-1);
        else
            k1=inf;
        for(i=1;i<n;i++)
        {
            if(flag&&s2[st].y<s1[i].y)
            {
                while(s2[now].y<s1[i].y&&now<m)
                {
                    if(s[now]-2*(s2[now].y-s2[st].y)<s[st])
                        st=now;
                    now++;
                }
                k2=s[st];
                if(now<m)
                    k3=read(1,now,m-1);
                else
                    k3=inf;
            }
            else if(flag)
            {
                k2=inf;k3=read(1,st,m-1);
            }
            else
            {
                k2=inf;k3=inf;
            }
            int dx=s1[0].x-s1[i].x;
            int dy=s1[i].y-s1[0].y;
            ans=min(ans,k1+dx+dy);
            ans=min(ans,k2+dx+(s1[i].y-s2[st].y)-(s2[st].y-s1[0].y));
            ans=min(ans,k3+dx-dy);
        }
        printf("%d\n",ans);
	}
	return 0;
}
