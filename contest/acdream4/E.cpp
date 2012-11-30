#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

int main()
{
	while (scanf("%d",&n) != EOF)
	{
		for (int i = 30;i >= 0;i--)
			if (((n>>i)&1) == 1)
			{
				n -= (1<<i);
				n <<= 1;
				n++;
				printf("%d\n",n);
				break;
			}
	}
	return 0;
}
