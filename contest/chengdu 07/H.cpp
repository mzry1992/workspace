#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double L,T;
int n;
int main()
{
    int cas=1;
	while(1)
	{
	    scanf("%lf",&L);
	    if(L==0)
            break;
        scanf("%d%lf",&n,&T);
        int i;
        double now=0,d=0;
        for(i=0;i<n;i++)
        {
            double tmp,v;
            scanf("%lf",&v);
            tmp=L/v+d;
            now=max(now,tmp);
            d+=T;
        }
        printf("Case %d: %.0f\n",cas++,now);
	}
    return 0;
}

