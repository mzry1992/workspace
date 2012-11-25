#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[100001];
long long tree[100001],f[100001];

long long read(int k)
{
    long long sum = 0;
    for (;k;k^=k&-k)
        sum += tree[k];
    return sum;
}

void updata(int k,int v = 1)
{
    for (;k <= 100000;k+=k&-k)
        tree[k] += v;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = n-1;i >= 0;i--)
            scanf("%d",&a[i]);
        memset(tree,0,sizeof(tree));
        for (int i = 0;i < n;i++)
        {
            f[i] += read(a[i]-1);
            updata(a[i]);
        }
        memset(tree,0,sizeof(tree));
        long long res = 0;
        for (int i = 0;i < n;i++)
        {
            res += read(a[i]-1);
            updata(a[i],f[i]);
        }
        printf("%lld\n",res);
    }
	return 0;
}
