#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long pre[64],cnt[64];

int main()
{
    pre[0] = 0;
    cnt[0] = 1;
    for (int i = 1;i < 52;i++)
    {
        cnt[i] = (1LL<<i);
        pre[i] = pre[i-1]*2+(1LL<<(i-1));
        //printf("%d %lld %lld\n",i,pre[i],cnt[i]);
    }
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        long long n;
        scanf("%lld",&n);
        long long res = 0;
        for (int i = 0;i < 52;i++)
        {
            if (cnt[i] >= n)
            {
            //printf("%lld %lld\n",n,res);
                int more = 0;
                for (int j = i-1;j >= 0;j--)
                {
                    if (n > cnt[j])
                    {
                        res += pre[j]+more*cnt[j];
                        n -= cnt[j];
                        more++;
                    }
                    //printf("%lld %lld %d %d\n",n,res,j,more);
                }
                res += more;
                break;
            }
            res += pre[i];
            n -= cnt[i];
        }
        printf("Case %d: %lld\n",cas,res);
    }
	return 0;
}
