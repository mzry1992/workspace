#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,p;
long long val[100005],sum[100005];
int M,T;
bool check(int L,int R)
{
    if(L+M<=p&&p-L+R-L-M<=T)
        return true;
    if(R-M>=p&&R-p+R-M-L<=T)
        return true;
    if(L+M>p)
    {
        if(L+M<=R&&max(p-L,R-p)<=T)
            return true;
        if(L+M>R&&)
    }
    return false;
}
int main()
{
	while(scanf("%d%d",&n,&p)==2)
	{
	    int i;
	    sum[0]=0;
	    for(i=1;i<=n;i++)
	    {
            scanf("%lld",&val[i]);
            sum[i]=sum[i-1]+val[i];
	    }
        scanf("%d%d",&M,&T);
        long long ans=0;
        ans=max(ans,sum[p]-sum[max(1,p-T)-1]);
        ans=max(ans,sum[min(p+T,n)]-sum[p-1]);
        for(i=max(1,p-T);i<=p;i++)
        {
            int l=p,r=n;
            while(l<r)
            {
                int mid=l+r>>1;
                if(check(i,mid))
                    l=mid+1;
                else
                    r=mid;
            }
            if(check(i,l))
            {
                ans=max(ans,sum[l]-sum[i-1]);
                printf("%lld %d %d\n",ans,i,l);
            }
            else
            {
                ans=max(ans,sum[l-1]-sum[i-1]);
                printf("%lld %d %d\n",ans,i,l);
            }
        }
        printf("%lld\n",ans);
	}
	return 0;
}
