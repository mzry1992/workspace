#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,l,s;
int a[100];

int main()
{
	while (scanf("%d%d%d",&n,&l,&s) != EOF)
	{
		for (int i = 0;i < n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		n = unique(a,a+n)-a;
		for (int i = 0;i < n;i++)
			printf("%.10f\n",(double)(l+a[i]+s)/2.0);
	}
    return 0;
}

