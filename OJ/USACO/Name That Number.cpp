/*
ID: muziriy3
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int tot;
char dic[6000][30];
char num[30];
char p[10][4];
bool flag;
struct tire
{
    int next[26];
    int flag;
}buf[100000];
int totbuf;

void DFS(int now,int cur)
{
    if (now >= strlen(num))
    {
        if (buf[cur].flag != -1)
        {
            puts(dic[buf[cur].flag]);
            flag = true;
        }
    }
    else
    {
        for (int i = 1;i <= 3;i++)
        if (buf[cur].next[p[num[now]-'0'][i]-'A'] != -1)
            DFS(now+1,buf[cur].next[p[num[now]-'0'][i]-'A']);
    }
}

int main()
{
    freopen("dict.txt","r",stdin);
    totbuf = 0;
    buf[0].flag = false;
    for (int i = 0;i < 'Z'-'A';i++)
        buf[0].next[i] = -1;
    tot = 0;
    while (scanf("%s",dic[tot]) == 1)
    {
        int cur = 0;
        for (int i = 0;i < strlen(dic[tot]);i++)
        if (buf[cur].next[dic[tot][i]-'A'] != -1)
            cur = buf[cur].next[dic[tot][i]-'A'];
        else
        {
            totbuf++;
            buf[cur].next[dic[tot][i]-'A'] = totbuf;
            buf[totbuf].flag = -1;
            for (int j = 0;j < 'Z'-'A';j++)
                buf[totbuf].next[j] = -1;
            cur = totbuf;
        }
        buf[cur].flag = tot;
        tot++;
    }
    p[2][1] = 'A';p[2][2] = 'B';p[2][3] = 'C';
    p[3][1] = 'D';p[3][2] = 'E';p[3][3] = 'F';
    p[4][1] = 'G';p[4][2] = 'H';p[4][3] = 'I';
    p[5][1] = 'J';p[5][2] = 'K';p[5][3] = 'L';
    p[6][1] = 'M';p[6][2] = 'N';p[6][3] = 'O';
    p[7][1] = 'P';p[7][2] = 'R';p[7][3] = 'S';
    p[8][1] = 'T';p[8][2] = 'U';p[8][3] = 'W';
    p[9][1] = 'W';p[9][2] = 'X';p[9][3] = 'Y';
    freopen("namenum.in","r",stdin);
    freopen("namenum.out","w",stdout);
    scanf("%s",num);
    flag = false;
    DFS(0,0);
    if (flag == false)
        puts("NONE");
}
