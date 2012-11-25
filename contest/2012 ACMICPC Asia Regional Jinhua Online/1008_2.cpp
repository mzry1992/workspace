#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,a[400001];

int main()
{
    freopen("data.in","r",stdin);
    freopen("data1.out","w",stdout);
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            a[i] = i;
        for (int i = 0;i < m;i++)
        {
            int typ;
            scanf("%d",&typ);
            if (typ == 1)
            {
                int x,y,p;
                scanf("%d%d%d",&x,&y,&p);
                long long ans = 0;
                for (int j = x;j <= y;j++)
                    if (__gcd(a[j],p) == 1)
                        ans += a[j];
                printf("%I64d\n",ans);
            }
            else
            {
                int x,c;
                scanf("%d%d",&x,&c);
                a[x] = c;
            }
        }
    }
	return 0;
}
