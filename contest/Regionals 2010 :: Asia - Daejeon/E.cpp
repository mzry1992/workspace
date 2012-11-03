#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 9999991;
struct Tree
{
    int ch[2];
    int size,key;
};
Tree tree[21];
int n,c[21][21];
int solve(int x)
{
    //printf("%d\n",x);
    if (x==20)
        return 1;
    return (long long)solve(tree[x].ch[0])*solve(tree[x].ch[1])%mod*c[tree[tree[x].ch[0]].size][tree[x].size-1]%mod;
}
int main()
{
    for (int i=0;i<=20;i++)
        c[0][i]=1;
    for (int i=1;i<=20;i++)
        for (int j=1;j<=i;j++)
            c[j][i]=c[j][i-1]+c[j-1][i-1];
    tree[20].size = 0;
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            int v;
            scanf("%d",&v);

            tree[i].size = 1;
            tree[i].key = v;
            tree[i].ch[0] = tree[i].ch[1] = 20;

            if (i > 0)
            {
                int now = 0,fa;
                while (true)
                {
                    fa = now;
                    tree[now].size++;
                    if (v < tree[now].key)
                        now = tree[now].ch[0];
                    else
                        now = tree[now].ch[1];
                    if (now == 20)
                    {
                        if (v < tree[fa].key)
                            tree[fa].ch[0] = i;
                        else
                            tree[fa].ch[1] = i;
                        break;
                    }
                }
            }

        }

        printf("%d\n",solve(0));
    }
    return 0;
}

