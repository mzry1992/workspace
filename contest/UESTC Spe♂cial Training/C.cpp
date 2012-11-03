#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,lr,lc;
char mp[20][20];
int num[60],cntE,cntB,bx[20],by[20],ex[60],ey[60],id[60][60];
int repairB;

bool g[60][60];
int N;

void INIT(int n)
{
    N = n;
    memset(g,false,sizeof(g));
}

void ADD(int s,int t)
{
    printf("ADD : %d -----> %d\n",s,t);
    g[s][t] = true;
}

int RUN()
{
    return 0;
}

int idB[20],totB;

void DFSB(int ids,int x,int y)
{
    if (x >= n || y >= m || mp[x][y] == '#')    return;

    if (mp[x][y] == 'B')
        if (id[x][y] != ids && ((repairB>>id[x][y])&1) == 1)
            ADD(idB[ids],idB[id[x][y]]);
    DFSB(ids,x+1,y);
    DFSB(ids,x,y+1);
}

void DFSE(int ids,int x,int y)
{
    if (x >= n || y >= m || mp[x][y] == '#')    return;
    if (mp[x][y] == 'B' && ((repairB>>id[x][y])&1) == 0)
        return;

    if (mp[x][y] == 'E')
    {
        ADD(ids,id[x][y]);
    }

    DFSE(ids,x+1,y);
    DFSE(ids,x,y+1);
}

bool GAO()
{
    for (repairB = 0; repairB < (1<<cntB); repairB++)
    {
        totB = 0;
        for (int i = 0;i < cntB;i++)
            if (((repairB>>i)&1) == 1)
                idB[i] = totB++;
        INIT(totB);
        for (int i = 0; i < cntB; i++)
            if (((repairB>>i)&1) == 1)
                DFSB(i,bx[i],by[i]);
        if (RUN())
        {

            for (int i = 0; i < cntE; i++)
                DFSE(i,ex[i],ey[i]);
            if (RUN())
                return true;
        }
    }
    return false;
}

int main()
{
    int totcas;
    scanf("%d",&totcas);
    for (int cas = 1; cas <= totcas; cas++)
    {
        scanf("%d%d%d%d",&n,&m,&lr,&lc);
        cntE = cntB = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%s",mp[i]);
            for (int j = 0; mp[i][j] != 0; j++)
                if (mp[i][j] == 'E')
                {
                    ex[cntE] = i;
                    ey[cntE] = j;
                    id[i][j] = cntE++;
                }
                else if (mp[i][j] == 'B')
                {
                    bx[cntB] = i;
                    by[cntB] = j;
                    id[i][j] = cntB++;
                }
        }
        for (int i = 0; i < cntE; i++)
            scanf("%d",&num[i]);

        if (GAO())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}

