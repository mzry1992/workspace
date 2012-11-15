#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[10],t[10];
char res[10][10];
char tmap[10][10],smap[10][10];
const int bb[7][4][2] = {{{0,0},{0,1},{0,2},{0,3}},
                         {{0,0},{0,1},{0,2},{1,0}},
                         {{0,0},{0,1},{0,2},{1,1}},
                         {{0,0},{0,1},{0,2},{1,2}},
                         {{0,0},{0,1},{1,1},{1,2}},
                         {{0,0},{0,1},{1,0},{1,1}},
                         {{0,1},{0,2},{1,0},{1,1}}};
int tb[7][4][4][2];
bool hasans,jihasans;

inline bool check(int x,int y)
{
    if (x < 0)  return false;
    if (y < 0)  return false;
    if (x >= 6) return false;
    if (y >= 6) return false;
    return true;
}

void ji(int deep)
{
    if (jihasans == true)   return;
    if (deep == 3)
    {
        hasans = jihasans = true;
        for (int i = 0;i < 6;i++)
        for (int j = 0;j < 6;j++)
            res[i][j] = tmap[i][j];
        return;
    }
    for (int i = 0;i < 6;i++)
    for (int j = 0;j < 6;j++)
    if (tmap[i][j] == 'X')
    for (int k = 0;k < 4;k++)
    {
        bool canput = true;
        for (int q = 0;q < 4;q++)
        {
            if (check(i+tb[t[deep]-'A'][k][q][0],j+tb[t[deep]-'A'][k][q][1]) == false)
            {
                canput = false;
                break;
            }
            if (tmap[i+tb[t[deep]-'A'][k][q][0]][j+tb[t[deep]-'A'][k][q][1]] != 'X')
            {
                canput = false;
                break;
            }
        }
        if (canput == false)    continue;
        for (int q = 0;q < 4;q++)
            tmap[i+tb[t[deep]-'A'][k][q][0]][j+tb[t[deep]-'A'][k][q][1]] = '#';
        ji(deep+1);
        for (int q = 0;q < 4;q++)
            tmap[i+tb[t[deep]-'A'][k][q][0]][j+tb[t[deep]-'A'][k][q][1]] = 'X';
    }
}

void gao(int deep)
{
    if (deep == 3)
    {
        jihasans = false;
        int isbig = 0;
        for (int i = 0;i < 6;i++)
        for (int j = 0;j < 6;j++)
        {
            if (isbig != 0) break;
            if (res[i][j] == '.' && tmap[i][j] != '.')
            {
                isbig = 1;
            }
            else if (res[i][j] != '.' && tmap[i][j] == '.')
            {
                isbig = -1;
            }
        }
        if (isbig == -1)    return;
        ji(0);
        return;
    }
    for (int i = 0;i < 6;i++)
    for (int j = 0;j < 6;j++)
    if (tmap[i][j] == '.')
    for (int k = 0;k < 4;k++)
    {
        bool canput = true;
        for (int q = 0;q < 4;q++)
        {
            if (check(i+tb[s[deep]-'A'][k][q][0],j+tb[s[deep]-'A'][k][q][1]) == false)
            {
                canput = false;
                break;
            }
            if (tmap[i+tb[s[deep]-'A'][k][q][0]][j+tb[s[deep]-'A'][k][q][1]] != '.')
            {
                canput = false;
                break;
            }
        }
        if (canput == false)    continue;
        for (int q = 0;q < 4;q++)
            tmap[i+tb[s[deep]-'A'][k][q][0]][j+tb[s[deep]-'A'][k][q][1]] = 'X';
        gao(deep+1);
        for (int q = 0;q < 4;q++)
            tmap[i+tb[s[deep]-'A'][k][q][0]][j+tb[s[deep]-'A'][k][q][1]] = '.';
    }
}

int main()
{
    for (int i = 0;i < 7;i++)
    {
        memset(tmap,0,sizeof(tmap));
        for (int j = 0;j < 4;j++)
            tmap[bb[i][j][0]][bb[i][j][1]] = 1;
        for (int k = 0;k < 4;k++)
        {
            int fx,fy;
            for (int x = 0;x < 4;x++)
            for (int y = 0;y < 4;y++)
            if (tmap[x][y] == 1)
            {
                fx = x;
                fy = y;
                break;
            }
            int ttot = 0;
            for (int x = 0;x < 4;x++)
            for (int y = 0;y < 4;y++)
            if (tmap[x][y] == 1)
            {
                tb[i][k][ttot][0] = x-fx;
                tb[i][k][ttot][1] = y-fy;
                ttot++;
            }
            for (int x = 0;x < 4;x++)
            for (int y = 0;y < 4;y++)
                smap[3-y][x] = tmap[x][y];
            for (int x = 0;x < 4;x++)
            for (int y = 0;y < 4;y++)
                tmap[x][y] = smap[x][y];
        }
    }
    int Tt;
    scanf("%d",&Tt);
    for (int ft = 1;ft <= Tt;ft++)
    {
        scanf("%s",s);
        scanf("%s",t);
        for (int i = 0;i < 6;i++)
        for (int j = 0;j < 6;j++)
            tmap[i][j] = res[i][j] = '.';
        hasans = false;
        gao(0);
        printf("%d\n",ft);
        if (hasans == false)
        {
            printf("No solution\n");
            continue;
        }
        for (int i = 0;i < 6;i++)
        {
            for (int j = 0;j < 6;j++)
                printf("%c",res[i][j]);
            printf("\n");
        }
    }
}
