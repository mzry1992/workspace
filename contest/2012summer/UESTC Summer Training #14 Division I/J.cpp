#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 1<<30;
int n,m,K;
int val[1005][1005];
int dp[1005][1005],path[1005][1005];
int que[2005],head,tail;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d%d",&n,&m,&K);
	    int i,j;
	    for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&val[i][j]);
        for(i=0;i<m;i++)
        {
            dp[n-1][i]=val[n-1][i];
            path[n-1][i]=-1;
        }
        for(i=n-2;i>=0;i--)
        {
            if(2*K-1>=m)
            {
                int ma=-inf,p;
                for(j=m-1;j>=0;j--)
                {
                    if(dp[i+1][j]>=ma)
                    {
                        ma=dp[i+1][j];
                        p=j;
                    }
                }
                for(j=0;j<m;j++)
                {
                    dp[i][j]=ma+val[i][j];
                    path[i][j]=p;
                }
            }
            else
            {
                head=tail=0;
                for(j=0;j<2*K-1;j++)
                {
                    while(tail>head)
                    {
                        if(dp[i+1][j]>dp[i+1][que[tail-1]])
                            tail--;
                        else if(dp[i+1][j]==dp[i+1][que[tail-1]])
                        {
                            if(j>que[tail-1])
                                break;
                            else
                                tail--;
                        }
                        else
                            break;
                    }
                    que[tail++]=j;
                }
                dp[i][K-1]=dp[i+1][que[head]]+val[i][K-1];
                path[i][K-1]=que[head];
                for(j=K;j<K-1+m;j++)
                {
                    while(tail>head&&que[head]+K-1<j)
                        head++;
                    while(tail>head)
                    {
                        if(dp[i+1][(j+K-1)%m]>dp[i+1][que[tail-1]%m])
                            tail--;
                        else if(dp[i+1][(j+K-1)%m]==dp[i+1][que[tail-1]%m])
                        {
                            if((j+K-1)%m>que[tail-1]%m)
                                break;
                            else
                                tail--;
                        }
                        else
                            break;
                    }
                    que[tail++]=j+K-1;
                    dp[i][j%m]=dp[i+1][que[head]%m]+val[i][j%m];
                    path[i][j%m]=que[head]%m;
                }
            }
        }
        int ans=-inf,ansp;
        for(i=0;i<m;i++)
            if(dp[0][i]>ans)
            {
                ans=dp[0][i];
                ansp=i;
            }
        printf("%d %d",ans,ansp+1);
        for(i=1;i<n;i++)
        {
            printf(" %d",path[i-1][ansp]+1);
            ansp=path[i-1][ansp];
        }
        printf("\n");
	}
	return 0;
}
