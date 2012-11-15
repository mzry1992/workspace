#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

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
struct graph
{
    int to,next;
}g[1<<18];
int totg;
bool hasres,canuse[1<<18];

int getid(char *s)
{
    for (int i = 0;i < 100;i++)
    if (strcmp(s,nuclear[i]) == 0)    return i+1;
    return -1;
}

void addedge(int u,int v)
{
    totg++;
    g[totg].to = v;
    g[totg].next = g[u].next;
    g[u].next = totg;
}

int totnode;

void DFS(int now,int use)
{
    totnode++;
    if (now == m+1) hasres = true;
    if (hasres == true) return;
    for (int ii = g[nb[now]].next;ii != -1;ii = g[ii].next)
    {
        int i = g[ii].to;
        bool cango = true;
        for (int j = 0;j < n;j++)
            if (((i>>j)&1) == 1 && ((use>>j)&1) == 1)
            {
                cango = false;
                break;
            }
        if (cango == true)
            DFS(now+1,use|i);
    }
}

int main()
{
    while (scanf("%d%d",&n,&m) == 2)
    {
        for (int i = 1;i <= n;i++)  {scanf("%s",a[i]);na[i] = getid(a[i]);}
        for (int i = 1;i <= m;i++)  {scanf("%s",b[i]);nb[i] = getid(b[i]);}
        memset(sum,0,sizeof(sum));
        for (int i = 0;i < (1<<n);i++)
            for (int j = 1;j <= n;j++)
                if (((i>>(j-1))&1) == 1)
                    sum[i] += na[j];
        for (int i = 1;i <= 100;i++)    g[i].next = -1;
        memset(canuse,false,sizeof(canuse));
        for (int i = 0;i < (1<<n);i++)
            for (int j = 1;j <= m;j++)
                if (sum[i] == nb[j])
                    canuse[i] = true;
        totg = 100;
        for (int i = 0;i < (1<<n);i++)
            if (sum[i] <= 100)
                addedge(sum[i],i);
        bool ttest = true;
        for (int i = 1;i <= m;i++)
            if (g[nb[i]].next == -1)
                ttest = false;
        if (ttest == false)
        {
            printf("NO\n");
            continue;
        }
        hasres = false;
        totnode = 0;
        DFS(1,0);
        //cout << "Tot node = " << totnode << endl;
        if (hasres == false)    printf("NO\n");
        else printf("YES\n");
    }
}
