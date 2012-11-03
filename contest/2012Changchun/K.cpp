#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
long long ans,R,k;
vector<long long> cand[50];
void solve(long long x)
{
	for (int i=2;i<50;i++)
	{
		if (cand[i].empty())
			return ;
		int l=0,r=cand[i].size()-1;
		while (l<r)
		{
			int mid=l+r+1>>1;
			if (cand[i][mid]>x)
				r=mid-1;
			else
				l=mid;
		}
		if (cand[i][l]==x)
		{
			if (ans>(long long)(l+2)*i)
			{
				ans=(long long)(l+2)*i;
				R=i;
				k=l+2;
			}
		}
	}
}
int main()
{
	for (int i=2;i<=1000000;i++)
	{
		long long now=i,tot=i;
		for (int j=1;tot<=1000000000000LL;j++)
		{
			cand[j].push_back(tot);
			now*=i;
			tot+=now;
		}
	}
	long long n;
	while (scanf("%lld",&n)!=EOF)
	{
		ans=n-1;
		R=1;
		k=n-1;
		solve(n);
		solve(n-1);
		printf("%lld %lld\n",R,k);
	}
	return 0;
}
