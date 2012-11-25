#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n,a[2000],b[2000];
char mp[2000][2001];

bool check()
{
    long long tot = 0;
    for (int i = 0;i < n;i++)
        tot += a[i]*(a[i]-1)/2+b[i]*(b[i]-1)/2;
    tot = (long long)n*(long long)(n-1)*(long long)(n-2)/6-tot/2;
    return tot != 0;
}

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
	    {
            scanf("%s",mp[i]);
            a[i] = b[i] = 0;
            for (int j = 0;j < n;j++)
                if (i != j)
                {
                    if (mp[i][j] == '1')
                        a[i]++;
                    else
                        b[i]++;
                }
	    }
        printf("Case #%d: ",cas);
        if (check())
            puts("Yes");
        else
            puts("No");
	}
	return 0;
}
