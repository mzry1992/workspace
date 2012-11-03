#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
const int inf = 1<<29;
int mi,sum;
int val[100005];
int c[100005];
int main()
{
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
	    mi=inf;sum=0;
	    scanf("%d%d",&n,&m);
	    int i,num=0;
	    for(i=0;i<n;i++)
	    {
	        int a,b;
	        scanf("%d%d",&a,&b);
	        if(b!=0)
	        {
	            mi=min(mi,a);
	            sum+=b;
	        }
	        else
                val[num++]=a;
            c[i]=a;
	    }
	    sort(val,val+num);
	    sort(c,c+n);
	    int ans1=0,cost1=0;
	    if(m>=mi)
	    {
	        cost1=mi;
	        ans1=min(sum+1,n);
	        int p=0,rest=m-mi;
	        while(ans1<n&&rest>=c[p])
            {
                ans1++;
                cost1+=c[p];
                rest-=c[p];
                p++;
            }
	    }
	    int ans2=0,cost2=0,rest2=m,p=0;
	    while(ans2<num&&rest2>=val[p])
	    {
	        ans2++;
	        cost2+=val[p];
	        rest2-=val[p];
	        p++;
	    }
	    printf("Case %d: ",cas++);
	    if(ans1>ans2)
	        printf("%d %d\n",ans1,cost1);
        else if(ans1<ans2)
            printf("%d %d\n",ans2,cost2);
        else if(ans1==ans2)
        {
            if(cost1>cost2)
                printf("%d %d\n",ans2,cost2);
            else
                printf("%d %d\n",ans1,cost1);
        }
	}
	return 0;
}
