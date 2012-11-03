#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 5000;
const int MaxM = 1200;
int res[MaxN][3];
char s[20][20];
int sudoku[20][20];
const int block[17][17] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                           {0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4},{0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4},{0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4},{0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4},
                           {0,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8},{0,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8},{0,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8},{0,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8},
                           {0,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12},{0,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12},{0,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12},{0,9,9,9,9,10,10,10,10,11,11,11,11,12,12,12,12},
                           {0,13,13,13,13,14,14,14,14,15,15,15,15,16,16,16,16},{0,13,13,13,13,14,14,14,14,15,15,15,15,16,16,16,16},{0,13,13,13,13,14,14,14,14,15,15,15,15,16,16,16,16},{0,13,13,13,13,14,14,14,14,15,15,15,15,16,16,16,16}};
struct DLX
{
    int h,n,m,tot;
    int U[MaxN*MaxM],D[MaxN*MaxM],L[MaxN*MaxM],R[MaxN*MaxM],Row[MaxN*MaxM],Col[MaxN*MaxM];
    int S[MaxM],O[MaxN];
    bool hasans;
    void init()
    {
        h = 0;
        hasans = false;
        tot = m+n;
        for (int i = 0;i <= m;i++)
        {
            D[i] = U[i] = Col[i] = i;
            Row[i] = S[i] = 0;
            L[i] = (i+m)%(m+1);
            R[i] = (i+1)%(m+1);
        }
        for (int i = 1;i <= n;i++)
        {
            R[i+m] = L[i+m] = i+m;
            Row[i+m] = i;
            Col[i+m] = 0;
        }
    }
    void insert(int x,int y)
    {
        tot++;
        Row[tot] = x;   Col[tot] = y;   S[y]++;
        int colPos,rowPos;
        colPos = y;
        while (true)
        {
            colPos = D[colPos];
            if (colPos == y || Row[colPos] > x)    break;
        }
        colPos = U[colPos];
        if (Row[colPos] == x)   return;
        U[tot] = colPos;    D[tot] = D[colPos]; U[D[tot]] = D[U[tot]] = tot;
        rowPos = x+m;
        while (true)
        {
            rowPos = R[rowPos];
            if (rowPos == x+m || Col[rowPos] > y)    break;
        }
        rowPos = L[rowPos];
        if (Col[rowPos] == y)   return;
        L[tot] = rowPos;    R[tot] = R[rowPos]; L[R[tot]] = R[L[tot]] = tot;
    }
    void print(int deep)
    {
        for (int i = 0;i < deep;i++)
            sudoku[res[O[i]][0]][res[O[i]][1]] = res[O[i]][2];
    }
    void cover(int col)
    {
        L[R[col]] = L[col]; R[L[col]] = R[col];
        for (int i = D[col];i != col;i = D[i])
            for (int j = R[i];j != i;j = R[j])
                if (Col[j] != col)
                {
                    U[D[j]] = U[j]; D[U[j]] = D[j];
                    S[Col[j]]--;
                }
    }
    void resume(int col)
    {
        for (int i = U[col];i != col;i = U[i])
            for (int j = L[i];j != i;j = L[j])
                if (Col[j] != col)
                {
                    S[Col[j]]++;
                    U[D[j]] = j;    D[U[j]] = j;
                }
        L[R[col]] = col;
        R[L[col]] = col;
    }
    void initDFS()
    {
        for (int i = 1;i <= n;i++)
        {
            L[R[i+m]] = L[i+m];
            R[L[i+m]] = R[i+m];
        }
    }
    void DFS(int deep)
    {
        if (hasans == true) return;
        if (R[0] == 0)  {hasans = true; print(deep);   return;};
        int tc = R[0];
        for (int i = R[0];i != 0;i = R[i])
            if (S[i] < S[tc])   tc = i;
        cover(tc);
        for (int i = D[tc];i != tc;i = D[i])
        {
            int temp = O[deep];
            O[deep] = Row[i];
            for (int j = R[i];j != i;j = R[j])
                cover(Col[j]);
            DFS(deep+1);
            for (int j = L[i];j != i;j = L[j])
                resume(Col[j]);
            O[deep] = temp;
        }
        resume(tc);
    }
}g;

int main()
{
    while (scanf("%s",s[0]) != EOF)
    {
        for (int i = 1;i < 16;i++)
            scanf("%s",s[i]);
        for (int i = 1;i <= 16;i++)
            for (int j = 1;j <= 16;j++)
                if (s[i-1][j-1] == '-')
                    sudoku[i][j] = 0;
                else
                    sudoku[i][j] = s[i-1][j-1]-'A'+1;
        g.n = 16*16*16;
        g.m = (16+16+16)*16+16*16;
        g.init();
        for (int i = 1;i <= 16;i++)
            for (int j = 1;j <= 16;j++)
                if (sudoku[i][j] == 0)
                {
                    for (int k = 1;k <= 16;k++)
                    {
                        int idx = ((i-1)*16+j-1)*16+k;
                        g.insert(idx,(i-1)*16+k);
                        g.insert(idx,16*16+(j-1)*16+k);
                        g.insert(idx,16*16+16*16+(block[i][j]-1)*16+k);
                        g.insert(idx,(16+16+16)*16+(i-1)*16+j);
                        res[idx][0] = i;
                        res[idx][1] = j;
                        res[idx][2] = k;
                    }
                }
                else
                {
                    int k = sudoku[i][j];
                    int idx = ((i-1)*16+j-1)*16+k;
                    g.insert(idx,(i-1)*16+k);
                    g.insert(idx,16*16+(j-1)*16+k);
                    g.insert(idx,16*16+16*16+(block[i][j]-1)*16+k);
                    g.insert(idx,(16+16+16)*16+(i-1)*16+j);
                    res[idx][0] = i;
                    res[idx][1] = j;
                    res[idx][2] = k;
                }
        g.initDFS();
        g.DFS(0);
        for (int i = 1;i <= 16;i++)
        {
            for (int j = 1;j <= 16;j++)
                printf("%c",(char)(sudoku[i][j]+'A'-1));
            printf("\n");
        }
        printf("\n");
    }
}

