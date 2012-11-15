#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char label[] = "~ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const int step[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int n,m;
char map[120][120];
int blocks[60][10010][2],points[60],totblocks;
int tblock[10010][2],block[10010][2],point;

void DFS(int x,int y)
{
    if (x < 0)  return;
    if (y < 0)  return;
    if (x >= n) return;
    if (y >= m) return;
    if (map[x][y] != '1')   return;
    map[x][y] = '2';
    point++;
    tblock[point][0] = block[point][0] = x;
    tblock[point][1] = block[point][1] = y;
    for (int i = 0;i < 8;i++)
        DFS(x+step[i][0],y+step[i][1]);
}

bool tmap[110][110],tmap2[110][110],tmap3[110][110];

int gaoji()
{
    int minx,miny;
    minx = block[1][0];
    miny = block[1][1];
    for (int i = 1;i <= point;i++)
    {
        if (block[i][0] < minx) minx = block[i][0];
        if (block[i][1] < miny) miny = block[i][1];
    }
    for (int i = 1;i <= point;i++)
    {
        block[i][0] -= minx;
        block[i][1] -= miny;
    }
    int pos = 0;
    memset(tmap2,false,sizeof(tmap2));
    for (int i = 1;i <= point;i++)
        tmap2[block[i][0]][block[i][1]] = true;
    for (int i = 1;i <= totblocks;i++)
    if (point == points[i])
    {
        memset(tmap,false,sizeof(tmap));
        int tn,tm;
        tn = tm = 0;
        for (int j = 1;j <= point;j++)
        {
            tmap[blocks[i][j][0]][blocks[i][j][1]] = true;
            if (blocks[i][j][0] > tn)   tn = blocks[i][j][0];
            if (blocks[i][j][1] > tm)   tm = blocks[i][j][1];
        }
        tn++;
        tm++;
        for (int k = 0;k < 4;k++)
        {
            bool flag = true;
            for (int x = 0;x < tn && flag == true;x++)
            for (int y = 0;y < tm && flag == true;y++)
            if (tmap[x][y] != tmap2[x][y])  flag = false;
            if (flag == true)
            {
                pos = i;
                break;
            }
            flag = true;
            for (int x = 0;x < tn && flag == true;x++)
            for (int y = 0;y < tm && flag == true;y++)
            if (tmap[tn-1-x][y] != tmap2[x][y])  flag = false;
            if (flag == true)
            {
                pos = i;
                break;
            }
            flag = true;
            for (int x = 0;x < tn && flag == true;x++)
            for (int y = 0;y < tm && flag == true;y++)
            if (tmap[x][tm-1-y] != tmap2[x][y])  flag = false;
            if (flag == true)
            {
                pos = i;
                break;
            }
            for (int x = 0;x < tn;x++)
            for (int y = 0;y < tm;y++)
                tmap3[y][tn-1-x] = tmap[x][y];
            int tt = tn; tn = tm; tm = tt;
            for (int x = 0;x < tn;x++)
            for (int y = 0;y < tm;y++)
                tmap[x][y] = tmap3[x][y];
        }
        if (pos != 0)   break;
    }
    if (pos == 0)
    {
        totblocks++;
        points[totblocks] = point;
        for (int i = 1;i <= point;i++)
        {
            blocks[totblocks][i][0] = block[i][0];
            blocks[totblocks][i][1] = block[i][1];
        }
        pos = totblocks;
    }
    return pos;
}

int main()
{
    bool first = true;
    while (true)
    {
        scanf("%d%d",&n,&m);
        if (n == 0 && m == 0)   break;
        if (first == false) printf("\n");
        first = false;
        for (int i = 0;i < n;i++)
            scanf("%s",map[i]);
        totblocks = 0;
        for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        if (map[i][j] == '1')
        {
            point = 0;
            DFS(i,j);
            int index = gaoji();
            for (int k = 1;k <= point;k++)
                map[tblock[k][0]][tblock[k][1]] = label[index];
        }
        printf("%d\n",totblocks);
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < m;j++)
                printf("%c",map[i][j]);
            printf("\n");
        }
    }
}
