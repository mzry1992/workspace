#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char s[120],s1[60],s2[120];
const int pos[12] = {3,10,17,24,31,38,50,57,64,71,78,85};
int tot;
char res[10][15];
char tres[15];
const string numl[10] = {"0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011"};
const string numr[10] = {"1110010","1100110","1101100","1000010","1011100","1001110","1010000","1000100","1001000","1110100"};

int checkr(char s[120],int l)
{
    char ts[8];
    for (int i = 0;i < 7;i++)
        ts[i] = s[l+i];
    ts[7] = 0;
    if (strcmp(ts,"1110010") == 0)  return 0;
    if (strcmp(ts,"1100110") == 0)  return 1;
    if (strcmp(ts,"1101100") == 0)  return 2;
    if (strcmp(ts,"1000010") == 0)  return 3;
    if (strcmp(ts,"1011100") == 0)  return 4;
    if (strcmp(ts,"1001110") == 0)  return 5;
    if (strcmp(ts,"1010000") == 0)  return 6;
    if (strcmp(ts,"1000100") == 0)  return 7;
    if (strcmp(ts,"1001000") == 0)  return 8;
    if (strcmp(ts,"1110100") == 0)  return 9;
    return -1;
}

int checkl(char s[120],int l)
{
    char ts[8];
    for (int i = 0;i < 7;i++)
        ts[i] = s[l+i];
    ts[7] = 0;
    if (strcmp(ts,"0001101") == 0)  return 0;
    if (strcmp(ts,"0011001") == 0)  return 1;
    if (strcmp(ts,"0010011") == 0)  return 2;
    if (strcmp(ts,"0111101") == 0)  return 3;
    if (strcmp(ts,"0100011") == 0)  return 4;
    if (strcmp(ts,"0110001") == 0)  return 5;
    if (strcmp(ts,"0101111") == 0)  return 6;
    if (strcmp(ts,"0111011") == 0)  return 7;
    if (strcmp(ts,"0110111") == 0)  return 8;
    if (strcmp(ts,"0001011") == 0)  return 9;
    return -1;
}

bool check(char tres[15])
{
    for (int i = 0;i < 12;i++)
    if (tres[i] < '0' || tres[i] > '9') return false;
    int d0,d1;
    int c,cs;
    c = tres[11]-'0';
    d0 = d1 = 0;
    for (int i = 1;i <= 9;i += 2)
        d0 += (tres[i]-'0');
    for (int i = 0;i <= 10;i += 2)
        d1 += (tres[i]-'0');
    cs = 3*d1+d0;
    cs %= 10;
    int tc;
    if (cs == 0)    tc = 0;
    else tc = 10-cs;
    if (tc != c)    return false;
    return true;
}

void DFS(int now)
{
    if (tot == 9)   return;
    if (now == 12)
    {
        if (check(tres) == true)
        {
            tot++;
            if (tot <= 8)
            {
                for (int i = 0;i < 12;i++)
                    res[tot][i] = tres[i];
                res[tot][12] = 0;
            }
        }
        return;
    }
    bool flag = true;
    for (int i = 0;i < 7;i++)
    if (s[pos[now]+i] == '?')
    {
        flag = false;
        break;
    }
    if (flag == true)
    {
        if (now < 6)
            tres[now] = checkl(s,pos[now])+'0';
        else
            tres[now] = checkr(s,pos[now])+'0';
        DFS(now+1);
    }
    else
    {
        if (now < 6)
        {
            for (int i = 0;i < 10;i++)
            {
                bool tflag = true;
                for (int j = 0;j < 7;j++)
                if (s[pos[now]+j] != '?')
                if (s[pos[now]+j] != numl[i][j])
                {
                    tflag = false;
                    break;
                }
                if (tflag == true)
                {
                    tres[now] = i+'0';
                    DFS(now+1);
                }
            }
        }
        else
        {
            for (int i = 0;i < 10;i++)
            {
                bool tflag = true;
                for (int j = 0;j < 7;j++)
                if (s[pos[now]+j] != '?')
                if (s[pos[now]+j] != numr[i][j])
                {
                    tflag = false;
                    break;
                }
                if (tflag == true)
                {
                    tres[now] = i+'0';
                    DFS(now+1);
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int ft = 1;ft <= T;ft++)
    {
        int tt;
        scanf("%d",&tt);
        scanf("%s",s2);
        scanf("%s",s1);
        strcat(s2,s1);
        if (checkl(s2,3) == -1)
        {
            int tl = strlen(s2);
            for (int i = 0;i < tl;i++)
                s[i] = s2[tl-1-i];
            s[tl] = 0;
            if (checkr(s,3) == -1)
            {
                printf("%d %d\n",tt,0);
                continue;
            }
        }
        else
        {
            int tl = strlen(s2);
            for (int i = 0;i <= tl;i++)
                s[i] = s2[i];
        }
        tot = 0;
        DFS(0);
        if (tot > 8)    tot = 9;
        printf("%d %d\n",tt,tot);
        if (tot > 8)    tot = 8;
        for (int i = 1;i <= tot;i++)
            puts(res[i]);
    }
}
