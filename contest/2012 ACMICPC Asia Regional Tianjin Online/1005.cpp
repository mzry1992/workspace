#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a;
long long power(long long x,int a)
{
    long long ret=1;
    for (;a;a>>=1,x*=x)
        if (a&1)
            ret*=x;
    return ret;
}
long long calc(long long x,long long y,long long z)
{
    return power(x,z)+power(y,z)+x*y*z;
}
bool check(int y,int z,int k)
{
    int l=1,r=y-1;
    while (l<r)
    {
        int mid=l+r+1>>1;
        if (calc(mid,y,z)<=k)
            l=mid;
        else
            r=mid-1;
    }
    return calc(l,y,z)==k;
}
int main()
{
    while (true)
    {
        scanf("%d",&a);
        if (a == 0) break;
        int x,y,z=2;
        int res=0;
        for (long long tmp=4;tmp<a;tmp*=2,z++)
        {
            for (y=2;power(y,z)<a;y++)
                if (check(y,z,a))
                    res++;
        }
        printf("%d\n",res);
    }
	return 0;
}
