#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char a[10][10],b[10][10],temp[10][10];
char res[20];

int main()
{
    while (scanf("%s",a[0]) != EOF)
    {
        for (int i = 1;i <= 3;i++)
            scanf("%s",a[i]);
        for (int i = 0;i < 4;i++)
            scanf("%s",b[i]);
        int tot = 0;
        for (int i = 1;i <= 4;i++)
        {
            for (int x = 0;x < 4;x++)
            for (int y = 0;y < 4;y++)
            if (a[x][y] == 'X')
            {
                res[tot] = b[x][y];
                tot++;
            }
            for (int x = 0;x < 4;x++)
            for (int y = 0;y < 4;y++)
                temp[y][3-x] = a[x][y];
            for (int x = 0;x < 4;x++)
            for (int y = 0;y < 4;y++)
                a[x][y] = temp[x][y];
        }
        res[tot] = 0;
        printf("%s\n",res);
    }
}
