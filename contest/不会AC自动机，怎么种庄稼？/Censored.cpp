#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int move[110][110];

struct trie
{
    int next[110][110],fail[110];
    char charset[110];
    bool end[110];
    int root,L,charsetlen;
    int newnode(int pos)
    {
        for (int i = 0; i < charsetlen; i++)
            next[pos][i] = -1;
        end[pos] = false;
        return pos;
    }
    void init(char buf[])
    {
        strcpy(charset,buf);
        charsetlen = strlen(charset);
        L = 0;
        root = newnode(L++);
    }
    int getch(char ch)
    {
        for (int i = 0;i < charsetlen;i++)
            if (charset[i] == ch)
                return i;
    }
    void insert(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][getch(buf[i])] == -1)
                next[now][getch(buf[i])] = newnode(L++);
            now = next[now][getch(buf[i])];
        }
        end[now] = true;
    }
    void build()
    {
        queue<int> Q;
        for (int i = 0; i < charsetlen; i++)
            if (next[root][i] == -1)
                next[root][i] = root;
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            if (end[fail[now]] == true)
                end[now] = true;
            for (int i = 0; i < charsetlen; i++)
                if (next[now][i] == -1)
                    next[now][i] = next[fail[now]][i];
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
        }
    }
    void getmove()
    {
        for (int i = 0;i < L;i++)
            for (int j = 0;j < L;j++)
                move[i][j] = 0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < charsetlen; j++)
                if (end[next[i][j]] == false)
                    move[next[i][j]][i] += 1;
    }
};

struct BigInt
{
    int a[100],len;
    BigInt()
    {
        memset(a,0,sizeof(a));
        len = 1;
    }
    BigInt operator + (const BigInt& b)const
    {
        BigInt res = BigInt();
        for (int i = 0;i < 100;i++)
            res.a[i] = a[i]+b.a[i];
        for (int i = 0;i < 99;i++)
        {
            res.a[i+1] += res.a[i]/10;
            res.a[i] %= 10;
        }
        res.len = 1;
        for (int i = 99;i >= 0;i--)
            if (res.a[i] != 0)
            {
                res.len = i+1;
                break;
            }
        return res;
    }
    void output()
    {
        for (int i = len-1;i >= 0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
};

int n,m,p;
trie ac;
char buf[110];
BigInt dp[2][110];

int main()
{
    while (scanf("%d%d%d",&n,&m,&p) != EOF)
    {
        gets(buf);
        gets(buf);
        ac.init(buf);
        for (int i = 0; i < p; i++)
        {
            gets(buf);
            ac.insert(buf);
        }
        ac.build();
        ac.getmove();
        for (int i = 0;i < ac.L;i++)
            dp[0][i] = BigInt();
        dp[0][0].a[0] = 1;
        int pos = 0;
        for (int i = 0;i < m;i++,pos = !pos)
            for (int j = 0;j < ac.L;j++)
            {
                dp[!pos][j] = BigInt();
                for (int k = 0;k < ac.L;k++)
                    for (int q = 0;q < move[j][k];q++)
                        dp[!pos][j] = dp[!pos][j]+dp[pos][k];
            }
        BigInt res = BigInt();
        for (int i = 0;i < ac.L;i++)
            res = res+dp[pos][i];
        res.output();
    }
    return 0;
}

