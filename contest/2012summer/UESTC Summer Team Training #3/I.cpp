#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
const double inf = 1ll<<60;
int n,m,num,sum;
double dis[500][500];
int main()
{
	while(scanf("%d%d",&n,&m)==2)
	{
	    n++;m++;
	    scanf("%d",&num);
	    int i,j;
	    for(i=0;i<n*m;i++)
            for(j=0;j<n*m;j++)
            {
                if(i!=j)
                    dis[i][j]=inf;
                else
                    dis[i][j]=0;
            }
	    for(i=0;i<num;i++)
	    {
	        int a,b,c,d;
	        double x;
	        scanf("%d%d%d%d%lf",&a,&b,&c,&d,&x);
	        int u,v;
	        u=a*m+b;
	        v=c*m+d;
	        if(a==c||b==d)
	        {
                dis[u][v]=min(dis[u][v],1.0/x);
                dis[v][u]=dis[u][v];
	        }
            else
            {
                dis[u][v]=min(dis[u][v],sqrt(2.0)/x);
                dis[v][u]=dis[u][v];
            }
	    }
	    for(i=0;i<n-1;i++)
            for(j=0;j<m-1;j++)
            {
                int tmp=i*m+j;
                if(dis[tmp][tmp+m+1]<inf&&dis[tmp+1][tmp+m]<inf)
                {
                    double a=dis[tmp][tmp+m+1],b=dis[tmp+1][tmp+m];
                    dis[tmp][tmp+1]=min(dis[tmp][tmp+1],(a+b)/2.0);
                    dis[tmp][tmp+m]=min(dis[tmp][tmp+m],(a+b)/2.0);
                    dis[tmp+1][tmp+m+1]=min(dis[tmp+1][tmp+m+1],(a+b)/2.0);
                    dis[tmp+m][tmp+m+1]=min(dis[tmp+m][tmp+m+1],(a+b)/2.0);
                }
            }
	    sum=n*m;
	    int k;
	    for(k=0;k<n*m;k++)
            for(i=0;i<n*m;i++)
                for(j=i;j<n*m;j++)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    dis[j][i]=dis[i][j];
                }
        double l,r,mid;
        l=0;r=inf;
        for(i=0;i<100;i++)
        {
            mid=(l+r)/2.0;
            bool flag=false;
            int num;
            for(j=0;j<n*m;j++)
            {
                num=0;
                for(k=0;k<n*m;k++)
                    if(dis[j][k]<=mid)
                        num++;
                if(num>sum/2)
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
                r=mid;
            else
                l=mid;
        }
        printf("%.3f\n",mid);
	}
	return 0;
}
