#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c,res=0,k;
	int d[100][100];
	int s[101],a[100];
	while(scanf("%d",&c)==1)
	{
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<c;j++)
			{
				scanf("%d",&d[i][j]);
			}
		}
		for(int i=0;i<c;i++)
		{
			for(int j=(i+1);j<c;j++)
			{
				s[0]=0;
				for(int l=0;l<100;l++)
				{
					a[l]=0;
					s[l]=0;
				}
				for(k=0;k<c;k++)
				{
					for(int m=i;m<=j;m++)
						a[k]+=d[m][k];
					if(s[k]>=0)
						s[k+1]=s[k]+a[k];
					else
						s[k+1]=a[k];
				}
				for(int i=0;i<k;i++)
				{
					if(res<s[i])
						res=s[i];
				}
			}
		}
		printf("%d",res);
	}
}
