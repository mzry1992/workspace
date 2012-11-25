#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

char buf[1000000],dic[300][300];
int tot,len[300];
bool del[300];

void Split()
{
    for (int i = 0; buf[i] != 0; i++)
        if (buf[i] == ';')
            buf[i] = ' ';
    tot = 0;
    int pos = 0,npos;
    while (sscanf(buf+pos,"%s%n",dic[tot++],&npos) != EOF)
        pos += npos;
    tot--;
}

int p[400];

void KMP(char b[],int lb)
{
    int j;
    p[0] = j = -1;
    for (int i = 1;i < lb;i++)
    {
        while (j >= 0 && b[j+1] != b[i])    j = p[j];
        if (b[j+1] == b[i]) j++;
        p[i] = j;
    }
}

int dist[300][200][200];
int dp[300][300],pre[300][300];
int rank[300][300][300];

void output(int now,int pos,int val)
{
    if (now == tot) return;
    for (int i = val;i < len[now];i++)
        putchar(dic[now][(pos+i)%len[now]]);
    output(now+1,pre[now][pos],dist[now+1][pre[now][pos]][pos]);
}

int main()
{
    freopen("G.in","r",stdin);
    freopen("G.out","w",stdout);
    int totcas;
    scanf("%d",&totcas);
    gets(buf);
    for (int cas = 1; cas <= totcas; cas++)
    {
        gets(buf);
        Split();
        for (int i = 0; i < tot; i++)
            len[i] = strlen(dic[i]);
        for (int i = 1;i < tot;i++)
            for (int j = 0;j < len[i];j++)
            {
                int l = 0;
                for (int k = 0;k < len[i];k++)
                    buf[l++] = dic[i][(j+k)%len[i]];
                buf[l++] = '|';
                for (int k = 0;k < len[i-1];k++)
                    buf[l++] = dic[i-1][k];
                for (int k = 0;k < len[i-1];k++)
                    buf[l++] = dic[i-1][k];
                buf[l] = 0;
                eKMP(buf,l);
//                puts(buf);
//                for (int k = 0;k < l;k++)
//                    printf("%d",p[k]+1);
//                puts("");
            }

        for (int i = 0;i < len[tot-1];i++)
            dp[tot-1][i] = len[tot-1];
        for (int i = tot-2;i >= 0;i--)
            for (int j = 0;j < len[i];j++)
            {
                dp[i][j] = 0x3fffffff;
                for (int k = 0;k < len[i+1];k++)
                {
                    int tmp = dp[i+1][k]+len[i]-dist[i+1][k][j];
                    if (tmp < dp[i][j])
                    {
                        dp[i][j] = tmp;
                        pre[i][j] = k;
                    }
                }
            }
        int res = 0x3fffffff;
        int pos;
        for (int i = 0;i < len[0];i++)
            if (res > dp[0][i])
            {
                res = dp[0][i];
                pos = i;
            }
        //output(0,pos,0);
        //puts("");
        printf("%d\n",res);
    }
    return 0;
}
