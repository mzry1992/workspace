#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,hh,mm,tim,f[3000],tot[3000],ans[3000];

int findf(int x)
{
    if (f[x] != x)  f[x] = findf(f[x]);
    return f[x];
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < 1440+n;i++)
            f[i] = i;
	    for (int i = 0;i < n;i++)
	    {
	        scanf("%d",&m);
	        for (int j = 0;j < m;j++)
	        {
	            scanf("%d:%d",&hh,&mm);
	            tim = hh*60+mm;
                f[findf(1440+i)] = findf(tim);
	        }
	    }
	    for (int i = 0;i < 1440+n;i++)
            tot[i] = 0;
        for (int i = 1440;i < 1440+n;i++)
            tot[findf(i)]++;
        int cnt = 0;
        for (int i = 0;i < 1440+n;i++)
            if (tot[i] > 0)
                ans[cnt++] = tot[i];
        sort(ans,ans+cnt);
        printf("%d\n%d",cnt,ans[0]);
        for (int i = 1;i < cnt;i++)
            printf(" %d",ans[i]);
        printf("\n");
	}
	return 0;
}
