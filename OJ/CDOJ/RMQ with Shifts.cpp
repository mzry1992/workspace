#include <cstdio>
#include<cstring>
int n,q,a[100000],b[30],totb,len;
char buf[35];
int tree[400000];
int min(int x,int y)
{
    if (x<y) return x;
    else return y;
}
void build(int x,int l,int r)
{
    if (l==r)
    {
        tree[x]=a[l];
        return ;
    }
    int mid=l+r>>1;
    build(x*2,l,mid);
    build(x*2+1,mid+1,r);
    tree[x]=min(tree[x*2],tree[x*2+1]);
}
void update(int x,int l,int r,int p,int v)
{
    if (l==r)
    {
        tree[x]=v;
        return ;
    }
    int mid=l+r>>1;
    if (p<=mid)
        update(x*2,l,mid,p,v);
    else
        update(x*2+1,mid+1,r,p,v);
    tree[x]=min(tree[x*2],tree[x*2+1]);
}
int read(int x,int l,int r,int s,int t)
{
    if (s<=l && r<=t)
        return tree[x];
    int mid=l+r>>1;
    int ret=1000000;
    if (s<=mid)
        ret=read(x*2,l,mid,s,t);
    if (t>mid)
        ret=min(read(x*2+1,mid+1,r,s,t),ret);
    return ret;
}
int main()
{
    while (scanf("%d%d",&n,&q) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        build(1,0,n-1);
        for (int i = 0;i < q;i++)
        {
            scanf("%s",buf);
            len = strlen(buf);
            totb = 0;
            for (int j = 1;j < len;j++)
                if (buf[j] >= '0' && buf[j] <= '9' && (buf[j-1] < '0' || buf[j-1] > '9'))
                {
                    b[totb] = 0;
                    for (int k = j;k < len;k++)
                        if (buf[k] >= '0' && buf[k] <= '9')
                            b[totb] = b[totb]*10+buf[k]-'0';
                        else
                            break;
                    totb++;
                }
            if (buf[0] == 'q')
            {
                printf("%d\n",read(1,0,n-1,b[0]-1,b[1]-1));
            }
            else
            {
                update(1,0,n-1,b[totb-1]-1,a[b[0]-1]);
                for (int i=1;i<totb;i++)
                    update(1,0,n-1,b[i-1]-1,a[b[i]-1]);
                int tmp = a[b[0]-1];
                for (int i=1;i<totb;i++)
                    a[b[i-1]-1] = a[b[i]-1];
                a[b[totb-1]-1] = tmp;
            }
        }
    }
    return 0;
}
