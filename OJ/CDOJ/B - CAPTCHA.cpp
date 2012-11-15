#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int map[30][200][2];
int tot[30];
const char alp[26][7][20] = {
{"111111MMM1111111",
"11111MM1MM111111",
"1111MM111MM11111",
"111MMMMMMMMM1111",
"11MM1111111MM111",
"1MMM11111111MM11",
"1MM1111111111MM1"},
{"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM11111111MM111",
"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM11111111MM111",
"1MMMMMMMMMMM1111"},
{"11111MMMMMMMM111",
"111MM1111111MM11",
"11MM111111111MM1",
"11MM111111111111",
"11MM111111111MM1",
"111MM1111111MM11",
"11111MMMMMMMM111"},
{"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111"},
{"1MMMMMMMMMMMM111",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMM111",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMM111"},
{"1MMMMMMMMMMMMM11",
"1MM1111111111111",
"1MM1111111111111",
"1MMMMMMMMMMMMM11",
"1MM1111111111111",
"1MM1111111111111",
"1MM1111111111111"},
{"11111MMMMMMMM111",
"111MM1111111MM11",
"11MM111111111MM1",
"11MM111111111111",
"11MM111111MMMMM1",
"111MM1111111MM11",
"11111MMMMMMMMM11"},
{"1MM111111111MM11",
"1MM111111111MM11",
"1MM111111111MM11",
"1MMMMMMMMMMMMM11",
"1MM111111111MM11",
"1MM111111111MM11",
"1MM111111111MM11"},
{"11111MMMMMM11111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"11111MMMMMM11111"},
{"1111MMMMMMMM1111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"111MM11MM1111111",
"111MMM1MM1111111",
"11111MMMM1111111"},
{"11MM111111MMM111",
"11MM11111MMM1111",
"11MM111MMM111111",
"11MMMMM111111111",
"11MM111MMM111111",
"11MM11111MMM1111",
"11MM111111MMMM11"},
{"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MM111111111111",
"11MMMMMMMMMMMM11"},
{"1MM1111111111MM1",
"1MMMM111111MMMM1",
"1MM1MM1111MM1MM1",
"1MM11MMMMM111MM1",
"1MM1111M11111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1"},
{"1MMM111111111MM1",
"1MMMM11111111MM1",
"1MM1MM1111111MM1",
"1MM11MM111111MM1",
"1MM1111MM1111MM1",
"1MM111111MMM1MM1",
"1MM11111111MMMM1"},
{"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM111111MMM11",
"111MMM1111MMM111",
"11111MMMMMM11111"},
{"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",
"1MM1111111111111",
"1MM1111111111111"},
{"11111MMMMMM11111",
"111MMM1111MMM111",
"11MMM111111MMM11",
"1MM1111111111MM1",
"11MMM1MMMM1MMM11",
"111MMM11MMMMM111",
"111111MMMM1MMMM1"},
{"1MMMMMMMMMMM1111",
"1MM111111111MM11",
"1MM1111111111MM1",
"1MM111111111MM11",
"1MMMMMMMMMMM1111",
"1MM11111111MM111",
"1MM111111111MMM1"},
{"1111MMMMMMMM1111",
"111MM1111111MM11",
"11MMM1111111MMM1",
"1111MMMMM1111111",
"1MMM111MMMM11111",
"111MMM11111MMM11",
"11111MMMMMMM1111"},
{"11MMMMMMMMMMMM11",
"11MMMMMMMMMMMM11",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111"},
{"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MM1111111111MM1",
"1MMM11111111MMM1",
"1MMM11111111MMM1",
"111MMMMMMMMMM111"},
{"1MMMM111111MMMM1",
"11MMM111111MMM11",
"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"11111MM11MM11111",
"111111MMMM111111"},
{"1MM1111111111MM1",
"1MM1111111111MM1",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM111MM111MM11",
"11MM1MM11MM1MM11",
"111MMM1111MMM111"},
{"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111MMM11MMM1111",
"111MMM1111MMM111",
"11MMM111111MMM11"},
{"11MMM111111MMM11",
"111MMM1111MMM111",
"1111MMM11MMM1111",
"111111MMMM111111",
"1111111MM1111111",
"1111111MM1111111",
"1111111MM1111111"},
{"111MMMMMMMMMM111",
"1111111111MM1111",
"111111111MM11111",
"11111111MM111111",
"111111MM11111111",
"11111MM111111111",
"111MMMMMMMMMMM11"}};

void init()
{
    for (int k = 0;k < 26;k++)
    {
        bool first = false;
        int sx,sy;
        tot[k] = 0;
        for (int i = 0;i < 7;i++)
        for (int j = 0;j < 16;j++)
        if (alp[k][i][j] == 'M')
        {
            if (first == false)
            {
                tot[k]++;
                sx = i;
                sy = j;
                map[k][tot[k]][0] = i;
                map[k][tot[k]][1] = j;
                tot[k]++;
                map[k][tot[k]][0] = 0;
                map[k][tot[k]][1] = 0;
                first = true;
            }
            else
            {
                tot[k]++;
                map[k][tot[k]][0] = i-sx;
                map[k][tot[k]][1] = j-sy;
            }
        }
    }
}

int n,m;
char s[350][350];
bool ans[30];

int abs(int x)
{
    if (x < 0)  return -x;
    return x;
}

bool check(int x,int y)
{
    if (x < 0)  return false;
    if (y < 0)  return false;
    if (x >= n)  return false;
    if (y >= m)  return false;
    if (s[x][y] != 'M')   return false;
    return true;
}

int ctot;
bool visit[350][350];
const int step[8][2] = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void DFS(int x,int y)
{
    if (x < 0)  return;
    if (y < 0)  return;
    if (x >= n) return;
    if (y >= m) return;
    if (s[x][y] != 'M') return;
    if (visit[x][y] == true)    return;
    visit[x][y] = true;
    ctot++;
    for (int i = 0;i < 8;i++)
        DFS(x+step[i][0],y+step[i][1]);
}

int findit1(int x,int y)
{
    memset(visit,false,sizeof(visit));
    ctot = 0;
    DFS(x,y);
    for (int i = 0;i < 26;i++)
    if (tot[i]-1 == ctot)
    {
        int ttot = tot[i];
        int sx,sy;
        sx = x;
        sy = y;
        bool flag = true;
        for (int j = 2;j <= ttot;j++)
        if (check(sx+map[i][j][0],sy+map[i][j][1]) == false)
        {
            flag = false;
            break;
        }
        if (flag == true)   return i;
    }
    return -1;
}

void coverit1(int x,int y,int res)
{
    int ttot = tot[res];
    int sx,sy;
    sx = x;
    sy = y;
    for (int i = 2;i <= ttot;i++)
        s[sx+map[res][i][0]][sy+map[res][i][1]] = '1';
}

int findit2(int x,int y)
{
    memset(visit,false,sizeof(visit));
    ctot = 0;
    DFS(x,y);
    for (int i = 0;i < 26;i++)
    if (tot[i]-1 == ctot)
    {
        int ttot = tot[i];
        int sx,sy;
        sx = x;
        sy = y;
        bool flag = true;
        for (int j = 2;j <= ttot;j++)
        if (check(sx-map[i][j][0],sy-map[i][j][1]) == false)
        {
            flag = false;
            break;
        }
        if (flag == true)   return i;
    }
    return -1;
}

void coverit2(int x,int y,int res)
{
    int ttot = tot[res];
    int sx,sy;
    sx = x;
    sy = y;
    for (int i = 2;i <= ttot;i++)
        s[sx-map[res][i][0]][sy-map[res][i][1]] = '1';
}

int main()
{
    init();
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 0;i < n;i++)
            scanf("%s",s[i]);
        memset(ans,false,sizeof(ans));
        for (int x = 0;x < n;x++)
        for (int y = 0;y < m;y++)
        if (s[x][y] == 'M')
        {
            int res = findit1(x,y);
            if (res >= 0)
            {
                ans[res] = true;
                coverit1(x,y,res);
            }
            res = findit2(x,y);
            if (res >= 0)
            {
                ans[res] = true;
                coverit2(x,y,res);
            }
        }
        for (int i = 0;i < 26;i++)
        if (ans[i] == true)
            printf("%c",(char)('A'+i));
        printf("\n");
    }
}
