#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char ins[1000][20];
int vid[1000][5],cnt[1000];
bool wa[1000];
int m,n;

int main()
{
    while (true)
    {
        scanf("%d%d",&m,&n);
        if (m == 0 && n == 0)   break;
        for (int i = 0;i < n;i++)
            cnt[i] = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%s",ins[i]);
            for (int j = 0;j < m;j++)
            {
                scanf("%d",&vid[i][j]);
                vid[i][j]--;
                cnt[vid[i][j]]++;
            }
        }
        memset(wa,false,sizeof(wa));
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
                if (strcmp(ins[i],ins[vid[i][j]]) == 0)
                    wa[vid[i][j]] = true;
            for (int j = 0;j < m;j++)
                for (int k = j+1;k < m;k++)
                    if (vid[i][j] == vid[i][k])
                        wa[vid[i][j]] = true;
        }
        for (int i = 0;i < n;i++)
            if (cnt[i] != m)
                wa[i] = true;
        int res = 0;
        for (int i = 0;i < n;i++)
            if (wa[i] == true)
                res++;
        if (res == 0)
            puts("NO PROBLEMS FOUND");
        else if (res == 1)
            puts("1 PROBLEM FOUND");
        else
            printf("%d PROBLEMS FOUND\n",res);
    }
	return 0;
}
