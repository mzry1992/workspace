#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m,totstep;
char g[30][30],tg[30][30],step[300000];
bool hasres;

void DFS(int x,int y,int clic,int tot,int sx,int sy)
{
    if (hasres == true) return;
    if (clic == tot)
    {
        hasres = true;
        printf("%d\n%d\n",sx,sy);
        for (int i = 1;i <= totstep;i++)    putchar(step[i]);
        printf("\n");
        return;
    }
    char tmp1,tmp2;
    if (x-1 >= 0)
        if (tg[x-1][y] == '.')
            for (int i = x-2;i >= 0;i--)
                if (tg[i][y] != '.')
                {
                    tmp1 = tg[i][y];
                    if (tg[i][y] > 'a')
                    {
                        if (i-1 >= 0)
                        {
                            tmp2 = tg[i-1][y];
                            if (tg[i-1][y] == '.')  tg[i-1][y] = tg[i][y]-1;
                            else tg[i-1][y] += tg[i][y]-'a';
                        }
                    }
                    tg[i][y] = '.';
                    totstep++;
                    step[totstep] = 'U';
                    DFS(i,y,clic+1,tot,sx,sy);
                    totstep--;
                    tg[i][y] = tmp1;
                    if (i > 0)  tg[i-1][y] = tmp2;
                    break;
                }
    if (x+1 < n)
        if (tg[x+1][y] == '.')
            for (int i = x+2;i < n;i++)
                if (tg[i][y] != '.')
                {
                    tmp1 = tg[i][y];
                    if (tg[i][y] > 'a')
                    {
                        if (i+1 < n)
                        {
                            tmp2 = tg[i+1][y];
                            if (tg[i+1][y] == '.')  tg[i+1][y] = tg[i][y]-1;
                            else tg[i+1][y] += tg[i][y]-'a';
                        }
                    }
                    tg[i][y] = '.';
                    totstep++;
                    step[totstep] = 'D';
                    DFS(i,y,clic+1,tot,sx,sy);
                    totstep--;
                    tg[i][y] = tmp1;
                    if (i+1 < n)  tg[i+1][y] = tmp2;
                    break;
                }
    if (y-1 >= 0)
        if (tg[x][y-1] == '.')
            for (int i = y-2;i >= 0;i--)
                if (tg[x][i] != '.')
                {
                    tmp1 = tg[x][i];
                    if (tg[x][i] > 'a')
                    {
                        if (i-1 >= 0)
                        {
                            tmp2 = tg[x][i-1];
                            if (tg[x][i-1] == '.')  tg[x][i-1] = tg[x][i]-1;
                            else tg[x][i-1] += tg[x][i]-'a';
                        }
                    }
                    tg[x][i] = '.';
                    totstep++;
                    step[totstep] = 'L';
                    DFS(x,i,clic+1,tot,sx,sy);
                    totstep--;
                    tg[x][i] = tmp1;
                    if (i > 0)  tg[x][i-1] = tmp2;
                    break;
                }
    if (y+1 < m)
        if (tg[x][y+1] == '.')
            for (int i = y+2;i < m;i++)
                if (tg[x][i] != '.')
                {
                    tmp1 = tg[x][i];
                    if (tg[x][i] > 'a')
                    {
                        if (i+1 < m)
                        {
                            tmp2 = tg[x][i+1];
                            if (tg[x][i+1] == '.')  tg[x][i+1] = tg[x][i]-1;
                            else tg[x][i+1] += tg[x][i]-'a';
                        }
                    }
                    tg[x][i] = '.';
                    totstep++;
                    step[totstep] = 'R';
                    DFS(x,i,clic+1,tot,sx,sy);
                    totstep--;
                    tg[x][i] = tmp1;
                    if (i+1 < m)  tg[x][i+1] = tmp2;
                    break;
                }
}

void play(int sx,int sy)
{
    int tot = 0;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        {
            tg[i][j] = g[i][j];
            if (tg[i][j] >= 'a' && tg[i][j] <= 'z') tot += tg[i][j]-'a'+1;
        }
    totstep = 0;
    DFS(sx,sy,0,tot,sx,sy);
}

int main()
{
    while (scanf("%d%d",&m,&n) != EOF)
    {
        for (int i = 0;i < n;i++)   scanf("%s",g[i]);
        hasres = false;
        for (int i = 0;i < n && hasres == false;i++)
            for (int j = 0;j < m && hasres == false;j++)
                if (g[i][j] == '.')
                    play(i,j);
    }
}
