#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,k;
int mp[1005][1005];
int high[1005][1005][4];
int sta[1005],top,ans;
int main()
{
	int t,cas=1;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d%d",&n,&m,&k);
	    int i,j;
	    for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&mp[i][j]);
        for(j=1;j<=m;j++)
        {
            high[1][j][0]=1;
            high[1][j][1]=1;
            if(j+1<=m&&abs(mp[1][j]-mp[1][j+1])<=k)
            {
                high[1][j][2]=1;
                high[1][j][3]=1;
            }
            else
            {
                high[1][j][2]=0;
                high[1][j][3]=0;
            }
        }
        for(j=1;j<=m;j++)
            for(i=2;i<=n;i++)
            {
                if(abs(mp[i][j]-mp[i-1][j])<=k)
                {
                    high[i][j][0]=high[i-1][j][0]+1;
                    high[i][j][1]=high[i-1][j][1]+1;
                    if(j+1<=m&&abs(mp[i][j]-mp[i][j+1])<=k)
                    {
                        high[i][j][2]=high[i-1][j][2]+1;
                        high[i][j][3]=high[i-1][j][3]+1;
                    }
                    else
                    {
                        high[i][j][2]=0;
                        high[i][j][3]=0;
                    }
                }
                else
                {
                    high[i][j][0]=1;
                    high[i][j][1]=1;
                    if(j+1<=m&&abs(mp[i][j]-mp[i][j+1])<=k)
                    {
                        high[i][j][2]=1;
                        high[i][j][3]=1;
                    }
                    else
                    {
                        high[i][j][2]=0;
                        high[i][j][3]=0;
                    }
                }
            }
        ans=0;
        for(i=1;i<=n;i++)
        {
            top=0;
            for(j=1;j<=m;j++)
            {
                ans=max(ans,high[i][j][0]);
                while(top&&high[i][j][2]<=high[i][sta[top-1]][2])
                {
                    int tmp;
                    if(high[i][sta[top-1]][2]<=high[i][j][0])
                    {
                        tmp=high[i][sta[top-1]][2]*(j-sta[top-1]);
                        tmp+=high[i][sta[top-1]][3];
                        ans=max(ans,tmp);
                        high[i][j][3]+=high[i][j][2]*(high[i][sta[top-1]][3]/high[i][sta[top-1]][2]);
                    }
                    else
                    {
                        tmp=high[i][j][0]*(high[i][sta[top-1]][3]/high[i][sta[top-1]][2]);
                        tmp+=high[i][j][1];
                        ans=max(ans,tmp);
                        high[i][j][1]=tmp;
                        high[i][j][3]+=high[i][j][2]*(high[i][sta[top-1]][3]/high[i][sta[top-1]][2]);
                    }
                    top--;
                }
                if(high[i][j][2]>0)
                    sta[top++]=j;
            }
            while(top)
            {
                int tmp;
                tmp=high[i][sta[top-1]][2]*(m-sta[top-1]);
                tmp+=high[i][sta[top-1]][3];
                ans=max(ans,tmp);
                top--;
            }
        }
        printf("Case %d: %d\n",cas++,ans);
	}
	return 0;
}
