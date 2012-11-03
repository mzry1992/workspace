#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,cur[4],all[4][50001],p[4],need[50001];
struct resources
{
    int need,id;
}req[4][50001];

bool cmp(resources a,resources b)
{
    return a.need < b.need;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1;i <= m;i++)
            for (int j = 1;j <= n;j++)
                scanf("%d",&all[i][j]);
        for (int i = 1;i <= m;i++)
        {
            for (int j = 1;j <= n;j++)
            {
                scanf("%d",&req[i][j].need);
                req[i][j].id = j;
            }
            sort(req[i]+1,req[i]+1+n,cmp);
        }
        for (int i = 1;i <= m;i++)
            scanf("%d",&cur[i]);
        for (int i = 1;i <= m;i++)
            p[i] = 0;
        for (int i = 1;i <= n;i++)
            need[i] = 0;
        bool hasres = true;
        while (true)
        {
            bool flag = false;
            for (int i = 1;i <= m;i++)
                if (p[i] < n)
                    flag = true;
            if (flag == false)  break;
            flag = false;
            for (int i = 1;i <= m;i++)
                if (p[i] < n)
                    if (req[i][p[i]+1].need <= cur[i])
                    {
                        p[i]++;
                        need[req[i][p[i]].id]++;
                        flag = true;
                        if (need[req[i][p[i]].id] == m)
                        {
                            for (int j = 1;j <= m;j++)
                                cur[j] += all[j][p[i]];
                        }
                    }
            if (flag == false)
            {
                hasres = false;
                break;
            }
        }
        if (hasres == true) printf("Yes\n");
        else printf("No\n");
    }
}
