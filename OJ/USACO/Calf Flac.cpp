/*
ID: muziriy3
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[30000],ts[30000],ks[30000];
int pos[30000];
int ml,mr;

int main()
{
    freopen("calfflac.in","r",stdin);
    freopen("calfflac.out","w",stdout);
    int l = 0;
    int kl = 0;
    while (gets(ts))
    {
        for (int i = 0;i < strlen(ts);i++)
        {
            if (('A' <= ts[i] && ts[i] <= 'Z') || ('a' <= ts[i] && ts[i] <= 'z'))
            {
                s[l] = ts[i];
                if ('A' <= s[l] && s[l] <= 'Z')
                    s[l] = s[l]-'A'+'a';
                pos[l] = kl;
                l++;
            }
            ks[kl] = ts[i];
            kl++;
        }
        ks[kl] = '\n';
        kl++;
    }
    ml = mr = 0;
    for (int i = 1;i < l;i++)
    {
        bool flag1,flag2;
        flag1 = flag2 = true;
        for (int j = 0;j <= i;j++)
        if (flag1 == false && flag2 == false)   break;
        else
        {
            if (i+j == l)   flag1 = false;
            else
                if (s[i-j] != s[i+j])   flag1 = false;
            if (i+1+j == l) flag2 = false;
            else
                if (s[i-j] != s[i+1+j]) flag2 = false;
            if (flag1 == true)
            if (mr-ml+1 < j*2+1)
            {
                ml = i-j;
                mr = i+j;
            }
            if (flag2 == true)
            if (mr-ml+1 < j*2+2)
            {
                ml = i-j;
                mr = i+1+j;
            }
        }
    }
    printf("%d\n",mr-ml+1);
    for (int i = pos[ml];i <= pos[mr];i++)
        printf("%c",ks[i]);
    printf("\n");
}
