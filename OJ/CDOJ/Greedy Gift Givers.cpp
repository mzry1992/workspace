/*
ID: muziriy3
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char name[20][100];
int g[20];
char tname[200];
int tt,tn;
char tto[200];

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        scanf("%s",name[i]);
    memset(g,0,sizeof(g));
    for (int i = 1;i <= n;i++)
    {
        scanf("%s",tname);
        int cur;
        for (int j = 1;j <= n;j++)
        if (strcmp(tname,name[j]) == 0)
            cur = j;
        scanf("%d%d",&tt,&tn);
        g[cur] -= tt;
        if (tn != 0)
            g[cur] += tt%tn;
        for (int j = 1;j <= tn;j++)
        {
            scanf("%s",tto);
            int curto;
            for (int k = 1;k <=n;k++)
            if (strcmp(tto,name[k]) == 0)
                curto = k;
            g[curto] += tt/tn;
        }
    }
    for (int i = 1;i <= n;i++)
        printf("%s %d\n",name[i],g[i]);
}
