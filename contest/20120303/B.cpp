#include<cstdio>
#include<algorithm>
const int mod=1000000007;
long long power(long long a,long long x)
{
    long long ret=1;
    for (long long b=a;x;x>>=1,b=b*b%mod)
        if (x&1)
            ret=ret*b%mod;
    return ret;
}
int a[100000];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        int maxn=0,minn=0x7fffffff;
        int numma,nummi;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]>maxn)
            {
                maxn=a[i];
                numma=1;
            }
            else if (a[i]==maxn)
                numma++;
            if (a[i]<minn)
            {
                minn=a[i];
                nummi=1;
            }
            else if (a[i]==minn)
                nummi++;
        }
        int tot=0;
        int posma=-1,posmi=-1;
        for (int i=0;i<n;i++)
        {
            if (a[i]==maxn)
                posma=i;
            if (a[i]==minn)
                posmi=i;
            tot+=std::min(posma,posmi)+1;
            if (tot>=mod)
                tot-=mod;
        }
        int ans;
        if (maxn==minn)
            ans=power(2,n)-1;
        else
            ans=(power(2,numma)-1)*(power(2,nummi)-1)%mod*power(2,n-numma-nummi)%mod;
        ans=(ans+mod)%mod;
        printf("%d %d\n",tot,ans);
    }
    return 0;
}
