#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,s[11][11],res[11];

void DFS(int n,int nowuse,int now,int totd,int nowd,int totind,int use)
{
    if (n == nowuse)    return;
    if (totd == nowd+1)
    {
        int tuse = 0;
        bool first ;
        for (int i = 1;i <= nowd;i++)
        {
            printf("{");
            first = true;
            for (int j = 1;j <= n;j++)
                if ((((res[i]>>(j-1))&1) == 1) && (((tuse>>(j-1))&1) == 0))
                {
                    if (first == false) printf(",");
                    first = false;
                    printf("%d",j);
                    tuse = tuse|(1<<(j-1));
                }
            printf("},");
        }
        first = true;
        printf("{");
        for (int i = 1;i <= n;i++)
            if (((tuse>>(i-1))&1) == 0)
            {
                if (first == false) printf(",");
                first = false;
                printf("%d",i);
            }
        printf("}\n");
        return;
    }
    if (totind == 0)
    {
        for (int i = 1;i <= n;i++)
            if (((use>>(i-1))&1) == 0)
            {
                DFS(n,nowuse+1,i,totd,nowd,totind+1,use|(1<<(i-1)));
                break;
            }
        return;
    }
    res[nowd+1] = use;
    DFS(n,nowuse,0,totd,nowd+1,0,use);
    for (int i = now+1;i <= n;i++)
        if (((use>>(i-1))&1) == 0)
            DFS(n,nowuse+1,i,totd,nowd,totind+1,use|(1<<(i-1)));
}

int main()
{
    memset(s,0,sizeof(s));
    s[0][0] = 1;
    for (int i = 1;i <= 10;i++)
        for (int j = 1;j <= 10;j++)
            s[i][j] = j*s[i-1][j]+s[i-1][j-1];
    scanf("%d",&n);
    int tot = 0;
    for (int i = 1;i <= n;i++)
        tot += s[n][i];
    printf("%d\n",tot);
    for (int i = 1;i <= n;i++)
        DFS(n,0,0,i,0,0,0);
}
