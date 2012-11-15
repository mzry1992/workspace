#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char map[200][200];
bool flag[30];

bool onTop(int x,int y)
{
    int tl,td;
    tl = y;
    td = x;
    while (map[x][tl+1] == map[x][y])
        tl++;
    while (map[td+1][y] == map[x][y])
        td++;
    int tl2,td2;
    tl2 = y;
    td2 = x;
    while (map[td][tl2+1] == map[x][y])
        tl2++;
    while (map[td2+1][tl] == map[x][y])
        td2++;
    if (!((tl == tl2) && (td == td2) && (tl-y+1 >= 3) && (td-x+1 >= 3)))
        return false;
    for (int i = x+1;i <= td-1;i++)
        for (int j = y+1;j <= tl-1;j++)
            if (map[i][j] != '.')
                return false;
    return true;
}

int main()
{
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)
            break;
        for (int i = 0;i < 200;i++)
            for (int j = 0;j < 200;j++)
                map[i][j] = '.';
        for (int i = 0;i < n;i++)
            scanf("%s",&map[i]);
        memset(flag,false,sizeof(flag));
        for (int i = 0;i <= n-3;i++)
            for (int j = 0;j <= m-3;j++)
                if (map[i][j] != '.')
                if (map[i][j] == map[i+1][j] && map[i][j] == map[i][j+1])
                if (onTop(i,j))
                    flag[map[i][j]-'A'+1] = true;
        for (int i = 1;i <= 26;i++)
            if (flag[i] == true)
                printf("%c",'A'+i-1);
        printf("\n");
    }
}
