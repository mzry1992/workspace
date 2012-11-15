#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[10][10];

bool check(int x,int y,char c)
{
    if (x >= 2)
    {
        if (s[x-1][y] == c && s[x-2][y] == c)   return true;
        if (y >= 2)
        {
            if (s[x-1][y-1] == c && s[x-2][y-2] == c)   return true;
            if (s[x][y-1] == c && s[x][y-2] == c)   return true;
        }
        if (y <= 2)
        {
            if (s[x-1][y+1] == c && s[x-2][y+2] == c)   return true;
            if (s[x][y+1] == c && s[x][y+2] == c)   return true;
        }
    }
    if (x <= 2)
    {
        if (s[x+1][y] == c && s[x+2][y] == c)   return true;
        if (y >= 2)
        {
            if (s[x+1][y-1] == c && s[x+2][y-2] == c)   return true;
            if (s[x][y-1] == c && s[x][y-2] == c)   return true;
        }
        if (y <= 2)
        {
            if (s[x+1][y+1] == c && s[x+2][y+2] == c)   return true;
            if (s[x][y+1] == c && s[x][y+2] == c)   return true;
        }
    }
    return false;
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        bool a,b;
        a = b = false;
        for (int i = 0;i < 5;i++)
            scanf("%s",s[i]);
        for (int i = 0;i < 5;i++)
        for (int j = 0;j < 5;j++)
        {
            if (s[i][j] == 'A')
            {
                if (check(i,j,s[i][j]))
                    a = true;
            }
            else
            {
                if (check(i,j,s[i][j]))
                    b = true;
            }
        }
        if ((a == false && b == false) || (a == true && b == true))
        {
            printf("draw\n");
            continue;
        }
        if (a == true)
            printf("A wins\n");
        else
            printf("B wins\n");
    }
}
