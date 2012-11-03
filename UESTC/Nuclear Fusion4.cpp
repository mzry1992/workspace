#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MaxN = 1010;
const int MaxM = 1010;
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
        printf("%d ",deep);
        for (int i = 0;i < deep;i++)
            printf("%d ",O[i]);
        printf("\n");
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
        if (R[0] == 0)  {hasans = true; /*print(deep);*/   return;};
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
const char nuclear[100][5] =
{"H","He","Li","Be","B","C","N","O","F","Ne",
"Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca",
"Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu",
"Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr",
"Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag",
"Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba",
"La","Ce","Pr","Nd","Pm","Sm","Eu","Gd",
"Tb","Dy","Ho","Er","Tm","Yb","Lu","Hf","Ta",
"W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb",
"Bi","Po","At","Rn","Fr","Ra","Ac","Th","Pa",
"U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm" };
int n,m;
char a[20][5],b[20][5];
int na[20],nb[20],sum[1<<18];

int getid(char *s)
{
    for (int i = 0;i < 100;i++)
    if (strcmp(s,nuclear[i]) == 0)    return i+1;
    return -1;
}

int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        for (int i = 1;i <= n;i++)  {scanf("%s",a[i]);na[i] = getid(a[i]);}
        for (int i = 1;i <= m;i++)  {scanf("%s",b[i]);nb[i] = getid(b[i]);}
        memset(sum,0,sizeof(sum));
        for (int i = 0;i < (1<<n);i++)
            for (int j = 1;j <= n;j++)
                if (((i>>(j-1))&1) == 1)
                    sum[i] += na[j];
        int totn = 0;
        for (int i = 0;i < (1<<n);i++)
            if (sum[i] <= 100)  totn++;
        g.n = totn;
        g.m = n+m;
        g.init();
        for (int i = 0;i < (1<<n);i++)
            if (sum[i] <= 100)
                for (int j = 1;j <= m;j++)
                    if (sum[i] == nb[j])
                    {
                        g.insert(i+1,n+j);
                        for (int k = 1;k <= n;k++)
                            if (((i>>(k-1))&1) == 1)
                                g.insert(i+1,k);
                    }
        g.initDFS();
        g.DFS(0);
        if (g.hasans == false)  printf("NO\n");
        else printf("YES\n");
    }
}
