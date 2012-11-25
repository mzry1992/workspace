#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+20;
double a[maxn],b[maxn],sum[maxn],maxs[maxn];

int main()
{
	freopen("B.in","r",stdin);
	freopen("B4.out","w",stdout);

    int N;
    double X,Y;

    while(scanf("%d%lf%lf",&N,&X,&Y)==3)
    {
        for(int i=1;i<=N;i++)
            scanf("%lf%lf",&a[i],&b[i]);
        sum[N+1]=0;
        maxs[N+1]=1e100;
        for(int i=N;i>0;i--)
        {
            sum[i]=sum[i+1]+b[i];
            double now=(a[i]-sum[i]);
            maxs[i]=min(maxs[i+1],now);
        }

        for(int i=1;i<=N;i++)
        {
            if ((sum[i]+maxs[i+1]>a[i]&&sum[i]>a[i])||(b[i]>a[i]))
            {
                //printf("i=%d ",i);
                double t=X/a[i];
                Y+=t;
                X=0;
            }
            X+=Y*b[i];
        }
        printf("%.2f\n",X);
    }
    return 0;
}
