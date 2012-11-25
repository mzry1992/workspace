#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
int sum1[1<<15],sum2[1<<15];
int c[35];
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
	    int i,j;
	    for(i=0;i<n;i++)
            scanf("%d",&c[i]);
        int k1,k2;
        k1=(1<<(n/2));
        k2=(1<<((n+1)/2));
        for(i=0;i<k1;i++)
        {
            sum1[i]=0;
            for(j=0;j<n/2;j++)
                if(i&(1<<j))
                    sum1[i]+=c[j];
        }
        for(i=0;i<k2;i++)
        {
            sum2[i]=0;
            for(j=n/2;j<n;j++)
                if(i&(1<<(j-n/2)))
                    sum2[i]+=c[j];
        }
        sort(sum2,sum2+k2);
        int ans=0;
        for(i=0;i<k1;i++)
        {
            int l,r,mid;
            l=0;r=k2-1;mid=l+r>>1;
            while(l<r)
            {
                mid=l+r>>1;
                if(sum1[i]+sum2[mid]>m)
                    r=mid-1;
                else
                    l=mid;
            }
            if(sum1[i]+sum2[r]<=m)
                ans=max(ans,sum1[i]+sum2[r]);
            else if(sum1[i]+sum2[l]<=m)
                ans=max(ans,sum1[i]+sum2[l]);
        }
        printf("%d\n",ans);
	}
	return 0;
}
