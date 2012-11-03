#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const bool mp[10][6] = {{0,1,1,1,0,0},{1,0,0,0,0,0},{1,0,1,0,0,0},{1,1,0,0,0,0},{1,1,0,1,0,0},{1,0,0,1,0,0},{1,1,1,0,0,0},{1,1,1,1,0,0},{1,0,1,1,0,0},{0,1,1,0,0,0}};
int n;
char com,tmp[1000];
bool num[100][6];

int main()
{
    while (true)
    {
        scanf("%d",&n);
        if (n == 0) break;
        scanf(" %c",&com);
        if (com == 'S')
        {
            scanf("%s",tmp);
            for (int i = 0;i < 3;i++)
            {
                for (int j = 0;j < n;j++)
                {
                    for (int k = 0;k < 2;k++)
                        if (mp[tmp[j]-'0'][i*2+k])
                            printf("*");
                        else
                            printf(".");
                    if (j+1 < n)
                        printf(" ");
                }
                printf("\n");
            }
        }
        else
        {
            for (int i = 0;i < n;i++)
                for (int j = 0;j < 6;j++)
                    num[i][j] = false;
            for (int i = 0;i < 3;i++)
                for (int j = 0;j < n;j++)
                {
                    scanf("%s",tmp);
                    for (int k = 0;k < 2;k++)
                        if (tmp[k] == '*')
                            num[j][i*2+k] = true;
                }
            for (int i = 0;i < n;i++)
            {
                bool check;
                for (int j = 0;j < 10;j++)
                {
                    check = true;
                    for (int k = 0;k < 6;k++)
                        if (num[i][k] != mp[j][k])
                            check = false;
                    if (check == true)
                    {
                        printf("%d",j);
                        break;
                    }
                }
            }
            printf("\n");
        }
    }
	return 0;
}
