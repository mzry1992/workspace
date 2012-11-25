#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
bool nod[55][55];
int dir[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int turn[4]={1,2,3,0};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,m;
	    scanf("%d%d",&n,&m);
        int i;
        memset(nod,false,sizeof(nod));
        for(i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            nod[a][b]=true;
        }
        int x,y;
        scanf("%d%d",&x,&y);
        int d;
        if(x==0)
        {
            d=0;
            x=1;
        }
        else if(y==0)
        {
            d=3;
            y=1;
        }
        else if(x==n+1)
            d=2;
        else if(y==n+1)
            d=1;
        bool flag=true;
        int num=0;
        while(flag&&x>0&&x<=n+1&&y>0&&y<=n+1)
        {
            x+=dir[d][0];
            y+=dir[d][1];
            if(nod[x][y])
            {
                num++;
                if(num>4*m)
                    flag=false;
                d=turn[d];
            }
        }
        if(!flag)
            printf("0 0\n");
        else
            printf("%d %d\n",min(x,n+1),min(y,n+1));
	}
	return 0;
}
