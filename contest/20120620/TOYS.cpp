#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int xa[6000],xb[6000],res[6000];
int bxa,bya,bxb,byb,x,y;
int n,m;

int sgn(long long x)
{
    if (x < 0)  return -1;
    return 1;
}

long long xmult(long long xa,long long ya,long long xb,long long yb)
{
    return xa*yb-xb*ya;
}

int main()
{
    bool first = true;
	while (true)
	{
	    scanf("%d",&n);
	    if (n == 0) break;
	    scanf("%d",&m);
	    scanf("%d%d%d%d",&bxa,&bya,&bxb,&byb);
	    xa[0] = xb[0] = bxa;
	    for (int i = 1;i <= n;i++)
            scanf("%d%d",&xa[i],&xb[i]);
        xa[n+1] = xb[n+1] = bxb;
	    memset(res,0,sizeof(res));
	    for (int i = 0;i < m;i++)
	    {
	        scanf("%d%d",&x,&y);
	        int l=1,r=n+1;
	        while (l<r)
	        {
	            int mid=l+r>>1;
                if (sgn(xmult(xa[0]-x,bya-y,xb[0]-x,byb-y)) !=
                    sgn(xmult(xa[mid]-x,bya-y,xb[mid]-x,byb-y)))
                    r=mid;
                else
                    l=mid+1;
	        }
	        res[l-1]++;
	    }
	    if (first == false) puts("");
	    first = false;
	    for (int i = 0;i <= n;i++)
            printf("%d: %d\n",i,res[i]);
	}
	return 0;
}
