#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int m,n,k,res,tot;

int main()
{
    while (scanf("%d%d%d",&m,&n,&k) != EOF)
    {
        res = min(m/2,n);
        k = k-(m+n-3*res);
        if (k > 0)
            res -= (k/3)+((k%3) == 0 ? 0 : 1);
        printf("%d\n",res);
    }
}
