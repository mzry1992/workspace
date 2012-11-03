#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char mp[1000][1000];

void putit(int mt,int ml,int n)
{
    mp[mt][ml] = '+';
    for (int x = 0;x < (1<<(n+2))-2;x++)
        mp[mt][ml+1+x] = '-';
    mp[mt][ml+(1<<(n+2))-1] = '+';
    for (int x = 0;x < (1<<(n+2))-2;x++)
    {
        mp[mt+1+x][ml] = '|';
        mp[mt+1+x][ml+(1<<(n+2))-1] = '|';
    }
    mp[mt+(1<<(n+2))-1][ml] = '+';
    for (int x = 0;x < (1<<(n+2))-2;x++)
        mp[mt+(1<<(n+2))-1][ml+1+x] = '-';
    mp[mt+(1<<(n+2))-1][ml+(1<<(n+2))-1] = '+';
    if (n == 0) return;
    int sx = mt+2;
    int sy = ml+(1<<(n+1))-2;
    while (true)
    {
        mp[sx][sy] = '/';
        sx++;
        sy--;
        if (sy == ml+1)    break;
    }
    sx = mt+2;
    sy = ml+(1<<(n+1))+1;
    while (true)
    {
        mp[sx][sy] = '\\';
        sx++;
        sy++;
        if (sy == ml+(1<<(n+2))-2)    break;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d",&n);
        int ml,mt,mut;
        ml = mt = 0;
        mut = 1<<(n+1);
        for (int i = 0;i < 1000;i++)
            for (int j = 0;j < 1000;j++)
                mp[i][j] = ' ';
        for (int i = n;i >= 0;i--)
        {
            putit(mt,ml,i);
            mt += mut;
            ml += mut/2;
            mut /= 2;
        }
        for (int i = 0;i < (1<<(n+2));i++,puts(""))
            for (int j = 0;j < (1<<(n+2));j++)
                printf("%c",mp[i][j]);
        puts("");
    }
    return 0;
}
