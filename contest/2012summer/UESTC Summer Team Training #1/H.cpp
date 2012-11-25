#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[1000][1000];

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
	    scanf("%d",&n);
	    for (int i = 0;i < n;i++)
            for (int j = 1;j < n-i;j++)
            {
                scanf("%d",&a[i][i+j]);
                a[i+j][i] = a[i][i+j];
            }
        long long res = 0;
        for (int i = 0;i < n;i++)
        {
            int cnt0 = 0,cnt1 = 0;
            for (int j = 0;j < n;j++)
                if (j != i)
                {
                    if (a[i][j] == 0)
                        cnt0++;
                    else
                        cnt1++;
                }
            //cout << i << ' ' << cnt0 << ' ' << cnt1 << endl;
            res += cnt0*cnt1;
        }
        res /= 2;
        res = (long long)n*(n-1)*(n-2)/6-res;
        printf("%lld\n",res);
	}
	return 0;
}
