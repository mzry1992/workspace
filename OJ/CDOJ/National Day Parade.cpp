#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> y[57];
int tx,ty;

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        for (int i = 1;i <= n;i++)
            y[i].clear();
        for (int i = 0;i < n*n;i++)
        {
            scanf("%d%d",&tx,&ty);
            y[tx].push_back(ty);
        }
        for (int i = 1;i <= n;i++)
            sort(y[i].begin(),y[i].end());
        int res = 199210050;
        for (int i = 1;i <= m-n+1;i++)
        {
            int tres = 0;
            for (int j = 1;j <= n;j++)
            {
                for (int k = 0;k < n;k++)
                    tres += abs(i+k-y[j][k]);
            }
            res = min(res,tres);
        }
        printf("%d\n",res);
    }
    return 0;
}
