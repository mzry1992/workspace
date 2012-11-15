#include<cstdio>
#include<cstdlib>
#include<time.h>
int f[15],i,j,t;
int main()
{
	srand(time(0));
	freopen("din.txt","w",stdout);
	t=50;
	printf("%d\n",t);
	for(i=0;i<t;i++)
	{
		printf("1000\n");
		for(j=0;j<1000;j++)
		{
			printf("%d ",rand()%2000+1);
		}
		printf("\n");
	}
}
