#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,k,a[200][200];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i = 0;i < m;i++)
            for (int j = 0;j < n;j++)
                scanf("%d",&a[i][j]);
    }
    return 0;
}
