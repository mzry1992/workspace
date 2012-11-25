#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int tree[50001];
int n;

void update(int k,int v)
{
    for (;k <= n;k += k&-k)
        tree[k] += v;
}

int find_Kth(int k)
{
    int idx = 0;
    for (int i = 20;i >= 0;i--)
    {
        idx |= 1<<i;
        if (idx <= n && tree[idx] < k)
            k -= tree[idx];
        else
            idx ^= 1<<i;
    }
    return idx+1;
}

int a[50001];

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        memset(tree,0,sizeof(tree));
        for (int i = 1;i <= n;i++)
            update(i,1);
        for (int i = 0;i < n;i++)
        {
            int pos;
            scanf("%d",&pos);
            a[i] = find_Kth(pos);
            update(a[i],-1);
        }
        int m;
        scanf("%d",&m);
        for (int i = 0;i < m;i++)
        {
            int pos;
            scanf("%d",&pos);
            if (i > 0)
                printf(" ");
            printf("%d",a[pos-1]);
        }
        puts("");
    }
	return 0;
}
