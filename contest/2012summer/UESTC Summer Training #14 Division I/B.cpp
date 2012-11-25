#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[1100],b[1100];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	while (totcas--)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for (int i = 0;i < m;i++)
            scanf("%d",&b[i]);
        int res = abs(a[0]-b[0]);
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                res = min(res,abs(a[i]-b[j]));
        printf("%d\n",res);
	}
	return 0;
}
