#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int w,t;
int map[100][100];

void gao(int x,int y,int l)
{
    int cb,cw;
    cb = cw = 0;
    for (int i = 0;i < l;i++)
    for (int j = 0;j < l;j++)
    if (map[x+i][y+j] == 1) cb++;
    else    cw++;
    if (cb*100 >= l*l*t)
    {
        for (int i = 0;i < l;i++)
        for (int j = 0;j < l;j++)
            map[x+i][y+j] = 1;
        return;
    }
    if (cw*100 >= l*l*t)
    {
        for (int i = 0;i < l;i++)
        for (int j = 0;j < l;j++)
            map[x+i][y+j] = 0;
        return;
    }
    if (l == 1) return;
    gao(x,y,l/2);
    gao(x+l/2,y,l/2);
    gao(x,y+l/2,l/2);
    gao(x+l/2,y+l/2,l/2);
}

int main()
{
    int ft = 0;
    while (true)
    {
        scanf("%d",&w);
        if (w == 0) break;
        scanf("%d",&t);
        for (int i = 1;i <= w;i++)
        {
            char ss[100];
            scanf("%s",ss);
            for (int j = 1;j <= w;j++)
                map[i][j] = ss[j-1]-'0';
        }
        gao(1,1,w);
        ft++;
        printf("Image %d:\n",ft);
        for (int i = 1;i <= w;i++)
        {
            for (int j = 1;j <= w;j++)
                printf("%d",map[i][j]);
            printf("\n");
        }
    }
}
