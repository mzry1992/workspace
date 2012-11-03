#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int mod;
long long inv[100000];
long long num[100000];
void getInv2(int x)
{
    inv[0]=inv[1]=1;
    for (int i=2; i<x; i++)
        inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
}
int ni[100],mi[100];
int len;
void init(int p)
{
    mod=p;
    getInv2(p);
    num[0]=1;
    for (int i=1; i<p; i++)
        num[i]=i*num[i-1]%p;
}
void get(int n,int ni[],int p)
{
    memset(ni,0,sizeof(ni));
    int tlen = 0;
    while (n != 0)
    {
        ni[tlen++] = n%p;
        n /= p;
    }
    len = tlen;
}

struct node
{
    int n,m,p,id;
    long long ans;
}q[100000];

bool cmp(const node& a,const node& b)
{
    if (a.p == b.p)
        return a.id < b.id;
    return a.p < b.p;
}

bool cmp2(const node& a,const node& b)
{
    return a.id < b.id;
}

long long calc(int n,int m,int p)
{
    n+=m;
    get(m,mi,p);
    get(n,ni,p);
    long long ans=1;
    for (int i=0; ans && i<len; i++)
        if (ni[i]>=mi[i])
            ans=ans*num[ni[i]]%p*inv[num[mi[i]]]%p*inv[num[ni[i]-mi[i]]]%p;
        else
            ans=0;
    return ans;
}

int main()
{
    freopen("G.in","r",stdin);
    freopen("G2.out","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 0; ft < t; ft++)
    {
        scanf("%d%d%d",&q[ft].n,&q[ft].m,&q[ft].p);
        q[ft].id = ft;
    }
    sort(q,q+t,cmp);
    int pre = 0;
    for (int ft = 1; ft <= t; ft++)
        if (ft == t || q[ft].p != q[pre].p)
        {
            init(q[pre].p);
            for (int i = pre; i < ft; i++)
                q[i].ans = calc(q[i].n,q[i].m,q[i].p);
            pre = ft;
        }
    sort(q,q+t,cmp2);
    for (int i = 0; i < t; i++)
        printf("%I64d\n",q[i].ans);
    return 0;
}
