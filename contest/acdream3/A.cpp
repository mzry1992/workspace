#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[100000],b[100000];

int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for (int i = 0;i < n;i++)
		scanf("%d",&b[i]);

	int ans = 0;
	for (int i = 0;i < 30;i++)
	{
		int cnta,cntb;
		cnta = cntb = 0;
		for (int j = 0;j < n;j++)
		{
			if (((a[j]>>i)&1) == 1)
				cnta++;
			if (((b[j]>>i)&1) == 1)
				cntb++;
		}
		if (cnta != cntb)
			ans |= (1<<i);
	}
	for (int i = 0;i < n;i++)
		a[i] = a[i]^ans;
	sort(a,a+n);
	sort(b,b+n);
	bool flag = true;
	for (int i = 0;i < n;i++)
		if (a[i] != b[i])
			flag = false;
	if (flag == false)
		ans = -1;
	printf("%d\n",ans);
	return 0;
}
