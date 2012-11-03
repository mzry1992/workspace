#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char map[300][300];
int l[300],r[300];

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if ((n == 0) && (m == 0))   break;
        for (int i = 0;i < n;i++)
            scanf("%s",map[i]);
        int res = 0;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        if (map[i][j] == 'S')   res++;
        for (int i = 0;i < n;i++)
        {
            l[i] = -1;
            r[i] = -1;
            for (int j = 0;j < m;j++)
            if (map[i][j] == 'S')
            {
                if (l[i] == -1)
                    l[i] = j;
                r[i] = j;
            }
        }
        int prel,prer,pre;
        prer = n;
        prel = r[0];
        pre = -1;
        l[n] = r[n-1];
        r[n] = n;
        int flag = 2;
        for (int i = 1;i < n;i++)
        {
            if (l[i] < l[i-1])
                flag = 1;
            else if (l[i] > l[i-1] && flag != 0)
            {
                if (flag == 2)
                    res += 1;
                else
                    res -= 2;
                flag = 0;
            }
        }
        if (flag == 1)
            res--;
        printf("%d\n",res);
    }
}
