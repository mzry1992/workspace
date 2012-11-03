#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char map[9][9],tmap[9][9];
int res;
const int step[5][2] = {{-1,0},{1,0},{0,-1},{0,1},{0,0}};

void press(int x,int y)
{
    for (int i = 0;i < 5;i++)
    {
        int tx,ty;
        tx = x+step[i][0];
        ty = y+step[i][1];
        if (tx >= 0 && tx < 4 && ty >= 0 && ty < 4)
            map[tx][ty] = (map[tx][ty] == 'b')?'w':'b';
    }
}

int main()
{
    while (gets(map[0]))
    {
        for (int i = 1;i < 4;i++)   gets(map[i]);
        res = 99;
        for (int i = 0;i < (1<<16);i++)
        {
            int step = 0;
            for (int j = 0;j < 16;j++)
            if (((i>>j)&1) == 1)
            {
                step++;
                press(j/4,j%4);
            }
            for (int j = 0;j < 16;j++)
            if (map[j/4][j%4] != map[0][0]) step = 99;
            res = min(res,step);
            for (int j = 0;j < 16;j++)
            if (((i>>j)&1) == 1)
                press(j/4,j%4);
        }
        if (res == 99)  printf("Impossible\n");
        else printf("%d\n",res);
    }
}
