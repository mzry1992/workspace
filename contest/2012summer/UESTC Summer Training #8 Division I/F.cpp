#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const double inf = 1e10;
int n;
struct N
{
    int x,y;
    int s;
    double dis;
}nod[50];
double val;
char name[105];
double dp[35][6005];
double dist(double a,double b)
{
    return sqrt(a*a+b*b);
}
int main()
{
    int cas=1;
	while(scanf("%d",&n)&&n)
	{
	    int i,j,k;
	    for(i=1;i<=n;i++)
	    {
	        scanf("%d%d%d",&nod[i].x,&nod[i].y,&nod[i].s);
            nod[i].dis=dist(nod[i].x,nod[i].y);
	    }
	    for(i=1;i<=n;i++)
	    {
	        for(j=6000;j>=0;j--)
	        {
	            if(j<=nod[i].s)
                    dp[i][j]=nod[i].dis;
                else
                    dp[i][j]=inf;
	        }
	        for(j=1;j<i;j++)
	        {
	            double tmp=dist(nod[i].x-nod[j].x,nod[i].y-nod[j].y);
	            for(k=6000-nod[i].s;k>=0;k--)
                    dp[i][k+nod[i].s]=min(dp[i][k+nod[i].s],dp[j][k]+tmp);
	        }
	    }
        printf("Race %d\n",cas++);
        while(1)
        {
            memset(name,0,sizeof(name));
            scanf("%s %lf",name,&val);
            if(strlen(name)==1&&name[0]=='#'&&val==0)
                break;
            int ans=0;
            for(i=1;i<=n;i++)
            {
                for(j=6000;j>=0;j--)
                    if(dp[i][j]+nod[i].dis<=val)
                        break;
                ans=max(ans,j);
            }
            printf("%s: %d\n",name,ans);
        }
	}
	return 0;
}
