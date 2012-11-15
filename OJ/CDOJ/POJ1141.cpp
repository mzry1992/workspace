#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char st[110],ast[110][110][500];
int len,ans[110][110],fans[110][110];

void scopy(int i,int j,int l,int r)
{
     int len;
     len = strlen(ast[l][r]);
     for (int ti = 0;ti <= len;ti++)
         ast[i][j][ti] = ast[l][r][ti];
}

void sadd(int i,int j,char ch,int order)
{
     if (order == 0)
     {
               int len;
               len = strlen(ast[i][j]);
               for (int ti = len;ti >= 0;ti--)
                   ast[i][j][ti+1] = ast[i][j][ti];
               ast[i][j][0] = ch;
     }
     else
     {
               int len;
               len = strlen(ast[i][j]);
               ast[i][j][len] = ch;
               ast[i][j][len+1] = '\0';
     }
}

void scat(int l,int r,int i1,int j1,int i2,int j2)
{
     int len1,len2;
     len1 = strlen(ast[i1][j1]);
     len2 = strlen(ast[i2][j2]);
     for (int ti = 0;ti <= len1-1;ti++)
         ast[l][r][ti] = ast[i1][j1][ti];
     for (int ti = 0;ti <= len2;ti++)
         ast[l][r][len1+ti] = ast[i2][j2][ti];
}

int solve(int l,int r)
{
    int i,j,answer,temp,temp2;
    if (fans[l][r] == 0) return ans[l][r];
    if (l > r) return 0;
    if (l == r) 
    {
       ast[l][r][0] = st[l];
       ast[l][r][1] = '\0';
       if (st[l] == '(') sadd(l,r,')',1);
       if (st[l] == '[') sadd(l,r,']',1);
       if (st[l] == ')') sadd(l,r,'(',0);
       if (st[l] == ']') sadd(l,r,'[',0);
       return 1;
    }
    answer = 19921005;
    if (((st[l] == '(') && (st[r] == ')')) || ((st[l] == '[') && (st[r] == ']')))
    {
                temp = solve(l+1,r-1);
                if (answer >= temp) 
                {
                           answer = temp;
                           scopy(l,r,l+1,r-1);
                           sadd(l,r,st[l],0);
                           sadd(l,r,st[r],1);
                }
    }
    if ((st[l] == '(') || (st[l] == '['))
    {
               temp = solve(l+1,r)+1;
               if (answer >= temp) 
               {
                  answer = temp;
                  scopy(l,r,l+1,r);
                  sadd(l,r,st[l],0);
                  if (st[l] == '(') sadd(l,r,')',1);
                  if (st[l] == '[') sadd(l,r,']',1);
               }
    }
    if ((st[r] == ')') || (st[r] == ']'))
    {
               temp = solve(l,r-1)+1;
               if (answer >= temp) 
               {
                  answer = temp;
                  scopy(l,r,l,r-1);
                  sadd(l,r,st[r],1);
                  if (st[l] == ')') sadd(l,r,'(',0);
                  if (st[l] == ']') sadd(l,r,'[',0);
               }
    }
    for (i = l;i <= r-1;i++)
    {
        temp = solve(l,i);
        temp2 = solve(i+1,r);
        if (answer >= temp+temp2) 
        {
                   answer = temp+temp2;
                   scat(l,r,l,i,i+1,r);
        }
    }
    fans[l][r] = 0;
    ans[l][r] = answer;
    return answer;
}

int main()
{
    while (gets(st))
    {
        for (int i = 0;i <= 100;i++)
        for (int j = 0;j <= 100;j++)
            fans[i][j] = 1;
        len = strlen(st);
        if (!len)
        {
                 cout << endl;
                 continue;
        }
        solve(0,len-1);
        cout << ast[0][len-1] << endl;
    }
    return 0;
}
