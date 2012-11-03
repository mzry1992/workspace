#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,nim,m,l;

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        nim = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&m,&l);
            nim = nim^(m%l);
        }
        if (nim != 0)   printf("Yes\n");
        else printf("No\n");
    }
}
