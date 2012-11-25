#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

long long a,b;

long long calc(long long pos)
{
    if (pos < 3)
        return 0;
    long long tmp = (long long)sqrt(1.0*pos);
    if (tmp%2 == 1) tmp--;
    long long res = pos/2-tmp/2;
    tmp = (long long)sqrt(1.0*pos);
    if (tmp%2 == 0) tmp--;
    res += (tmp+1)/2;
    return res-2;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1;cas <= totcas;cas++)
    {
        scanf("%I64d%I64d",&a,&b);
        printf("%I64d\n",calc(b)-calc(a-1));
    }
	return 0;
}
