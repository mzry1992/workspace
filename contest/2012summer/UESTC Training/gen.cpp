#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "algorithm"
using namespace std;

int a[2000],c[2000];

int main(int argc, char const *argv[])
{
	freopen("data.in","w",stdout);
	srand(time(0));
	int totcas = 20;
	printf("%d\n",totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		int n = 2000;
		for (int i = 0;i < n;i++)
		{
			a[i] = i+1;
			c[i] = rand()%n+1;
		}
		random_shuffle(a,a+n);
		printf("%d\n",n);
		for (int i = 0;i < n;i++)
			printf("%d ",a[i]);
		printf("\n");
		for (int i = 0;i < n;i++)
			printf("%d ",c[i]);
		printf("\n");
	}
	return 0;
}