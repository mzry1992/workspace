#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

long long a,b;
long long mut[500000];
int cnt;
long long mutb[500000];
int cntb;

int main()
{
    while (scanf("%lld%lld",&a,&b) != EOF)
    {
        if (a == b)
        {
            printf("%lld\n",a,b);
            continue;
        }
        if ((a*b)%(a+b) == 0)
        {
            printf("%lld %lld\n",a,b);
            continue;
        }
        long long ta,tb,gcd;
        ta = a;
        tb = b;
        gcd = __gcd(a,b);
        ta /= gcd;
        tb /= gcd;

        cnt = 0;
        for (int i = 2;i*i <= a;i++)
            if (a%i == 0)
            {
                long long tmp = i;
                if (tmp-1 != 1 && __gcd(tmp-1,tb) != 1)
                    mut[cnt++] = tmp-1;
                if (i*i < a)
                {
                    tmp = a/i;
                    if (tmp-1 != 1 && __gcd(tmp-1,tb) != 1)
                        mut[cnt++] = tmp-1;
                }
            }
        sort(mut,mut+cnt);

        printf("%lld ",a);
        for (int i = cnt-1;i >= 0;i--)
            if (__gcd(mut[i],tb) != 1)
            {
                a = a*mut[i];
                printf("%lld ",a);
                gcd = __gcd(mut[i],tb);
                tb /= gcd;
            }
        while (a != b)
        {
            ta = a/b;
            //cout << ta << endl;
            for (int j = 2;j*(j+1) <= a;j++)
                if (a%(j*(j+1)) == 0)
                {
                    a = a/j;
                    printf("%lld ",a);
                    break;
                }
        }
        printf("%lld\n",b);
    }
	return 0;
}
