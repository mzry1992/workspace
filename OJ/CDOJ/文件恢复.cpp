#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,hs[100001][3],c,f,tim[10001];

int main()
{
    scanf("%d",&n);
    memset(hs,0,sizeof(hs));
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&c);
        for (int j = 1;j <= c;j++)
        {
            scanf("%d",&f);
            hs[f][0]++;
            if (hs[f][0] <= 2)
                hs[f][hs[f][0]] = i;
        }
    }
    memset(tim,0,sizeof(tim));
    for (int i = 0;i <= 100000;i++)
    {
        if (hs[i][0] == 1)
            tim[hs[i][1]] += 2;
        else if (hs[i][0] == 2)
        {
            if (tim[hs[i][1]] <= tim[hs[i][2]])
                tim[hs[i][1]]++;
            else
                tim[hs[i][2]]++;
        }
    }
    int res = 0;
    for (int i = 1;i <= n;i++)
        res = max(res,tim[i]);
    printf("%d\n",res);
}
