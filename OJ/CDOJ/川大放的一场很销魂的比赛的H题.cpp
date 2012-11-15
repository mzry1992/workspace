#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int n,a[20100];
int tree[300000];
int minl[20100],minr[20100],maxl[20100],maxr[20100];

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
    while (k <= 100000)
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
        scanf("%d",&n);
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        memset(tree,0,sizeof(tree));
        for (int i = 1;i <= n;i++)
        {
            minl[i] = read(a[i]);
            maxl[i] = i-1-minl[i];
            updata(a[i],1);
        }
        memset(tree,0,sizeof(tree));
        for (int i = n;i >= 1;i--)
        {
            minr[i] = read(a[i]);
            maxr[i] = n-i-minr[i];
            updata(a[i],1);
        }
        long long ans = 0;
        for (int i = 1;i <= n;i++)
            ans += minl[i]*maxr[i]+maxl[i]*minr[i];
        printf("%lld\n",ans);
    }
}
