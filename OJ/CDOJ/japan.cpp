#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,k;
int tree[12000];
struct node
{
    int a,b;
}g[1200000];

bool cmp(node a,node b)
{
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}

int read(int k)
{
    int sum = 0;
    while (k > 0)
    {
        sum += tree[k];
        k -= k & -k;
    }
    return sum;
}

void updata(int k,int v)
{
    while (k <= m)
    {
        tree[k] += v;
        k += k & -k;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d%d",&n,&m,&k);
        int res = 0;
        memset(tree,0,sizeof(tree));
        for (int i = 1;i <= k;i++)
            scanf("%d%d",&g[i].a,&g[i].b);
        sort(g+1,g+1+k,cmp);
        for (int i = 1;i <= k;i++)
        {
            res += read(m-g[i].b);
            updata(m-g[i].b+1,1);
        }
        printf("Test case %d: %d\n",ft,res);
    }
}
