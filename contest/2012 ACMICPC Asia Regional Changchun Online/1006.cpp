#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n,a[1100],ta[1100],cnt[1100];
int L[1100],R[1100];

void remove(int pos)
{
    //printf("remove : %d\n",pos);
    L[R[pos]] = L[pos];
    R[L[pos]] = R[pos];
}

void resume(int pos)
{
    L[R[pos]] = pos;
    R[L[pos]] = pos;
}

bool DFS(int pos)
{
    //printf("pos = %d\n",pos);
    if (pos == n+1)
        return true;

    int now = R[pos];
    int pre = -1;

    for (int i = 1; i <= 5; i++)
    {
        if (now == n+1) break;
        if (a[now] == a[pos])
        {
            if (pre != a[now])
            {
                remove(pos);
                remove(now);
                if (DFS(R[0]))    return true;
                resume(now);
                resume(pos);
            }
        }
        pre = a[now];
        now = R[now];
    }
    return false;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
            ta[i] = a[i];
        }
        sort(ta,ta+n);
        int tn = unique(ta,ta+n)-ta;
        for (int i = 0; i < tn; i++)
            cnt[i] = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = lower_bound(ta,ta+tn,a[i])-ta;
            cnt[a[i]]++;
        }
        bool flag = true;
        for (int i = 0; i < tn; i++)
            if (cnt[i]%2 != 0)
                flag = false;
        if (flag == false)
        {
            puts("0");
            continue;
        }

        reverse(a,a+n);

        for (int i = n; i >= 1; i--)
            a[i] = a[i-1];
        R[0] = 1;
        L[n+1] = n;
        for (int i = 1; i <= n; i++)
        {
            L[i] = i-1;
            R[i] = i+1;
        }

        printf("%d\n",DFS(1));
    }
    return 0;
}
