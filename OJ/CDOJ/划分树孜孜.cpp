#include<cstdio>
#include<algorithm>
using namespace std;
const int NSIZE=100000;
const int DEGSIZE=30;
int a[NSIZE+1];
int ranks[DEGSIZE][NSIZE],org[DEGSIZE][NSIZE];
bool goleft[DEGSIZE][NSIZE];
int sum[DEGSIZE][NSIZE];
struct eles
{
    int key,pos;
}ele[NSIZE];
int DEG,N;
int getLen(int x)
{
    int ret=0;
    for (;x;x>>=1)
        ret++;
    return ret;
}
bool cmp(const eles &x,const eles &y)
{
    return x.key<y.key;
}
void build(int deg,int l,int r)
{
    if (l==r) return;
    int mid=l+r>>1;
    for (int i=l,nl=l,nr=mid+1;i<=r;i++)
        if (ranks[deg][i]<=mid)
        {
            goleft[deg][i]=1;
            org[deg+1][nl]=org[deg][i];
            ranks[deg+1][nl++]=ranks[deg][i];
        }
        else
        {
            goleft[deg][i]=0;
            org[deg+1][nr]=org[deg][i];
            ranks[deg+1][nr++]=ranks[deg][i];
        }
    build(deg+1,l,mid);
    build(deg+1,mid+1,r);
}
void init(int n)
{
    DEG=getLen(n-1)+1;
    N=n;
    for (int i=1;i<=n;i++)
    {
        ele[i-1].key=a[i];
        ele[i-1].pos=i;
    }
    sort(ele,ele+n,cmp);
    for (int i=0;i<n;i++)
    {
        ranks[0][ele[i].pos]=i+1;
        org[0][i+1]=i+1;
    }
    build(0,1,n);
    for (int i=0;i<DEG;i++)
        for (int j=1;j<=n;j++)
            sum[i][j]=sum[i][j-1]+goleft[i][j];
}
int find(int s,int t,int k)
{
    int deg=0;
    for (int l=1,r=N;s<t;deg++)
    {
        int num=sum[deg][t]-sum[deg][s-1];
        if (num>=k)
        {
            s=l+sum[deg][s-1]-sum[deg][l-1];
            t=l-1+sum[deg][t]-sum[deg][l-1];
            r=l+r>>1;
        }
        else
        {
            k-=num;
            int mid=l+r>>1;
            s=mid+s-sum[deg][s-1]-l+1+sum[deg][l-1];
            t=mid+t-sum[deg][t]-l+1+sum[deg][l-1];
            l=mid+1;

        }
    }
    return org[deg][s];
}
int find(int deg,int l,int r,int s,int t,int k)
{
    if (s==t)
        return org[deg][s];
    int num=sum[deg][t]-sum[deg][s-1],mid=l+r>>1;
    if (num>=k)
        return find(deg+1,l,mid,l+sum[deg][s-1]-sum[deg][l-1],l-1+sum[deg][t]-sum[deg][l-1],k);
    else
        return find(deg+1,mid+1,r,mid+s-sum[deg][s-1]-l+1+sum[deg][l-1],mid+t-sum[deg][t]-l+1+sum[deg][l-1],k-num);
}
bool check(int s,int t,int k)
{
    int deg=0;
    for (int l=1,r=N;s<t;deg++)
    {
        int mid=l+r>>1;
        if (ele[sum[deg][mid+1]].key>=k)
        {
            s=l+sum[deg][s-1]-sum[deg][l-1];
            t=l-1+sum[deg][t]-sum[deg][l-1];
            r=mid;
        }
        else
        {
            s=mid+s-sum[deg][s-1]-l+1+sum[deg][l-1];
            t=mid+t-sum[deg][t]-l+1+sum[deg][l-1];
            l=mid+1;
        }
    }
    return k==a[org[deg][s]];
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        init(n);
        for (int i=0;i<q;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            printf("%d\n",a[find(x,y,z)]);
            //printf("%d\n",a[find(0,1,n,x,y,z)]);
        }
    }
    return 0;
}
