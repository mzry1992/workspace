#include "iostream"
#include "cstdio"
#include "cstring"
#include "cstdlib"
#include "ctime"
using namespace std;

int main(int argc, char const *argv[])
{
	freopen("data.in","w",stdout);

	srand(time(0));
	
	int totcas = 1;

	for (int cas = 1; cas <= totcas; ++cas)
	{
		int n = 100000;

		printf("%d\n",n);
		for (int i = 0;i < n;i++)
			printf("%d ",rand()%10000-5000);
		for (int i = 2;i <= n;i++)
			printf("%d %d\n",i,rand()%(i-1)+1);

		int m = 100000;

		printf("%d\n",m);
		for (int i = 0;i < m;i++)
		{
			int typ;

			typ = rand()%2;
			printf("%d %d %d",typ+1,rand()%n+1,rand()%n+1);
			if (typ == 1)
				printf(" %d",rand()%10-5);
			puts("");
		}
	}
	return 0;
}