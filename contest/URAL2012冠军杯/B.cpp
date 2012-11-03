#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000],out[100000];
int main()
{
	int n,s;
	scanf("%d%d",&n,&s);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	int l=0,r=n-1;
	int num=0,m=0;
	while (l<r)
	{
		if (a[l]+a[r]>s)
		{
			out[m++]=a[l++];
			out[m++]=a[r--];
			num+=2;
		}
		else
		{
			out[m++]=a[l++];
			out[m++]=a[l++];
			num++;
		}
	}
	if (l==r)
	{
		out[m++]=a[l];
		num++;
	}
	printf("%d\n",num);
	for (int i=0;i<n;i++)
		printf("%d ",out[i]);
	puts("");
	return 0;
}
