/*
ID: muziriy3
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

char s[300000],temp[300];
char ls[1000][20];
int l[1000];
int tot;
bool dp[300000];
int maxl;

int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    tot = 0;
    maxl = 0;
    while (true)
    {
        tot++;
        scanf("%s",ls[tot]);
        if (ls[tot][0] == '.')
        {
            tot--;
            break;
        }
        l[tot] = strlen(ls[tot]);
        if (l[tot] > maxl)
            maxl = l[tot];
    }
    int h = 0;
    while (scanf("%s",s+h) == 1)
        h += strlen(s+h);
    memset(dp,false,sizeof(dp));
    dp[0] = true;
    int res = 0;
    for (int i = 0;i < h;i++)
    {
        if (i-res > maxl)   break;
        for (int j = 1;j <= tot;j++)
        if (dp[i+1] == false)
        if (i-l[j]+1 >= 0)
        if (dp[i-l[j]+1] == true)
        {
            bool equal = true;
            for (int k = 0;k < l[j];k++)
            if (s[i-l[j]+1+k] != ls[j][k])
            {
                equal = false;
                break;
            }
            if (equal == true)
            {
                dp[i+1] = true;
                break;
            }
        }
        if (dp[i+1] == true)    res = i+1;
    }
    printf("%d\n",res);
}
