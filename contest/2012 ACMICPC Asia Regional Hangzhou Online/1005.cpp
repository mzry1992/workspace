#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char mp[60][60];

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        for (int i = 0;i < n;i++)
            scanf("%s",mp[i]);
        int res = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                if (mp[i][j] == '#')
                {
                    int li = 0;
                    for (;li < n;li++)
                    {
                        if (i+li >= n)  break;
                        if (i-li < 0)   break;
                        if (mp[i+li][j] != '#' || mp[i-li][j] != '#')   break;
                    }
                    int lj = 0;
                    for (;lj < n;lj++)
                    {
                        if (j+lj >= n)  break;
                        if (j-lj < 0)   break;
                        if (mp[i][j+lj] != '#' || mp[i][j-lj] != '#')   break;
                    }
                    if (li == lj && li > 1)
                    {
                        bool flag = true;
                        if (i-li >= 0 && mp[i-li][j] == '#')
                            flag = false;
                        if (i+li < n && mp[i+li][j] == '#')
                            flag = false;
                        if (j-li >= 0 && mp[i][j-li] == '#')
                            flag = false;
                        if (j+li < n && mp[i][j+li] == '#')
                            flag = false;
                        for (int k = 1;k < li && flag;k++)
                        {
                            if (mp[i-k][j-1] == '#' || mp[i-k][j+1] == '#')
                                flag = false;
                            if (mp[i-1][j-k] == '#' || mp[i+1][j-k] == '#')
                                flag = false;
                            if (mp[i+k][j-1] == '#' || mp[i+k][j+1] == '#')
                                flag = false;
                            if (mp[i-1][j+k] == '#' || mp[i+1][j+k] == '#')
                                flag = false;
                        }
                        if (flag)
                            res++;
                    }
                }
        printf("%d\n",res);
    }
	return 0;
}
