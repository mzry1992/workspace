#include <cstdio>
#include <cstring>

const int Maxn = 50000;
int n,lent[11][11],sum[11][11];
int tree[10][Maxn*4],a[Maxn];

void init()
{
    memset(tree,0,sizeof(tree));
    for (int i = 1;i <= 10;i++)
    {
        for (int j = 0;j < i;j++)
            lent[i][j] = n/i;
        for (int j = 0;j < n%i;j++)
            lent[i][j]++;
        sum[i][0] = lent[i][0];
        for (int j = 1;j < i;j++)
            sum[i][j] = sum[i][j-1]+lent[i][j];
    }
}

int getpos(int a,int k)
{
    int res = 0;
    if (a%k > 0)
        res = sum[k][a%k-1];
    res += a/k;
    return res;
}

int getpos(int a,int b,int k)
{
    return getpos(a,k)+(b-a)/k;
}
void update(int k,int x,int l,int r,int s,int t,int c)
{
    if (s<=l && r<=t)
    {
        tree[k][x]+=c;
        return ;
    }
    int mid=l+r>>1;
    if (s<=mid)
        update(k,x*2,l,mid,s,t,c);
    if (t>mid)
        update(k,x*2+1,mid+1,r,s,t,c);
}
int query(int k,int x,int l,int r,int p)
{
    if (l==r)
        return tree[k][x];
    int mid=l+r>>1;
    if (p<=mid)
        return tree[k][x]+query(k,x*2,l,mid,p);
    else
        return tree[k][x]+query(k,x*2+1,mid+1,r,p);
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        init();
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int m;
        scanf("%d",&m);
        while (m--)
        {
            int typ;
            scanf("%d",&typ);
            if (typ==1)
            {
                int s,t,k,c;
                scanf("%d%d%d%d",&s,&t,&k,&c);
                s--;
                t--;
                update(k-1,1,0,n-1,getpos(s,k),getpos(s,t,k),c);
                //printf("%d %d\n",getpos(s,k),getpos(s,t,k));
            }
            else
            {
                int x;
                scanf("%d",&x);
                x--;
                int ans=a[x];
                for (int i=0;i<10;i++)
                    ans+=query(i,1,0,n-1,getpos(x,i+1));
                printf("%d\n",ans);
            }
        }
    }
}
