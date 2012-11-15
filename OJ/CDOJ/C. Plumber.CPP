#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

const long long mod = 1000003LL;
vector<string> g;
char buf[500010];
int n,m;

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        g.resize(n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s",buf);
            g[i] = buf;
        }
        int ud,lr;
        long long res = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
            }
        printf("%I64d\n",res);
    }
    return 0;
}
