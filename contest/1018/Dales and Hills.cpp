#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[1000000],pre[1000000],nxt[1000000];

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        for (int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        int highest,deepest;
        highest = deepest = 0;
        pre[0] = 0;
        for (int i = 1;i < n;i++)
            if (a[i] > a[i-1])
                pre[i] = pre[i-1];
            else
                pre[i] = i;
        nxt[n-1] = n-1;
        for (int i = n-2;i >= 0;i--)
            if (a[i] > a[i+1])
                nxt[i] = nxt[i+1];
            else
                nxt[i] = i;
        for (int i = 0;i < n;i++)
            highest = max(highest,min(i-pre[i],nxt[i]-i));
        pre[0] = 0;
        for (int i = 1;i < n;i++)
            if (a[i] < a[i-1])
                pre[i] = pre[i-1];
            else
                pre[i] = i;
        nxt[n-1] = n-1;
        for (int i = n-2;i >= 0;i--)
            if (a[i] < a[i+1])
                nxt[i] = nxt[i+1];
            else
                nxt[i] = i;
        for (int i = 0;i < n;i++)
            deepest = max(deepest,min(i-pre[i],nxt[i]-i));
        printf("%d %d\n",highest,deepest);
    }
    return 0;
}
