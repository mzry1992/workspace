#include "iostream"
#include "cstdio"
#include "cstdlib"
#include "ctime"
using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(0));
	freopen("N.in","w",stdout);

	int n = 10,m = 1000;
	printf("%d %d\n",n,m);
	for (int i = 0;i < n;i++)
		printf("%d ",rand()%20-10);
	printf("\n");
	for (int i = 0;i < m;i++)
	{
		int id = rand()%6;
		if (n < 2)	id = 0;
		if (id == 0)
		{
			printf("INSERT ");
			int pos = rand()%(n+1);
			int tot = rand()%10+1;
			printf("%d %d",pos,tot);
			for (int j = 0;j < tot;j++)
				printf(" %d",rand()%20-10);
			printf("\n");
			n += tot;
		}
		else if (id == 1)
		{
			printf("DELETE ");
			int pos = rand()%n+1;
			int posr = rand()%n+1;
			if (pos > posr)	swap(pos,posr);
			printf("%d %d\n",pos,posr-pos+1);
			n -= posr-pos+1;
		}
		else if (id == 2)
		{
			printf("MAKE-SAME ");
			int pos = rand()%n+1;
			int posr = rand()%n+1;
			if (pos > posr)	swap(pos,posr);
			printf("%d %d %d\n",pos,posr-pos+1,rand()%20-10);
		}
		else if (id == 3)
		{
			printf("REVERSE ");
			int pos = rand()%n+1;
			int posr = rand()%n+1;
			if (pos > posr)	swap(pos,posr);
			printf("%d %d\n",pos,posr-pos+1);
		}
		else if (id == 4)
		{
			printf("GET-SUM ");
			int pos = rand()%n+1;
			int posr = rand()%n+1;
			if (pos > posr)	swap(pos,posr);
			printf("%d %d\n",pos,posr-pos+1);
		}
		else
			puts("MAX-SUM");
	}
	return 0;
}