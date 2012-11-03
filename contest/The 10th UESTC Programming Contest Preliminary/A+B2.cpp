#include<cstdio>
#include<cstring>
int tree[400000],lazy[400000],con1[400000],con2[400000];
int a[100000],b[100000],c[100000];
int mod;
void build(int x,int l,int r)
{
    lazy[x]=-1;
    con1[x]=con2[x]=0;
    if (l==r)
    {
        tree[x]=c[l];
        if (c[l]==mod-1)
            con1[x]=1;
        if (!c[l])
            con2[x]=1;
        return ;
    }
    int mid=l+r>>1;
    build(x<<1,l,mid);
    build(x*2+1,mid+1,r);
    con1[x]=con1[x*2+1];
    if (con1[x]==r-mid)
        con1[x]+=con1[x<<1];
    con2[x]=con2[x*2+1];
    if (con2[x]==r-mid)
        con2[x]+=con2[x<<1];
}
void clear(int x,int l,int r)
{
    if (lazy[x]==-1)
        return;
    tree[x]=lazy[x];
    if (tree[x]==mod-1)
        con1[x]=r-l+1;
    if (!tree[x])
        con2[x]=r-l+1;
    if (l<r)
        lazy[x<<1]=lazy[x*2+1]=lazy[x];
    lazy[x]=-1;
}
int query(int x,int l,int r,int p)
{
    clear(x,l,r);
    if (l==r)
        return tree[x];
    int mid=l+r>>1;
    if (p<=mid)
        return query(x*2,l,mid,p);
    else
        return query(x*2+1,mid+1,r,p);
}
int query1(int x,int l,int r,int p)
{
    clear(x,l,r);
    if (r==p)
        return con1[x];
    int mid=l+r>>1;
    if (p<=mid)
        return query1(x<<1,l,mid,p);
    int ret=query1(x*2+1,mid+1,r,p);
    if (ret==p-mid)
    {
        clear(x<<1,l,mid);
        ret+=con1[x*2];
    }
    return ret;
}
int query2(int x,int l,int r,int p)
{
    clear(x,l,r);
    if (r==p)
        return con2[x];
    int mid=l+r>>1;
    if (p<=mid)
        return query2(x<<1,l,mid,p);
    int ret=query2(x*2+1,mid+1,r,p);
    if (ret==p-mid)
    {
        clear(x<<1,l,mid);
        ret+=con2[x*2];
    }
    return ret;
}
void update(int x,int l,int r,int s,int t,int v)
{
    if (s<=l && r<=t)
    {
        lazy[x]=v;
        clear(x,l,r);
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        update(x<<1,l,mid,s,t,v);
    else
        clear(x<<1,l,mid);
    if (t>mid)
        update(x*2+1,mid+1,r,s,t,v);
    else
        clear(x*2+1,mid+1,r);
    con1[x]=con1[x*2+1];
    if (con1[x]==r-mid)
        con1[x]+=con1[x*2];
    con2[x]=con2[x*2+1];
    if (con2[x]==r-mid)
        con2[x]+=con2[x*2];
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1; cas<=t; cas++)
    {
        printf("Case #%d:\n",cas);
        int n;
        scanf("%d%d",&mod,&n);
        for (int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for (int i=0; i<n; i++)
            scanf("%d",&b[i]);
        memset(c,0,4*n);
        for (int i=n-1; i; i--)
        {
            c[i]+=b[i]+a[i];
            c[i-1]+=c[i]/mod;
            c[i]%=mod;
        }
        c[0]+=a[0]+b[0];
        c[0]%=mod;
        build(1,0,n-1);
        int m;
        scanf("%d",&m);
        for (int i=0; i<m; i++)
        {
            char c;
            scanf(" %c",&c);
            if (c=='C')
            {
                int x,y;
                scanf(" %c%d%d",&c,&x,&y);
                x=n-x-1;
                int nowc=query(1,0,n-1,x),dif;
                if (c=='A')
                {
                    dif=y-a[x];
                    a[x]=y;
                }
                else
                {
                    dif=y-b[x];
                    b[x]=y;
                }
                if (nowc+dif<0)
                {
                    if (!x)
                    {
                        update(1,0,n-1,x,x,(nowc+dif+mod)%mod);
                        continue;
                    }
                    int len=query2(1,0,n-1,x-1);
                    if (x>len)
                        update(1,0,n-1,x-len-1,x-len-1,query(1,0,n-1,x-len-1)-1);
                    if (len)
                        update(1,0,n-1,x-len,x-1,mod-1);
                    update(1,0,n-1,x,x,(nowc+dif+mod)%mod);
                }
                else if (nowc+dif>=mod)
                {
                    if (!x)
                    {
                        update(1,0,n-1,x,x,(nowc+dif)%mod);
                        continue;
                    }
                    int len=query1(1,0,n-1,x-1);
                    if (x>len)
                        update(1,0,n-1,x-len-1,x-len-1,query(1,0,n-1,x-len-1)+1);
                    if (len)
                        update(1,0,n-1,x-len,x-1,0);
                    update(1,0,n-1,x,x,(nowc+dif)%mod);
                }
                else
                    update(1,0,n-1,x,x,nowc+dif);
            }
            else
            {
                int x;
                scanf("%d",&x);
                x=n-x-1;
                printf("%d\n",query(1,0,n-1,x));
            }
        }
    }
    return 0;
}
