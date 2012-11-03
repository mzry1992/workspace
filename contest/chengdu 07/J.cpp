#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[1005],b[1005],c[1005];
int main()
{
    int cas=1;
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0)
            break;
	    int i,ans=0,k;
	    for(i=0;i<n;i++)
	    {
            scanf("%d",&k);
            a[k-1]=i;
	    }
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            b[k-1]=i;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
            c[i]--;
        }
        for(i=0;i<n;i++)
        {
            if(a[i]<=c[i])
                ans+=3;
            else if(a[i]<b[i])
                ans+=2;
            else
                ans++;
        }
        printf("Case %d: %d\n",cas++,ans);
	}
    return 0;
}

