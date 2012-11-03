#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[1000];
char buf[1100];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    gets(buf);
	    int maxn = 0;
	    for (int i = 0;i < n;i++)
	    {
	        gets(buf);
	        a[i] = strlen(buf);
	        maxn = max(maxn,a[i]);
	    }
	    int l,r;
	    l = n;
	    r = 0;
	    for (int i = 0;i < n;i++)
            if (a[i]*2 >= maxn)
            {
                l = min(l,i);
                r = max(r,i);
            }
        printf("%d\n",r-l+1);
	}
	return 0;
}
