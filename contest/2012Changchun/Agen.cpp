#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double p[10000];

int main()
{
	freopen("A.in","w",stdout);
	for (int cas = 1;cas <= 1000;cas++)
	{
		int l = 0,r = 1000;
		for (int i = l;i <= r;i++)
			p[i] = rand()%15 == 0;
		int n = 0;
		for (int i = l;i <= r;i++)
			if (p[i])
				n++;
		int acnt = rand()%(r-l+1)+1;
		int bcnt = rand()%acnt+1;
		if (cas%2 == 0)
			acnt = bcnt = 0;
		if (cas%3 == 0)
			bcnt = 0;
		printf("%d\n%d %d\n%d %d\n",n,l,r,acnt,bcnt);
		for (int i = l;i <= r;i++)
			if (p[i])
				printf("%d ",i);
		printf("\n");
	}
    return 0;
}

