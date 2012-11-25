#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int res[1005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int a,b,c,d,e,f,g,h,k;
	    scanf("%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h,&k);
	    res[0]=a;res[1]=b;res[2]=c;
	    int i;
	    for(i=3;i<=k;i++)
	    {
	        if(i%2==1)
                res[i]=((d*res[i-1]+e*res[i-2]-f*res[i-3])%g+g)%g;
            else
                res[i]=((f*res[i-1]-d*res[i-2]+e*res[i-3])%h+h)%h;
	    }
	    printf("%d\n",res[k]);
	}
	return 0;
}
