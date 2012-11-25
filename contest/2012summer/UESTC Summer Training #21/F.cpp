#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,p;
long long val[100005],sum[100005];
int M,T;
bool check(int L,int R,int lim)
{
    if(R-L+lim<=T||2*R-L-p<=T)
        return true;
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
        for(i=max(1,p-T);i<=p;i++)
        {
            int l,r,mid;
            l=p;r=n;mid=l+r>>1;
            while(l<r)
            {
                mid=l+r>>1;
                if(check(min(i+M,p),mid,p-i))
                    l=mid+1;
                else
                    r=mid;
            }
            if(l>p)
                ans=max(ans,sum[l-1]-sum[i-1]);
            else
                ans=max(ans,sum[p]-sum[i-1]);
        }
        for(i=p;i<=min(n,p+T);i++)
        {
            int l,r,mid;
            l=1;r=p;mid=l+r>>1;
            while(l<r)
            {
                mid=l+r>>1;
                if(check(mid,max(i-M,p),i-p))
                    r=mid;
                else
                    l=mid+1;
            }
            if(check(r,max(i-M,p),i-p))
                ans=max(ans,sum[i]-sum[r-1]);
            else
                ans=max(ans,sum[i]-sum[p-1]);
        }
        printf("%lld\n",ans);
	}
	return 0;
}
