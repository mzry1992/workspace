#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int fa[20];
int n;
bool sg[1<<20];
bool flag[1<<20];

bool SG(int now)
{
    printf("now = %d\n",now);
    if (flag[now] == true)  return sg[now];
    bool& res = sg[now];
    flag[now] = true;

    for (int i = 0;i < n;i++)
        if (((now>>i)&1) == 0)
        {
            int nxt = now,pos = i;
            while (true)
            {
                nxt |= 1<<pos;
                pos = fa[pos];
                if (pos == -1 || (((now>>pos)&1) == 1))
                    break;
            }
            if (SG(nxt) == false)
                return res = true;
        }
    return res = false;
}

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%d",&fa[i]);
        memset(flag,false,sizeof(flag));
        flag[(1<<n)-1] = true;
        sg[(1<<n)-1] = false;
        printf("%s\n",SG(0)?"alice":"bob");
    }
    return 0;
}

