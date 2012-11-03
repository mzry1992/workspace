#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int mp[10][10];
int s[100];
int dir[4][2]={{1,-1},{1,1},{-1,1},{-1,-1}};
int main()
{
	int n;
	while(scanf("%d",&n)==1)
    {
    	int i,j;
    	for(i=0;i<n*n;i++)
			scanf("%d",&s[i]);
		sort(s,s+n*n);
		int a,b,pos=n*n-1,k=0;
		a=b=n/2;
		memset(mp,-1,sizeof(mp));
		mp[a][b]=s[pos--];
		a--;
		while(pos>=0)
		{
			if(a>=0&&a<n&&b>=0&&b<n)
				mp[a][b]=s[pos--];
			a+=dir[k][0];
			b+=dir[k][1];
			if(b==n/2&&a<n/2)
				a--;
			if(a==n/2||b==n/2)
				k++;
			k%=4;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(j==0)
					printf("%d",mp[i][j]);
				else
					printf(" %d",mp[i][j]);
			}
			printf("\n");
		}
    }
    return 0;
}

