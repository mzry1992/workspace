#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int inf = 1<<30;
int n;
struct N
{
    int x,y;
}line[105];
int dp[2][200005][2];
char s[1000];
double ans;
double dist(double a,double b)
{
    return sqrt(a*a+b*b);
}
int main()
{
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0)
            break;
        int i;
        for(i=0;i<n;i++)
            scanf("%d%d",&line[i].x,&line[i].y);
        for(i=0;i<=200000;i++)
        {
            dp[0][i][0]=-inf;
            dp[0][i][1]=inf;
            dp[1][i][0]=-inf;
            dp[1][i][1]=inf;
        }
        int j,maxx=0,st=100000;
        dp[1][st][0]=dp[1][st][1]=0;
        for(i=0;i<n;i++)
        {
            for(j=st-maxx;j<=st+maxx;j++)
            {
                dp[i%2][j][0]=-inf;
                dp[i%2][j][1]=inf;
            }
            for(j=st-maxx;j<=st+maxx;j++)
            {
                if(dp[(i+1)%2][j][0]>-inf)
                {
                    dp[i%2][j-line[i].x][0]=max(dp[i%2][j-line[i].x][0],dp[(i+1)%2][j][0]-line[i].y);
                    dp[i%2][j+line[i].x][0]=max(dp[i%2][j+line[i].x][0],dp[(i+1)%2][j][0]+line[i].y);
                }
                if(dp[(i+1)%2][j][1]<inf)
                {
                    dp[i%2][j-line[i].x][1]=min(dp[i%2][j-line[i].x][0],dp[(i+1)%2][j][1]-line[i].y);
                    dp[i%2][j+line[i].x][1]=min(dp[i%2][j+line[i].x][0],dp[(i+1)%2][j][1]+line[i].y);
                }
            }
            maxx+=abs(line[i].x);
        }
        ans=0;
        for(i=st-maxx;i<=st+maxx;i++)
        {
            if(dp[(n-1)%2][i][0]>-inf)
                ans=max(ans,dist(i-st,dp[(n-1)%2][i][0]));
            if(dp[(n-1)%2][i][1]<inf)
                ans=max(ans,dist(i-st,dp[(n-1)%2][i][1]));
        }
        sprintf(s,"%.4f",ans+1e-6);
        int l=strlen(s);
        if (s[l-1]<'5')
        {
            s[l-1]=0;
            puts(s);
            continue;
        }
        for (int i=l-2;i>=0;i--)
        {
            if (s[i]=='.')
                continue;
            s[i]++;
            if (s[i]<='9')
                break;
            else
            {
                s[i]='0';
                if (!i)
                    putchar('1');
            }
        }
        s[l-1]=0;
        puts(s);
	}
	puts("");
	return 0;
}
