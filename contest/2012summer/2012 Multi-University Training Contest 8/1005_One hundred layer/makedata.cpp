#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

int n,m;
int N[]={10, 20, 50, 10, 10, 100, 100, 100, 100, 100};
int M[]={10, 50, 50, 100, 100, 100, 1000, 2000, 3000, 8000};

int main()
{
	int i,j,k;

	char in[]="data.in";
	freopen(in, "w", stdout);
	for(int u=0;u<10;u++)
	{
		n = N[u]; m = M[u];
		printf("%d %d %d %d\n", n, m, rand()%m+1, rand()%m+1);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<m;j++) printf("%d ", rand()%1000-500);
			printf("%d\n", rand()%1000-500);
		}
	}
	return 0;
}
