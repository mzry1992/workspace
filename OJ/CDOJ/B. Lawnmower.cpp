#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char g[160][160];

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%s",g[i]);
        while (n > 1)
        {
            bool flag = true;
            for (int i = 0;i < m;i++)
                if (g[n-1][i] == 'W')
                {
                    flag = false;
                    break;
                }
            if (flag == false)  break;
            n--;
        }
        int res = 0;
        int cur = 0;
        int nxt;
        bool flag;
        for (int i = 0;i < n;i++)
        {
            //(i,cur)
            if (i%2 == 0)
            {
                nxt = cur;
                for (int j = cur;j < m;j++)
                {
                    if (g[i][j] == 'W')
                        nxt = j;
                    if (i+1 < n && g[i+1][j] == 'W')
                        nxt = j;
                }
                res = res+(nxt-cur);
            }
            else
            {
                nxt = cur;
                for (int j = cur;j >= 0;j--)
                {
                    if (g[i][j] == 'W')
                        nxt = j;
                    if (i+1 < n && g[i+1][j] == 'W')
                        nxt = j;
                }
                res = res+(cur-nxt);
            }
            if (i+1 < n)    res++;
            cur = nxt;
        }
        printf("%d\n",res);
    }
    return 0;
}
