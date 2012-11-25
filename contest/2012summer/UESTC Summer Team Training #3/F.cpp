#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,b,g;
int sum[105][2005];
int sex[105][2005];
int neg[105][2005];
int main()
{
	while(scanf("%d%d%d%d",&n,&m,&b,&g)==4)
	{
        int i,j;
        for(j=1;j<=m;j++)
        {
            sum[0][j]=0;
            sex[0][j]=0;
            neg[0][j]=0;
        }
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                int a,b;
                scanf("%d%d",&a,&b);
                sum[i][j]=sum[i-1][j]+a;
                sex[i][j]=sex[i-1][j];
                if(b==1)
                    sex[i][j]++;
                neg[i][j]=neg[i-1][j];
                if(a<0)
                    neg[i][j]++;
            }
        int k;
        int k1,k2,ans=-1,ret;
        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
            {
                ret=0;
                k1=k2=0;
                for(k=1;k<=m;k++)
                {
                    if(neg[j][k]-neg[i-1][k]==0)
                    {
                        ret+=sum[j][k]-sum[i-1][k];
                        k1+=sex[j][k]-sex[i-1][k];
                        k2+=(j-i+1)-(sex[j][k]-sex[i-1][k]);
                    }
                    else
                    {
                        if(k1>=b&&k2>=g)
                            ans=max(ans,ret);
                        ret=k1=k2=0;
                    }
                }
                if(k1>=b&&k2>=g)
                    ans=max(ans,ret);
            }
        if(ans==-1)
            printf("No solution!\n");
        else
            printf("%d\n",ans);
	}
	return 0;
}
