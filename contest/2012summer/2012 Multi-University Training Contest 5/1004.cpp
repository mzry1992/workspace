#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n;

long long check(long long n)
{
    return sqrt(1.0*n);
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    long long l = 2,r = 1LL<<32,mid;
	    while (l < r)
	    {
	        mid = l+r>>1;
	        if (mid-check(mid) >= n)
                r = mid;
            else
                l = mid+1;
	    }
	    long long res = 0;
        for (long long i = 1;i*i < l;i++)
        {
            r = min((i+1)*(i+1),l+1);
            res += (r-i*i)*i;
        }
        printf("%I64d %I64d\n",l,res);
	}
	return 0;
}
