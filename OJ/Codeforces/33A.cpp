#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,k,tm[1000],rid,ce;

int main()
{
    while (scanf("%d%d%d",&n,&m,&k) != EOF)
    {
        for (int i = 0;i < m;i++)
            tm[i] = k;
        for (int i = 0;i < n;i++)
        {
            scanf("%d%d",&rid,&ce);
            rid--;
            tm[rid] = min(tm[rid],ce);
        }
        int res = 0;
        for (int i = 0;i < m;i++)
            res += tm[i];
        res = min(res,k);
        printf("%d\n",res);
    }
    return 0;
}
