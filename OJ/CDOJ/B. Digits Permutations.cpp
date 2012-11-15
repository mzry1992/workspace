#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[100001],resa[100001],resb[100001];
int n,tot[10],ta[10],tb[10],res,len,ress;

int Gao(int ff)
{
    for (int i = 0; i < 10; i++)
        ta[i] = tb[i] = tot[i];
    int a,b;
    a = ff;
    b = 10-a;
    if (ta[a] == 0 || tb[b] == 0)   return tot[0];
    ta[a]--;
    tb[b]--;
    int res = tot[0]+1;
    ta[0] = tb[0] = 0;
    for (int i = 1; i < 10; i++)
    {
        int tot = min(ta[i],tb[9-i]);
        res += tot;
        ta[i] -= tot;
        tb[9-i] -= tot;
    }
    return res;
}

void Output(int ff)
{
    if (ff == -1)
    {
        puts(s);
        puts(s);
        return;
    }
    for (int i = 0; i < 10; i++)
        ta[i] = tb[i] = tot[i];
    len = 0;
    for (int i = 0; i < tot[0]; i++)
    {
        resa[len] = resb[len] = '0';
        len++;
    }
    ta[0] = tb[0] = 0;
    int a,b;
    a = ff;
    b = 10-a;
    resa[len] = '0'+a;
    resb[len] = '0'+b;
    len++;
    ta[a]--;
    tb[b]--;
    for (int i = 1; i < 10; i++)
    {
        int tot = min(ta[i],tb[9-i]);
        ta[i] -= tot;
        tb[9-i] -= tot;
        for (int j = 0;j < tot;j++)
        {
            resa[len] = '0'+i;
            resb[len] = '0'+9-i;
            len++;
        }
    }
    int tlen = len;
    for (int i = 0;i < 10;i++)
        for (int j = 0;j < ta[i];j++)
            resa[len++] = '0'+i;
    for (int i = 0;i < 10;i++)
        for (int j = 0;j < tb[i];j++)
            resb[tlen++] = '0'+i;
    for (int i = len-1;i >= 0;i--)
        putchar(resa[i]);
    puts("");
    for (int i = len-1;i >= 0;i--)
        putchar(resb[i]);
    puts("");
}

int main()
{
    while (scanf("%s",s) != EOF)
    {
        n = strlen(s);
        for (int i = 0; i < 10; i++)  tot[i] = 0;
        for (int i = 0; i < n; i++)
            tot[s[i]-'0']++;
        res = tot[0];
        ress = -1;
        for (int i = 1; i < 10; i++)
        {
            len = Gao(i);
            if (len > res)
            {
                res = len;
                ress = i;
            }
        }
        Output(ress);
    }
    return 0;
}
