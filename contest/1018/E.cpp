#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        printf("%d\n",(n+1)&1);
    }
    return 0;
}

