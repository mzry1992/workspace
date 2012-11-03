#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n,m;
struct rank
{
    int pos,rank;
}p[200];

bool cmp(rank a,rank b)
{
    return a.pos > b.pos;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        for (int i = 1;i <= n;i++)
            scanf("%d%d",&p[i].pos,&p[i].rank);
        sort(p+1,p+n+1,cmp);
        bool flag = true;
        for (int i = 1;i < n;i++)
        for (int j = i+1;j <= n;j++)
        {
            bool kflag = true;
            for (int k = i+1;k <= j;k++)
            if (p[k-1].rank < p[k].rank)
                kflag = false;
            if (kflag == true)
            {
                if (j-i+1 > m/400+1)
                    flag = false;
                if (j-i+1 == m/400+1)
                    if (p[j].pos >= m%400)
                        flag = false;
            }
        }
        if (flag)
            puts("YES");
        else
            puts("NO");
    }
}
