#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char s[120][120];
char tt[120];
int totres;

bool gao(char a[100],char b[100])
{
    int pos = -1;
    int la = strlen(a);
    int lb = strlen(b);
    for (int i = 0;i < la;i++)
    if (a[i] == '*')
        pos = i;
    if (pos == -1)
        if (strcmp(a,b) == 0)
            return true;
        else
            return false;
    for (int i = 0;i < pos;i++)
    {
        if (i >= lb)    return false;
        if (a[i] != b[i])   return false;
    }
    int ll = pos-1;
    int ttt = la-pos-1;
    for (int i = 0;i < ttt;i++)
    {
        if (lb-1-i < 0)    return false;
        if (a[la-1-i] != b[lb-1-i]) return false;
    }
    int rr = lb-ttt;
    if (ll < rr)    return true;
    return false;
}

int main()
{
    bool first = true;
    while (scanf("%d",&n) != EOF)
    {
        if (first == false)
            printf("\n");
        first = false;
        for (int i = 1;i <= n;i++)
            scanf("%s",s[i]);
        scanf("%d",&m);
        for (int i = 1;i <= m;i++)
        {
            scanf("%s",tt);
            int ltt = strlen(tt);
            totres = 0;
            bool tfirst = true;
            for (int j = 1;j <= n;j++)
            {
                bool cmpp,cmpn;
                cmpp = gao(tt,s[j]);
                if (cmpp == true)
                {
                    totres++;
                    if (tfirst == false)
                        printf(", ");
                    tfirst = false;
                    printf("%s",s[j]);
                }
            }
            if (totres == 0)
                printf("FILE NOT FOUND\n");
            else
                printf("\n");
        }
    }
}
