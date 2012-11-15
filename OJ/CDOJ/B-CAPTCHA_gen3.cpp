#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char s[10][10][20];

int main()
{
    freopen("BC.txt","r",stdin);
    freopen("BC_out3.txt","w",stdout);
    int now = 0;
    for (int k = 1;k <= 4;k++)
    {
        for (int i = 0;i < 7;i++)
        {
            for (int j = 1;j <= 6;j++)
                scanf("%s",s[j][i]);
        }
        for (int i = 1;i <= 6;i++)
        {
            for (int j = 0;j < 7;j++)
            {
                printf("\"%s\"",s[i][j]);
            }
            printf("}");
        }
    }
    for (int i = 0;i < 7;i++)
        {
            for (int j = 1;j <= 2;j++)
                scanf("%s",s[j][i]);
        }
        for (int i = 1;i <= 2;i++)
        {
            for (int j = 0;j < 7;j++)
            {
                if (j != 0)
                    printf(",\n");
                printf("\"%s\"",s[i][j]);
            }
        }
}
