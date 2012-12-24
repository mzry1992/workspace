#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,k;
int q[100],m[100],p[100],tp[100];

bool chk(int a[],int b[])
{
	for (int i = 0;i < n;i++)
		if (a[i] != b[i])
			return false;
	return true;
}
int p0[100],p1[100];
bool check()
{
	for (int i = 0;i < n;i++)
		p[i] = i;
	if (chk(p,m) == true)
		return false;

	for (int i = 0;i < n;i++)
	{
		p0[i] = p[q[i]];
		p1[q[i]] = p[i];
	}
	if (chk(p0,p1) == true && chk(p0,m) == true)
		return k == 1;

	bool res = false;
	for (int tim = 0;tim <= k;tim++)
	{
		if (chk(p,m) == true)
		{
			if ((k-tim)%2 == 0)
				res = true;
			break;
		}
		for (int i = 0;i < n;i++)
			tp[i] = p[q[i]];
		for (int i = 0;i < n;i++)
			p[i] = tp[i];
	}

	for (int i = 0;i < n;i++)
		p[i] = i;
	for (int tim = 0;tim <= k;tim++)
	{
		if (chk(p,m) == true)
		{
			if ((k-tim)%2 == 0)
				res = true;
			break;
		}
		for (int i = 0;i < n;i++)
			tp[q[i]] = p[i];
		for (int i = 0;i < n;i++)
			p[i] = tp[i];
	}
	return res;
}

int main()
{
	while (scanf("%d%d",&n,&k) != EOF)
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&q[i]);
			q[i]--;
		}
		for (int i = 0;i < n;i++)
		{
			scanf("%d",&m[i]);
			m[i]--;
		}
		if (check())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
