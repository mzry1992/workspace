#include<cstdio>
#include<cstdlib>
#include<time.h>
int p,n,m,i,t,a,b,c;
int main()
{
	freopen("ain.txt","w",stdout);
	srand(time(0));
	t=1;
	printf("%d\n",t);
	while(t--)
	{
		n=10;
		m=20;
		printf("%d %d\n",n,m);
		for(i=1;i<=n;i++) printf("%d ",rand()%100-50);
		printf("\n");
		for(i=1;i<=m;i++)
		{
			p=rand()%2;
			if (p)
			{
				printf("a");
				a=0;b=n+1;
				c=rand()%100-50;
				while(a+b>n)
				{
					a=rand()%n+1;
					b=rand()%n;
				}
				printf(" %d %d %d\n",a,a+b,c);
			}
			else
			{
				printf("q");
				a=0;b=n+1;
				while(a+b>n)
				{
					a=rand()%n+1;
					b=rand()%n;
				}
				printf(" %d %d\n",a,a+b);
			}
		}
	}
}

