#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
long long sum1[150005],sum2[150005];
long long m,a,b;
double cal(double k)
{
    return k*(k-1.0)*(k-2.0)/6.0;
}
int main()
{
	int i;
	sum1[0]=0;
	for(i=1;i<=150000;i++)
        sum1[i]=sum1[i-1]+i;
    sum2[0]=0;
    for(i=1;i<=150000;i++)
        sum2[i]=sum2[i-1]+sum1[i];
    int cas=1;
    while(1)
    {
        scanf("%lld%lld%lld",&m,&a,&b);
        if(m==0&&a==0&&b==0)
            break;
        printf("Case %d: ",cas++);
        if(m<=a)
        {
            printf("0.00\n");
            continue;
        }
        if(a<m&&m<=b)
        {
            double tmp1=(double)sum1[m-a]*(b-m)*0.1;
            double tmp2=(double)sum2[m-a]*0.1+cal(m-a+2)*0.2;
            printf("%.2f\n",(tmp1+tmp2)*2.0/(double)((b-a+2)*(b-a+1)));
        }
        else if(m>b)
        {
            double tmp=(double)sum2[b-a]*0.1+(cal(b-a+2)+sum1[b-a+1]*(m-b))*0.2;
            printf("%.2f\n",tmp*2.0/(double)((b-a+2)*(b-a+1)));
        }
    }
	return 0;
}
