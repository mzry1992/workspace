#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,xa[10],xb[10],ya[10],yb[10];
int ans[10],id;

bool read(int above,int l,int r)
{
    int vie = -1;
    for (int i = 0; i < n; i++)
        if (ans[i] == -1 && yb[i] <= above && xa[i] >= l && xb[i] <= r)
        {
            if (vie == -1 || (xa[i] < xa[vie] || (xa[i] == xa[vie] && ya[i] < ya[vie])))
                vie = i;
        }
    if (vie == -1)  return false;

    ans[vie] = id++;

    int nowl = xa[vie],nowabove = yb[vie];
    int nowr = 500;
    for (int i = 0; i < n; i++)
        if (yb[i] > nowabove && ya[i] < nowabove && xa[i] <= xb[vie])
            nowr = min(nowr,xa[i]);

    while (read(nowabove,nowl,nowr));
    return true;
}

int main()
{
    bool first = true;
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;

        if (!first)
            puts("");
        first = false;

        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d",&xa[i],&ya[i],&xb[i],&yb[i]);
            if (xa[i] > xb[i])
                swap(xa[i],xb[i]);
            if (ya[i] > yb[i])
                swap(ya[i],yb[i]);
            ans[i] = -1;
        }

        id = 1;
        while (read(500,0,500));

        for (int i = 0; i < n; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
