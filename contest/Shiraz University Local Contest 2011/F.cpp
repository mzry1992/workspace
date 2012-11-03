#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,a[1000],cnt[1001],tmp[1001],sum;

int main()
{
	int totcas;
	scanf("%d",&totcas);
	for (int cas = 1;cas <= totcas;cas++)
	{
        scanf("%d%d",&n,&m);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        reverse(a,a+n);
        memset(cnt,0,sizeof(cnt));
        sum = 0;
        for (int i = 0;i < m;i++)
        {
            int v;
            scanf("%d",&v);
            cnt[v]++;
            sum += v;
        }
        int res = 0;
        for (int i = 0;i < n;i++)
        {
            memset(tmp,0,sizeof(tmp));
            res += a[i];
            for (int j = 1000;j >= 1;j--)
            {
                if (cnt[j] >= a[i])
                {
                    cnt[j] -= a[i];
                    tmp[j-1] = a[i];
                    sum -= a[i];
                    a[i] = 0;
                    break;
                }
                else
                {
                    sum -= cnt[j];
                    tmp[j-1] = cnt[j];
                    a[i] -= cnt[j];
                    cnt[j] = 0;
                }
            }
            for (int j = 1;j <= 1000;j++)
                cnt[j] += tmp[j];

            //printf("i = %d res = %d\n",i,res);
        }
        res += sum;
        printf("%d\n",res);
	}
    return 0;
}

