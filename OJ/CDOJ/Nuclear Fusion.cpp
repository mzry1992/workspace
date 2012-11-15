#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const char g[100][5] =
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
int na[20],nb[20],suma,sumb;
bool hasres,dp[120*20];
int f[1<<18];

int getid(char *s)
{
    for (int i = 0;i < 100;i++)
    if (strcmp(s,g[i]) == 0)    return i+1;
    return -1;
}

bool DFS(int now,int last,int tota,int nowb,int use)
{
    if (f[use] != 0)
        if (f[use] == 2)    return true;
        else return false;
    if (now == m+1)
    {
        hasres = true;
        f[use] = 2;
        return true;
    }
    if (nowb == nb[now])
    {
        for (int i = now+1;i <= m;i++)
            if (dp[nb[i]+tota] == false)
            {
                f[use] = 1;
                return false;
            }
        bool res = DFS(now+1,0,tota,0,use);
        if (res == true)    f[use] = 2;
        else f[use] = 1;
        return res;
    }
    for (int i = last+1;i <= n;i++)
        if (((use>>(i-1))&1) == 0)
        {
            if (na[i] > nb[now]-nowb)   break;
            if (DFS(now,i,tota+na[i],nowb+na[i],use|(1<<(i-1))) == true)
            {
                f[use] = 2;
                return true;
            }
        }
    f[use] = 1;
    return false;
}

int main()
{
    while (scanf("%d%d",&n,&m) == 2)
    {
        suma = sumb = 0;
        for (int i = 1;i <= n;i++)  {scanf("%s",a[i]);na[i] = getid(a[i]);suma += na[i];}
        for (int i = 1;i <= m;i++)  {scanf("%s",b[i]);nb[i] = getid(b[i]);sumb += nb[i];}
        sort(na+1,na+1+n);
        sort(nb+1,nb+1+m);
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        for (int i = 1;i <= n;i++)
            for (int j = suma;j >= na[i];j--)
                dp[j] = dp[j]|dp[j-na[i]];
        hasres = true;
        if (suma != sumb)   hasres = false;
        for (int i = 1;i <= m;i++)
            if (dp[nb[i]] == false) hasres = false;
        if (hasres == true)
        {
            memset(f,0,sizeof(f));
            hasres = DFS(1,0,0,0,0);
        }
        if (hasres == false)    printf("NO\n");
        else printf("YES\n");
    }
}
