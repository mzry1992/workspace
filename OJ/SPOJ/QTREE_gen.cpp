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
	int totcas = 20;
	printf("%d\n",totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
		int n = rand()%1000+9001;
		printf("%d\n",n);
		for (int i = 1;i < n;i++)
			//printf("%d %d %d\n",i+1,i,rand());
			printf("%d %d %d\n",i+1,rand()%i+1,rand());
		for (int q = 0;q < 50000;q++)
		{
			//if (q > 25000)
			if (rand()%2)
			{
				int l,r;
				while (true)
				{
					l = rand()%n+1;
					r = rand()%n+1;
					if (l != r)	break;
				}
				printf("QUERY %d %d\n",l,r);
			}
			else
				printf("CHANGE %d %d\n",rand()%(n-1)+1,rand());
		}
		puts("DONE");
	}
	return 0;
}