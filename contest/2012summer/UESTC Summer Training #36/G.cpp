#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k;
char ans[405][405];
int main()
{
	while(scanf("%d%d",&n,&k)==2)
    {
        memset(ans,'.',sizeof(ans));
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                int a=i*n+j;
                int st=j*n+i;
                int b;
                for(b=st;b<st+k;b++)
                    ans[a][b%(n*n)]='*';
            }
        for(i=0;i<n*n;i++)
        {
            for(j=0;j<n*n;j++)
                printf("%c",ans[i][j]);
            printf("\n");
        }
    }
	return 0;
}
