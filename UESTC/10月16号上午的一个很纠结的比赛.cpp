#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int n;
	long long m;
	while (scanf("%d",&n)>0)
	{
		long long ans=0;
		long long ff=1;
		for (int i=1;i<=n;i++)
		{
			ff=(4*i-2)*ff/(i+1);
			//f=(((4*i-2)*f)%(m*(i+1)))/(i+1);
			//f=(((4*i-2)%(m*(i+1))/(i+1))*f)%m;
			ans=(ans+ff);
			//cout<<ans<<endl;
			//cout<<ff<<endl;
		}
		printf("%I64d\n",ans);
	}
}
