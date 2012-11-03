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

int getid(char *s)
{
    for (int i = 0;i < 100;i++)
    if (strcmp(s,g[i]) == 0)    return i+1;
    return -1;
}

int totnode;

void DFS(int now,int leava,int leavb,int sumnow,int use)
{
    totnode++;
    if (now == m+1)
    {
        hasres = true;
        return;
    }
    for (int i = now+1;i <= m;i++)
        if (dp[nb[i]+suma-leava] == false)  return;
    if (dp[nb[now]-sumnow+suma-leava] == false) return;
    if (hasres == true) return;
    if (leava != leavb) return;
    if (sumnow > nb[now])   return;
    if (sumnow == nb[now])
    {
        DFS(now+1,leava,leavb,0,use);
        return;
    }
    for (int i = n;i >= 1;i--)
    if (((use>>(i-1))&1) == 0)
        DFS(now,leava-na[i],leavb-na[i],sumnow+na[i],use|(1<<(i-1)));
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
        hasres = false;
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        for (int i = 1;i <= n;i++)
            for (int j = suma;j >= na[i];j--)
                dp[j] = dp[j]|dp[j-na[i]];
        bool flag = true;
        if (suma != sumb)   flag = false;
        for (int i = 1;i <= m;i++)
            if (dp[nb[i]] == false)
                flag = false;
        if (flag == false)
        {
            printf("NO\n");
            continue;
        }
        totnode = 0;
        DFS(1,suma,sumb,0,0);
        //cout << n << ' ' << m << ' ' << totnode << endl;
        if (hasres == false)    printf("NO\n");
        else printf("YES\n");
    }
}

