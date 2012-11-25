#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

struct node
{
    int last,tot;
    bool operator < (const node& b)const
    {
        return last < b.last;
    }
}a[256];
int n;
char buf[25010];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    scanf("%s",buf);
	    for (int i = 0;i < 256;i++)
	    {
	        a[i].tot = 0;
	        a[i].last = n;
	    }
	    for (int i = 0;i < n;i++)
        {
            a[buf[i]].tot++;
            a[buf[i]].last = i;
        }
        sort(a,a+256);
        long long res = 0;
        int last = -1;
        for (int i = 0;a[i].last < n;i++)
        {
            last += a[i].tot;
            res += (a[i].last-last)*a[i].tot;
        }
        printf("%lld\n",res*5);
	}
	return 0;
}
