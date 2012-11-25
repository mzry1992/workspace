#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int r,c;
char mp[11][11];
int cov[11][11];
int id;

int main()
{
    int cas = 0;
    while (true)
    {
        scanf("%d",&r);
        if (r == 0) break;
        scanf("%d",&c);
        for (int i = 0; i < r; i++)
            scanf("%s",mp[i]);
        memset(cov,0,sizeof(cov));
        id = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (mp[i][j] != '*')
                    if (i == 0 || mp[i-1][j] == '*' || j == 0 || mp[i][j-1] == '*')
                        cov[i][j] = ++id;
        if (cas > 0) puts("");
        printf("puzzle #%d:\n",++cas);
        printf("Across\n");
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (cov[i][j] != 0)
                    if (j == 0 || mp[i][j-1] == '*')
                    {
                        printf("%3d.",cov[i][j]);
                        for (int k = j; k < c && mp[i][k] != '*'; k++)
                            printf("%c",mp[i][k]);
                        printf("\n");
                    }
        printf("Down\n");
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (cov[i][j] != 0)
                    if (i == 0 || mp[i-1][j] == '*')
                    {
                        printf("%3d.",cov[i][j]);
                        for (int k = i; k < r && mp[k][j] != '*'; k++)
                            printf("%c",mp[k][j]);
                        printf("\n");
                    }
    }
    return 0;
}
