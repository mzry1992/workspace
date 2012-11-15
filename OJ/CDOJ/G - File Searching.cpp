#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char pre[120][100],nex[120][100];
char tpre[120],tnex[120];
char tt[120];
char res[120];
int totres;

bool gao(char a[100],char b[100])
{
    int cur = 0;
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
    char ta[100],tb[100];
    int tal = 0;
    for (int i = 0;i < pos;i++)
    {
        ta[tal] = a[i];
        tal++;
    }
    for (int i = pos+1;i < la;i++)
    {
        ta[tal] = a[i];
        tal++;
    }
    ta[tal] = 0;
    if (strcmp(ta,b) == 0)  return true;
    for (int i = 0;i < lb;i++)
    for (int j = i;j < lb;j++)
    {
        int tbl = 0;
        for (int k = 0;k < i;k++)
        {
            tb[tbl] = b[k];
            tbl++;
        }
        for (int k = j+1;k < lb;k++)
        {
            tb[tbl] = b[k];
            tbl++;
        }
        tb[tbl] = 0;
        //cout << i << ' ' << j << ' ' << tb << endl;
        if (strcmp(ta,tb) == 0) return true;
    }
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
        {
            scanf("%s",tt);
            int prel,nexl;
            int ltt = strlen(tt);
            prel = nexl = 0;
            bool ispre = true;
            for (int j = 0;j < ltt;j++)
            if (tt[j] == '.')
                ispre = false;
            else
            {
                if (ispre == true)
                {
                    pre[i][prel] = tt[j];
                    prel++;
                }
                else
                {
                    nex[i][nexl] = tt[j];
                    nexl++;
                }
            }
            pre[i][prel] = nex[i][nexl] = 0;
        }
        scanf("%d",&m);
        for (int i = 1;i <= m;i++)
        {
            scanf("%s",tt);
            int prel,nexl;
            prel = nexl = 0;
            int ltt = strlen(tt);
            bool ispre = true;
            for (int j = 0;j < ltt;j++)
            if (tt[j] == '.')
                ispre = false;
            else
            {
                if (ispre == true)
                {
                    tpre[prel] = tt[j];
                    prel++;
                }
                else
                {
                    tnex[nexl] = tt[j];
                    nexl++;
                }
            }
            tpre[prel] = tnex[nexl] = 0;
            totres = 0;
            bool tfirst = true;
            for (int j = 1;j <= n;j++)
            {
                bool cmpp,cmpn;
                cmpp = gao(tpre,pre[j]);
                cmpn = gao(tnex,nex[j]);
                if (cmpp == true && cmpn == true)
                {
                    totres++;
                    if (tfirst == false)
                        printf(", ");
                    tfirst = false;
                    printf("%s",pre[j]);
                    if (strlen(nex[j]) != 0)
                        printf(".%s",nex[j]);
                }
            }
            if (totres == 0)
                printf("FILE NOT FOUND\n");
            else
                printf("\n");
        }
    }
}
