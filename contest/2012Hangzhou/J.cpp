#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y;
};

int r[10];
Point p[10];
int n,m;

int cntbit(int sta)
{
    int ans = 0;
    for (int i = 0; i < m; i++)
        if (((sta>>i)&1) == 1)
            ans++;
    return ans;
}

bool mp[50][50];
bool check(int sta)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            mp[i][j] = false;
            for (int k = 0;k < m;k++)
                if (p[k].x == i && p[k].y == j)
                    mp[i][j] = true;

            for (int k = 0; k < m; k++)
                if (((sta>>k)&1) == 1)
                    if (abs(p[k].x-i)+abs(p[k].y-j) <= r[k])
                        mp[i][j] = true;
            if (mp[i][j] == false)
                return false;
        }
    return true;
}

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;

        scanf("%d",&m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].x--;
            p[i].y--;
        }
        for (int i = 0; i < m; i++)
            scanf("%d",&r[i]);

        int ans = -1;
        for (int i = 0; i < (1<<m); i++)
            if (check(i))
            {
                int tot = cntbit(i);
                if (ans == -1 || ans > tot)
                    ans = tot;
            }
        printf("%d\n",ans);
    }
    return 0;
}

