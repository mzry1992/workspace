#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cstdlib>

using namespace std;

typedef long long LL;

int R(int mod)
{
	return (rand()+rand()*2)%mod+1;
}

LL R(LL mod)
{
	return (rand()+LL(rand())*rand()*3ll+413432ll)%mod+1;
}

int g[310][310];

int main()
{
	int i,j;
	int n,m=35;
	srand(time(0));
	freopen("data.in","w",stdout);
	while(m--)
	{
		int i,j,k;
		n=300;
		printf("%d\n",n);
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(rand()%101)
			{
				g[i][j]=R(50000)+50000;
			}
			else
			{
				g[i][j]=R(1000)+3000;
			}
		}
		g[0][n-1]=100000;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n-1;j++) printf("%d ",g[i][j]);
			printf("%d\n",g[i][j]);
		}
	}
	return 0;
}
