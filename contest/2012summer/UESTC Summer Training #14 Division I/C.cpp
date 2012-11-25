#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[110000];
long long sum,p[110000],sl,sr;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%d",&n);
	    sum = p[0] = 0;
	    for (int i = 1;i <= n;i++)
	    {
            scanf("%d",&a[i]);
            sum += a[i];
            p[i] = p[i-1]+a[i];
	    }
	    long long res = 0x7fffffffffffffff;
	    for (int i = 1;i <= n;i++)
	    {
            sl = p[i-1];
            sr = sum-sl-a[i];
            res = min(res,max(sl,sr)+min(sl,sr)*2);
	    }
	    printf("%lld\n",res);
	}
	return 0;
}
