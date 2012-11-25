#include"iostream"
#include"cstring"
#include"cstdio"
#include"algorithm"
#include"cmath"
#include"stack"
#include"queue"
#include"vector"
#include"map"
#include"ctime"
#include"set"
#define int_max 0x7fffffff
#define ll_max 0x7fffffffffffffffLL
#define fr first
#define se second
typedef long long ll;
typedef unsigned long long llu;
using namespace std;
double dp[123456],sum[123456];
double qq[123456][2];
int st[123456];
double a[123456],b[123456];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B3.out","w",stdout);
	int n,x,y;
	while(~scanf("%d %d %d",&n,&x,&y))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lf %lf",&a[i],&b[i]);
			sum[i]=sum[i-1]+b[i];
		}


		int he=1,ta=0;
        st[ta]=0;
		double ans=sum[n]*y+x,dy,dx;
		for(int i=1;i<=n;i++)
		{
			double k=sum[i-1]+a[i];
			while(he<ta&&(qq[he][1]-qq[he+1][1])<(qq[he][0]-qq[he+1][0])*k)he++;
			dp[i]=(y*sum[i-1]+x)/a[i]+y;
			if(he<=ta)
            dp[i]=max(dp[i],dp[st[he]]*(sum[i-1]-sum[st[he]-1]+a[i])/a[i]);
			dy=dp[i]*sum[i-1];
			dx=dp[i];
			while(he<ta&&(dy-qq[ta][1])*(qq[ta][0]-qq[ta-1][0])<(qq[ta][1]-qq[ta-1][1])*(dx-qq[ta][0]))
            --ta;
            ++ta;
            qq[ta][0]=dx;
            qq[ta][1]=dy;
            st[ta]=i;
            ans=max(ans,dp[i]*(sum[n]-sum[i-1]));
		}
		printf("%.2f\n",ans);
	}
}
