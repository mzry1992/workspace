#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int r[600000];
int x[1000],y[1000];
int n;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d%d",&x[i],&y[i]);
        int tot = 0;
        for (int i = 0;i < n;i++)
            for (int j = i+1;j < n;j++)
                r[tot++] = (x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]);
        sort(r,r+tot);
        tot = unique(r,r+tot)-r;
        printf("Case %d: %d\n",cas,tot+1);
	}
    return 0;
}
