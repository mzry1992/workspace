#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const double eps=1e-8;
int n,m,N;
long long tree[100001];
double a[100001],b[100001];
int p[100001],v[100001];
void update(int x)
{
    x++;
    for (;x<=N;x+=x&-x)
        tree[x]++;
}
long long query(int x)
{
    x++;
    long long ret=0;
    for (;x;x^=x&-x)
        ret+=tree[x];
    return ret;
}
int getId(double x)
{
    return lower_bound(b,b+N,x)-b;
}
long long count(double x)
{
    for (int i=1;i<=n;i++)
        b[i]=a[i]=v[i]-p[i]*x;
    sort(b,b+n+1);
    N=1;
    for (int i=1;i<=n;i++)
        if (b[i]-b[i-1]>eps)
            b[N++]=b[i];
    long long ret=0;
    memset(tree,0,8*N+8);
    for (int i=m;i<=n;i++)
    {
        update(getId(a[i-m]));
        ret+=query(getId(a[i]));
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        long long k;
        scanf("%d%d%lld",&n,&m,&k);
        for (int i=1;i<=n;i++)
            scanf("%d",&p[i]);
        for (int i=2;i<=n;i++)
            p[i]+=p[i-1];
        for (int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        for (int i=2;i<=n;i++)
            v[i]+=v[i-1];
        double l=-1000,r=1000;
        while (l+eps<r)
        {
            double mid=(l+r)/2;
            if (count(mid)>=k)
                l=mid;
            else
                r=mid;
        }
        printf("%.8f\n",l);
    }
    return 0;
}
