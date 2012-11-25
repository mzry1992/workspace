#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	freopen("G.in","w",stdout);
	for (int cas = 1;cas <= 10;cas++)
	{
		int n = 6000;
		printf("%d\n",n);
		int cnt = 0;
		for (int q = 0; q < n; ++q)
		{
			if (q%3 == 0)
			{
				printf("insert %d 1000 100 10000 1112 2223",rand()%(cnt+1));
				for (int i = 0; i < 100; ++i)
					printf(" %d",rand()%10000);
				printf("\n");
				cnt += 1000;
			}
			else if (q%3 == 1)
			{
				int l = rand()%cnt;
				int r = rand()%cnt;
				if (l > r)
					swap(l,r);
				printf("sum %d %d\n",l,r);
			}
			else
			{
				int l = rand()%cnt;
				int r = rand()%cnt;
				if (l > r)
					swap(l,r);
				printf("delete %d %d\n",l,r);
				cnt -= (r-l+1);
			}
		}
	}
	printf("0\n");
	return 0;
}
