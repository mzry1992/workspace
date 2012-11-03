#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

long long res;
int n,u,v,w;

set<int> num;

int f[100000];

int main()
{
    num.clear();
    for (int len = 1; len < 9; len++)
        for (int i = 0; i < (1<<len); i++)
        {
            int tnum = 0;
            for (int j = 0; j < len; j++)
                if (((i>>j)&1) == 1)
                    tnum = tnum*10+4;
                else
                    tnum = tnum*10+7;
            num.insert(tnum);
        }
    while (scanf("%d",&n) != EOF)
    {
        L = 0;
        for (int i = 0;i < n;i++)
            head[i] = -1;
        for (int i = 0;i < n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            u--;
            v--;
        }
        res = 0;
        printf("%I64d\n",res);
    }
    return 0;
}
