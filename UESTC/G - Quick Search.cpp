#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int s,n,p;
char e[10];
int map[20][20];
int a[20];

int main()
{
    while (true)
    {
        scanf("%d",&s);
        if (s == 0) break;
        scanf("%d%d",&n,&p);
        for (int i = 0;i < s;i++)
        for (int j = 0;j < s;j++)
            map[i][j] = 19921005;
        for (int i = 1;i <= p;i++)
        {
            scanf("%s",e);
            map[e[0]-'A'][e[1]-'A'] = map[e[1]-'A'][e[0]-'A'] = 1;
        }
        for (int k = 0;k < s;k++)
        for (int i = 0;i < s;i++)
        for (int j = 0;j < s;j++)
        if (i != j && i != k && j != k)
        if (map[i][j] > map[i][k]+map[k][j])
            map[i][j] = map[i][k]+map[k][j];
        for (int i = 1;i < s;i++)
            a[i] = i;
        int res = 19921005;
        do
        {
            int l = 1;
            int r = s*s;
            while (true)
            {
                int mid = (l+r)>>1;
                bool check = true;
                int cur = 1;
                for (int i = 1;i <= n;i++)
                {
                    if (cur >= s)   break;
                    int tt = map[0][a[cur]];
                    if (tt > mid)
                    {
                        check = false;
                        break;
                    }
                    while (true)
                    {
                        cur++;
                        if (cur >= s)   break;
                        tt += map[a[cur-1]][a[cur]];
                        if (tt > mid)   break;
                    }
                }
                if (cur < s)  check = false;
                if (check == true) r = mid;
                else l = mid+1;
                if (l == r) break;
            }
            if (l < res)    res = l;
        }while (next_permutation(a+1,a+s));
        printf("%d\n",res);
    }
}
