#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char alp[60][3];
char word[60][12][12],now[12][12],tnow[12][12];
int minres,minnosi;

int main()
{
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 1;i <= n;i++)
        {
            scanf("%s",alp[i]);
            for (int j = 0;j < 10;j++)
                scanf("%s",word[i][j]);
        }
        scanf("%d",&m);
        for (int i = 1;i <= m;i++)
        {
            for (int j = 0;j < 10;j++)
                scanf("%s",now[j]);
            minres = 120;
            minnosi = 120;
            for (int f = 0;f < 4;f++)
            {
                for (int k = 1;k <= n;k++)
                {
                    int nownosi = 0;
                    for (int x = 0;x < 10;x++)
                        for (int y = 0;y < 10;y++)
                            if (word[k][x][y] != now[x][y])
                                nownosi++;
                    if (nownosi < minnosi || (nownosi == minnosi && minres > k))
                    {
                        minnosi = nownosi;
                        minres = k;
                    }
                }
                for (int x = 0;x < 10;x++)
                    for (int y = 0;y < 10;y++)
                        tnow[9-y][x] = now[x][y];
                for (int x = 0;x < 10;x++)
                    for (int y = 0;y < 10;y++)
                        now[x][y] = tnow[x][y];
            }
            printf("%s",alp[minres]);
        }
        printf("\n");
    }
}
