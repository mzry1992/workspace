#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
long long res;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        res = 0;
        int tb = n-m;
        int ta = m-1;
        res = 1+(long long)ta*(long long)(tb);
        printf("Case #%d: %lld\n",ft,res);
    }
}
