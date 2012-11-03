#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1<<29;
int len[901][8101];
int last[901][8101];
vector<int> q;
int main()
{
	int i,j,k;
	for(i=0;i<=900;i++)
		for(j=0;j<=8100;j++)
			len[i][j]=inf;
	len[0][0]=last[0][0]=0;
	for(i=0;i<=900;i++)
		for(j=0;j<=8100;j++)
			for(k=0;k<=9;k++)
				if(i+k<=900&&j+k*k<=8100)
				{
					if(len[i][j]+1<len[i+k][j+k*k])
					{
						len[i+k][j+k*k]=len[i][j]+1;
						last[i+k][j+k*k]=k;
					}
					else if(len[i][j]+1==len[i+k][j+k*k])
						if(last[i+k][j+k*k]>k)
							last[i+k][j+k*k]=k;
				}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a > 900 || b > 8100 || len[a][b] > 100)
		{
			printf("No solution\n");
			continue;
		}
		q.clear();
		while(a&&b)
		{
			q.push_back(last[a][b]);
			k=a;
			a-=last[k][b];
			b-=last[k][b]*last[k][b];
		}
		for(i=0;i<q.size();i++)
			printf("%d",q[i]);
		printf("\n");
	}
    return 0;
}

