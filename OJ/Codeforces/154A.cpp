#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while (scanf("%d%d",&n,&m) != EOF)
	{
		if (n < m)
		{
			for (int i = 0;i < n;i++)
				printf("GB");
			for (int i = n;i < m;i++)
				printf("G");
		}
		else
		{
			for (int i = 0;i < m;i++)
				printf("BG");
			for (int i = m;i < n;i++)
				printf("B");
		}
		printf("\n");
	}
	return 0;
}
